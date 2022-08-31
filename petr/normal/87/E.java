import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Idol implements Runnable {
    static class Point {
        final long x;
        final long y;

        Point(long x, long y) {
            this.x = x;
            this.y = y;
        }
    }

    class Polygon {
        List<Point> vertices = new ArrayList<Point>();
        List<Point> leftBorder = new ArrayList<Point>();
        List<Point> rightBorder = new ArrayList<Point>();

        void read() throws IOException {
            int n = nextInt();
            for (int i = 0; i < n; ++i) {
                int x = nextInt();
                int y = nextInt();
                vertices.add(new Point(x, y));
            }
        }

        public void prepareBorders() {
            long maxy = Long.MIN_VALUE;
            long miny = Long.MAX_VALUE;
            for (Point p : vertices) {
                miny = Math.min(miny, p.y);
                maxy = Math.max(maxy, p.y);
            }
            {
                int rightStart;
                for (rightStart = 0; rightStart < vertices.size(); ++rightStart) {
                    if (vertices.get(rightStart).y == miny && vertices.get((rightStart + 1) % vertices.size()).y > miny) {
                        break;
                    }
                }
                for (int i = rightStart;; i = (i + 1) % vertices.size()) {
                    rightBorder.add(vertices.get(i));
                    if (vertices.get(i).y == maxy)
                        break;
                }
            }
            {
                int leftStart;
                for (leftStart = 0; leftStart < vertices.size(); ++leftStart) {
                    if (vertices.get(leftStart).y == maxy && vertices.get((leftStart + 1) % vertices.size()).y < maxy) {
                        break;
                    }
                }
                for (int i = leftStart;; i = (i + 1) % vertices.size()) {
                    leftBorder.add(vertices.get(i));
                    if (vertices.get(i).y == miny)
                        break;
                }
            }
        }

        public boolean inside(Point point) {
            int rightPos;
            int leftPos;
            {
                int left = -1;
                int right = rightBorder.size();
                while (right - left > 1) {
                    int middle = (left + right) / 2;
                    if (rightBorder.get(middle).y <= point.y)
                        left = middle;
                    else
                        right = middle;
                }
                if (left < 0) return false;
                if (left == rightBorder.size() - 1) --left;
                rightPos = left;
            }
            {
                int left = -1;
                int right = leftBorder.size();
                while (right - left > 1) {
                    int middle = (left + right) / 2;
                    if (leftBorder.get(middle).y >= point.y)
                        left = middle;
                    else
                        right = middle;
                }
                if (left < 0) return false;
                if (left == leftBorder.size() - 1) --left;
                leftPos = left;
            }
            int z = 1;
            z *= signum(rightBorder.get(rightPos), point, rightBorder.get(rightPos + 1));
            z *= signum(leftBorder.get(leftPos), leftBorder.get(leftPos + 1), point);
            return z <= 0;
        }
    }

    private static int signum(Point a, Point b, Point c) {
        long dxb = b.x - a.x;
        long dyb = b.y - a.y;
        long dxc = c.x - a.x;
        long dyc = c.y - a.y;
        long z = dxb * dyc - dxc * dyb;
        if (z < 0) return -1; else if (z > 0) return 1; else return 0;
    }

    public Polygon add(Polygon a, Polygon b) {
        Polygon c = new Polygon();
        int sa = 0;
        {
            Point sap = a.vertices.get(0);
            for (int i = 1; i < a.vertices.size(); ++i) {
                Point p = a.vertices.get(i);
                if (p.y < sap.y || p.y == sap.y && p.x < sap.x) {
                    sap = p;
                    sa = i;
                }
            }
        }
        int sb = 0;
        {
            Point sbp = b.vertices.get(0);
            for (int i = 1; i < b.vertices.size(); ++i) {
                Point p = b.vertices.get(i);
                if (p.y < sbp.y || p.y == sbp.y && p.x < sbp.x) {
                    sbp = p;
                    sb = i;
                }
            }
        }
        int ra = sa;
        int rb = sb;
        while (true) {
            Point ca = a.vertices.get(sa);
            Point na = a.vertices.get((sa + 1) % a.vertices.size());
            Point cb = b.vertices.get(sb);
            Point nb = b.vertices.get((sb + 1) % b.vertices.size());
            c.vertices.add(addPoints(ca, cb));
            long dxa = na.x - ca.x;
            long dya = na.y - ca.y;
            long dxb = nb.x - cb.x;
            long dyb = nb.y - cb.y;
            long z = (dxa * dyb - dya * dxb);
            if (z > 0) {
                sa = (sa + 1) % a.vertices.size();
            } else if (z < 0) {
                sb = (sb + 1) % b.vertices.size();
            } else {
                sa = (sa + 1) % a.vertices.size();
                sb = (sb + 1) % b.vertices.size();
            }
            if (sa == ra && sb == rb)
                break;
        }
        return c;
    }

    private Point addPoints(Point ca, Point cb) {
        return new Point(ca.x + cb.x, ca.y + cb.y);
    }

    private void solve() throws IOException {
        Polygon[] p = new Polygon[3];
        for (int i = 0; i < p.length; ++i) {
            p[i] = new Polygon();
            p[i].read();
        }
        Polygon sum = p[0];
        for (int i = 1; i < p.length; ++i) {
            sum = add(sum, p[i]);
        }
        sum.prepareBorders();
        int m = nextInt();
        for (int i = 0; i < m; ++i) {
            int x = nextInt() * 3;
            int y = nextInt() * 3;
            Point pp = new Point(x, y);
            if (sum.inside(pp)) {
                writer.println("YES");
            } else {
                writer.println("NO");
            }
        }
    }

    public static void main(String[] args) {
        new Idol().run();
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            writer = new PrintWriter(System.out);
            solve();
            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}