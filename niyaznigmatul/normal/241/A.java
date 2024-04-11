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
        int n = in.nextInt() + 1;
        int k = in.nextInt();
        int[] a = new int[n - 1];
        for (int i = 0; i + 1 < n; i++) {
            a[i] = in.nextInt();
        }
        int[] s = new int[n - 1];
        for (int i = 0; i + 1 < n; i++) {
            s[i] = in.nextInt();
        }
        long[] dp = new long[n];
        long[] fuel = new long[n];
        dp[0] = 0;
        fuel[0] = s[0];
        int maximal = s[0];
        for (int i = 1; i < n; i++) {
            long curTime = dp[i - 1] + a[i - 1];
            long curFuel = fuel[i - 1] - a[i - 1];
            long add = curFuel >= 0 ? 0 : (Math.abs(curFuel) + maximal - 1) / maximal;
            curFuel += add * maximal;
            curTime += add * k;
            if (i + 1 < n) {
                curFuel += s[i];
                maximal = Math.max(maximal, s[i]);
            }
            dp[i] = curTime;
            fuel[i] = curFuel;
        }
        out.println(dp[n - 1]);
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