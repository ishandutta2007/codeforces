import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.PrintStream;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int[] h = new int[n];
        for (int i = 0; i < n; i++) {
            h[i] = in.nextInt();
        }
        long[] sum = new long[n];
        for (int i = 0; i < n; i++) {
            sum[i] = i == 0 ? h[0] : sum[i - 1] + h[i];
        }
        int[][] dp = new int[n + 1][n + 1];
        for (int[] d : dp) {
            Arrays.fill(d, Integer.MIN_VALUE);
        }
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            int[] next = new int[n + 1];
            int k = 0;
            for (int j = 0; j <= n; j++) {
                while (k <= n && getSum(sum, i, j) > getSum(sum, j, k)) {
                    k++;
                }
                next[j] = k;
            }
            for (int j = i; j < n; j++) {
                dp[i][j + 1] = Math.max(dp[i][j], dp[i][j + 1]);
                k = next[j];
                if (k <= n) {
                    dp[j][k] = Math.max(dp[j][k], dp[i][j] + 1);
                }
            }
        }
        int answer = 0;
        for (int i = 0; i < n; i++) {
            answer = Math.max(answer, dp[i][n]);
        }
        out.println(n - answer);
    }

    static long getSum(long[] sum, int left, int right) {
        if (right <= 0 || left >= right) {
            return 0;
        }
        long ret = sum[right - 1];
        if (left > 0) {
            ret -= sum[left - 1];
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