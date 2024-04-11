import java.io.*;
import java.util.*;

public class C {
    private FastScanner in;
    private PrintWriter out;

    class Rational implements Comparable<Rational>{
        int up, down;

        public Rational(int up, int down) {
            this.up = up;
            this.down = down;
            if (down < 0) {
                this.up *= -1;
                this.down *= -1;
            }
        }

        @Override
        public int compareTo(Rational o) {
            return Long.compare(up * 1L * o.down, down * 1L * o.up);
        }

        @Override
        public String toString() {
            return up * 1. / down +"";
        }
    }

    Rational from, to;

    void updateTo(Rational r) {
        if (r.compareTo(to) < 0) {
            to = r;
        }
    }

    void updateFrom(Rational r) {
        if (r.compareTo(from) > 0) {
            from = r;
        }
    }

    boolean update(int xStart, int xMove, int xMin, int xMax) {
        if (xMove == 0) {
            if (xStart > xMin && xStart < xMax) {
                return true;
            }
            to =new Rational(0, 1);
            return false;
        }

        if (xStart > xMin && xStart < xMax) {
            if (xMove > 0) {
                updateTo(new Rational(xMax - xStart, xMove));
            } else {
                updateTo(new Rational(xMin - xStart, xMove));
            }
            return true;
        } else {
            if (xMove > 0) {
                updateFrom(new Rational(xMin - xStart, xMove));
                updateTo(new Rational(xMax - xStart, xMove));
            } else {
                updateFrom(new Rational(xMax - xStart, xMove));
                updateTo(new Rational(xMin - xStart, xMove));
            }
            return false;
        }
    }

    private void solve() {
        int n = in.nextInt();
        int x1 = in.nextInt();
        int y1 = in.nextInt();
        int x2 = in.nextInt();
        int y2 = in.nextInt();
        int xMin = Math.min(x1, x2), xMax = Math.max(x1, x2);
        int yMin = Math.min(y1, y2), yMax = Math.max(y1, y2);
        from = new Rational(0, 1);
        to =new Rational((int) 1e9, 1);
        boolean allInside = true;
        for (int i = 0; i < n; i++) {
            int x = in.nextInt();
            int y = in.nextInt();
            int vx = in.nextInt();
            int vy = in.nextInt();

            allInside &= update(x, vx, xMin, xMax);
            allInside &= update(y, vy, yMin, yMax);
//            System.err.println(from + " " +to);
        }
        if (allInside) {
            out.println(0);
            return;
        }
        if (from.compareTo(to) >= 0) {
            out.println(-1);
            return;
        }
        out.println(from.up * 1.0 / from.down);
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