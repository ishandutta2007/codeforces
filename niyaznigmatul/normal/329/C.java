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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
        long[] edges = new long[m];
        for (int i = 0; i < m; i++) {
            int x = in.nextInt() - 1;
            int y = in.nextInt() -1 ;
            if (x > y) {
                int t = x;
                x = y;
                y = t;
            }
            edges[i] = (long) x * n + y;
        }
        ArrayUtils.sort(edges);
        int IT = 10000000 / n;
        for (int it = 0; it < IT; it++) {
            ArrayUtils.shuffle(p);
            int count = 0;
            for (int i = 0; i < n; i++) {
                int x = p[i];
                int y = p[(i + 1) % n];
                if (x > y) {
                    int t = x;
                    x = y;
                    y = t;
                }
                long ed = (long) x * n + y;
                if (Arrays.binarySearch(edges, ed) < 0) {
                    ++count;
                }
            }
            if (count >= m) {
                count = 0;
                for (int i = 0; count < m && i < n; i++) {
                    int x = p[i];
                    int y = p[(i + 1) % n];
                    if (x > y) {
                        int t = x;
                        x = y;
                        y = t;
                    }
                    long ed = (long) x * n + y;
                    if (Arrays.binarySearch(edges, ed) < 0) {
                        out.println((x + 1) + " " + (y + 1));
                        ++count;
                    }
                }
                return;
            }
        }
        out.println(-1);
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

class ArrayUtils {


    static final long seed = System.nanoTime();

    static final Random rand = new Random(seed);

    public static void shuffle(int[] a) {
        for (int i = 0; i < a.length; i++) {
            int j = rand.nextInt(i + 1);
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }


    public static void sort(long[] a) {
        shuffle(a);
        Arrays.sort(a);
    }

    public static void shuffle(long[] a) {
        for (int i = 0; i < a.length; i++) {
            int j = rand.nextInt(i + 1);
            long t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }

    }