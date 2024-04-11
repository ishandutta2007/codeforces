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
 * @author niyaznigmatul 
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
        long[] x = new long[n];
        for (int i = 0; i < n; i++) {
            x[i] = in.nextInt() * 2;
        }
        ArrayUtils.sort(x);
        long l = -1;
        long r = x[n - 1];
        ans = new long[3];
        while (l < r - 1) {
            long mid = l + r >> 1;
            if (check(mid, x)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        long d = r;
        check(d, x);
        out.println(d * .5);
        out.println(ans[0] * .5 + " " + ans[1] * .5 + " " + ans[2] * .5);
	}

    static boolean check(long d, long[] x) {
        long last = Long.MIN_VALUE;
        int count = 0;
        for (long i : x) {
            if (i > last) {
                if (count == 3) {
                    return false;
                }
                ans[count++] = i + d;
                last = 2 * d + i;
            }
        }
        while (count < 3) {
            long cur = ans[count - 1];
            ans[count++] = cur;
        }
        return true;
    }

    static long[] ans;
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


    public static void sort(long[] a) {
        Random rand = new Random(System.nanoTime());
        for (int i = 0; i < a.length; i++) {
            int j = rand.nextInt(i + 1);
            long t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
        Arrays.sort(a);
    }
}