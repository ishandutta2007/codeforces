import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    void solve() {
        double a = in.nextDouble();
        double d = in.nextDouble();
        int n = in.nextInt();
        d %= (4 * a);
        double eps = 1e-9;
        double x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            double more = d;
            for (int it = 0; it < 3; it++) {
                if (y < eps) {
                    double addX = Math.min(a - x, more);
                    more -= addX;
                    x += addX;
                }
                if (x > a - eps) {
                    double addY = Math.min(a - y, more);
                    more -= addY;
                    y += addY;
                }
                if (y > a - eps) {
                    double addX = Math.min(x, more);
                    more -= addX;
                    x -= addX;
                }
                if (x < eps) {
                    double addY = Math.min(y, more);
                    more -= addY;
                    y -= addY;
                }
            }
            out.println(x + " " + y);
        }
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