import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Comparator;
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
		Triangles solver = new Triangles();
		solver.solve(1, in, out);
		out.close();
	}
}

class Triangles {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        Point2DInteger[] red = new Point2DInteger[n];
        Point2DInteger[] blue = new Point2DInteger[m];
        for (int i = 0; i < n; i++) {
            red[i] = new Point2DInteger(in.nextInt(), in.nextInt());
        }
        for (int i = 0; i < m; i++) {
            blue[i] = new Point2DInteger(in.nextInt(), in.nextInt());
        }
        int answer = 0;
        for (int first = 0; first < n; first++) {
            ColoredPoint[] z = new ColoredPoint[n + m - first - 1];
            final Point2DInteger root = red[first];
            for (int i = first + 1; i < n; i++) {
                z[i - first - 1] = new ColoredPoint(red[i].subtract(root), 0);
            }
            for (int i = 0; i < m; i++) {
                z[i + n - first - 1] = new ColoredPoint(blue[i].subtract(root), 1);
            }
            Comparator<ColoredPoint> comp = new Comparator<ColoredPoint>() {
                public int compare(ColoredPoint o1, ColoredPoint o2) {
                    int c1 = getZ(o1.p);
                    int c2 = getZ(o2.p);
                    if (c1 != c2) {
                        return c1 - c2;
                    }
                    return -Long.signum(o1.p.vmul(o2.p));
                }

                int getZ(Point2DInteger a) {
                    int x = a.x;
                    int y = a.y;
                    if (x > 0) {
                        return y > 0 ? 2 : y < 0 ? 8 : 1;
                    } else if (x < 0) {
                        return y > 0 ? 4 : y < 0 ? 6 : 5;
                    } else {
                        return y > 0 ? 3 : y < 0 ? 7 : 0;
                    }
                }
            };
            Arrays.sort(z, comp);
            final Point2DInteger origin = new Point2DInteger(0, 0);
            for (int i = 0; i < z.length; i++) {
                if (z[i].color == 1) {
                    continue;
                }
                Point2DInteger second = z[i].p;
                Point2DInteger best = null;
                for (int j = (i + 1) % z.length; j != i;) {
                    if (vmulFromPoint(second, origin, z[j].p) > 0) {
                        break;
                    }
                    if (z[j].color == 1) {
                        if (best == null || vmulFromPoint(second, best, z[j].p) > 0) {
                            best = z[j].p;
                        }
                    } else {
                        if (best == null || vmulFromPoint(second, best, z[j].p) > 0) {
                            ++answer;
                        }
                    }
                    ++j;
                    if (j == z.length) {
                        j = 0;
                    }
                }
            }
        }
        out.println(answer);
    }

    static long vmulFromPoint(Point2DInteger from, Point2DInteger a, Point2DInteger b) {
        long x1 = a.x - from.x;
        long y1 = a.y - from.y;
        long x2 = b.x - from.x;
        long y2 = b.y - from.y;
        return x1 * y2 - x2 * y1;
    }

    static class ColoredPoint {
        Point2DInteger p;
        int color;

        ColoredPoint(Point2DInteger p, int color) {
            this.p = p;
            this.color = color;
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

    public Point2DInteger subtract(Point2DInteger p) {
        return new Point2DInteger(x - p.x, y - p.y);
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


    }