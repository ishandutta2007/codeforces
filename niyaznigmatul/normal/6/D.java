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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        a = in.nextInt();
        b = in.nextInt();
        h = new int[n];
        for (int i = 0; i < n; i++) {
            h[i] = in.nextInt() + 1;
        }
        best = Integer.MAX_VALUE;
        shoot = new int[n];
        go(1, n, 0);
        out.println(best);
        for (int i = 0; i < n; i++) {
            while (ans[i] > 0) {
                out.print(i + 1 + " ");
                --ans[i];
            }
        }
    }

    static void go(int x, int n, int steps) {
        if (x == n - 1) {
            int left = h[x] <= 0 ? 0 : (h[x] + b - 1) / b;
            if (best > steps + left) {
                ans = shoot.clone();
                ans[x - 1] += left;
                best = steps + left;
            }
            return;
        }
        if (steps >= best) {
            return;
        }
        if (h[x - 1] <= 0) {
            go(x + 1, n, steps);
        }
        while (h[x] > 0 || h[x - 1] > 0) {
            h[x] -= a;
            h[x - 1] -= b;
            h[x + 1] -= b;
            shoot[x]++;
            if (steps + shoot[x] >= best) {
                break;
            }
            if (h[x - 1] <= 0) {
                go(x + 1, n, steps + shoot[x]);
            }
        }
        while (shoot[x] > 0) {
            h[x] += a;
            h[x - 1] += b;
            h[x + 1] += b;
            --shoot[x];
        }
    }

    static int best;

    static int a, b;
    static int[] h;
    static int[] shoot;
    static int[] ans;
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