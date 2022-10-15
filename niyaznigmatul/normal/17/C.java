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
		Balance solver = new Balance();
		solver.solve(1, in, out);
		out.close();
	}
}

class Balance {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        in.next();
        String s = in.next();
        int n = s.length();
        int[][] next = new int[3][n + 1];
        next[0][n] = next[1][n] = next[2][n] = n;
        for (int i = s.length() - 1; i >= 0; i--) {
            for (int j = 0; j < 3; j++) {
                next[j][i] = next[j][i + 1];
            }
            next[s.charAt(i) - 'a'][i] = i;
        }
        int maxLen = (n + 2) / 3 + 2;
        int[][][] dp = new int[n][maxLen + 1][maxLen + 1];
        dp[0][0][0] = 1;
        int answer = 0;
        for (int a = 0; a <= maxLen; a++) {
            int[][][] dp2 = new int[n][maxLen + 1][maxLen + 1];
            for (int i = 0; i < n; i++) {
                for (int b = 0; b <= maxLen; b++) {
                    for (int c = 0; c <= maxLen; c++) {
                        int val = dp[i][b][c];
                        if (val == 0) {
                            continue;
                        }
                        if (a + b + c == n && Math.abs(a - b) <= 1 && Math.abs(b - c) <= 1 && Math.abs(a - c) <= 1) {
                            answer += val;
                            if (answer >= MOD) {
                                answer -= MOD;
                            }
                        }
                        for (int let = 0; let < 3; let++) {
                            int go = next[let][i];
                            if (go < n) {
                                int newB = b + (let == 1 ? 1 : 0);
                                int newC = c + (let == 2 ? 1 : 0);
                                if (newB <= maxLen && newC <= maxLen) {
                                    int[] z = (let == 0 ? dp2 : dp)[go][newB];
                                    z[newC] += val;
                                    if (z[newC] >= MOD) {
                                        z[newC] -= MOD;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            dp = dp2;
        }
        out.println(answer);
    }

    static final int MOD = 51123987;
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

    }

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }

    public FastPrinter(Writer out) {
        super(out);
    }


}