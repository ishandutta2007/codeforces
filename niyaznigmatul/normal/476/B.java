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
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        String s = in.next();
        int sum = 0;
        for (char c : s.toCharArray()) {
            sum += c == '+' ? 1 : -1;
        }
        int shift = 50;
        double[] dp = new double[123];
        dp[shift] = 1.;
        for (char c : in.next().toCharArray()) {
            double[] next = new double[123];
            if (c == '+') {
                for (int i = 0; i < dp.length; i++) {
                    if (dp[i] == 0) continue;
                    next[i + 1] = dp[i];
                }
            } else if (c == '-') {
                for (int i = 0; i < dp.length; i++) {
                    if (dp[i] == 0) continue;
                    next[i - 1] = dp[i];
                }
            } else {
                for (int i = 0; i < dp.length; i++) {
                    if (dp[i] == 0) continue;
                    next[i - 1] += dp[i] * .5;
                    next[i + 1] += dp[i] * .5;
                }
            }
            dp = next;
        }
        out.println(dp[sum + shift]);
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