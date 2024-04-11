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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {

    static int[] DX = {0, 0, -1, 1};
    static int[] DY = {1, -1, 0, 0};

    static String DIRS = "UDLR";

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int a = in.nextInt();
        int b = in.nextInt();
        String s = in.next();
        int dx = 0;
        int dy = 0;
        for (char c : s.toCharArray()) {
            dx += DX[DIRS.indexOf(c)];
            dy += DY[DIRS.indexOf(c)];
        }
        int cx = 0;
        int cy = 0;
        for (char c : s.toCharArray()) {
            if (check(cx, cy, dx, dy, a, b)) {
                out.println("Yes");
                return;
            }
            cx += DX[DIRS.indexOf(c)];
            cy += DY[DIRS.indexOf(c)];
        }
        out.println("No");
    }

    static boolean check(int cx, int cy, int dx, int dy, int a, int b) {
        int ex = a - cx;
        int ey = b - cy;
        if (ex != 0 && dx == 0 || ey != 0 && dy == 0) {
            return false;
        }
        if (ex == 0 && dx == 0 && ey == 0 && dy == 0) {
            return true;
        }
        if (ey == 0 && dy == 0) {
            int t = ex;
            ex = ey;
            ey = t;
            t = dx;
            dx = dy;
            dy = t;
        }
        if (ey % dy != 0) {
            return false;
        }
        int k = ey / dy;
        if (k >= 0 && (long) k * dx == ex) {
            return true;
        }
        return false;
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

    }

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }

    public FastPrinter(Writer out) {
        super(out);
    }


}