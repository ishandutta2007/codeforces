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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        in.next();
        char[] s = in.next().toCharArray();
        int n = s.length;
        if ((n & 1) == 1) {
            out.println(0);
            return;
        }
        int[] dp = new int[n / 2 + 1];
        int[] next = new int[n / 2 + 1];
        dp[0] = 1;
        int count = 0;
        for (int i1 = 0; i1 < n; i1++) {
            char e = s[i1];
            if (e == '?') {
                ++count;
                int left = i1 - n / 2;
                int right = i1 / 2;
                if (left < 0) left = 0;
                if ((i1 & 1) == 1) {
                    dp[(i1 + 1) / 2] += dp[(i1 + 1) / 2 - 1];
                }
                for (int i = right; i > left; i--) {
                    dp[i] += dp[i - 1];
                }
                if (i1 - n / 2 >= 0) {
                    dp[i1 - n / 2] = 0;
                }
            }
        }
        int ans = dp[n / 2];
        for (int i = 0; i < count - n / 2; i++) {
            ans *= 25;
        }
        out.println(Long.parseLong(Integer.toBinaryString(ans), 2));
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