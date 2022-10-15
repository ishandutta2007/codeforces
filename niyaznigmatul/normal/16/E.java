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
		Fish solver = new Fish();
		solver.solve(1, in, out);
		out.close();
	}
}

class Fish {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        double[][] p = new double[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                p[i][j] = in.nextDouble();
            }
        }
        double[] dp = new double[1 << n];
        dp[(1 << n) - 1] = 1;
        for (int mask = (1 << n) - 1; mask >= 0; mask--) {
            int countPairs = Integer.bitCount(mask);
            countPairs = countPairs * (countPairs - 1) / 2;
            for (int i = 0; i < n; i++) {
                if (((mask >> i) & 1) == 0) {
                    continue;
                }
                for (int j = i + 1; j < n; j++) {
                    if (((mask >> j) & 1) == 0) {
                        continue;
                    }
                    dp[mask ^ (1 << j)] += dp[mask] * p[i][j] / countPairs;
                    dp[mask ^ (1 << i)] += dp[mask] * p[j][i] / countPairs;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            out.print(dp[1 << i] + " ");
        }
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

    public double nextDouble() {
        return Double.parseDouble(next());
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