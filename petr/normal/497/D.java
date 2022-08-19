import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.StringTokenizer;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    static class Point {
        int x;
        int y;

        public Point(InputReader in) {
            x = in.nextInt();
            y = in.nextInt();
        }

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static class Polygon {
        Point[] points;

        public Polygon(InputReader in) {
            int n = in.nextInt();
            points = new Point[n];
            for (int i = 0; i < n; ++i) {
                points[i] = new Point(in);
            }
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        Point oA = new Point(in);
        Polygon A = new Polygon(in);
        Point oB = new Point(in);
        Polygon B = new Polygon(in);
        for (Point v : A.points) {
            if (willIntersect(oA, v, oB, B)) {
                out.println("YES");
                return;
            }
        }
        for (Point v : B.points) {
            if (willIntersect(oB, v, oA, A)) {
                out.println("YES");
                return;
            }
        }
        out.println("NO");
    }

    private boolean willIntersect(Point oA, Point a, Point oB, Polygon b) {
        Point center = new Point(a.x + oB.x - oA.x, a.y + oB.y - oA.y);
        long r2 = d2(oA, oB);
        boolean haveIn = false;
        boolean haveOut = false;
        for (int i = 0; i < b.points.length; ++i) {
            Point x = b.points[i];
            long dd = d2(x, center);
            if (dd <= r2) haveIn = true;
            if (dd >= r2) haveOut = true;
        }
        if (haveIn && haveOut) return true;
        if (haveOut) {
            for (int i = 0; i < b.points.length; ++i) {
                Point p = b.points[i];
                Point q = b.points[(i + 1) % b.points.length];
                if ((p.x - q.x) * (long) (center.x - q.x) + (p.y - q.y) * (long) (center.y - q.y) <= 0) continue;
                if ((q.x - p.x) * (long) (center.x - p.x) + (q.y - p.y) * (long) (center.y - p.y) <= 0) continue;
                long prod = (p.x - q.x) * (long) (center.y - q.y) - (p.y - q.y) * (long) (center.x - q.x);
                long numerator = prod * prod;
                long denom = r2 * d2(p, q);
                if (numerator <= denom) {
                    return true;
                }
            }
        }
        return false;
    }

    private long d2(Point a, Point b) {
        long dx = a.x - b.x;
        long dy = a.y - b.y;
        return dx * dx + dy * dy;
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream), 32768);
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

}