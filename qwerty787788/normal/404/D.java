import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    long mod = (long) 1e9 + 7;

    void solve() {
        String s = in.next();
        // need ? (0, 1)
        // 2 - bomb
        int n = s.length();
        long[][] dp = new long[3][n];
        if (s.charAt(0) == '*' || s.charAt(0) == '?') {
            dp[2][0] = 1;
        }
        if (s.charAt(0) == '0' || s.charAt(0) == '?') {
            dp[0][0] = 1;
        }
        if (s.charAt(0) == '1' || s.charAt(0) == '?') {
            dp[1][0] = 1;
        }

        for (int i = 1; i < n; i++) {
            char c = s.charAt(i);
            for (int was = 0; was < 3; was++) {
                long w = dp[was][i - 1];
                if (c == '*' || c == '?') {
                    if (was == 1 || was == 2) {
                        dp[2][i] += w;
                    }
                }
                if (c == '0' || c == '?') {
                    if (was == 0) {
                        dp[0][i] += w;
                    }
                }
                if (c == '1' || c == '?') {
                    if (was == 0) {
                        dp[1][i] += w;
                    }
                    if (was == 2) {
                        dp[0][i] += w;
                    }
                }
                if (c == '2' || c == '?') {
                    if (was == 2) {
                        dp[1][i] += w;
                    }
                }

            }
            for (int j = 0; j < 3; j++)
                dp[j][i] %= mod;
        }
        long res = dp[0][n - 1] + dp[2][n - 1];
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