import java.io.*;
import java.util.*;

public class CF2 {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int a = in.nextInt();
        int b = in.nextInt();
        for (int x = 1; x < a; x++) {
            int y = (int) Math.round(Math.sqrt(a * a - x * x));
            if (x * x + y * y == a * a) {
                for (int x2 = 1; x2 < b; x2++) {
                    int y2 = (int) Math.round(Math.sqrt(b * b - x2 * x2));
                    if (x2 * x2 + y2 * y2 == b * b) {
                        int dx = x + x2;
                        int dy = Math.abs(y2 - y);
                        if (dx * dx + dy * dy == a * a + b * b) {
                            if (y2 != y) {
                                out.println("YES");
                                out.println("0 0");
                                out.println(x + " " + y);
                                out.println(-x2 + " " + y2);
                                return;
                            }
                        }
                    }
                }
            }
        }
        out.println("NO");
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
        new CF2().runIO();
    }
}