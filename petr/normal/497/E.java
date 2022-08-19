import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.StringTokenizer;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    static final long MODULO = (long) (1e9 + 7);
    static final long BIG = Long.MAX_VALUE - Long.MAX_VALUE % MODULO;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        long n = in.nextLong();
        int k = in.nextInt();
        long pk = 1;
        int pow = 0;
        while (pk <= n / k) {
            pk *= k;
            ++pow;
        }
        matrCache = new long[pow + 1][][];
        long at = 0;
        long[] ways = new long[k + 1];
        ways[k] = 1;
        while (at < n) {
            while (at + pk <= n) {
                long[][] matr = getMatr(digitSum(at, k) % k, k, pow);
                ways = mul(matr, ways);
                at += pk;
            }
            pk /= k;
            --pow;
        }
        long res = 0;
        for (long x : ways) res += x;
        res %= MODULO;
        out.println(res);
    }

    long[][][] matrCache;

    private long[][] getMatr(int pre, int k, int pow) {
        long[][] res = matrCache[pow];
        if (res == null) {
            if (pow == 0) {
                res = new long[k + 1][k + 1];
                for (int i = 0; i < k + 1; ++i) ++res[i][i];
                for (int i = 0; i < k + 1; ++i) {
                    ++res[0][i];
                }
                --res[0][0];
            } else {
                res = new long[k + 1][k + 1];
                for (int i = 0; i < k + 1; ++i) ++res[i][i];
                for (int i = 0; i < k; ++i) {
                    res = mul(getMatr(i, k, pow - 1), res);
                }
            }
            matrCache[pow] = res;
        }
        long[][] rotated = new long[k + 1][k + 1];
        for (int i = 0; i <= k; ++i)
            for (int j = 0; j <= k; ++j) {
                int ii = (i == k) ? k : (pre + i) % k;
                int jj = (j == k) ? k : (pre + j) % k;
                rotated[ii][jj] = res[i][j];
            }
        return rotated;
    }

    private long[] mul(long[][] a, long[] b) {
        long[] c = new long[b.length];
        for (int i = 0; i < c.length; ++i) {
            long s = 0;
            for (int j = 0; j < c.length; ++j) {
                s += a[i][j] * b[j];
                if (s < 0) s -= BIG;
            }
            c[i] = s % MODULO;
        }
        return c;
    }

    private long[][] mul(long[][] a, long[][] b) {
        long[][] c = new long[b.length][b.length];
        for (int i = 0; i < c.length; ++i) {
            for (int k = 0; k < c.length; ++k) {
                long s = 0;
                for (int j = 0; j < c.length; ++j) {
                    s += a[i][j] * b[j][k];
                    if (s < 0) s -= BIG;
                }
                c[i][k] = s % MODULO;
            }
        }
        return c;
    }

    private int digitSum(long at, int k) {
        int res = 0;
        while (at > 0) {
            res += at % k;
            at /= k;
        }
        return res;
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream), 32768);
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

}