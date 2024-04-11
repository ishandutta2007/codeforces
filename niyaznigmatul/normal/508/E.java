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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int[][] dp = new int[n][n];
        int[] left = new int[n];
        int[] right = new int[n];
        for (int i = 0; i < n; i++) {
            left[i] = in.nextInt();
            right[i] = in.nextInt();
        }
        for (int[] e : dp) Arrays.fill(e, -1);
        for (int i = 0; i < n; i++) {
            if (left[i] <= 1 && 1 <= right[i]) {
                dp[i][i] = 0;
            }
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 0, j = len - 1; j < n; i++, j++) {
                for (int dist = left[i]; dist <= right[i]; dist++) {
                    if ((dist & 1) == 0) continue;
                    int inside = dist / 2;
                    int after = i + 1 + inside;
                    if (after > j + 1) continue;
                    int before = after - 1;
                    boolean can1 = i + 1 > before || dp[i + 1][before] >= 0;
                    boolean can2 = after > j || dp[after][j] >= 0;
                    if (can1 && can2) {
                        dp[i][j] = after;
                        break;
                    }
                }
            }
        }
        if (dp[0][n - 1] < 0) {
            out.println("IMPOSSIBLE");
        } else {
            out.println(restore(0, n - 1, dp));
        }
    }

    static String restore(int left, int right, int[][] dp) {
        if (left == right) return "()";
        int after = dp[left][right];
        String ret = "(";
        if (left + 1 <= after - 1) ret += restore(left + 1, after - 1, dp);
        ret += ")";
        if (after <= right) ret += restore(after, right, dp);
        return ret;
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

}

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }

    public FastPrinter(Writer out) {
        super(out);
    }


}