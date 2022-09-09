import java.io.*;
import java.util.*;

public class CF {
    private FastScanner in;
    private PrintWriter out;

    final int mod = (int) 1e9 + 7;

    private long f(String s, int digit) {
        final int n = s.length();
        int[][] dp = new int[2][n + 1]; // [less][cntBigger] -> sum
        dp[0][0] = 1;
        int[][] ndp = new int[2][n + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                Arrays.fill(ndp[j], 0);
            }
            for (int less = 0; less < 2; less++) {
                for (int cntBigger = 0; cntBigger <= n; cntBigger++) {
                    int cur = dp[less][cntBigger];
                    if (cur == 0) {
                        continue;
                    }
                    int max = less == 1 ? 9 : (s.charAt(i) - '0');
                    for (int next = 0; next <= max; next++) {
                        int nextLess = (less == 1) || (next < max) ? 1 : 0;
                        int nextCntBigger = cntBigger + ((next >= digit) ? 1 : 0);
                        ndp[nextLess][nextCntBigger] += cur;
                        while (ndp[nextLess][nextCntBigger] >= mod) {
                            ndp[nextLess][nextCntBigger] -= mod;
                        }
                    }
                }
            }
            int[][] tmp = dp;
            dp = ndp;
            ndp = tmp;
        }
        long result = 0;
        for (int less = 0; less < 2; less++) {
            long sum = 0;
            for (int cntBigger = 1; cntBigger <= n; cntBigger++) {
                sum = (sum * 10 + 1) % mod;
                result = (result + sum * dp[less][cntBigger]) % mod;
            }
        }
        return result % mod;
    }

    private void solve() {
        final String number = in.next();
        long result = 0;
        for (int digit = 1; digit < 10; digit++) {
            long cur = f(number, digit);
            result += cur;
        }
        out.println(result % mod);
    }

    private void run() {
        try {
            in = new FastScanner(new File("CF.in"));
            out = new PrintWriter(new File("CF.out"));

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
        new CF().runIO();
    }
}