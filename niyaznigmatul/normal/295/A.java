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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        int[] left = new int[m];
        int[] right = new int[m];
        int[] d = new int[m];
        for (int i = 0; i < m; i++) {
            left[i] = in.nextInt() - 1;
            right[i] = in.nextInt();
            d[i] = in.nextInt();
        }
        int[] c = new int[m];
        for (int i = 0; i < k; i++) {
            int x = in.nextInt() - 1;
            int y = in.nextInt();
            c[x]++;
            if (y < m) {
                --c[y];
            }
        }
        for (int i = 1; i < m; i++) {
            c[i] += c[i - 1];
        }
        long[] b = new long[n];
        for (int i = 0; i < m; i++) {
            long dd = (long) c[i] * d[i];
            b[left[i]] += dd;
            if (right[i] < n) {
                b[right[i]] -= dd;
            }
        }
        for (int i = 1; i < n; i++) {
            b[i] += b[i - 1];
        }
        for (int i = 0; i < n; i++) {
            if (i > 0)out.print(' ');
            out.print(a[i] + b[i]);
        }
        out.println();
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

    }

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }

    public FastPrinter(Writer out) {
        super(out);
    }


}