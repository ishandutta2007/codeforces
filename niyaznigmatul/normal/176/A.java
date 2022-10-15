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
        int k = in.nextInt();
        int[][] a = new int[n][m];
        int[][] b = new int[n][m];
        int[][] c = new int[n][m];
        for (int i = 0; i < n; i++) {
            in.next();
            for (int j = 0; j < m; j++) {
                a[i][j] = in.nextInt();
                b[i][j] = in.nextInt();
                c[i][j] = in.nextInt();
            }
        }
        boolean[] was = new boolean[m];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                int all = k;
                Arrays.fill(was, false);
                int profit = 0;
                while (all > 0) {
                    int min = -1;
                    for (int z = 0; z < m; z++) {
                        int val = b[j][z] - a[i][z];
                        if (was[z] || val <= 0) {
                            continue;
                        }
                        if (min < 0 || val > b[j][min] - a[i][min]) {
                            min = z;
                        }
                    }
                    if (min < 0) {
                        break;
                    }
                    int got = Math.min(all, c[i][min]);
                    all -= got;
                    profit += (b[j][min] - a[i][min]) * got;
                    was[min] = true;
                }
                ans = Math.max(ans, profit);
            }
        }
        out.println(ans);
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