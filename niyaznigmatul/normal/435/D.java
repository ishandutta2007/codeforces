import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
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

    static int go(char[][] c) {
        int n = c.length;
        int m = c[0].length;
        int ans = 0;
        int[][] dp1 = new int[n][m];
        int[][] dp2 = new int[n][m];
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                if (c[i][j] == '1') {
                    dp1[i][j] = dp2[i][j] = 0;
                } else {
                    dp1[i][j] = dp2[i][j] = 1;
                    if (i + 1 < n && j + 1 < m) {
                        dp1[i][j] += dp1[i + 1][j + 1];
                    }
                    if (i + 1 < n && j > 0) {
                        dp2[i][j] += dp2[i + 1][j - 1];
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (c[i][j] == '1') continue;
                for (int k = j + 1; k < m; k++) {
                    if (c[i][k] == '1') break;
                    if ((k - j & 1) == 0) {
                        int step = ((k - j) >> 1);
                        int vx = i - step;
                        int vy = j + step;
                        if (vx < 0) continue;
                        if (dp1[vx][vy] >= step + 1 && dp2[vx][vy] >= step + 1) ++ans;
                    }
                }
                for (int k = 1; k + i < n && k + j < m; k++) {
                    if (c[k + i][j] != '0' || c[i][k + j] != '0') break;
                    if (dp2[i][k + j] >= k + 1) ++ans;
                }
            }
        }
        return ans;
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        char[][] c = in.readCharacterFieldTokens(n, m);
        int ans = 0;
        for (int a = 0; a < 4; a++) {
            ans += go(c);
            c = ArrayUtils.rotateCounterclockwise(c);
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

    public char[][] readCharacterFieldTokens(int n, int m) {
        char[][] ret = new char[n][];
        for (int i = 0; i < n; i++) {
            ret[i] = next().toCharArray();
            if (ret[i].length != m) {
                throw new AssertionError("length expected " + m + ", found " + ret[i].length);
            }
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

class ArrayUtils {


    public static char[][] rotateCounterclockwise(char[][] c) {
        if (c.length == 0) return c;
        int n = c.length;
        int m = c[0].length;
        char[][] d = new char[m][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                d[m - j - 1][i] = c[i][j];
            }
        }
        return d;
    }

}