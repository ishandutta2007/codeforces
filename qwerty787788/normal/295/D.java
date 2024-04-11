import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    long mod = (long) 1e9 + 7;

    void solve() {
//        for (int i = 1; i <= 10; i++) {
//            for (int j = 1; j <= 10; j++) {
//                System.err.print(sol2(i, j) - sol3(i, j) + " ");
//            }
//            System.err.println();
//        }
         out.println(sol2(in.nextInt(), in.nextInt()));
    }

    long sol2(int n, int m) {
        long res = 0;
        long[][] dp01 = new long[m + 1][n + 1];
        long[][] dp01Sum = new long[m + 1][n + 1];
        for (int w = 2; w <= m; w++)
            dp01[w][1] = 1;
        for (int h = 2; h <= n; h++)
            for (int w = 2; w <= m; w++) {
                dp01Sum[w][h] = (dp01Sum[w - 1][h] + dp01[w][h - 1]) % mod;
                dp01[w][h] = (dp01[w - 1][h] + dp01Sum[w][h]) % mod;
            }
        long[][] dp1 = new long[m + 1][n + 1];
        long[][] dp1Sum = new long[m + 1][n + 1];
        for (int w = 2; w <= m; w++)
            dp1[w][1] = 1;
        for (int h = 2; h <= n; h++)
            for (int w = 2; w <= m; w++) {
                dp1Sum[w][h] = (dp1Sum[w - 1][h] + dp01[w - 1][h - 1]) % mod;
                dp1[w][h] = (dp1[w - 1][h] + dp1Sum[w][h] + dp01[w - 1][h - 1]) % mod;
//                 for (int w1 = 2; w1 < w; w1++) {
//                 dp1[w][h] = (dp1[w][h] + (dp01[w1][h - 1] * (w - w1 + 1))
//                 % mod)
//                 % mod;
//                 }
            }
        long[][] dpSum01 = new long[m + 1][n + 1];
        for (int h = 1; h <= n; h++)
            for (int w = 1; w <= m; w++)
                dpSum01[w][h] = (dpSum01[w][h - 1] + dp01[w][h]) % mod;
        long[][] dpSum1 = new long[m + 1][n + 1];
        for (int h = 1; h <= n; h++)
            for (int w = 1; w <= m; w++)
                dpSum1[w][h] = (dpSum1[w][h - 1] + dp1[w][h]) % mod;
        for (int h1 = 1; h1 <= n; h1++)
            for (int w1 = 1; w1 <= m; w1++) {
                long curRes = (dpSum01[w1][h1] * dpSum1[w1][n - h1 + 1]) % mod;
                curRes = (curRes * (m - w1 + 1)) % mod;
                res = (res + curRes) % mod;
            }
        return res;
    }

    long sol3(int n, int m) {
        long res = 0;
        long[][] dp01 = new long[m + 1][n + 1];
        long[][] dp01Sum = new long[m + 1][n + 1];
        for (int w = 2; w <= m; w++)
            dp01[w][1] = 1;
        for (int h = 2; h <= n; h++)
            for (int w = 2; w <= m; w++) {
                dp01Sum[w][h] = (dp01Sum[w - 1][h] + dp01[w][h - 1]) % mod;
                dp01[w][h] = (dp01[w - 1][h] + dp01Sum[w][h]) % mod;
            }
        long[][] dp1 = new long[m + 1][n + 1];
        for (int w = 2; w <= m; w++)
            dp1[w][1] = 1;
        for (int h = 2; h <= n; h++)
            for (int w = 2; w <= m; w++) {
                for (int w1 = 2; w1 < w; w1++) {
                    dp1[w][h] = (dp1[w][h] + (dp01[w1][h - 1] * (w - w1 + 1))
                            % mod)
                            % mod;
                }
            }
        long[][] dp3 = new long[m + 1][n + 1];
        for (int h = 1; h <= n; h++)
            for (int w = 1; w <= m; w++) {
                for (int h1 = 1; h1 <= h; h1++) {
                    dp3[w][h] = (dp3[w][h] + (dp01[w][h1] * dp1[w][h - h1 + 1])
                            % mod)
                            % mod;

                }
                // dp3[w][h] = dp3[w][h - 1] + dp01[w][h] * dp1[w][h - h + 1];
            }
        for (int h = 1; h <= n; h++)
            for (int w = 1; w <= m; w++) {
                long curRes = (dp3[w][h] * (n - h + 1)) % mod;
                curRes = (curRes * (m - w + 1)) % mod;
                res = (res + curRes) % mod;
            }
        return res;
    }

    int stupid(int n, int m) {
        int total = n * m;
        int sum = 0;
        boolean[][] field = new boolean[n][m];
        for (int st = 0; st < (1 << total); st++) {
            int it = 0;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    if (((1 << it++) & st) != 0)
                        field[i][j] = true;
                    else
                        field[i][j] = false;
            int l = -1, r = -1;
            boolean ok = true;
            int[] first = new int[n];
            int[] last = new int[n];
            Arrays.fill(first, -1);
            Arrays.fill(last, -1);
            for (int i = 0; i < n; i++) {
                int cnt = 0;
                for (int j = 0; j < m; j++)
                    if (field[i][j]) {
                        if (cnt == 0)
                            first[i] = j;
                        last[i] = j;
                        cnt++;
                    }
                if (cnt != 2 && cnt != 0)
                    ok = false;
                if (cnt == 2) {
                    r = i;
                    if (l == -1)
                        l = i;
                }
            }
            if (!ok)
                continue;
            if (l == -1 || r == -1)
                continue;
            for (int i = l; i <= r; i++)
                if (first[i] == -1 || last[i] == -1 || first[i] == last[i])
                    ok = false;
            if (!ok)
                continue;
            boolean ok2 = false;
            for (int t = l; t <= r; t++) {
                boolean ok3 = true;
                for (int i = l; i < t; i++) {
                    if (first[i] < first[i + 1] || last[i] > last[i + 1])
                        ok3 = false;
                }
                for (int i = r; i > t; i--)
                    if (first[i] < first[i - 1] || last[i] > last[i - 1])
                        ok3 = false;
                if (ok3)
                    ok2 = true;
            }
            if (ok2)
                sum++;
        }
        return sum;
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

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) {
        new CF().runIO();
    }
}