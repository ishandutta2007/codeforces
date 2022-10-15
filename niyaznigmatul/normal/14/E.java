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
		Deve solver = new Deve();
		solver.solve(1, in, out);
		out.close();
	}
}

class Deve {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        long[][][][][] dp = new long[n - 1][k + 1][k][4][4];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                dp[0][0][0][i][j] = 1;
            }
        }
        for (int i = 1; i + 1 < n; i++) {
            for (int d = 0; d <= k; d++) {
                for (int e = 0; e < k; e++) {
                    for (int preLast = 0; preLast < 4; preLast++) {
                        for (int last = 0; last < 4; last++) {
                            if (preLast == last) {
                                continue;
                            }
                            long val = dp[i - 1][d][e][preLast][last];
                            if (val == 0) {
                                continue;
                            }
                            for (int next = 0; next < 4; next++) {
                                if (last == next) {
                                    continue;
                                }
                                int newD = d;
                                int newE = e;
                                if (last > preLast && last > next) {
                                    ++newD;
                                }
                                if (last < preLast && last < next) {
                                    ++newE;
                                }
                                if (newD > k || newE >= k) {
                                    continue;
                                }
                                dp[i][newD][newE][last][next] += val;
                            }
                        }
                    }
                }
            }
        }
        long answer = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                answer += dp[n - 2][k][k - 1][i][j];
            }
        }
        out.println(answer);
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