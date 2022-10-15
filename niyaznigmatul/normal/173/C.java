import java.io.InputStreamReader;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.Writer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author niyaznigmatul 
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
//        int n = 500;
//        int m = 500;
        int[][] a = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = in.nextInt();
//                a[i][j] = 0;
            }
        }
        int[][] b = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                b[i][j] = a[i][j];
                if (j > 0) {
                    b[i][j] += b[i][j - 1];
                }
                if (i > 0) {
                    b[i][j] += b[i - 1][j];
                }
                if (i > 0 && j > 0) {
                    b[i][j] -= b[i - 1][j - 1];
                }
            }
        }
        int[][] dp1 = new int[n][m];
        int[][] dp2 = new int[n][m];
        int ans = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp1[i][j] = a[i][j];
//                ans = Math.max(ans, dp[1][i][j]);
            }
        }
//        for (int i = 0; i + 1 < n; i++) {
//            for (int j = 0; j + 1 < m; j++) {
//                dp[2][i][j] = a[i + 1][j] + a[i + 1][j + 1];
//                ans = Math.max(ans, dp[2][i][j]);
//            }
//        }
        for (int i = 0; i + 2 < n; i++) {
            for (int j = 0; j + 2 < m; j++) {
                dp2[i][j] = sum(b, i, j, i, j + 2) + sum(b, i + 2, j, i + 2, j + 2) + a[i + 1][j + 2];
                ans = Math.max(ans, dp2[i][j]);
            }
        }
//        for (int i = 0; i + 3 < n; i++) {
//            for (int j = 0; j + 3 < m; j++) {
//                int size = 4;
//                dp[4][i][j] = sum(b, i, j, i, j + size - 1) + sum(b, i + size - 1, j, i + size - 1, j + size - 1)
//                            + sum(b, i + 2, j, i + size - 2, j) + sum(b, i + 1, j + size - 1, i + size - 2, j + size - 1);
//                ans = Math.max(ans, dp[4][i][j]);
//                System.err.println(dp[4][i][j] + " " + i + " " + j);
//            }
//        }
        for (int size = 5; size <= Math.max(n, m) + 1; size += 2) {
            int[][] next = new int[n][m];
            for (int i = 0; i + size <= n; i++) {
                for (int j = 0; j + size <= m; j++) {
                    next[i][j] = dp1[i + 2][j + 2] + sum(b, i, j, i, j + size - 1) + sum(b, i + size - 1, j, i + size - 1, j + size - 1)
                            + sum(b, i + 2, j, i + size - 2, j) + sum(b, i + 1, j + size - 1, i + size - 2, j + size - 1) + a[i + 2][j + 1];
                    ans = Math.max(ans, next[i][j]);
                }
            }
            dp1 = dp2;
            dp2 = next;
        }
        out.println(ans);
    }

    static int sum(int[][] a, int x1, int y1, int x2, int y2) {
        int ret = a[x2][y2];
        if (x1 > 0) {
            ret -= a[x1 - 1][y2];
        }
        if (y1 > 0) {
            ret -= a[x2][y1 - 1];
        }
        if (x1 > 0 && y1 > 0) {
            ret += a[x1 - 1][y1 - 1];
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