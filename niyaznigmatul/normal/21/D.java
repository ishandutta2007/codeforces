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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[][] a = new int[n][n];
        for (int[] d : a) {
            Arrays.fill(d, Integer.MAX_VALUE);
        }
        int sum = 0;
        int[] deg = new int[n];
        for (int i = 0; i < m; i++) {
            int from = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            int w = in.nextInt();
            deg[from]++;
            deg[to]++;
            sum += w;
            a[from][to] = a[to][from] = Math.min(a[from][to], w);
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (a[i][k] == Integer.MAX_VALUE || a[k][j] == Integer.MAX_VALUE) {
                        continue;
                    }
                    a[i][j] = Math.min(a[i][j], a[i][k] + a[k][j]);
                }
            }
        }
        for (int i = 1; i < n; i++) {
            if (deg[i] > 0 && a[0][i] == Integer.MAX_VALUE) {
                out.println(-1);
                return;
            }
        }
        int[] dp = new int[1 << n];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;
        for (int mask = 0; mask < 1 << n; mask++) {
            if (dp[mask] == Integer.MAX_VALUE) {
                continue;
            }
            for (int i = 0; i < n; i++) {
                if (((mask >> i) & 1) == 1) {
                    continue;
                }
                for (int j = i + 1; j < n; j++) {
                    if (((mask >> j) & 1) == 1 || a[i][j] == Integer.MAX_VALUE) {
                        continue;
                    }
                    int nMask = mask | (1 << i) | (1 << j);
                    dp[nMask] = Math.min(dp[nMask], dp[mask] + a[i][j]);
                }
            }
        }
        int mask = 0;
        for (int i = 0; i < n; i++) {
            if ((deg[i] & 1) == 1) {
                mask |= 1 << i;
            }
        }
        if (dp[mask] == Integer.MAX_VALUE) {
            out.println(-1);
            return;
        }
        out.println(dp[mask] + sum);
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