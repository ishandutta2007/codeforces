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

    static long[][][][] f;

    static long query(int x, int y) {
        long[][] ff = f[x - 1 & 1][y - 1 & 1];
        long ret1 = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1) {
                ret1 ^= ff[i][j];
            }
        }
        return ret1;
    }

    static long query(int x1, int y1, int x2, int y2) {
        return query(x2, y2) ^ query(x1 - 1, y2) ^ query(x2, y1 - 1) ^ query(x1 - 1, y1 - 1);
    }

    static void update(long[][] f, int x, int y, long v) {
        for (int i = x; i < f.length; i |= i + 1) {
            for (int j = y; j < f[i].length; j |= j + 1) {
                f[i][j] ^= v;
            }
        }
    }

    static void update(int x1, int y1, int x2, int y2, long v) {
        update(f[x2 & 1][y2 & 1], x2, y2, v);
        update(f[x1 - 1 & 1][y2 & 1], x1, y2, v);
        update(f[x2 & 1][y1 - 1 & 1], x2, y1, v);
        update(f[x1 - 1 & 1][y1 - 1 & 1], x1, y1, v);
    }


    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        f = new long[2][2][n][n];
        for (int i = 0; i < m; i++) {
            int op = in.nextInt();
            int x1 = in.nextInt() - 1;
            int y1 = in.nextInt() - 1;
            int x2 = in.nextInt() - 1;
            int y2 = in.nextInt() - 1;
            if (op == 1) {
                out.println(query(x1, y1, x2, y2));
            } else {
                long v = in.nextLong();
                update(x1, y1, x2, y2, v);
            }
        }
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

    public long nextLong() {
        return Long.parseLong(next());
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