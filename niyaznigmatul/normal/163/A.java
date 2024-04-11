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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {

    static final int MOD = 1000000007;

	public void solve(int testNumber, FastScanner in, FastPrinter out) {
        char[] c1 = in.next().toCharArray();
        char[] c2 = in.next().toCharArray();
        int[][] dp = new int[c1.length + 1][c2.length + 1];
        for (int i = 0; i <= c1.length; i++) {
            dp[i][0] = 1;
        }
        for (int i = 0; i <= c1.length; i++) {
            for (int j = 0; j <= c2.length; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                if (j > 0) {
                    dp[i][j] += dp[i][j - 1];
                    if (dp[i][j] >= MOD) {
                        dp[i][j] -= MOD;
                    }
                }
                if (i > 0 && j > 0 && c1[i - 1] == c2[j - 1]) {
                    dp[i][j] += dp[i - 1][j - 1];
                    if (dp[i][j] >= MOD) {
                        dp[i][j] -= MOD;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= c1.length; i++) {
            ans += dp[i][c2.length];
            if (ans >= MOD) {
                ans -= MOD;
            }
        }
        out.println((ans + MOD - c1.length) % MOD);
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

    public String next() {
        StringBuilder sb = new StringBuilder();
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        while (!isWhiteSpace(c)) {
            sb.appendCodePoint(c);
            c = read();
        }
        return sb.toString();
    }

    static boolean isWhiteSpace(int c) {
        return c >= -1 && c <= 32;
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