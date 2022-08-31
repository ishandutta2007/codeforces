import java.util.Arrays;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Random;
import java.util.HashMap;
import java.io.BufferedReader;
import java.util.Map;
import java.io.PrintStream;
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
    static final int MODULO = 10007;
    int magic;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        String s = in.next();
        int n = in.nextInt() + s.length();
        int[][][] ways = new int[s.length()][s.length() + 1][s.length() / 2 + 2];
        int[][] waysAll = new int[3][s.length() / 2 + 2];
        ways[0][s.length()][0] = 1;
        for (int start = 0; start < s.length(); ++start)
            for (int len = s.length() - start; len >= 1; --len) {
                int[] src = ways[start][len];
                if (s.charAt(start) == s.charAt(start + len - 1)) {
                    int nlen = len - 2;
                    int[] dest;
                    if (nlen <= 0) {
                        dest = waysAll[len];
                    } else {
                        dest = ways[start + 1][nlen];
                    }
                    for (int doubles = 0; doubles < src.length; ++doubles) if (src[doubles] != 0) {
                        dest[doubles + 1] = (dest[doubles + 1] + src[doubles]) % MODULO;
                    }
                } else {
                    int nlen = len - 1;
                    int[] dest = ways[start][nlen];
                    for (int doubles = 0; doubles < src.length; ++doubles) if (src[doubles] != 0) {
                        dest[doubles] = (dest[doubles] + src[doubles]) % MODULO;
                    }
                    dest = ways[start + 1][nlen];
                    for (int doubles = 0; doubles < src.length; ++doubles) if (src[doubles] != 0) {
                        dest[doubles] = (dest[doubles] + src[doubles]) % MODULO;
                    }
                }
            }
        int steps = n / 2;
        int ret = 0;
        int maxSingles = s.length();
        int maxDoubles = waysAll[1].length - 1;
        int size = maxSingles + maxDoubles + maxDoubles;
        magic = maxDoubles + maxSingles;
        int[][] m = new int[size][size];
        for (int i = 0; i < maxSingles + maxDoubles + maxDoubles; ++i) {
            if (i + 1 < maxSingles + maxDoubles) m[i + 1][i] = 1;
            if (i >= maxSingles && i < maxSingles + maxDoubles) m[i + maxDoubles][i] = 1;
            m[i][i] = (i < maxSingles ? 24 : (i < maxSingles + maxDoubles ? 25 : 26));
        }
        m = pow(m, steps);
        for (int last = 1; last <= 2; ++last) {
            for (int doubles = 0; doubles < waysAll[last].length; ++doubles) {
                int w = waysAll[last][doubles];
                if (w != 0) {
                    int singles = s.length() + (last == 1 ? 1 : 0) - 2 * doubles;
                    if (n % 2 == 0) {
                        ret = (int) ((ret + (long) w * m[maxSingles + maxDoubles + doubles - 1][maxSingles - singles]) % MODULO);
                    } else {
                        ret = (int) ((ret + (long) w * m[maxSingles + maxDoubles + doubles - 1][maxSingles - singles] * 26) % MODULO);
                        if (last == 1) {
                            ret = (int) ((ret + (long) w * m[maxSingles + doubles - 1][maxSingles - singles]) % MODULO);
                        }
                    }
                }
            }
        }
        out.println(ret);
    }

    private int[][] pow(int[][] m, int k) {
        int[][] res = new int[m.length][m.length];
        for (int i = 0; i < m.length; ++i) res[i][i] = 1;
        while (k > 0) {
            System.err.println(k + " " + m.length);
            if (k % 2 != 0) {
                res = mul(m, res);
            }
            k /= 2;
            m = mul(m, m);
        }
        return res;
    }

    private final int BIG = Integer.MAX_VALUE - Integer.MAX_VALUE % MODULO;

    private int[][] mul(int[][] a, int[][] b) {
        int n = a.length;
        int[][] c = new int[n][n];
        for (int i = 0; i < c.length; ++i) {
            for (int j = 0; j < magic; ++j) {
                int s = 0;
                for (int k = 0; k < magic; ++k) {
                    s += a[i][k] * b[k][j];
                    if (s < 0)
                        s -= BIG;
                }
                if (i >= magic) {
                    int k = i;
                    s += a[i][k] * b[k][j];
                    if (s < 0)
                        s -= BIG;
                }
                c[i][j] = s % MODULO;
            }
            if (i >= magic) {
                int j = i;
                int s = 0;
                for (int k = 0; k < magic; ++k) {
                    s += a[i][k] * b[k][j];
                    if (s < 0)
                        s -= BIG;
                }
                if (i >= magic) {
                    int k = i;
                    s += a[i][k] * b[k][j];
                    if (s < 0)
                        s -= BIG;
                }
                c[i][j] = s % MODULO;
            }
        }
        return c;
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

}