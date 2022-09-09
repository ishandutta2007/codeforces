import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int x1 = in.nextInt();
        int y1 = in.nextInt();
        int x2 = in.nextInt();
        int y2 = in.nextInt();
        if (x1 != x2 && y1 != y2) {
            if (Math.abs(x2 - x1) != Math.abs(y2 - y1)) {
                out.println(-1);
                return;
            }
            out.println(x1 + " " + y2 + " " + x2 + " " + y1);
            return;
        }
        if (x1 == x2) {
            int d = Math.abs(y1 - y2);
            if (x1 + d <= 1000) {
                out.println((x1 + d) + " " + y1 + " " + (x1 + d) + " " + y2);
                return;
            }
            if (x1 - d >= -1000) {
                out.println((x1 - d) + " " + y1 + " " + (x1 - d) + " " + y2);
                return;
            }
            out.println(-1);
            return;
        }
        int d = Math.abs(x1 - x2);
        if (y1 + d <= 1000) {
            out.println((x1) + " " + (d + y1) + " " + (x2) + " " + (d + y2));
            return;
        }
        if (y1 - d >= -1000) {
            out.println((x1) + " " + (y1 - d) + " " + (x2) + " " + (y2 - d));
            return;
        }
        out.println(-1);
        return;
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