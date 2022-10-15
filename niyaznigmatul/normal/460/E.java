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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int r = in.nextInt();
        ax = new int[1234];
        ay = new int[ax.length];
        cn = 0;
        for (int x = -r; x <= r; x++) {
            int y = 0;
            while (y * y + x * x <= r * r) ++y;
            --y;
            ax[cn] = x;
            ay[cn++] = y;
            if (y > 0) {
                ax[cn] = x;
                ay[cn++] = -y;
            }
        }
        Point2DInteger[] pp = new Point2DInteger[cn];
        for (int i = 0; i < cn; i++) {
            pp[i] = new Point2DInteger(ax[i], ay[i]);
        }
        pp = GeometryAlgorithms.convexHull(pp);
        cn = pp.length;
        for (int i = 0; i < cn; i++) {
            ax[i] = pp[i].x;
            ay[i] = pp[i].y;
        }
        d = new int[cn][cn];
        for (int i = 0; i < cn; i++) {
            for (int j = 0; j < cn; j++) {
                int dx = ax[i] - ax[j];
                int dy = ay[i] - ay[j];
                d[i][j] = dx * dx + dy * dy;
            }
        }
        best = new int[n + 1];
        answer = new int[n + 1][];
        cur = new int[n];
        go(0, n, 0, 0);
        out.println(best[n]);
        for (int i : answer[n]) {
            out.println(ax[i] + " " + ay[i]);
        }
    }

    static int[] cur;

    static int[][] answer;
    static int[] best;
    static int[] ax;
    static int[] ay;

    static void go(int x, int n, int last, int collect) {
        if (x == n) {
            if (collect > best[x]/* || collect == best[x] && count(answer[x]) > count(Arrays.copyOf(cur, x))*/) {
                best[x] = collect;
                answer[x] = Arrays.copyOf(cur, x);
            }
            return;
        }
        for (int i = last; i < cn; i++) {
            cur[x] = i;
            int add = 0;
            for (int j = 0; j < x; j++) add += dist(cur[j], i);
            go(x + 1, n, i, collect + add);
        }
    }

    static int cn;
    static int[][] d;

    static int dist(int i, int j) {
        return d[i][j];
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

class GeometryAlgorithms {

    public static long vmulFromPoint(Point2DInteger from, Point2DInteger v, Point2DInteger u) {
        long x1 = v.x - from.x;
        long y1 = v.y - from.y;
        long x2 = u.x - from.x;
        long y2 = u.y - from.y;
        return x1 * y2 - x2 * y1;
    }

    public static Point2DInteger[] convexHull(Point2DInteger[] p) {
        p = p.clone();
        if (p.length < 3) {
            return p;
        }
        for (int i = 1; i < p.length; i++) {
            if (p[i].x < p[0].x || p[i].x == p[0].x && p[i].y < p[0].y) {
                Point2DInteger t = p[i];
                p[i] = p[0];
                p[0] = t;
            }
        }
        final Point2DInteger first = p[0];
        Arrays.sort(p, 1, p.length, new Comparator<Point2DInteger>() {
            public int compare(Point2DInteger o1, Point2DInteger o2) {
                long d = vmulFromPoint(first, o1, o2);
                if (d == 0) {
                    return Long.signum(first.distanceSquared(o1) - first.distanceSquared(o2));
                }
                return -Long.signum(d);
            }
        });
        int cur = 2;
        for (int i = 2; i < p.length; i++) {
            Point2DInteger add = p[i];
            while (cur > 1) {
                if (vmulFromPoint(p[cur - 2], p[cur - 1], add) <= 0) {
                    --cur;
                    continue;
                }
                break;
            }
            p[cur++] = add;
        }
        return Arrays.copyOf(p, cur);
    }

}