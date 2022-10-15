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
		TaskE1 solver = new TaskE1();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE1 {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
//        int[] b = new int[n];
//        {
//            int curSum = 0;
//            for (int i = 0; i < n; i++) {
//                curSum += a[i];
//                b[i] = curSum;
//            }
//        }
        int[][] dp = new int[n + 1][k + 1];
        int[][] dp1 = new int[n + 1][k + 1];
        int[][] dp2 = new int[n + 1][k + 1];
        for (int[] e : dp)
            Arrays.fill(e, Integer.MIN_VALUE);
        for (int[] e : dp1)
            Arrays.fill(e, Integer.MIN_VALUE);
        for (int[] e : dp2)
            Arrays.fill(e, Integer.MIN_VALUE);
//        int[][] minElement = new int[n + 1][k + 1];
//        int[][] maxElement = new int[n + 1][k + 1];
//        for (int[] e : minElement) Arrays.fill(e, Integer.MAX_VALUE);
//        for (int[] e : maxElement) Arrays.fill(e, Integer.MIN_VALUE);
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int e = 1; e <= k; e++) {
            for (int i = 1; i <= n; i++) {
                dp[i][e] = dp[i - 1][e];
                dp1[i][e] = dp1[i - 1][e];
                dp2[i][e] = dp2[i - 1][e];
                int sum = 0;
                for (int j = i - 1; j >= 0; j--) {
                    sum += a[j];
                    if (dp[j][e - 1] == Integer.MIN_VALUE) continue;
                    int val1 = dp1[j][e - 1] == Integer.MIN_VALUE ? 0 : dp1[j][e - 1] + sum;
                    int val2 = dp2[j][e - 1] == Integer.MIN_VALUE ? 0 : dp2[j][e - 1] - sum;
                    int val = Math.max(val1, val2);
                    if (dp[i][e] < val) {
                        dp[i][e] = val;
                    }
                    if (dp1[i][e] < val - sum) {
                        dp1[i][e] = val - sum;
                    }
                    if (dp2[i][e] < val + sum) {
                        dp2[i][e] = val + sum;
                    }
                }
//                System.out.println(i + " " + e + " " + dp[i][e] + " " + dp1[i][e] + " " + dp2[i][e]);
            }
        }
        out.println(dp[n][k]);
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