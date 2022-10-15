import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
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
        int n = in.nextInt();
        int m = in.nextInt();
        int p = in.nextInt();
        int[] a = in.readIntArray(n);
        int[] b = in.readIntArray(m);
        for (int i = 0; i < n; i++) {
            a[i] %= p;
        }
        for (int j = 0; j < m; j++) {
            b[j] %= p;
        }
        int k = 130;
        int[] dp = new int[1];
        dp[0] = (a[0] + b[0]) % p;
        List<int[]> dynamics = new ArrayList<int[]>();
        dynamics.add(dp);
        List<Integer> step = new ArrayList<Integer>();
        step.add(0);
        int[] size = new int[n + m - 1];
        size[0] = 1;
        for (int steps = 1; steps < n + m - 1; steps++) {
            dp = nextDP(n, m, p, a, b, dp, steps);
            if (steps != n + m - 2 && steps % k == 0) {
                dynamics.add(dp);
                step.add(steps);
            }
        }
        out.println(dp[0]);
        StringBuilder answer = new StringBuilder();
        for (int curStep = n + m - 2, curIndex = 0; curStep > 0; ) {
            int lastStep = step.remove(step.size() - 1);
            int[][] dps = new int[curStep - lastStep + 1][];
            dps[0] = dynamics.remove(dynamics.size() - 1);
            for (int i = 1; i < curStep - lastStep; i++) {
                dps[i] = nextDP(n, m, p, a, b, dps[i - 1], lastStep + i);
            }
            dps[curStep - lastStep] = dp;
            for (int i = curStep - lastStep; i > 0; i--) {
                int steps = i + lastStep;
                int shift2 = steps < n ? 1 : 0;
                int x = Math.min(steps, n - 1) - curIndex;
                int y = steps - x;
                if (x == 0 || y > 0 && dps[i - 1][curIndex - shift2 + 1] < dps[i - 1][curIndex - shift2]) {
                    answer.append('S');
                    curIndex -= shift2;
                } else {
                    answer.append('C');
                    curIndex -= shift2;
                    ++curIndex;
                }
            }
            dp = dps[0];
            curStep = lastStep;
        }
        out.println(answer.reverse());
    }

    private int[] nextDP(int n, int m, int p, int[] a, int[] b, int[] dp, int steps) {
        int shift1 = steps < m ? 0 : -1;
        int shift2 = steps < n ? 1 : 0;
        int newSize = dp.length + shift1 + shift2;
        int[] next = new int[newSize];
        int x = Math.min(steps, n - 1);
        int y = steps - x;
        int cur2 = -shift2;
        int cur3 = -shift2 + 1;
        for (int cur = 0; cur < newSize; cur++, cur2++, cur3++) {
            int pay = a[x] + b[y];
            if (pay >= p) {
                pay -= p;
            }
            int best = 0;
            if (x > 0 && best < dp[cur3]) {
                best = dp[cur3];
            }
            if (y > 0 && best < dp[cur2]) {
                best = dp[cur2];
            }
            next[cur] = best + pay;
            x--;
            y++;
        }
        return next;
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

    public int[] readIntArray(int n) {
        int[] ret = new int[n];
        for (int i = 0; i < n; i++) {
            ret[i] = nextInt();
        }
        return ret;
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