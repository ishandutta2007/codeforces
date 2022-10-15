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
    static int[] d;
    static int[] p;
    static boolean[] was;

	public void solve(int testNumber, FastScanner in, FastPrinter out) {
        d = new int[4];
        p = new int[4];
        for (int i = 0; i < 4; i++) {
            d[i] = in.nextInt();
        }
        int a = in.nextInt();
        int b = in.nextInt();
        int answer = 0;
        was = new boolean[4];
        for (int i = a; i <= b; i++) {
            if (go(0, 4, i) >= 7) {
                ++answer;
            }
        }
        out.println(answer);
	}

    static boolean check(int x) {
        int y = x;
        for (int i = 0; i < 4; i++) {
            y %= d[p[i]];
        }
        return x == y;
    }

    static int go(int x, int n, int y) {
        if (x == n) {
            return (check(y) ? 1 : 0);
        }
        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (was[i]) {
                continue;
            }
            was[i] = true;
            p[x] = i;
            ret += go(x + 1, n, y);
            was[i] = false;
        }
        return ret;
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