import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    class O {
        int xmin, xmax, ymin, ymax;

        O() {
            xmin = Integer.MAX_VALUE;
            ymin = Integer.MAX_VALUE;
            xmax = Integer.MIN_VALUE;
            ymax = Integer.MIN_VALUE;
            for (int i = 0; i < 4; i++) {
                int x =in.nextInt();
                int y = in.nextInt();
                xmin = Math.min(xmin, x);
                xmax = Math.max(xmax, x);
                ymin = Math.min(ymin, y);
                ymax = Math.max(ymax, y);
            }
        }

        boolean inside(int x, int y) {
            return x >= xmin && x <= xmax && y >= ymin && y <= ymax;
        }

        boolean inside2(int x, int y) {
            if (x < xmin || x > xmax) {
                return false;
            }
            int xmid = (xmin + xmax) / 2;
            int diff = Math.abs(x - xmid);
            int yfrom = ymin + diff, yto = ymax - diff;
            return y >= yfrom && y <= yto;
        }
    }

    void solve() {
        O a = new O();
        O b = new O();
        for (int x = -100; x <= 100; x++) {
            for (int y = -100; y <= 100; y++) {
                if (a.inside(x, y) && b.inside2(x, y)) {
                    out.println("YES");
                    return;
                }
            }
        }
        out.println("NO");
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