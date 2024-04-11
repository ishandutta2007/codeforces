import java.io.*;
import java.util.*;

public class C {
    private FastScanner in;
    private PrintWriter out;

    private void solve() {
        int n = in.nextInt();
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            b[i] = in.nextInt();
        }
        double angle = Math.PI / 2 * (2 * n - 2) / (2 * n);
        double betta = Math.PI / 2 - angle;
        double sin = Math.sin(betta), cos = Math.cos(betta);
        O[] all = new O[n];
        for (int i = 0; i < n; i++) {
            int pos1 = (n - b[i]), pos2 = b[(i + 1) % n];
            double f1 = pos1 / (n + 0.);
            double f2 = pos2 / (n + 0.);
            Point A = new Point(1 + f1 * cos, -f1 * sin);
            Point B = new Point(-f2 * cos, -f2 * sin);
            double dx = A.x - B.x, dy = A.y - B.y;
            double dist = Math.sqrt(dx * dx + dy * dy);
            double cur = dist * (B.y - A.y) / (A.x - B.x);
            all[i] = new O(i, cur);
        }
        Arrays.sort(all);
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[all[i].id] = i;
        }
        for (int x : res) {
            out.print(x + " ");
        }
        out.println();
    }

    class O implements Comparable<O> {
        int id;
        double val;

        public O(int id, double val) {
            this.id = id;
            this.val = val;
        }

        @Override
        public int compareTo(O o) {
            return -Double.compare(val, o.val);
        }
    }

    class Point {
        double x, y;

        public Point(double x, double y) {
            this.x = x;
            this.y = y;
        }
    }

    private void run() {
        try {
            in = new FastScanner(new File("C.in"));
            out = new PrintWriter(new File("C.out"));

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
        new C().runIO();
    }
}