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
        for (int i = 0; i < n; i++) {
            c[i] = in.next().toCharArray();
        }
        int answer = Integer.MAX_VALUE;
        int[][] left = getLeft(n, m, c);
        if (left == null) {
            out.println(-1);
            return;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0, k = c[i].length - 1; j < k; j++, k--) {
                char t = c[i][j];
                c[i][j] = c[i][k];
                c[i][k] = t;
            }
        }
        int[][] right = getLeft(n, m, c);
        for (int i = 0; i < n; i++) {
            for (int j = 0, k = right[i].length - 1; j < k; j++, k--) {
                int t = right[i][j];
                right[i][j] = right[i][k];
                right[i][k] = t;
            }
        }
        for (int i = 0; i < m; i++) {
            int best = 0;
            for (int j = 0; j < n; j++) {
                int curBest = Integer.MAX_VALUE;
                curBest = Math.min(curBest, left[j][i]);
                curBest = Math.min(curBest, right[j][i]);
                if (curBest == Integer.MAX_VALUE) {
                    best = Integer.MAX_VALUE;
                    break;
                }
                best += curBest;
            }
            answer = Math.min(answer, best);
        }
        out.println(answer == Integer.MAX_VALUE ? -1 : answer);
    }

    private static int[][] getLeft(int n, int m, char[][] c) {
        int[][] left = new int[n][m];
        for (int i = 0; i < n; i++) {
            int z = m - 1;
            while (z >= 0 && c[i][z] == '0') {
                --z;
            }
            if (z < 0) {
                return null;
            }
            left[i][0] = c[i][0] == '1' ? 0 : m - z;
            for (int j = 1; j < m; j++) {
                if (c[i][j] == '1') {
                    left[i][j] = 0;
                } else {
                    left[i][j] = left[i][j - 1] + 1;
                }
            }
        }
        return left;
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