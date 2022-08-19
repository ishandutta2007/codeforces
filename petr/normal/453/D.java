import java.io.InputStreamReader;
import java.io.IOException;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    long[][] comb;
    long[][][] ways;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int m = in.nextInt();
        long t = in.nextLong();
        long p = in.nextLong();
        long[] e0 = new long[1 << m];
        for (int i = 0; i < e0.length; ++i) e0[i] = in.nextLong() % p;
        long[] b = new long[m + 1];
        for (int i = 0; i < b.length; ++i) b[i] = in.nextLong();

        comb = new long[m + 1][m + 1];
        comb[0][0] = 1 % p;
        for (int i = 1; i <= m; ++i) {
            comb[i][0] = 1 % p;
            for (int j = 1; j <= m; ++j) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % p;
            }
        }

        ways = new long[m + 1][m + 1][m + 1];
        for (int da = 0; da <= m; ++da)
            for (int db = 0; db <= m; ++db)
                for (int dc = 0; dc <= m; ++dc)
                    for (int dd = 0; dd <= m; ++dd) {
                        if (dd > da) continue;
                        if (dd > dc) continue;
                        if (dc - dd > db) continue;
                        if (da - dd != db - (dc - dd)) continue;
                        if (da - dd > m - dc) continue;
                        ways[da][db][dc] = (ways[da][db][dc] + comb[dc][dd] * comb[m - dc][da - dd]) % p;
                    }

        b = pow(b, t, m, p);

        int[][] sumAtDist = new int[m + 1][1 << m];
        for (int i = 0; i < (1 << m); ++i)
            sumAtDist[0][i] = (int) e0[i];
        for (int bit = 0; bit < m; ++bit) {
            for (int oldDist = bit; oldDist >= 0; --oldDist) {
                int[] old = sumAtDist[oldDist];
                int[] nxt = sumAtDist[oldDist + 1];
                for (int x = 0; x < (1 << m); ++x) {
                    int xx = x ^ (1 << bit);
                    nxt[xx] += old[x];
                    if (nxt[xx] >= p) nxt[xx] -= p;
                }
            }
        }
        long[] res = new long[1 << m];
        for (int dist = 0; dist <= m; ++dist) {
            long mult = b[dist];
            for (int x = 0; x < (1 << m); ++x) {
                res[x] = (res[x] + sumAtDist[dist][x] * mult) % p;
            }
        }

        for (long x : res) {
            out.println(x);
        }
    }

    private long[] pow(long[] b, long t, int m, long p) {
        if (t == 0) {
            long[] res = new long[m + 1];
            res[0] = 1;
            return res;
        }
        if (t % 2 == 0) {
            return pow(mul(b, b, m, p), t / 2, m, p);
        } else {
            return mul(b, pow(b, t - 1, m, p), m, p);
        }
    }

    private long[] mul(long[] a, long[] b, int m, long p) {
        long[] res = new long[m + 1];
        for (int da = 0; da <= m; ++da)
            for (int db = 0; db <= m; ++db)
                for (int dc = 0; dc <= m; ++dc) {
                    long w = ways[da][db][dc];
                    if (w == 0) continue;
                    res[dc] = (res[dc] + ways[da][db][dc] * a[da] % p * b[db]) % p;
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