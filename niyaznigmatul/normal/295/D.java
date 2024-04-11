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
//        if (solve(n, m) != solveStupid(n, m)) {
//            throw new AssertionError();
//        }
    }

    static final int MOD = 1000000007;

    static int solve(int n, int m) {
        int[][] dp = new int[m][n + 1];
        int[][] dp2 = new int[m][n + 1];
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            int s = 0;
            int ss = 0;
            dp[0][i] = 1;
            for (int j = 1; j < m; j++) {
                dp2[j][i] = (ss + s + 1) % MOD;
                s += dp[j][i - 1];
                if (s >= MOD) {
                    s -= MOD;
                }
                ss += s;
                if (ss >= MOD) {
                    ss -= MOD;
                }
                dp[j][i] = (ss + 1) % MOD;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int j = 1; j < m; j++) {
                cur = (int) ((cur + (long) dp[j][i + 1] * dp2[j][n - i] % MOD * (m - j)) % MOD);
            }
            ans += cur;
            if (ans >= MOD) {
                ans -= MOD;
            }
        }
        return ans;
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
        return c >= 0 && c <= 32;
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
        while (c >= 0 && !isWhiteSpace(c)) {
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