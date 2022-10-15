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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {

    static int myLevel;
    static int[] level;
    static int[] loyalty;

    static double get(int n) {
        double ret = 0;
        for (int mask = 0; mask < 1 << n; mask++) {
            int k = Integer.bitCount(mask);
            double prob = 1.;
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (((mask >> i) & 1) == 1) {
                    prob *= loyalty[i] * .1;
                } else {
                    prob *= (10 - loyalty[i]) * .1;
                    sum += level[i];
                }
            }
            if (k * 2 > n) {
                ret += prob;
            } else {
                ret += prob * myLevel / (myLevel + sum);
            }
        }
        return ret;
    }

    static double go(int x, int k, int n) {
        if (x == n) {
            return get(n);
        }
        double ret = 0;
        for (int i = 0; i <= k && loyalty[x] + i <= 10; i++) {
            loyalty[x] += i;
            ret = Math.max(go(x + 1, k - i, n), ret);
            loyalty[x] -= i;
        }
        return ret;
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        myLevel = in.nextInt();
        level = new int[n];
        loyalty = new int[n];
        for (int i = 0; i < n; i++) {
            level[i] = in.nextInt();
            loyalty[i] = in.nextInt() / 10;
        }
        out.println(go(0, k, n));
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