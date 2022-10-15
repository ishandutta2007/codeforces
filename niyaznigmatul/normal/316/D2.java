import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.Writer;
import java.util.HashSet;
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
		TaskD1 solver = new TaskD1();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD1 {

    static final int MOD = 1000000007;

    static int get(int n) {
        if (n <= 1) return 1;
        int[] dp = new int[n + 1];
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = (int) ((dp[i - 1] + (long) (i - 1) * dp[i - 2]) % MOD);
        }
        return dp[n];
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int[] a = in.readIntArray(n);
        int ones = 0;
        for (int i : a) {
            if (i == 1) {
                ones++;
            }
        }
        long dp = get(ones);
        for (int i = ones + 1; i <= n; i++) {
            dp = dp * i % MOD;
        }
        out.println(dp);
//        if (dp != solve(a)) {
//            throw new AssertionError();
//        }
//        for (int ones = 8; ones <= 8; ones++) {
//            for (int n = ones; n <= 8; n++) {
//                int twos = n - ones;
//                int[] a = new int[n];
//                for (int i = 0; i < n; i++) {
//                    a[i] = i < ones ? 1 : 2;
//                }
//                System.out.println(n + " " + ones + " " + solve(a));
//            }
//        }
//        int n = in.nextInt();
//        int[] a = new int[n];
//        for (int i = 0; i < n; i++) {
//            a[i] = in.nextInt();
//        }
//        out.println(solve(a));
    }

    }

class FastScanner extends BufferedReader {

    public FastScanner(InputStream is) {
        super(new InputStreamReader(is));
    }

    public int read() {
        try {
            int ret = super.read();
//            if (isEOF && ret < 0) {
//                throw new InputMismatchException();
//            }
//            isEOF = ret == -1;
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

    public String readLine() {
        try {
            return super.readLine();
        } catch (IOException e) {
            return null;
        }
    }

    public int[] readIntArray(int n) {
        int[] ret = new int[n];
        for (int i = 0; i < n; i++) {
            ret[i] = nextInt();
        }
        return ret;
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