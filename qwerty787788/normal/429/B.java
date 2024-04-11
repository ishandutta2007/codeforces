import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        int[][] a = new int[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                a[i][j] = in.nextInt();
        int[][] dp1 = new int[n][m];
        for (int i = n - 1; i >= 0; i--)
            for (int j = m - 1; j >= 0; j--) {
                dp1[i][j] = a[i][j];
                if (i < n - 1)
                    dp1[i][j] = Math.max(dp1[i][j], a[i][j] + dp1[i + 1][j]);
                if (j < m - 1)
                    dp1[i][j] = Math.max(dp1[i][j], a[i][j] + dp1[i][j + 1]);
            }
        int[][] dp2 = new int[n][m];
        for (int i = 0; i < n; i++)
            for (int j = m - 1; j >= 0; j--) {
                dp2[i][j] = a[i][j];
                if (i > 0)
                    dp2[i][j] = Math.max(dp2[i][j], a[i][j] + dp2[i - 1][j]);
                if (j < m - 1)
                    dp2[i][j] = Math.max(dp2[i][j], a[i][j] + dp2[i][j + 1]);
            }
        int[][] dp3 = new int[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                dp3[i][j] = a[i][j];
                if (i > 0)
                    dp3[i][j] = Math.max(dp3[i][j], a[i][j] + dp3[i - 1][j]);
                if (j > 0)
                    dp3[i][j] = Math.max(dp3[i][j], a[i][j] + dp3[i][j - 1]);
            }
        int[][] dp4 = new int[n][m];
        for (int i = n - 1; i >= 0; i--)
            for (int j = 0; j < m; j++) {
                dp4[i][j] = a[i][j];
                if (i < n - 1)
                    dp4[i][j] = Math.max(dp4[i][j], a[i][j] + dp4[i + 1][j]);
                if (j > 0)
                    dp4[i][j] = Math.max(dp4[i][j], a[i][j] + dp4[i][j - 1]);
            }
        int res = 0;
        {
            for (int i = 1; i < n - 1; i++)
                for (int j = 1; j < m - 1; j++) {
                    int cost = 0;
                    if (j < m - 1)
                        cost += dp1[i][j + 1];
                    if (j > 0)
                        cost += dp3[i][j - 1];
                    if (i > 0)
                        cost += dp2[i - 1][j];
                    if (i < n - 1)
                        cost += dp4[i + 1][j];
                    res = Math.max(res, cost);
                }
        }
        {
            for (int i = 1; i < n - 1; i++)
                for (int j = 1; j < m - 1; j++) {
                    int cost = 0;
                    if (j < m - 1)
                        cost += dp2[i][j + 1];
                    if (j > 0)
                        cost += dp4[i][j - 1];
                    if (i > 0)
                        cost += dp3[i - 1][j];
                    if (i < n - 1)
                        cost += dp1[i + 1][j];
                    res = Math.max(res, cost);
                }
        }
        out.println(res);
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