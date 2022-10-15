import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        final int[] a = new int[n];
        int[] b = new int[n];
        int[] c = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        for (int i = 0; i < n; i++) {
            b[i] = in.nextInt();
        }
        for (int i = 0; i < n; i++) {
            c[i] = in.nextInt();
        }
        int[] nb = ArrayUtils.sortAndUnique(b);
        for (int i = 0; i < n; i++) {
            b[i] = Arrays.binarySearch(nb, b[i]);
        }
        FenwickMin f = new FenwickMin(nb.length);
        int ans = 0;
        long[] z = new long[n];
        for (int i = 0; i < n; i++) {
            z[i] = ((long) a[i] << 32) | i;
        }
        Arrays.sort(z);
        int[] index = new int[n];
        for (int i = 0; i < n; i++) {
            index[i] = (int) (z[i] & 0xFFFFFFFFL);
        }
        int m = nb.length;
        for (int i = n - 1; i >= 0; ) {
            int j = i;
            int ini = index[i];
            int inj;
            while (j >= 0 && a[ini] == a[inj = index[j]]) {
                if (-f.getMin(m - b[inj] - 2) > c[inj]) {
                    ++ans;
                }
                --j;
            }
            while (i > j) {
                ini = index[i];
                f.setAndMin(m - b[ini] - 1, -c[ini]);
                --i;
            }
        }
        out.println(ans);
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

class ArrayUtils {

    static public int[] sortAndUnique(int[] a) {
        int[] ret = a.clone();
        sort(ret);
        if (ret.length == 0) {
            return ret;
        }
        int last = ret[0];
        int j = 1;
        for (int i = 1; i < ret.length; i++) {
            if (last != ret[i]) {
                ret[j++] = ret[i];
            }
            last = ret[i];
        }
        return Arrays.copyOf(ret, j);
    }

    public static void sort(int[] a) {
        Random rand = new Random(System.nanoTime());
        for (int i = 0; i < a.length; i++) {
            int j = rand.nextInt(i + 1);
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
        Arrays.sort(a);
    }


    }

class FenwickMin {
    int[] min;

    public FenwickMin(int n) {
        min = new int[n];
        Arrays.fill(min, Integer.MAX_VALUE);
    }

    public void setAndMin(int x, int y) {
        for (int i = x; i < min.length; i |= i + 1) {
            min[i] = Math.min(min[i], y);
        }
    }

    public int getMin(int x) {
        x = Math.min(x, min.length - 1);
        int ret = Integer.MAX_VALUE;
        for (int i = x; i >= 0; i = (i & i + 1) - 1) {
            ret = Math.min(ret, min[i]);
        }
        return ret;
    }
}