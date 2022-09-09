import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    long mod = (long) 1e9;

    void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] a = new int[n];
        long[] f = new long[1000];
        f[0] = f[1] = 1;
        for (int i = 2; i < 1000; i++)
            f[i] = (f[i - 1] + f[i - 2]) % mod;
        for (int i = 0; i < n; i++)
            a[i] = in.nextInt();
        for (int i = 0; i < m; i++) {
            if (in.nextInt() == 1) {
                a[in.nextInt() - 1] = in.nextInt();
            } else {
                int l = in.nextInt() - 1;
                int r = in.nextInt() - 1;
                long res = 0;
                for (int j = 0; j < r - l + 1; j++) {
                    res = (res + f[j] * a[l + j]) % mod;
                }
                out.println(res);
            }
        }
    }

    void run() {
        long st = System.currentTimeMillis();
        try {
            in = new FastScanner(new File("test.in"));
            out = new PrintWriter(new File("test.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        long sp = System.currentTimeMillis() - st;
        System.err.println(sp);
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
    }

    public static void main(String[] args) {
        new CF().runIO();
    }
}