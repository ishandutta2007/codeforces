import java.io.*;
import java.util.*;

public class D {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] a = new int[m];
        for (int i = 0; i < n; i++) {
            a[in.nextInt() - 1]++;
        }
        int[][] dp = new int[5][5];
        int[][] ndp = new int[5][5];
        for (int i = 0; i < 5; i++) {
            Arrays.fill(dp[i], -1);
        }
        dp[0][0] = 0;
        for (int i = 0; i < m; i++) {
            int cnt = a[i];
            for (int x = 0; x < 5; x++) {
                Arrays.fill(ndp[x], -1);
            }
            for (int x = 0; x < 5; x++) {
                for (int y = 0; y < 5; y++) {
                    int cur = dp[x][y];
                    if (cur < 0) {
                        continue;
                    }
                    for (int use = 0; use <= x && use <= y && use <= cnt; use++) {
                        int score = cur + use;
                        for (int add = 0; add + use <= cnt && add < 5; add++) {
                            ndp[y - use][add] = Math.max(ndp[y - use][add], score + (cnt - use - add) / 3);
                        }
                    }
                }
            }
            int[][] tmp = dp;
            dp = ndp;
            ndp = tmp;
        }
        int res = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                res = Math.max(res, dp[i][j]);
            }
        }
        out.println(res);
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