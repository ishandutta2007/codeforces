import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    int cost(char c, int value) {
        int nval = c == 'L' ? 0 : 1;
        return Math.abs(nval - value);
    }

    void solve() {
        int n = in.nextInt();
        long[][] a = new long[n][n];
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                int sum = (x + y) - 1;
                if (y % 2 != 0 && (x + y > 0)) {
                    a[x][y] = 1L << sum;
                    if (a[x][y] > 1e16) {
                        throw new AssertionError();
                    }
                }
                out.print(a[x][y] + " ");
            }
            out.println();
        }
        out.flush();
        int tc = in.nextInt();
        for (int t = 0; t < tc; t++) {
            long value = in.nextLong();
            List<Point> answer = new ArrayList<>();
            answer.add(new Point(0, 0));
            for (int bit = 0; bit < 2 * n - 2; bit++) {
                long expect = 1L << bit;
                Point last = answer.get(answer.size() - 1);
                Point next = null;
                boolean changeY = false;
                boolean ymustOdd = false;
                if ((value & expect) == expect) {
                    ymustOdd = true;
                }
                boolean ywasOdd = last.y % 2 == 1;
                changeY = ymustOdd != ywasOdd;
                if (changeY) {
                    next = new Point(last.x, last.y + 1);
                } else {
                    next = new Point(last.x + 1, last.y);
                }
                answer.add(next);
            }
            for (Point p : answer) {
                out.println((p.x + 1) + " " + (p.y + 1));
            }
            out.flush();
        }
    }

    class Point {
        int x, y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
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

    public static void main(String[] args) {
        new A().runIO();
    }
}