import java.io.*;
import java.util.*;

public class D {
    private FastScanner in;
    private PrintWriter out;

    private void solve() {
        int n = in.nextInt();
        int k = in.nextInt();
        int m = in.nextInt();
        int[][] d = new int[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(d[i], Integer.MAX_VALUE);
        }
        for (int i = 0; i < m; i++) {
            int u = in.nextInt() - 1;
            int v = in.nextInt() - 1;
            int c = in.nextInt();
            d[u][v] =Math.min(d[u][v], c);
        }
        int[][] dp = new int[n][n];
        int[][] ndp = new int[n][n];
        for (int i = 0; i < dp.length; i++) {
            Arrays.fill(dp[i], Integer.MAX_VALUE);
        }
        for (int i = 0; i < n; i++) {
            dp[i][0] = dp[i][n - 1] = 0;
        }
        for (int go = 1; go < k; go++) {
            for (int i = 0; i < dp.length; i++) {
                Arrays.fill(ndp[i], Integer.MAX_VALUE);
            }
            for (int i = 0; i < dp.length; i++) {
                for (int j = 0; j < dp.length; j++) {
                    int cur = dp[i][j];
                    if (cur == Integer.MAX_VALUE) {
                        continue;
                    }
                    for (int next = Math.min(i, j); next <= Math.max(i, j); next++) {
                        if (next == i || d[i][next] == Integer.MAX_VALUE) continue;
                        if (i < j) {
                            ndp[next][i + 1] = Math.min(ndp[next][i + 1], cur + d[i][next]);
                        } else {
                            ndp[next][i - 1] = Math.min(ndp[next][i - 1], cur + d[i][next]);
                        }
                        ndp[next][j] = Math.min(ndp[next][j], cur + d[i][next]);

                    }
                }
            }
            int[][] tmp = dp;
            dp = ndp;
            ndp = tmp;
        }
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res = Math.min(res, dp[i][j]);
            }
        }
        out.println(res == Integer.MAX_VALUE ? -1 : res);
    }

    private void run() {
        try {
            in = new FastScanner(new File("D.in"));
            out = new PrintWriter(new File("D.out"));

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
        new D().runIO();
    }
}