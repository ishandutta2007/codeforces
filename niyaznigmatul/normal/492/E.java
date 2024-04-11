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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int dx = in.nextInt();
        int dy = in.nextInt();
        if (dx == 0 && dy == 0) {
            long[] points = new long[m];
            for (int i = 0; i < m; i++) points[i] = in.nextInt() * n + in.nextInt();
            ArrayUtils.sort(points);
            int ans = Integer.MIN_VALUE;
            int ansx = -1;
            int ansy = -1;
            for (int i = 0; i < m; ) {
                int j = i;
                while (j < m && points[i] == points[j]) {
                    ++j;
                }
                if (j - i > ans) {
                    ans = j - i;
                    ansx = (int) (points[i] / n);
                    ansy = (int) (points[i] % n);
                }
                i = j;
            }
            out.println(ansx + " " + ansy);
            return;
        }
        if (dx == 0 || dy == 0) {
            int[] rows = new int[n];
            int[] cols = new int[n];
            for (int i = 0; i < m; i++) {
                int x = in.nextInt();
                int y = in.nextInt();
                rows[x]++;
                cols[y]++;
            }
            int ans = Integer.MIN_VALUE;
            int ansx = -1;
            int ansy = -1;
            if (dx == 0) {
                for (int i = 0; i < n; i++) {
                    if (rows[i] > ans) {
                        ans = rows[i];
                        ansx = i;
                        ansy = 0;
                    }
                }
            } else {
                for (int i = 0; i < n; i++) {
                    if (cols[i] > ans) {
                        ans = cols[i];
                        ansx = 0;
                        ansy = i;
                    }
                }
            }
            out.println(ansx + " " + ansy);
            return;
        }
        int[] times = new int[n];
        for (int i = 0; i < n; i++) {
            times[((int) ((long) dx * i % n))] = i;
        }
        int[] cnt = new int[n];
        for (int i = 0; i < m; i++) {
            int x = in.nextInt();
            int y = in.nextInt();
            int t = times[x];
            x = (int) ((x + n - (long) t * dx % n) % n);
            if (x != 0) throw new AssertionError();
            y = (int) ((y + n - (long) t * dy % n) % n);
            cnt[y]++;
        }
        int ans = Integer.MIN_VALUE;
        int ansx = -1;
        int ansy = -1;
        for (int i = 0; i < n; i++) {
            if (cnt[i] > ans) {
                ans = cnt[i];
                ansx = 0;
                ansy = i;
            }
        }
        out.println(ansx + " " + ansy);
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