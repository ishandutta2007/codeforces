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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {

    static final int[] DX = {1, 0, -1, 0};
    static final int[] DY = {0, 1, 0, -1};

    static int getMask(char[][] c, int x, int y, boolean[][] last) {
        int ret = (1 << 26) - 1;
        for (int i = 0; i < 4; i++) {
            int nx = x + DX[i];
            int ny = y + DY[i];
            if (nx < 0 || ny < 0 || nx >= c.length || ny >= c[nx].length || c[nx][ny] == 0 || last[nx][ny]) continue;
            ret &= ~(1 << c[nx][ny] - 'A');
        }
        return ret;
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        char[][] ans = new char[n][m];
        boolean[][] last = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (ans[i][j] != 0) continue;
                int curChar = Integer.numberOfTrailingZeros(getMask(ans, i, j, last));
                ans[i][j] = (char) (curChar + 'A');
                last[i][j] = true;
                int size = 2;
                while (i + size <= n && j + size <= m) {
                    if (Integer.numberOfTrailingZeros(getMask(ans, i, j + size - 1, last)) < curChar) {
                        break;
                    }
                    boolean ok = true;
                    for (int k = 0; k < size; k++) {
                        if (ans[i + size - 1][j + k] != 0 || ans[i + k][j + size - 1] != 0 || ((getMask(ans, i + k, j + size - 1, last) >> curChar) & 1) == 0 ||
                                ((getMask(ans, i + size - 1, j + k, last) >> curChar) & 1) == 0) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        for (int k = 0; k < size; k++) {
                            ans[i + size - 1][j + k] = (char) (curChar + 'A');
                            ans[i + k][j + size - 1] = (char) (curChar + 'A');
                            last[i + size - 1][j + k] = true;
                            last[i + k][j + size - 1] = true;
                        }
                    } else break;
                    ++size;
                }
                for (int x = 0; x + 1 < size; x++) {
                    for (int y = 0; y + 1 < size; y++) last[i + x][j + y] = false;
                }
            }
        }
        for (char[] e : ans) out.println(e);
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