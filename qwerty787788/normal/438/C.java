import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    class Point {
        long x, y;

        public Point(long x, long y) {
            super();
            this.x = x;
            this.y = y;
        }

        @Override
        public String toString() {
            return "Point [x=" + x + ", y=" + y + "]";
        }

    }

    int vectMul(Point a, Point b, Point c) {
        return Long.signum((b.x - a.x) * (c.y - a.y) - (b.y - a.y)
                * (c.x - a.x));
    }

    int n;

    int ne(int v) {
        if (v < n - 1)
            return v + 1;
        return 0;
    }

    int pr(int v) {
        if (v == 0)
            return n - 1;
        return v - 1;
    }

    boolean inter(long x1, long x2, long y1, long y2) {
        return Math.max(x1, y1) <= Math.min(x2, y2);
    }

    boolean intersect(Point a, Point b, Point c, Point d) {
        if (a == c || a == d || b == c || b == d)
            return false;
        if (!inter(Math.min(a.x, b.x), Math.max(a.x, b.x), Math.min(c.x, d.x),
                Math.max(c.x, d.x)))
            return false;
        if (!inter(Math.min(a.y, b.y), Math.max(a.y, b.y), Math.min(c.y, d.y),
                Math.max(c.y, d.y)))
            return false;
        if (vectMul(a, b, c) * vectMul(a, b, d) > 0
                || vectMul(c, d, a) * vectMul(c, d, b) > 0)
            return false;
        return true;
    }

    long sq(Point[] a) {
        long res = 0;
        for (int i = 0; i < a.length; i++) {
            long dx = a[i].x - a[ne(i)].x;
            long dy = a[i].y + a[ne(i)].y;
            res += dx * dy;
        }
        return res;
    }

    boolean ok(Point a, Point b, Point c, Point d) {
        if (vectMul(a, b, c) > 0) {
            return vectMul(a, b, d) > 0 && vectMul(a, c, d) < 0;
        } else {
            if (vectMul(a, b, d) <= 0 && vectMul(a, c, d) >= 0)
                return false;
            return true;
        }
    }

    void solve() {
        n = in.nextInt();
        final int MOD = (int) 1e9 + 7;
        Point[] a = new Point[n];
        for (int i = 0; i < n; i++) {
            a[i] = new Point(in.nextInt(), in.nextInt());
        }
        {
            int x = new Random(123).nextInt(n);
            Point[] tmp = new Point[n];
            for (int i = 0; i < n; i++)
                tmp[i] = a[(i + x) % n];
            a = tmp;
        }
        if (sq(a) < 0) {
            for (int i = 0; i < n / 2; i++) {
                Point tmp = a[i];
                a[i] = a[n - i - 1];
                a[n - i - 1] = tmp;
            }
        }
        int[][] dp = new int[n][n];
        boolean[][] can = new boolean[n][n];
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                can[i][j] = true;
                for (int k = 0; k < n; k++)
                    if (intersect(a[i], a[j], a[k], a[ne(k)])) {
                        can[i][j] = false;
                        break;
                    }
                if (can[i][j]) {
                    if (!ok(a[i], a[ne(i)], a[pr(i)], a[j])) {
                        can[i][j] = false;
                    } else {
                        if (!ok(a[j], a[ne(j)], a[pr(j)], a[i])) {
                            can[i][j] = false;
                        }
                    }
                    /*
                     * for (int k = 0; k < n; k++) { if (k != i && k != j) { if
                     * (a[k].x >= Math.min(a[i].x, a[j].x)) if (a[k].x <=
                     * Math.max(a[i].x, a[j].x)) if (a[k].y >= Math.min(a[i].y,
                     * a[j].y)) if (a[k].y <= Math.max(a[i].y, a[j].y)) if
                     * (vectMul(a[i], a[j], a[k]) == 0) { can[i][j] = false;
                     * break; } } }
                     */
                }
                can[j][i] = can[i][j];
            }
        for (int i = 0; i < n; i++)
            can[i][ne(i)] = can[i][pr(i)] = true;
        for (int from = 0; from < n; from++)
            dp[from][ne(from)] = 1;
        for (int cnt = 3; cnt <= n; cnt++)
            for (int from = 0; from < n; from++) {
                int to = (from + cnt - 1) % n;
                int mid = ne(from);
                while (mid != to) {
                    if (vectMul(a[to], a[from], a[mid]) != 0 && can[to][mid]
                            && can[from][mid] && can[to][from]) {
                        int add = (int) ((dp[from][mid] * 1L * dp[mid][to]) % MOD);
                        dp[from][to] += add;
                        if (dp[from][to] >= MOD)
                            dp[from][to] -= MOD;
                    }
                    mid = ne(mid);
                }
            }
        for (int i = 0; i < n; i++)
            if (dp[i][pr(i)] != dp[0][n - 1])
                throw new AssertionError();
        out.println(dp[0][n - 1]);
    }

    void run() {
        try {
            in = new FastScanner(new File("test.in"));
            out = new PrintWriter(new File("test.out"));

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

        double nextDouble() {
            return Double.parseDouble(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) {
        new CF().runIO();
    }
}