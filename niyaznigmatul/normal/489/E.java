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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int len = in.nextInt();
        int[] x = new int[n + 1];
        int[] b = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            x[i] = in.nextInt();
            b[i] = in.nextInt();
        }
        double[][] dist = new double[n + 1][n + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                dist[i][j] = Math.sqrt(Math.abs(len - (x[j] - x[i])));
            }
        }
        double l = 0;
        double r = 1e7;
        int[] lastfrom = null;
        for (int it = 0; it < 80; it++) {
            double mid = (l + r) * .5;
            double[] dp = new double[n + 1];
            Arrays.fill(dp, Double.POSITIVE_INFINITY);
            dp[0] = 0;
            int[] from = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < i; j++) {
                    double cur = dp[j] + dist[j][i] - b[i] * mid;
                    if (cur < dp[i]) {
                        dp[i] = cur;
                        from[i] = j;
                    }
                }
            }
            if (dp[n] < 0) {
                r = mid;
                lastfrom = from;
            }
            else l = mid;
        }
        int[] ans = new int[n];
        int ac = 0;
        for (int i = n; i > 0; i = lastfrom[i]) {
            ans[ac++] = i;
        }
        for (int i = ac - 1; i >= 0; i--) {
            if (i + 1 < ac) out.print(' ');
            out.print(ans[i]);
        }
        out.println();
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