import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
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
 * @author Niyaz Nigmatullin
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
        int w = in.nextInt();
        int n = in.nextInt();
        int c0 = in.nextInt();
        int d0 = in.nextInt();
        int[] dp = new int[w + 1];
        Arrays.fill(dp, Integer.MIN_VALUE);
        dp[0] = 0;
        for (int i = 0; i + c0 <= w; i++) {
            int val = dp[i];
            if (val == Integer.MIN_VALUE) {
                continue;
            }
            dp[i + c0] = Math.max(dp[i + c0], dp[i] + d0);
        }
        for (int i = 0; i < n; i++) {
            int all = in.nextInt();
            all /= in.nextInt();
            int c = in.nextInt();
            int d = in.nextInt();
            for (int j = w; j >= 0; j--) {
                for (int k = 1; j >= k * c && k <= all; k++) {
                    int val = dp[j - k * c];
                    if (val == Integer.MIN_VALUE) {
                        continue;
                    }
                    dp[j] = Math.max(dp[j], val + d * k);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= w; i++) {
            ans = Math.max(ans, dp[i]);
        }
        out.println(ans);
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