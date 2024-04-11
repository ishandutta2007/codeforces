import java.io.Reader;
import java.util.InputMismatchException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;

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

    static int[] count;

    static int code(int[] a) {
        int ret = 0;
        for (int i = 0; i < 10; i++) {
            ret = ret * (count[i] + 1) + a[i];
        }
        return ret;
    }

    static void decode(int x, int[] a) {
        for (int i = 9; i >= 0; i--) {
            a[i] = x % (count[i] + 1);
            x /= count[i] + 1;
        }
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        String s = in.next();
        int m = in.nextInt();
        count = new int[10];
        for (int i = 0; i < s.length(); i++) {
            count[s.charAt(i) - '0']++;
        }
        int[] cur = new int[10];
        int all = 1;
        for (int i : count) all *= i + 1;
        long[][] dp = new long[m][all];
        dp[0][all - 1] = 1;
        for (int state = all - 1; state > 0; state--) {
            decode(state, cur);
            for (int mod = 0; mod < m; mod++) {
                long val = dp[mod][state];
                if (val == 0) continue;
                for (int d = 0; d < 10; d++) {
                    if (state + 1 == all && d == 0 || cur[d] == 0) continue;
                    --cur[d];
                    int nState = code(cur);
                    int nMod = (mod * 10 + d) % m;
                    dp[nMod][nState] += val;
                    ++cur[d];
                }
            }
        }
        out.println(dp[0][0]);
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


}