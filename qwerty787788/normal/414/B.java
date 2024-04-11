import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    void solve() {
        long mod = (long) 1e9 + 7;
        int n = in.nextInt();
        int k = in.nextInt();
        long[][] dp = new long[k][n + 1];
        for (int last = 1; last <= n; last++)
            dp[0][last] = 1;
        for (int i = 0; i < k - 1; i++) {
            for (int last = 1; last <= n; last++)
                for (int x = last; x <= n; x += last) {
                    dp[i + 1][x] += dp[i][last];
                }
            for (int last = 1; last <= n; last++)
                dp[i + 1][last] %= mod;
        }
        long res = 0;
        for (int last = 1; last <= n; last++)
            res += dp[k - 1][last];
        out.println(res % mod);
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