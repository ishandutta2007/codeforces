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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {

    static final int MOD = 1000000007;

	public void solve(int testNumber, FastScanner in, FastPrinter out) {
        String a = in.next();
        String b = in.next();
        int cycle = -1;
        for (int i = 0; i < a.length(); i++) {
            if ((a.substring(i) + a.substring(0, i)).equals(b)) {
                cycle = i;
                break;
            }
        }
        if (cycle < 0) {
            out.println(0);
            return;
        }
        int period = a.length();
        all: for (int i = 1; i < a.length(); i++) {
            if (a.length() % i != 0) {
                continue;
            }
            for (int j = 0; j < i; j++) {
                for (int k = j; k < a.length(); k += i) {
                    if (a.charAt(k) != a.charAt(j)) {
                        continue all;
                    }
                }
            }
            period = i;
            break;
        }
        int k = a.length() / period;
        cycle %= period;
        int first = 1;
        int nonFirst = 0;
        int sum = 1;
        int it = in.nextInt();
        for (int i = 0; i < it; i++) {
            int newFirst = (int) (((sum * (long) (k) - first) % MOD + MOD) % MOD);
            int newNonFirst = (int) (((sum  * (long) k - nonFirst) % MOD + MOD) % MOD);
            int newSum = (int) ((newFirst + newNonFirst * (long) (period - 1)) % MOD);
            sum = newSum;
            nonFirst = newNonFirst;
            first = newFirst;
        }
        out.println(cycle == 0 ? first : nonFirst);
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