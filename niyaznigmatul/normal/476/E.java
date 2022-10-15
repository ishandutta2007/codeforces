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
        char[] c = in.next().toCharArray();
        char[] p = in.next().toCharArray();
        int[][] dp = new int[c.length + 1][c.length / p.length + 1];
        for (int[] e : dp) Arrays.fill(e, Integer.MAX_VALUE);
        dp[0][0] = 0;
        for (int i = 0; i < c.length; i++) {
            for (int j = 0; j < dp[i].length; j++) {
                if (dp[i][j] != Integer.MAX_VALUE)
                    dp[i + 1][j] = dp[i][j];
            }
            int cur = p.length - 1;
            int where = -1;
            for (int j = i; j >= 0; j--) {
                if (p[cur] == c[j]) {
                    --cur;
                }
                if (cur < 0) {
                    where = j;
                    break;
                }
            }
            if (where < 0) continue;
            for (int entries = 1; entries < dp[i + 1].length; entries++) {
                int got = dp[where][entries - 1];
                if (got == Integer.MAX_VALUE) continue;
                dp[i + 1][entries] = Math.min(dp[i + 1][entries], got + (i + 1 - where - p.length));
            }
        }
//        System.out.println(Arrays.deepToString(dp));
        int[] ans = new int[c.length + 1];
        for (int i = 0; i < dp[c.length].length; i++) {
            int cur = dp[c.length][i];
            if (cur == Integer.MAX_VALUE) continue;
            ans[cur] = Math.max(ans[cur], i);
        }
        for (int i = 1; i <= c.length; i++) ans[i] = Math.max(ans[i], ans[i - 1]);
        for (int i = 0; i <= c.length; i++) {
            int left = c.length - i;
            ans[i] = Math.min(ans[i], left / p.length);
        }
        out.printArray(ans);
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

    public String next() {
        StringBuilder sb = new StringBuilder();
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        if (c < 0) {
            return null;
        }
        while (c >= 0 && !isWhiteSpace(c)) {
            sb.appendCodePoint(c);
            c = read();
        }
        return sb.toString();
    }

    static boolean isWhiteSpace(int c) {
        return c >= 0 && c <= 32;
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

    public void printArray(int[] a) {
        for (int i = 0; i < a.length; i++) {
            if (i > 0) {
                print(' ');
            }
            print(a[i]);
        }
        println();
    }


}