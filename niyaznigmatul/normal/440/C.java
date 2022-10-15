import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int shift = 15;
        int maxn = 60;
        
        int[][][] dp = new int[maxn + 1][maxn + 1][shift * 2 + 1];
        for (int[][] e1 : dp) {
            for (int[] e2 : e1) Arrays.fill(e2, Integer.MAX_VALUE);
        }
        dp[maxn][maxn][shift] = 0;
        char[] d = ("000" + in.next()).toCharArray();
        for (int i = d.length - 1; i >= 0; i--) {
            int digit = d[i] - '0';
            for (int plus = maxn; plus >= 0; plus--) {
                for (int minus = maxn; minus >= 0; minus--) {
                    for (int carry = 0; carry <= 2 * shift; carry++) {
                        if (plus + 1 <= maxn)
                            dp[plus][minus][carry] = Math.min(dp[plus][minus][carry], dp[plus + 1][minus][carry]);
                        if (minus + 1 <= maxn)
                            dp[plus][minus][carry] = Math.min(dp[plus][minus][carry], dp[plus][minus + 1][carry]);
                    }
                }
            }
            int[][][] next = new int[maxn + 1][maxn + 1][shift * 2 + 1];
            for (int[][] e1 : next) {
                for (int[] e2 : e1) Arrays.fill(e2, Integer.MAX_VALUE);
            }
            for (int plus = maxn; plus >= 0; plus--) {
                for (int minus = maxn; minus >= 0; minus--) {
                    for (int carry = 0; carry <= 2 * shift; carry++) {
                        int val = dp[plus][minus][carry];
                        if (val == Integer.MAX_VALUE) continue;
                        int realCarry = carry - shift;
                        int curN = plus - minus + realCarry;
                        int curD = curN % 10;
                        if (curD < 0) curD += 10;
                        int newCarry = (curN - curD) / 10;
                        if (curD != digit) continue;
                        next[plus][minus][newCarry + shift] = Math.min(next[plus][minus][newCarry + shift], plus + minus + val);
                    }
                }
            }
            dp = next;
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i <= maxn; i++) {
            for (int j = 0; j <= maxn; j++) ans = Math.min(ans, dp[i][j][shift]);
        }
        out.println(ans);
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