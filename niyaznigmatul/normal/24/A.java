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
	public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        int[] c = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt() - 1;
            b[i] = in.nextInt() - 1;
            c[i] = in.nextInt();
        }
        int[] path = new int[n];
        path[0] = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0 || b[i] == 0) {
                path[1] = a[i] + b[i];
                break;
            }
        }
        all: for (int i = 2; i < n; i++) {
            int last = path[i - 1];
            int preLast = path[i - 2];
            for (int j = 0; j < n; j++) {
                if (last == a[j] || last == b[j]) {
                    if (preLast != (a[j] ^ b[j] ^ last)) {
                        path[i] = a[j] ^ b[j] ^ last;
                        continue all;
                    }
                }
            }
        }
        int[] pos = new int[n];
        for (int i = 0; i < n; i++) {
            pos[path[i]] = i;
        }
        int cost1 = 0;
        int cost2 = 0;
        for (int i = 0; i < n; i++) {
            int dif = pos[b[i]] - pos[a[i]];
            if (dif < 0) {
                dif += n;
            }
            if (dif == 1) {
                cost1 += c[i];
            } else {
                cost2 += c[i];
            }
        }
        out.println(Math.min(cost1, cost2));
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