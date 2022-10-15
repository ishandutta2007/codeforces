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
 * @author niyaznigmatul 
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        char[][] c = new char[n][];
        int count = 0;
        for (int i = 0; i < n; i++) {
            c[i] = in.next().toCharArray();
            for (int j = 0; j < m; j++) {
                if (c[i][j] == '#') {
                    ++count;
                }
            }
        }
        if (count <= 2) {
            out.println(-1);
            return;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (c[i][j] != '#') {
                    continue;
                }
                c[i][j] = '.';
                if (!connected(c, n, m)) {
                    out.println(1);
                    return;
                }
                c[i][j] = '#';
            }
        }
        out.println(2);
    }

    static final int[] DX = {1, 0, -1, 0};
    static final int[] DY = {0, 1, 0, -1};

    static boolean connected(char[][] c, int n, int m) {
        boolean[][] was = new boolean[n][m];
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (was[i][j] || c[i][j] != '#') {
                    continue;
                }
                dfs(i, j, c, was, n, m);
                ++count;
            }
        }
        return count == 1;
    }

    static void dfs(int i, int j, char[][] c, boolean[][] was, int n, int m) {
        was[i][j] = true;
        for (int dir = 0; dir < 4; dir++) {
            int x = i + DX[dir];
            int y = j + DY[dir];
            if (x < 0 || y < 0 || x >= n || y >= m || c[x][y] != '#' || was[x][y]) {
                continue;
            }
            dfs(x, y, c, was, n, m);
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

    }

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }

    public FastPrinter(Writer out) {
        super(out);
    }


}