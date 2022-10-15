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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int w = in.nextInt();
        FenwickMultiSum fx = new FenwickMultiSum(n);
        FenwickMultiSum fy = new FenwickMultiSum(m);
        long all = 0;
        for (int i = 0; i < w; i++) {
            int type = in.nextInt();
            int x1 = in.nextInt() - 1;
            int y1 = in.nextInt() - 1;
            int x2 = in.nextInt();
            int y2 = in.nextInt();
            if (type == 0) {
                long v = in.nextInt();
                all += v * (x2 - x1) * (y2 - y1);
                fx.add(x1, x2, (y2 - y1) * v);
                fy.add(y1, y2, (x2 - x1) * v);
            } else {
                out.println(fx.getSum(x1, x2) + fy.getSum(y1, y2) - all);
            }
        }
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


}

class FenwickMultiSum {
    long[] a;
    long[] b;

    public FenwickMultiSum(int n) {
        a = new long[n];
        b = new long[n];
    }

    public void add(int x, long d) {
        addSuffix(a, x, d);
        addSuffix(b, x, d * (1 - x));
    }

    private static void addSuffix(long[] a, int x, long d) {
        for (int i = x; i < a.length; i |= i + 1) {
            a[i] += d;
        }
    }

    public void add(int left, int right, long d) {
        add(left, d);
        add(right, -d);
    }

    public long getSum(int x) {
        return getPrefix(a, x) * x + getPrefix(b, x);
    }

    public long getSum(int left, int right) {
        return getSum(right - 1) - getSum(left - 1);
    }

    private static long getPrefix(long[] a, int x) {
        long ret = 0;
        for (int i = x; i >= 0; i = ((i + 1) & i) - 1) {
            ret += a[i];
        }
        return ret;
    }
}