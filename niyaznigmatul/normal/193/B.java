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
 * @author niyaznigmatul 
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    static int[] a;
    static int[] b;
    static int[] k;
    static int[] p;
    static int[] tmp;
    static int n;
    static int add;

    static long go(int last, int left) {
        long ret = Long.MIN_VALUE;
        if ((left & 1) == 0) {
            long got = 0;
            for (int i = 0; i < n; i++) {
                got += (long) a[i] * k[i];
            }
            ret = Math.max(ret, got);
        }
        if (left == 0) {
            return ret;
        }
        if (last != 0) {
            for (int i = 0; i < n; i++) {
                a[i] ^= b[i];
            }
            ret = Math.max(ret, go(0, left - 1));
            for (int i = 0; i < n; i++) {
                a[i] ^= b[i];
            }
        }
        for (int i = 0; i < n; i++) {
            tmp[i] = a[p[i]] + add;
        }
        for (int i = 0; i < n; i++) {
            a[i] = tmp[i];
        }
        ret = Math.max(ret, go(1, left - 1));
        for (int i = 0; i < n; i++) {
            tmp[p[i]] = a[i] - add;
        }
        for (int i = 0; i < n; i++) {
            a[i] = tmp[i];
        }
        return ret;
    }

	public void solve(int testNumber, FastScanner in, FastPrinter out) {
        n = in.nextInt();
        int m = in.nextInt();
        add = in.nextInt();
        a = new int[n];
        b = new int[n];
        k = new int[n];
        p = new int[n];
        tmp = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        for (int i = 0; i < n; i++) {
            b[i] = in.nextInt();
        }
        for (int i = 0; i < n; i++) {
            k[i] = in.nextInt();
        }
        for (int i = 0; i < n; i++) {
            p[i] = in.nextInt() - 1;
        }
        out.println(go(1, m));
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