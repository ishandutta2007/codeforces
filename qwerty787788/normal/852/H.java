import java.io.*;
import java.util.*;

public class H {
    private FastScanner in;
    private PrintWriter out;

    class Point implements Comparable<Point> {
        long x, y;

        public Point(long x, long y) {
            this.x = x;
            this.y = y;
        }

        int side(Point o) {
            if (o.y < y || (o.y == y && o.x < x)) {
                return -1;
            }
            return 1;
        }

        int id;

        @Override
        public String toString() {
            return "(" + x + " " + y + ")";
        }

        @Override
        public int compareTo(Point o) {
            if (y != o.y) {
                return Long.compare(y, o.y);
            }
            return Long.compare(x, o.x);
        }
    }

    int vectMul(Point a, Point b, Point c) {
        long r = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
        return Long.signum(r);
    }

    long vectMulValue(Point a, Point b, Point c) {
        long r = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
//        System.err.println("r " + r +" " + a + " " + b + " "+ c);
        return r;
    }

    private void solve() {
        long START = System.currentTimeMillis();
        Random rnd = new Random(123);
        int n = in.nextInt();
        int k = in.nextInt();
        long res = 0;
        Point[] a = new Point[n];
        for (int i = 0; i < n; i++) {
            a[i] = new Point(in.nextInt(), in.nextInt());
//            double angle = Math.PI * 2 * rnd.nextDouble();
//            a[i] = new Point((long) (Math.cos(angle) * 1000000), (long) (Math.sin(angle) * 1000000));
        }
        Arrays.sort(a);
//        System.err.println(Arrays.toString(a));
        long[][][] dp = new long[k + 1][n + 1][n + 1];
        Point[] prev = new Point[n];
        Point[] next = new Point[n];
        long[] curBest = new long[k];
        for (int first = 0; first < n; first++) {
            final int f = first;
            Arrays.sort(a, first + 1, n, new Comparator<Point>() {
                @Override
                public int compare(Point o1, Point o2) {
                    return -vectMul(a[f], o1, o2);
                }
            });
            int pts = n - first;
            for (int i = 0; i < dp.length; i++) {
                for (int j = 0; j < pts; j++) {
                    Arrays.fill(dp[i][j], -1);
                }
            }
            for (int i = 1; i < pts; i++) {
                dp[2][0][i] = 0;
            }
            for (int i = first; i < n; i++) {
                a[i].id = i;
            }
            for (int p2 = 1; p2 < pts; p2++) {
                Point se = a[first + p2];
                int prevSz = 0, nextSz = 0;
                for (int i = 0; i < p2; i++) {
                    prev[prevSz++] = a[i + first];
                }

                Point most = null;
                for (int i = p2 + 1; i < pts; i++) {
                    Point th = a[i + first];
                    if (most != null && vectMul(se, most, th) < 0) {
                        continue;
                    }
                    next[nextSz++] = th;
                    most = th;
                }
                Comparator<Point> cmp = new Comparator<Point>() {
                    @Override
                    public int compare(Point o1, Point o2) {
                        return -vectMul(se, o1, o2);
                    }
                };
                Arrays.sort(prev, 0, prevSz, cmp);
                Arrays.sort(next, 0, nextSz, cmp);

                Arrays.fill(curBest, -1);
                int p1Iter = 0;
                for (int p3Iter = 0; p3Iter < nextSz; p3Iter++) {
                    Point th = next[p3Iter];
                    long tm = vectMulValue(a[first], se, th);
                    while (p1Iter != prevSz && vectMul(prev[p1Iter], se, th) >= 0) {
                        for (int used = 2; used < k; used++) {
                            curBest[used] = Math.max(curBest[used], dp[used][prev[p1Iter].id - first][p2]);
                        }
                        p1Iter++;
                    }
                    for (int used = 2; used < k; used++) {
                        if (curBest[used] != -1) {
                            long nValue = tm + curBest[used];
                            dp[used + 1][p2][th.id - first] = Math.max(dp[used + 1][p2][th.id - first], nValue);
                        }
                    }
                }

                for (int p1 = 0; p1 < p2; p1++) {
                    res = Math.max(res, dp[k][p1][p2]);
                }
            }
        }
        System.err.println(System.currentTimeMillis() - START);
        out.print(res / 2 + "." + (res % 2 == 0 ? "00" : "50"));
    }

    private void run() {
        try {
            in = new FastScanner(new File("H.in"));
            out = new PrintWriter(new File("H.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    private void runIO() {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    private class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        FastScanner(InputStream f) {
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

    public static void main(String[] args) {
        new H().runIO();
    }
}