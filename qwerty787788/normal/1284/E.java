import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class A {
    FastScanner in;
    PrintWriter out;
    int mod;

    public static void main(String[] args) {
        new A().runIO();
    }

    int vectMul(Point a, Point b, Point c) {
        return Long.signum((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x));
    }

    boolean insideTriangle(Point p, Point A, Point B, Point C) {
        if (vectMul(A, B, p) > 0 && vectMul(B, C, p) > 0 && vectMul(C, A, p) > 0) {
            return true;
        }
        if (vectMul(A, B, p) < 0 && vectMul(B, C, p) < 0 && vectMul(C, A, p) < 0) {
            return true;
        }
        return false;
    }

    int sign(Point center, Point me) {
        return me.y > center.y || me.y == center.y && me.x >= center.x ? 0 : 1;
    }

    long countTriangles(Point[] pts, Point center) {
        Arrays.sort(pts, new Comparator<Point>() {
            @Override
            public int compare(Point o1, Point o2) {
                int s1 = sign(center, o1);
                int s2 = sign(center, o2);
                if (s1 != s2) {
                    return Integer.compare(s1, s2);
                }
                return -vectMul(center, o1, o2);
            }
        });
//        System.err.println(center + " " + Arrays.toString(pts));
        int it = 0;
        long n = pts.length;
        long res = n * (n - 1) * (n - 2) / 6;
        for (int i = 0; i < pts.length; i++) {
            if (it == i) {
                it = (it + 1) % pts.length;
            }
            while (vectMul(center, pts[i], pts[it]) > 0) {
                it = (it + 1) % pts.length;
            }
            long d = (it - i + pts.length) % pts.length;
            if (d == 0) {
                d += pts.length;
            }
//            System.err.println("for i = " + i + ", d = " + d);
            res -= (d - 1) * (d - 2) / 2;
        }
//        System.err.println("!! " + res);
        return res;
    }

    void solve() {
        int n = in.nextInt();
        Point[] a = new Point[n];
        for (int i = 0; i < n; i++) {
            a[i] = new Point(in.nextInt(), in.nextInt());
        }
        Point[] b = new Point[n - 1];
        long res = 0;
        for (int o = 0; o < n; o++) {
            int it = 0;
            for (int i = 0; i < n; i++) {
                if (i != o) {
                    b[it++] = a[i];
                }
            }
            res += countTriangles(b, a[o]);
        }
        res *= (n - 4);
        out.println(res / 2);
    }

    void solve123() {
        int n = in.nextInt();
        Point[] a = new Point[n];
        for (int i = 0; i < n; i++) {
            a[i] = new Point(in.nextInt(), in.nextInt());
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    for (int l = 0; l < n; l++) {
                        if (l == i || l == j || l == k) {
                            continue;
                        }
                        if (insideTriangle(a[l], a[i], a[j], a[k])) {
                            res++;
                        }
                    }
                }
            }
        }
        res *= (n - 4);
        if (res % 2 != 0) {
            throw new AssertionError(res);
        }
        res /= 2;
        out.println(res);
    }

    void run() {
        try {
            in = new FastScanner(new File("A.in"));
            out = new PrintWriter(new File("A.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {

        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class Point {
        long x, y;

        Point(long x, long y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public String toString() {
            return "Point{" +
                    "x=" + x +
                    ", y=" + y +
                    '}';
        }
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

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}