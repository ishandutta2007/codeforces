import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.PrintStream;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.io.Reader;
import java.io.Writer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Niyaz Nigmatullin
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
//        test();
        int n = in.nextInt();
        int m = in.nextInt();
        out.println(solve(n, m));
    }

    static final int MOD = 1000000007;

    static int solve(int n, int m) {
        int[][][][] dp = new int[2][2][n][n];
        int[][][][] next = new int[2][2][n][n];
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int a = 0; a < 2; a++) {
                for (int b = 0; b < 2; b++) {
                    makePart(dp[a][b], n, n);
                    for (int[] d : next[a][b]) {
                        Arrays.fill(d, 0);
                    }
                }
            }
            {
                int[][] n00 = next[0][0];
                int[][] n01 = next[0][1];
                int[][] n10 = next[1][0];
                int[][] n11 = next[1][1];
                int[][] d00 = dp[0][0];
                int[][] d11 = dp[1][1];
                int[][] d10 = dp[1][0];
                int[][] d01 = dp[0][1];
                for (int c = 0; c < n; c++) {
                    for (int d = c; d < n; d++) {
                        n00[c][d] = getSum(d00, c, d + 1, c, d + 1);
                        n01[c][d] = getSum(d00, c, d + 1, d + 1, n) + getSum(d01, c, d + 1, d, n);
                        if (n01[c][d] >= MOD) {
                            n01[c][d] -= MOD;
                        }
                        n10[c][d] = getSum(d00, 0, c, c, d + 1) + getSum(d10, 0, c + 1, c, d + 1);
                        if (n10[c][d] >= MOD) {
                            n10[c][d] -= MOD;
                        }
                        int z = getSum(d00, 0, c, d + 1, n) + getSum(d01, 0, c, d, n);
                        if (z >= MOD) {
                            z -= MOD;
                        }
                        z += getSum(d10, 0, c + 1, d + 1, n);
                        if (z >= MOD) {
                            z -= MOD;
                        }
                        z += getSum(d11, 0, c + 1, d, n);
                        if (z >= MOD) {
                            z -= MOD;
                        }
                        n11[c][d] = z;
                    }
                }
            }
            int[][] n00 = next[0][0];
            for (int c = 0; c < n; c++) {
                for (int d = c; d < n; d++) {
                    n00[c][d]++;
                    if (n00[c][d] >= MOD) {
                        n00[c][d] -= MOD;
                    }
                }
            }
            for (int a = 0; a < 2; a++) {
                for (int b = 0; b < 2; b++) {
                    int[][] nab = next[a][b];
                    for (int c = 0; c < n; c++) {
                        for (int d = 0; d < n; d++) {
                            ans += nab[c][d];
                            if (ans >= MOD) {
                                ans -= MOD;
                            }
                        }
                    }
                }
            }
            int[][][][] t = dp;
            dp = next;
            next = t;
        }
        return ans;
    }

    static void makePart(int[][] a, int b, int c) {
        for (int i = 1; i < b; i++) {
            for (int j = 0; j < c; j++) {
                a[i][j] += a[i - 1][j];
                if (a[i][j] >= MOD) {
                    a[i][j] -= MOD;
                }
            }
        }
        for (int i = 0; i < b; i++) {
            for (int j = 1; j < c; j++) {
                a[i][j] += a[i][j - 1];
                if (a[i][j] >= MOD) {
                    a[i][j] -= MOD;
                }
            }
        }
    }

    static int getSum(int[][] a, int x1, int x2, int y1, int y2) {
        if (x1 >= x2 || y1 >= y2) return 0;
        int ret = a[x2 - 1][y2 - 1];
        if (x1 > 0) {
            ret -= a[x1 - 1][y2 - 1];
            if (ret < 0) ret += MOD;
        }
        if (y1 > 0) {
            ret -= a[x2 - 1][y1 - 1];
            if (ret < 0) ret += MOD;
        }
        if (x1 > 0 && y1 > 0) {
            ret += a[x1 - 1][y1 - 1];
            if (ret >= MOD) ret -= MOD;
        }
        return ret;
    }
}

class FastScanner extends BufferedReader {

    boolean isEOF;

    public FastScanner(InputStream is) {
        super(new InputStreamReader(is));
    }

    public int read() {
        try {
            int ret = super.read();
            if (isEOF && ret < 0) {
                throw new InputMismatchException();
            }
            isEOF = ret == -1;
            return ret;
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }

    static boolean isWhiteSpace(int c) {
        return c >= -1 && c <= 32;
    }

    public int nextInt() {
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int ret = 0;
        while (!isWhiteSpace(c)) {
            if (c < '0' || c > '9') {
                throw new NumberFormatException("digit expected " + (char) c
                        + " found");
            }
            ret = ret * 10 + c - '0';
            c = read();
        }
        return ret * sgn;
    }

    }

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }

    public FastPrinter(Writer out) {
        super(out);
    }


}