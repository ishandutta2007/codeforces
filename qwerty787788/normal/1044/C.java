import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    int getMin(int[] a) {
        int r = Integer.MAX_VALUE;
        for (int z : a) {
            r = Math.min(r, z);
        }
        return r;
    }

    int getMax(int[] a) {
        int r = Integer.MIN_VALUE;
        for (int z : a) {
            r = Math.max(r, z);
        }
        return r;
    }

    void solve() {
        int n = in.nextInt();
        int[] x = new int[n];
        int[] y = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = in.nextInt();
            y[i] = in.nextInt();
        }
        int maxX = getMax(x), minX = getMin(x);
        int maxY = getMax(y), minY = getMin(y);
        int res = 0;
        for (int i = 0; i < n; i++) {
            int cx = x[i], cy = y[i];
            res = Math.max(res, cx - minX + cy - minY);
            res = Math.max(res, cx - minX - cy + maxY);
            res = Math.max(res, -cx + maxX + cy - minY);
            res = Math.max(res, -cx + maxX - cy + maxY);
        }
        out.print(res * 2);
        for (int i = 4; i <= n; i++) {
            int four = maxX - minX + maxY - minY;
            out.print(" " + (2 * four));
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