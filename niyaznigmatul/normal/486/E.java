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
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = in.nextInt();
        int[] longest1 = lis(n, a);
        for (int i = 0; i < n; i++) a[i] = -a[i];
        for (int i = 0; i < n - i - 1; i++) {
            int t = a[i];
            a[i] = a[a.length - i - 1];
            a[a.length - i - 1] = t;
        }
        int[] longest2 = lis(n, a);
        for (int i = 0; i < n - i - 1; i++) {
            int t = longest2[i];
            longest2[i] = longest2[n - i - 1];
            longest2[n - i - 1] = t;
        }
        int maximal = 0;
        for (int i = 0; i < n; i++) {
            maximal = Math.max(maximal, longest1[i] + longest2[i]);
        }
        boolean[] can = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (longest1[i] + longest2[i] == maximal) can[i] = true;
        }
        int[] countLens = new int[n + 1];
        for (int i = 0; i < n; i++) {
            if (can[i]) countLens[longest1[i]]++;
        }
        for (int i = 0; i < n; i++) {
            if (can[i] && countLens[longest1[i]] == 1) {
                out.print(3);
            } else if (can[i]) out.print(2); else out.print(1);
        }
        out.println();
    }

    private int[] lis(int n, int[] a) {
        int[] dp = new int[n + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = Integer.MIN_VALUE;
        int cn = 1;
        int[] longest = new int[n];
        for (int i = 0; i < n; i++) {
            int l = 0;
            int r = cn;
            while (l < r - 1) {
                int mid = (l + r) >> 1;
                if (dp[mid] >= a[i]) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            longest[i] = l + 1;
            if (r + 1 > cn) cn = r + 1;
            dp[r] = a[i];
        }
        return longest;
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