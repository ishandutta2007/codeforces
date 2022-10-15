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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {

    final static int N = 1 << 18;

    static long[] v1 = new long[2 * N];
    static long[] v2 = new long[2 * N];
    static long[] dif = new long[2 * N];

    static void set(int x, long a, long b) {
        x += N;
        v1[x] = a;
        v2[x] = b;
        dif[x] = Long.MIN_VALUE;
        while (x > 1) {
            x >>= 1;
            v1[x] = Math.max(v1[2 * x], v1[2 * x + 1]);
            v2[x] = Math.max(v2[2 * x], v2[2 * x + 1]);
            dif[x] = Math.max(dif[2 * x], dif[2 * x + 1]);
            dif[x] = Math.max(dif[x], v1[2 * x + 1] + v2[2 * x]);
        }
    }

    static long getMax(int l, int r) {
        l += N;
        r += N;
        --r;
        long v1Left = Long.MIN_VALUE;
        long v2Left = Long.MIN_VALUE;
        long difLeft = Long.MIN_VALUE;
        long v1Right = Long.MIN_VALUE;
        long v2Right = Long.MIN_VALUE;
        long difRight = Long.MIN_VALUE;
        while (l <= r) {
            if ((l & 1) == 1) {
                long nV1Left = Math.max(v1Left, v1[l]);
                long nV2Left = Math.max(v2Left, v2[l]);
                long nDifLeft = Math.max(difLeft, dif[l]);
                if (v1Left != Long.MIN_VALUE) {
                    nDifLeft = Math.max(nDifLeft, v1[l] + v2Left);
                }
                ++l;
                v1Left = nV1Left;
                v2Left = nV2Left;
                difLeft = nDifLeft;
            }
            if ((r & 1) == 0) {
                long nV1Right = Math.max(v1[r], v1Right);
                long nV2Right = Math.max(v2[r], v2Right);
                long nDifRight = Math.max(dif[r], difRight);
                if (v1Right != Long.MIN_VALUE) {
                    nDifRight = Math.max(nDifRight, v2[r] + v1Right);
                }
                --r;
                v1Right = nV1Right;
                v2Right = nV2Right;
                difRight = nDifRight;
            }
            l >>= 1;
            r >>= 1;
        }
        long ret = Math.max(difLeft, difRight);
        if (v1Left != Long.MIN_VALUE && v2Right != Long.MIN_VALUE) {
            ret = Math.max(ret, v1Right + v2Left);
        }
        return ret;
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        long[] d = new long[2 * n];
        long[] h = new long[2 * n];
        for (int i = 0; i < n; i++) {
            d[(i + 1) % n] = in.nextInt();
        }
        for (int i = 0; i < n; i++) {
            d[i + n] = d[i];
        }
        for (int i = 0; i < n; i++) h[i + n] = h[i] = 2L * in.nextInt();
        for (int i = 1; i < 2 * n; i++) d[i] += d[i - 1];
        for (int i = 0; i < 2 * n; i++) set(i, h[i] + d[i], h[i] - d[i]);
        for (int i = 0; i < m; i++) {
            int left = in.nextInt() - 1;
            int right = in.nextInt() - 1;
            if (right < left) {
                right += n;
            }
            left += n;
            out.println(getMax(right + 1, left));
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

    public FastPrinter(Writer out) {
        super(out);
    }


}