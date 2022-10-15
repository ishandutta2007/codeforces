import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {

    static boolean check(char[][] c, char[][] pattern) {
        int n = c.length;
        int m = c[0].length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pattern[i][j] == '0') continue;
                if (pattern[i][j] != c[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    static char[][] solve(char[][] c) {
        int n = c.length;
        int m = c[0].length;
        char[][] d = new char[n][m];
        int[] p = new int[]{1, 2, 3, 4};
        do {
            for (int i = 0, cur = 0; i < n; i++, cur ^= 2) {
                int xor = 0;
                for (int j = 0; j < m; j++) {
                    if (c[i][j] - '0' == p[cur]) {
                        xor = (j & 1);
                        break;
                    }
                    if (c[i][j] - '0' == p[cur + 1]) {
                        xor = ((j ^ 1) & 1);
                    }
                }
                for (int j = 0; j < m; j++) {
                    d[i][j] = (char) ('0' + p[cur + ((j ^ xor) & 1)]);
                }
            }
            if (check(d, c)) {
                return d;
            }
        } while (ArrayUtils.nextPermutation(p));
        return null;
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        char[][] c = in.readCharacterFieldTokens(n, m);
        char[][] d = solve(c);
        boolean flipped = false;
        if (d == null) {
            c = ArrayUtils.rotateCounterclockwise(c);
            d = solve(c);
            flipped = true;
        }
        if (d == null) {
            out.println(0);
        } else {
            if (flipped) {
                d = ArrayUtils.rotateClockwise(d);
            }
            for (char[] e : d) {
                out.println(e);
            }
        }
    }
}

class ArrayUtils {


    public static boolean nextPermutation(int[] a) {
        for (int i = a.length - 2; i >= 0; i--) {
            if (a[i] < a[i + 1]) {
                int cur = i + 1;
                for (int j = i + 2; j < a.length; j++) {
                    if (a[j] > a[i] && a[j] < a[cur]) {
                        cur = j;
                    }
                }
                {
                    int t = a[cur];
                    a[cur] = a[i];
                    a[i] = t;
                }
                for (int j = i + 1, k = a.length - 1; j < k; j++, k--) {
                    int t = a[j];
                    a[j] = a[k];
                    a[k] = t;
                }
                return true;
            }
        }
        return false;
    }


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

    public static char[][] rotateClockwise(char[][] c) {
        if (c.length == 0) return c;
        int n = c.length;
        int m = c[0].length;
        char[][] d = new char[m][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                d[j][n - i - 1] = c[i][j];
            }
        }
        return d;
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