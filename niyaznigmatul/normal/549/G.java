import java.io.Reader;
import java.util.InputMismatchException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;

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
		TaskG solver = new TaskG();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskG {

    static class Element {
        int val;
        int toLeft;
        int toRight;

        public Element(int val) {
            this.val = val;
        }
    }

    static long inversions(Element[] a, Element[] b, int left, int right) {
        if (b == null) {
            b = new Element[a.length];
        }
        if (left + 1 >= right) {
            return 0;
        }
        int middle = left + right >> 1;
        long ret = inversions(a, b, left, middle) + inversions(a, b, middle, right);
        for (int i = left, j = middle, k = 0; i < middle || j < right; k++) {
            if (j >= right || i < middle && a[i].val <= a[j].val) {
                ret += j - middle;
                a[i].toRight += j - middle;
                b[k] = a[i++];
            } else {
                a[j].toLeft += middle - i;
                b[k] = a[j++];
            }
        }
        for (int i = left; i < right; i++) {
            a[i] = b[i - left];
        }
        return ret;
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int[] a = in.readIntArray(n);
        Element[] f = new Element[n];
        for (int i = 0; i < n; i++) {
            f[i] = new Element(i + a[i]);
        }
        Element[] g = f.clone();
        long z = inversions(f, null, 0, f.length);
        int[] q = new int[n];
//        for (int i = 0; i < n; i++) {
//            System.err.println(a[i] + " " + g[i].toLeft + " " + g[i].toRight);
//        }
        for (int i = 0; i < n; i++) {
            q[i + g[i].toRight - g[i].toLeft] = a[i] - g[i].toRight + g[i].toLeft;
        }
        for (int i = 0; i + 1 < n; i++) if (q[i] > q[i + 1]) {
            out.println(":(");
            return;
        }
        out.printArray(q);
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