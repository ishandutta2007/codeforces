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
        Arrays.fill(time, -1);
        Arrays.fill(sh, -1);
        Arrays.fill(wh, -1);
        change = 0;
        int n = in.nextInt();
        int m = in.nextInt();
        int[] a = in.readIntArray(n);
        int[] b = in.readIntArray(n);
        for (int i = 0; i < m; i++) {
            int t = in.nextInt();
            if (t == 1) {
                int x = in.nextInt() - 1;
                int y = in.nextInt() - 1;
                int k = in.nextInt();
                set(y, y + k - 1, x, y);
            } else {
                int x = in.nextInt() - 1;
                int[] d = get(x);
                if (d == null) {
                    out.println(b[x]);
                } else {
                    out.println(a[x - d[1] + d[0]]);
                }
            }
        }
    }

    static int MAXN = 1 << 17;
    static int[] wh = new int[MAXN * 2];
    static int[] sh = new int[MAXN * 2];
    static int[] time = new int[MAXN * 2];

    static int change;

    static void set(int left, int right, int y, int z) {
        left += MAXN;
        right += MAXN;
        ++change;
        while (left <= right) {
            if ((left & 1) == 1) {
                time[left] = change;
                wh[left] = y;
                sh[left] = z;
                ++left;
            }
            if ((right & 1) == 0) {
                time[right] = change;
                wh[right] = y;
                sh[right] = z;
                --right;
            }
            left >>= 1;
            right >>= 1;
        }
    }

    static int[] get(int x) {
        x += MAXN;
        int bestChange = -1;
        int w = -1;
        int s = -1;
        while (x > 0) {
            if (bestChange < time[x]) {
                w = wh[x];
                s = sh[x];
                bestChange = time[x];
            }
            x >>= 1;
        }
        if (bestChange < 0) {
            return null;
        }
        return new int[]{w, s};
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

    public FastPrinter(Writer out) {
        super(out);
    }


}