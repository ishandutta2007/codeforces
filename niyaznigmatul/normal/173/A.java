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
 * @author niyaznigmatul 
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {

    static final String ALL = "RPS";
    static int[][] BEAT = {{0, -1, 1}, {1, 0, -1}, {-1, 1, 0}};

	public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        char[] c = in.next().toCharArray();
        char[] d = in.next().toCharArray();
        int m = c.length;
        int k = d.length;
        int all = (int) MathUtils.lcm(m, k);
        int period1 = 0;
        int period2 = 0;
        for (int i = 0; i < all; i++) {
            int e = BEAT[ALL.indexOf(c[i % m])][ALL.indexOf(d[i % k])];
            if (e > 0) {
                period1++;
            } else if (e < 0) {
                period2++;
            }
        }
        int ans1 = period1 * (n / all);
        int ans2 = period2 * (n / all);
        n %= all;
        for (int i = 0; i < n; i++) {
            int e = BEAT[ALL.indexOf(c[i % m])][ALL.indexOf(d[i % k])];
            if (e > 0) {
                ans1++;
            } else if (e < 0) {
                ans2++;
            }
        }
        out.println(ans2 + " " + ans1);
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

    public String next() {
        StringBuilder sb = new StringBuilder();
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        while (!isWhiteSpace(c)) {
            sb.appendCodePoint(c);
            c = read();
        }
        return sb.toString();
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

class MathUtils {

    public static int gcd(int a, int b) {
        while (b != 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }


    public static long lcm(int a, int b) {
        return a / gcd(a, b) * (long) b;
    }

    }