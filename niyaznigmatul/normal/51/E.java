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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        boolean[][] a = new boolean[n][n];
        int m = in.nextInt();
        for (int i = 0; i < m; i++) {
            int v = in.nextInt() - 1;
            int u = in.nextInt() - 1;
            a[v][u] = a[u][v] = true;
        }
        int[][] b = new int[n][n];
        int[] deg = new int[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j]) {
                    deg[i]++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int count = 0;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) {
                        continue;
                    }
                    if (a[i][k] && a[j][k]) {
                        ++count;
                    }
                }
                b[i][j] = b[j][i] = count;
            }
        }
        long ans = 0;
        for (int v = 0; v < n; v++) {
            for (int u = v + 1; u < n; u++) {
                if (!a[v][u]) {
                    continue;
                }
                for (int w = 0; w < n; w++) {
                    if (w == u || w == v) {
                        continue;
                    }
                    int z1 = b[v][w];
                    if (a[v][u] && a[w][u]) {
                        --z1;
                    }
                    int z2 = b[u][w];
                    if (a[v][u] && a[w][v]) {
                        --z2;
                    }
                    ans += z1 * z2;
                }
            }
        }
        for (int v = 0; v < n; v++) {
            for (int c = 0; c < n; c++) {
                if (v == c || !a[v][c]) {
                    continue;
                }
                for (int d = c + 1; d < n; d++) {
                    if (d == v || !a[v][d] || !a[c][d]) {
                        continue;
                    }
                    ans -= deg[v] - 2;
                }
            }
        }
        if (ans % 5 != 0) {
            throw new AssertionError(ans);
        }
        out.println(ans / 5);
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