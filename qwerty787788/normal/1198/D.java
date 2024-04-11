import java.io.*;
import java.util.*;

public class D {
    FastScanner in;
    PrintWriter out;

    int[] left;
    int[] right;
    int[] cost;
    int[][] id;

    void solve() {
        int n = in.nextInt();
        int[][] f = new int[n + 1][n + 1];
        for (int i = 0; i < n; i++) {
            String s = in.next();
            for (int j = 0; j < n; j++) {
                f[i + 1][j + 1] = s.charAt(j) == '#' ? 1 : 0;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
            }
        }
        int total = n * (n + 1) / 2;
        left = new int[total];
        right = new int[total];
        cost = new int[total];
        id = new int[n][n];
        int it = 0;
        for (int l = n - 1; l >= 0; l--) {
            for (int r = l; r < n; r++) {
                left[it] = l;
                right[it] = r;
                cost[it] = r - l + 1;
                id[l][r] = it;
                it++;
            }
        }
        if (it != total) {
            throw new AssertionError();
        }
        int[][] dp = new int[total][total];
        for (int i = 0; i < total; i++) {
            Arrays.fill(dp[i], -3123132);
        }
        for (int x = 0; x < total; x++) {
            int x1 = left[x], x2 = right[x] + 1;
            for (int y = 0; y < total; y++) {
                int y1 = left[y], y2 = right[y] + 1;
                int cnt = f[x2][y2] - f[x1][y2] - f[x2][y1] + f[x1][y1];
                if (cnt == 0) {
                    dp[x][y] = 0;
                } else {
                    int r = Math.max(x2 - x1, y2 - y1);
                    if (x2 - x1 > y2 - y1) {
                        for (int midX = x1; midX < x2 - 1; midX++) {
                            r = Math.min(dp[id[x1][midX]][y] + dp[id[midX + 1][x2 - 1]][y], r);
                        }
                    } else {
                        for (int midY = y1; midY < y2 - 1; midY++) {
                            r = Math.min(dp[x][id[y1][midY]] + dp[x][id[midY + 1][y2 - 1]], r);
                        }
                    }
                    dp[x][y] = r;
                }
            }
        }
        out.println(dp[it - 1][it - 1]);
    }

    void run() {
        try {
            in = new FastScanner(new File("D.in"));
            out = new PrintWriter(new File("D.out"));

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
        new D().runIO();
    }
}