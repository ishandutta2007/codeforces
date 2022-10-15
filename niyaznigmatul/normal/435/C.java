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
        int[] a = in.readIntArray(n);
        int[] x = new int[n + 1];
        int[] y = new int[n + 1];
        x[0] = 0;
        y[0] = 0;
        for (int i = 1; i <= n; i++) {
            x[i] = x[i - 1] + a[i - 1];
            y[i] = y[i - 1] + ((i & 1) == 1 ? 1 : -1) * a[i - 1];
        }
        int maxY = 0;
        int minY = 0;
        for (int i : y) {
            maxY = Math.max(maxY, i);
            minY = Math.min(minY, i);
        }
        char[][] c = new char[maxY - minY][x[n]];
        for (char[] e : c) Arrays.fill(e, ' ');
        for (int i = 0; i < n; i++) {
            for (int cx = x[i], cy = y[i]; cx < x[i + 1]; cx++) {
                if ((i & 1) == 0) {
                    c[c.length - (cy - minY) - 1][cx] = '/';
                }
                cy += (i & 1) == 0 ? 1 : -1;
                if ((i & 1) == 1) {
                    c[c.length - (cy - minY) - 1][cx] = '\\';
                }
            }
        }
        for (char[] e : c) out.println(e);
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