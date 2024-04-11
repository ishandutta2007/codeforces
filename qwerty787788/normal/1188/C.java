import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    final int mod = 998244353;

    int add(int x, int y) {
        x += y;
        return x >= mod ? (x - mod) : x;
    }

    void solve() {
        int n = in.nextInt();
        int k = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        Arrays.sort(a);
        int[][] dp = new int[2][n + 1];
        int res = 0;
        for (int minDelta = 1; minDelta * (k - 1) + a[0] <= a[n - 1]; minDelta++) {
            Arrays.fill(dp[0], 0);
            dp[0][0] = 1;
            for (int it = 0; it < k; it++) {
                int sum = dp[0][0];
                dp[1][0] = 0;
                int posIter = 0;
                for (int lastValuePos = 0; lastValuePos < n; lastValuePos++) {
                    while (posIter < lastValuePos && a[posIter] + minDelta <= a[lastValuePos]) {
                        posIter++;
                        sum = add(sum, dp[0][posIter]);
                    }
                    dp[1][lastValuePos + 1] = sum;
                }
                int[] tmp = dp[0];
                dp[0] = dp[1];
                dp[1] = tmp;
            }
            for (int lastPos = 0; lastPos <= n; lastPos++) {
                res = add(res, dp[0][lastPos]);
            }
        }
        out.println(res);
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