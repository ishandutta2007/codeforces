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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {

    static int[] primes = {2, 3, 5, 7};
    static int[] f;
    static int[] x;
    static int[] g;
    static int[][] add;
    static int len;

    static boolean go(int pos, int cur) {
        boolean found = true;
        for (int i = 0; i < primes.length; i++) if (f[i] != g[i]) {
            found = false;
        }
        if (found) {
            len = pos;
            return true;
        }
        for (int i = 2; i <= cur; i++) {
            boolean ok = true;
            for (int j = 0; j < primes.length; j++) {
                g[j] += add[i][j];
                if (g[j] > f[j]) {
                    ok = false;
                }
            }
            x[pos] = i;
            if (ok && go(pos + 1, i)) {
                return true;
            }
            for (int j = 0; j < primes.length; j++) {
                g[j] -= add[i][j];
            }
        }
        return false;
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        String s = in.next();
        f = new int[primes.length];
        add = new int[10][primes.length];
        for (int d = 2; d < 10; d++) {
            int[] f = add[d];
            for (int i = 0; i < primes.length; i++) {
                int p = primes[i];
                int x = d;
                while (x > 0) {
                    x /= p;
                    f[i] += x;
                }
            }
        }
        for (char c : s.toCharArray()) {
            int d = c - '0';
            if (d <= 1) continue;
            for (int i = 0; i < primes.length; i++) {
                f[i] += add[d][i];
            }
        }
        g = new int[primes.length];
        x = new int[1000];
        if (go(0, 9)) {
            for (int i = 0; i < len; i++) {
                out.print(x[i]);
            }
            out.println();
        } else {
            throw new AssertionError();
        }
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

    public String next() {
        StringBuilder sb = new StringBuilder();
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        if (c < 0) {
            return null;
        }
        while (c >= 0 && !isWhiteSpace(c)) {
            sb.appendCodePoint(c);
            c = read();
        }
        return sb.toString();
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