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
 * @author niyaznigmatul 
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        if (isGeometric(a)) {
            out.println(0);
            return;
        }
        int[] b = Arrays.copyOfRange(a, 1, n);
        int[] c = b.clone();
        b[0] = a[0];
        if (isGeometric(b) || isGeometric(c)) {
            out.println(1);
            return;
        }
        int bad = 0;
        int last = 1;
        int prev = 0;
        if (a[0] == 0) {
            for (int i = 0; i < n; i++) {
                if (a[i] != 0) {
                    ++bad;
                }
            }
            if (bad == 1) {
                out.println(1);
            } else {
                out.println(2);
            }
            return;
        }
        for (int i = 2; i < n; i++) {
            if (a[last] * a[last] != a[prev] * a[i] || a[last] == 0 && a[i] != 0) {
                bad++;
            } else {
                prev = last;
                last = i;
            }
        }
        if (bad == 1) {
            out.println(1);
            return;
        }
        out.println(2);
    }

    private boolean isGeometric(int[] a) {
        boolean ret = true;
        int n = a.length;
        if (a[0] == 0) {
            for (int i = 1; i < n; i++) {
                if (a[i] != 0) {
                    return false;
                }
            }
            return true;
        }
        for (int i = 1; i + 1 < n; i++) {
            if (a[i] * a[i] != a[i - 1] * a[i + 1] || a[i] == 0 && a[i + 1] != 0) {
                ret = false;
            }
        }
        return ret;
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