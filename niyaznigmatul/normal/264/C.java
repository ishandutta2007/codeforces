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
        int n = in.nextInt();
        int q = in.nextInt();
        int[] v = in.readIntArray(n);
        int[] c = in.readIntArray(n);
        long[] max0 = new long[n + 1];
        int[] c0 = new int[n + 1];
        for (int test = 0; test < q; test++) {
            Arrays.fill(max0, 0);
            Arrays.fill(c0, 0);
            long a = in.nextInt();
            long b = in.nextInt();
            long max1 = 0;
            long max2 = 0;
            int c1 = 0;
            int c2 = 0;
            for (int i = 0; i < n; i++) {
                long cur1 = (c1 == c[i] ? a : b) * v[i] + max1;
                long cur2 = (c2 == c[i] ? a : b) * v[i] + max2;
                long cur3 = (c0[c[i]] == c[i] ? a : b) * v[i] + max0[c[i]];
                long max3 = Math.max(cur3, Math.max(cur1, cur2));
                int c3 = c[i];
                if (max3 > max1) {
                    if (c1 != c[i]) {
                        max2 = max1;
                        c2 = c1;
                    }
                    max1 = max3;
                    c1 = c3;
                } else if (max3 > max2 && c1 != c[i]) {
                    max2 = max3;
                    c2 = c3;
                }
                if (c0[c[i]] == 0 || max0[c[i]] < max3) {
                    max0[c[i]] = max3;
                    c0[c[i]] = c3;
                }
            }
            long answer = 0;
            for (int i = 0; i <= n; i++) {
                answer = Math.max(answer, max0[i]);
            }
            out.println(answer);
        }
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