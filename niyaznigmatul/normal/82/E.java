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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int h = in.nextInt();
        int f = in.nextInt();
        Line[] z = new Line[4 * n];
        for (int i = 0; i < n; i++) {
            int left = in.nextInt();
            int right = in.nextInt();
            z[4 * i] = new Line(true, new Point2DInteger(0, f), new Point2DInteger(left, h));
            z[4 * i + 1] = new Line(false, new Point2DInteger(0, f), new Point2DInteger(right, h));
            z[4 * i + 2] = new Line(true, new Point2DInteger(0, -f), new Point2DInteger(left, -h));
            z[4 * i + 3] = new Line(false, new Point2DInteger(0, -f), new Point2DInteger(right, -h));
        }
        int iter = 2000;
        Event[] s = new Event[4 * n];
        for (int i = 0; i < 4 * n; i++) {
            s[i] = new Event(0, false);
        }
        double answer = 0;
        for (int it = 0; it < iter; it++) {
            double y = 2. * h * it / iter - h;
            for (int i = 0; i < 4 * n; i++) {
                s[i].x = z[i].get(y);
                s[i].begin = z[i].begin;
            }
            Arrays.sort(s);
            double last = Double.NEGATIVE_INFINITY;
            double sum = 0;
            int count = 0;
            for (int i = 0; i < 4 * n; i++) {
                if (count > 0) {
                    sum += s[i].x - last;
                }
                if (s[i].begin) {
                    ++count;
                } else {
                    --count;
                }
                last = s[i].x;
            }
            answer += sum;
        }
        out.println(2 * h * answer / iter);
    }

    static class Event implements Comparable<Event> {
        double x;
        boolean begin;

        Event(double x, boolean begin) {
            this.x = x;
            this.begin = begin;
        }

        public int compareTo(Event o) {
            return Double.compare(x, o.x);
        }
    }

    static class Line {
        boolean begin;
        Point2DInteger p, q;

        Line(boolean begin, Point2DInteger p, Point2DInteger q) {
            this.begin = begin;
            this.p = p;
            this.q = q;
        }

        double get(double y) {
            return p.x + 1. * (q.x - p.x) / (q.y - p.y) * (y - p.y);
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


    }