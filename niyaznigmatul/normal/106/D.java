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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        char[][] c = in.readCharacterFieldTokens(n, m);
        int[][][] can = new int[4][n][m];
        final String DIRS = "NESW";
        final int[] DX = {-1, 0, 1, 0};
        final int[] DY = {0, 1, 0, -1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (c[i][j] == '#') {
                    can[0][i][j] = can[3][i][j] = 0;
                } else {
                    can[0][i][j] = (i > 0 ? can[0][i - 1][j] : 0) + 1;
                    can[3][i][j] = (j > 0 ? can[3][i][j - 1] : 0) + 1;
                }
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (c[i][j] == '#') {
                    can[1][i][j] = can[2][i][j] = 0;
                } else {
                    can[1][i][j] = (j + 1 < m ? can[1][i][j + 1] : 0) + 1;
                    can[2][i][j] = (i + 1 < n ? can[2][i + 1][j] : 0) + 1;
                }
            }
        }
        int q = in.nextInt();
        int[] dir = new int[q];
        int[] step = new int[q];
        for (int i = 0; i < q; i++) {
            dir[i] = DIRS.indexOf(in.next());
            step[i] = in.nextInt();
        }
        boolean[] ans = new boolean[26];
        for (int i = 0; i < n; i++) {
            all: for (int j = 0; j < m; j++) {
                if (c[i][j] == '.' || c[i][j] == '#') {
                    continue;
                }
                int x = i;
                int y = j;
                for (int k = 0; k < q; k++) {
                    if (can[dir[k]][x][y] - 1 < step[k]) {
                        continue all;
                    }
                    x += DX[dir[k]] * step[k];
                    y += DY[dir[k]] * step[k];
                }
                ans[c[i][j] - 'A'] = true;
            }
        }
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (ans[i]) {
                out.print((char) (i + 'A'));
                ++cnt;
            }
        }
        if (cnt == 0) {
            out.print("no solution");
        }
        out.println();
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