import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

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
		Sub solver = new Sub();
		solver.solve(1, in, out);
		out.close();
	}
}

class Sub {
    long[][][][] cache;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        long n = in.nextLong();
        long res = solveIt(n);
        out.println(res);
    }

    private long solveIt(long n) {
        cache = new long[20][1 << 9][][];
        long[] ways = new long[10];
        Arrays.fill(ways, INF);
        ways[((int) (n % 10))] = 0;
        n /= 10;
        int pow = 1;
        for (long p10 = 1; n >= 0; p10 *= 10, ++pow) {
            long got = n / p10;
            while (got >= 0 && got % 10 != 9) {
                long[][] transfer = get(pow, makeMask(got));
                long[] nways = new long[10];
                Arrays.fill(nways, INF);
                for (int a = 0; a < 10; ++a)
                    for (int b = 0; b < 10; ++b)
                        nways[b] = Math.min(nways[b], transfer[a][b] + ways[a]);
                ways = nways;
                --got;
                n -= p10;
            }
        }
        return ways[0];
    }

    static final long INF = (long) 4e18;

    private long[][] get(int len, int mask) {
        long[][] res = cache[len][mask];
        if (res != null) return res;
        res = new long[10][10];
        for (long[] x : res) Arrays.fill(x, INF);
        cache[len][mask] = res;
        if (len == 1) {
            for (int last = 0; last < 10; ++last) {
                for (int digit = 1; digit < 10; ++digit) {
                    if (digit == last || (mask & (1 << (digit - 1))) != 0) {
                        int nlast = last - digit;
                        if (nlast < 0) {
                            res[last][nlast + 10] = Math.min(res[last][nlast + 10], 1);
                        } else {
                            for (int dest = 0; dest < 10; ++dest)
                                res[last][dest] = Math.min(res[last][dest], res[nlast][dest] + 1);
                        }
                    }
                }
                if (mask == 0 && last == 0)
                    res[0][0] = 0;
            }
        } else {
            for (int i = 0; i < 10; ++i) {
                res[i][i] = 0;
            }
            for (int pdigit = 9; pdigit >= 0; --pdigit) {
                int nmask = mask;
                if (pdigit > 0) nmask |= (1 << (pdigit - 1));
                long[][] step = get(len - 1, nmask);
                long[][] nres = new long[10][10];
                for (long[] x : nres) Arrays.fill(x, INF);
                for (int a = 0; a < 10; ++a)
                    for (int b = 0; b < 10; ++b)
                        for (int c = 0; c < 10; ++c)
                            nres[a][c] = Math.min(nres[a][c], res[a][b] + step[b][c]);
                res = nres;
            }
        }
        cache[len][mask] = res;
        return res;
    }

    private int makeMask(long x) {
        int res = 0;
        while (x > 0) {
            int cur = (int) (x % 10);
            x /= 10;
            if (cur > 0)
                res |= 1 << (cur - 1);
        }
        return res;
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
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

    public long nextLong() {
        return Long.parseLong(next());
    }

    }