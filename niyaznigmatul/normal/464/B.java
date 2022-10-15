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
 * @author Niyaz Nigmatullin
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {

    static int[][] x;
    static int[][] ps;
    static int[][] c;

    static int[][] PERMS = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};

    static long dist(int[] a, int[] b) {
        long dx = a[0] - b[0];
        long dy = a[1] - b[1];
        long dz = a[2] - b[2];
        return dx * dx + dy * dy + dz * dz;
    }

    static long[] ds;

    static boolean check() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 3; j++) {
                c[i][j] = x[i][ps[i][j]];
            }
        }
        int cn = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = i + 1; j < 8; j++) {
                ds[cn++] = dist(c[i], c[j]);
            }
        }
        Arrays.sort(ds);
        if (ds[0] == 0) return false;
        for (int i = 0; i < 12; i++) {
            if (ds[i] != ds[0]) return false;
        }
        for (int i = 12; i < 24; i++) {
            if (ds[i] != ds[0] * 2) return false;
        }
        for (int i = 24; i < 28; i++) {
            if (ds[i] != ds[0] * 3) return false;
        }
        return true;
    }

    static boolean go(int step) {
        if (step == 8) {
            return check();
        }
        for (int i = 0; i < 6; i++) {
            ps[step] = PERMS[i];
            if (go(step + 1)) {
                return true;
            }
        }
        return false;
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        x = new int[8][3];
        c = new int[8][3];
        ds = new long[4 * 7];
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 3; j++) {
                x[i][j] = in.nextInt();
            }
        }
        ps = new int[8][];
        ps[0] = PERMS[0];
        if (!go(1)) {
            out.println("NO");
            return;
        }
        out.println("YES");
        for (int i = 0; i < 8; i++) {
            out.println(c[i][0] + " " + c[i][1] + " " + c[i][2]);
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