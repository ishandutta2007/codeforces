import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
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

    static class SegmentTree {
        int n;
        int[] g;
        int[] count;

        SegmentTree(int m) {
            n = Integer.highestOneBit(m) << 1;
            g = new int[2 * n];
            count = new int[2 * n];
            for (int i = 0; i < n; i++) {
                count[i + n] = 1;
                set(i, 0);
            }
        }

        void set(int x, int y) {
            x += n;
            g[x] = y;
            while (x > 1) {
                x >>= 1;
                int gg = MathUtils.gcd(g[x * 2], g[x * 2 + 1]);
                count[x] = 0;
                if (gg == g[x * 2]) count[x] += count[x * 2];
                if (gg == g[x * 2 + 1]) count[x] += count[x * 2 + 1];
                g[x] = gg;
            }
        }

        int getGcdAndCount(int l, int r) {
            --r;
            l += n;
            r += n;
            int retG = 0;
            int retC = 0;
            while (l <= r) {
                if ((l & 1) == 1) {
                    int ng = MathUtils.gcd(retG, g[l]);
                    int nc = 0;
                    if (ng == retG) nc += retC;
                    if (ng == g[l]) nc += count[l];
                    ++l;
                    retG = ng;
                    retC = nc;
                }
                if ((r & 1) == 0) {
                    int ng = MathUtils.gcd(retG, g[r]);
                    int nc = 0;
                    if (ng == retG) nc += retC;
                    if (ng == g[r]) nc += count[r];
                    --r;
                    retG = ng;
                    retC = nc;
                }
                l >>= 1;
                r >>= 1;
            }
            return retC;
        }
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        SegmentTree tree = new SegmentTree(n);
        for (int i = 0; i < n; i++) {
            tree.set(i, in.nextInt());
        }
        int m = in.nextInt();
        for (int i = 0; i < m; i++) {
            int l = in.nextInt() - 1;
            int r = in.nextInt();
            out.println(r - l - tree.getGcdAndCount(l, r));
        }
    }
}

class MathUtils {

    public static int gcd(int a, int b) {
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        while (b != 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
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