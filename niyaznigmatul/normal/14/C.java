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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {

    static class Point {
        int x, y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Point point = (Point) o;

            if (x != point.x) return false;
            if (y != point.y) return false;

            return true;
        }

        public int hashCode() {
            int result = x;
            result = 31 * result + y;
            return result;
        }

        long abs2() {
            return smul(this);
        }

        long smul(Point p) {
            return (long) x * p.x + (long) y * p.y;
        }

        Point sub(Point p) {
            return new Point(x - p.x, y - p.y);
        }
    }

	public void solve(int testNumber, FastScanner in, FastPrinter out) {
        Point[] p1 = new Point[4];
        Point[] p2 = new Point[4];
        for (int i = 0; i < 4; i++) {
            p1[i] = new Point(in.nextInt(), in.nextInt());
            p2[i] = new Point(in.nextInt(), in.nextInt());
        }
        int[] first = new int[4];
        int[] second = new int[4];
        Arrays.fill(first, -1);
        Arrays.fill(second, -1);
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (i == j) {
                    continue;
                }
                if (p1[i].equals(p2[j]) || p1[i].equals(p1[j]) || p2[i].equals(p1[j]) || p2[i].equals(p2[j])) {
                    if (first[i] < 0) {
                        first[i] = j;
                    } else if (second[i] < 0) {
                        second[i] = j;
                    } else {
                        out.println("NO");
                        return;
                    }
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            if (second[i] < 0) {
                out.println("NO");
                return;
            }
        }
        int[] p = new int[4];
        p[1] = first[0];
        for (int i = 2; i < 4; i++) {
            p[i] = p[i - 2] ^ first[p[i - 1]] ^ second[p[i - 1]];
        }
        Point[] v = new Point[4];
        for (int i = 0; i < 4; i++) {
            v[i] = p2[p[i]].sub(p1[p[i]]);
        }
        for (int i = 0; i < 4; i++) {
            if (v[i].smul(v[(i + 1) & 3]) != 0 || v[i].abs2() != v[i + 2 & 3].abs2() || v[i].abs2() == 0 || (v[i].x != 0 && v[i].y != 0)) {
                out.println("NO");
                return;
            }
        }
        out.println("YES");
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