import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    class Point {
        double x, y;

        public Point(double x, double y) {
            super();
            this.x = x;
            this.y = y;
        }

    }

    class Line {
        double A, B, C;

        Line(Point p1, Point p2) {
            A = p2.y - p1.y;
            B = p1.x - p2.x;
            C = -A * p1.x - B * p1.y;
        }
    }

    Point intersect(Line l1, Line l2) {
        double zn = l1.A * l2.B - l2.A * l1.B;
        double xc = l2.C * l1.B - l1.C * l2.B;
        double yc = l1.C * l2.A - l2.C * l1.A;
        return new Point(xc / zn, yc / zn);
    }

    Random rnd = new Random(123);

    double dist(Point p1, Point p2) {
        double dx = p1.x - p2.x;
        double dy = p1.y - p2.y;
        return Math.sqrt(dx * dx + dy * dy);
    }

    double get_angle(Point p1, Point p2, Point p3) {
        double a = dist(p1, p2);
        double b = dist(p2, p3);
        double c = dist(p1, p3);
        double zz = (a * a + b * b - c * c) / a / b / 2.;
        return Math.acos(zz);
    }

    boolean isNorm(Point[] a) {
        int n = a.length;
        double[] dist = new double[n];
        for (int i = 0; i < n; i++) {
            if (a[i].x > 1e5 || a[i].x < -1e5)
                return false;
            if (a[i].y > 1e5 || a[i].y < -1e5)
                return false;
            double dx = a[i].x - a[(i + 1) % n].x;
            double dy = a[i].y - a[(i + 1) % n].y;
            dist[i] = Math.sqrt(dx * dx + dy * dy);
        }
        double[] angles = new double[n];
        for (int i = 0; i < n; i++) {
            angles[i] = get_angle(a[(i - 1 + n) % n], a[i], a[(i + 1) % n]);
        }
        Arrays.sort(angles);
        if (Math.abs(angles[0] - angles[n - 1]) > 1e-4) {
             return false;
        }
        Arrays.sort(dist);
        if (dist[0] < 2 || dist[n - 1] >= 999) {
            return false;
        }
        for (int i = 0; i < n - 1; i++)
            if (Math.abs(dist[i] - dist[i + 1]) < 1e-2)
                return false;
        return true;
    }

    void solve() throws IOException {
        int n = in.nextInt();
        if (n < 5) {
            out.println("No solution");
        } else {
            while (true) {
                double angle = Math.PI * (n - 2);
                angle /= n;
                angle = Math.PI - angle;
                Point[] a = new Point[n];
                a[0] = new Point(0, 0);
                double curAngle = 0;
                for (int i = 1; i < n - 1; i++) {
                    double R = rnd.nextDouble() * 1000 + 3;
                    a[i] = new Point(a[i - 1].x + R * Math.cos(curAngle),
                            a[i - 1].y + R * Math.sin(curAngle));
                    curAngle += angle;
                }
                Line l1 = new Line(a[a.length - 2], new Point(a[a.length - 2].x
                        + Math.cos(curAngle), a[a.length - 2].y
                        + Math.sin(curAngle)));
                double angle2 = Math.PI - angle;
                Line l2 = new Line(a[0], new Point(a[0].x + Math.cos(angle2),
                        a[0].y + Math.sin(angle2)));
                a[a.length - 1] = intersect(l1, l2);
                if (!isNorm(a)) {
                    continue;
                    // throw new AssertionError();
                }
                for (int i = 0; i < n; i++) {
                    out.println(a[i].x + " " + a[i].y);
                }
                break;
            }
        }
    }

    void run() throws IOException {
        try {
            in = new FastScanner(new File("test.in"));
            out = new PrintWriter(new File("test.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() throws IOException {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) throws IOException {
        new CF().runIO();
    }
}