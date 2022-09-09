import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class DCopy {
    FastScanner in;
    PrintWriter out;

    final int mod = 998244353;

    int add(int x, int y) {
        x += y;
        return x >= mod ? (x - mod) : x;
    }

    int sub(int x, int y) {
        x -= y;
        return x < 0 ? (x + mod) : x;
    }

    int mul(int x, int y) {
        return (int) (x * 1L * y % mod);
    }

    // return number of cycles of lengths upto k
    int[] solve(int n, int k) {
        List<Integer>[] g = new ArrayList[n];
        List<Integer>[] backId = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
            backId[i] = new ArrayList<>();
        }
        // [cycle_len][root is here][x - not going to g[root][x]]
        int[][][] dp = new int[k + 1][n][];
        int[][] dpSumNeigh = new int[k + 1][n];
        for (int i = 0; i + 1 < n; i++) {
            int fr = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            backId[fr].add(g[to].size());
            backId[to].add(g[fr].size());
            g[fr].add(to);
            g[to].add(fr);
        }
        int[] res = new int[k + 1];
        for (int time = 0; time <= k; time++) {
            for (int v = 0; v < n; v++) {
                dp[time][v] = new int[g[v].size() + 1];
                if (time == 0) {
                    Arrays.fill(dp[time][v], 1);
                } else {
                    for (int gId = 0; gId < dp[time][v].length; gId++) {
                        for (int firstLen = 2; firstLen <= time; firstLen++) {
                            int sumWays = dpSumNeigh[firstLen - 2][v];
                            if (gId != g[v].size()) {
                                int to = g[v].get(gId);
                                int myPos = backId[v].get(gId);
                                sumWays = sub(sumWays, dp[firstLen - 2][to][myPos]);
                            }
                            dp[time][v][gId] = add(dp[time][v][gId], mul(sumWays, dp[time - firstLen][v][gId]));
                        }
                    }
                }
                res[time] = add(res[time], dp[time][v][dp[time][v].length - 1]);
            }
            for (int v = 0; v < n; v++) {
                for (int pos = 0; pos < g[v].size(); pos++) {
                    int to = g[v].get(pos);
                    int fromId = backId[v].get(pos);
                    dpSumNeigh[time][v] = add(dpSumNeigh[time][v], dp[time][to][fromId]);
                }
            }
        }
        return res;
    }

    void solve() {
        int n1 = in.nextInt();
        int n2 = in.nextInt();
        int k = in.nextInt();
        int[] first = solve(n1, k);
        int[] second = solve(n2, k);
        int res = 0;
        int[][] c = new int[k + 1][k + 1];
        c[0][0] = 1;
        for (int i = 1; i < c.length; i++) {
            c[i][0] = 1;
            for (int j = 1; j < c[i].length; j++) {
                c[i][j] = add(c[i - 1][j - 1], c[i - 1][j]);
            }
        }
        for (int firstCycleLen = 0; firstCycleLen <= k; firstCycleLen++) {
            res = add(res, mul(first[firstCycleLen], mul(second[k - firstCycleLen], c[k][firstCycleLen])));
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
        new DCopy().runIO();
    }
}