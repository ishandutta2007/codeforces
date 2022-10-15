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
 * @author Niyaz Nigmatullin
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskF solver = new TaskF();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskF {
    static int MOD;

    static int add(int a, int b) {
        a += b;
        if (a >= MOD) a -= MOD;
        return a;
    }

    static int mul(int a, int b) {
        return (int) ((long) a * b % MOD);
    }

    static int f(int n) {
        return n * (n - 1) / 2 % MOD;
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        MOD = in.nextInt();
        int zeros = 0;
        int ones = 0;
        int[] cnt = new int[n];
        for (int i = 0; i < m; i++) {
            char[] c = in.next().toCharArray();
            for (int j = 0; j < n; j++) {
                cnt[j] += c[j] - '0';
            }
        }
        for (int i = 0; i < n; i++) {
            if (cnt[i] == 0) ++zeros; else
                if (cnt[i] == 1) ++ones;
        }
        int[][] dp = new int[n + 1][n + 1];
        dp[zeros][ones] = 1;
        for (int i = m; i < n; i++) {
            int[][] next = new int[n + 1][n + 1];
            for (int c0 = 0; c0 <= n; c0++) {
                for (int c1 = 0; c1 <= n; c1++) {
                    int val = dp[c0][c1];
                    if (val == 0) continue;
                    if (c0 >= 2) {
                        next[c0 - 2][c1 + 2] = add(next[c0 - 2][c1 + 2], mul(f(c0), val));
                    }
                    if (c0 >= 1 && c1 >= 1) {
                        next[c0 - 1][c1] = add(next[c0 - 1][c1], mul(c0, mul(c1, val)));
                    }
                    if (c1 >= 2) {
                        next[c0][c1 - 2] = add(next[c0][c1 - 2], mul(f(c1), val));
                    }
                }
            }
            dp = next;
        }
        out.println(dp[0][0]);
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