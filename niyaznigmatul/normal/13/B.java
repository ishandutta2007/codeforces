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
		LetterA solver = new LetterA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class LetterA {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        Segment[] p = new Segment[3];
        for (int i = 0; i < 3; i++) {
            Point2DInteger a = new Point2DInteger(in.nextInt(), in.nextInt());
            Point2DInteger b = new Point2DInteger(in.nextInt(), in.nextInt());
            p[i] = new Segment(a, b);
        }
        int countCommon = 0;
        int lastI = -1;
        int lastJ = -1;
        for (int i = 0; i < 3; i++) {
            Segment a = p[i];
            for (int j = i + 1; j < 3; j++) {
                Segment b = p[j];
                all: for (int it = 0; it < 2; it++) {
                    for (int it2 = 0; it2 < 2; it2++) {
                        if (a.p.equals(b.p)) {
                            break all;
                        }
                        {
                            Point2DInteger t = b.p;
                            b.p = b.q;
                            b.q = t;
                        }
                    }
                    {
                        Point2DInteger t = a.p;
                        a.p = a.q;
                        a.q = t;
                    }
                }
                if (a.p.equals(b.p)) {
                    Point2DInteger v1 = a.getVector();
                    Point2DInteger v2 = b.getVector();
                    if (v1.smul(v2) < 0 || v1.vmul(v2) == 0) {
                        out.println("NO");
                        return;
                    }
                    ++countCommon;
                    lastI = i;
                    lastJ = j;
                }
            }
        }
        if (countCommon != 1) {
            out.println("NO");
            return;
        }
        Segment first = p[lastI];
        Segment second = p[lastJ];
        Segment third = p[lastI ^ lastJ ^ 1 ^ 2];
        for (int it = 0; it < 2; it++) {
            if (good(first.p, first.q, third.p) && good(second.p, second.q, third.q)) {
                out.println("YES");
                return;
            }
            {
                Point2DInteger t = third.p;
                third.p = third.q;
                third.q = t;
            }
        }
        out.println("NO");
    }

    static boolean good(Point2DInteger a, Point2DInteger b, Point2DInteger c) {
        if (!c.isOnSegment(a, b)) {
            return false;
        }
        long d1 = c.distanceSquared(a);
        long d2 = c.distanceSquared(b);
        if (d1 > d2) {
            long t = d1;
            d1 = d2;
            d2 = t;
        }
        return (d1 * 16 >= d2);
    }

    static class Segment {
        Point2DInteger p, q;

        Segment(Point2DInteger p, Point2DInteger q) {
            this.p = p;
            this.q = q;
        }

        Point2DInteger getVector() {
            return q.subtract(p);
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

class Point2DInteger {
    public int x;
    public int y;

    public Point2DInteger(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public long distanceSquared(Point2DInteger p) {
        long dx = x - p.x;
        long dy = y - p.y;
        return dx * dx + dy * dy;
    }

    public Point2DInteger subtract(Point2DInteger p) {
        return new Point2DInteger(x - p.x, y - p.y);
    }

    public long smul(Point2DInteger p) {
        return (long) x * p.x + (long) y * p.y;
    }

    public long vmul(Point2DInteger p) {
        return (long) x * p.y - (long) y * p.x;
    }

    public String toString() {
        return "{" +
                "x=" + x +
                ", y=" + y +
                '}';
    }

    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Point2DInteger that = (Point2DInteger) o;

        if (x != that.x) return false;
        if (y != that.y) return false;

        return true;
    }

    public int hashCode() {
        int result = x;
        result = 31 * result + y;
        return result;
    }


    public boolean isOnSegment(Point2DInteger p, Point2DInteger q) {
        Point2DInteger v1 = subtract(p);
        Point2DInteger v2 = subtract(q);
        if (v1.vmul(v2) != 0) {
            return false;
        }
        return v1.smul(v2) <= 0;
    }
}