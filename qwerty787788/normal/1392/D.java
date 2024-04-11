import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    int cost(char c, int value) {
        int nval = c == 'L' ? 0 : 1;
        return Math.abs(nval - value);
    }

    void solve() {
        int tc = in.nextInt();
        for (int t = 0; t < tc; t++) {
            int n = in.nextInt();
            char[] s = in.next().toCharArray();
            int res = Integer.MAX_VALUE;
            for (int first = 0; first < 2; first++) {
                for (int second = 0; second < 2; second++) {
                    int[][] dp = new int[2][2];
                    int[][] ndp = new int[2][2];
                    for (int i = 0; i < 2; i++) {
                        Arrays.fill(dp[i], Integer.MAX_VALUE / 2);
                    }
                    dp[first][second] = cost(s[0], first) + cost(s[1], second);
                    for (int pos = 2; pos < n; pos++) {
                        for (int i = 0; i < 2; i++) {
                            Arrays.fill(ndp[i], Integer.MAX_VALUE / 2);
                        }
                        for (int x = 0; x < 2; x++) {
                            for (int y = 0; y < 2; y++) {
                                for (int z = 0; z < 2; z++) {
                                    if (x == z && x == y) {
                                        continue;
                                    }
                                    ndp[y][z] = Math.min(ndp[y][z], dp[x][y] + cost(s[pos], z));
                                }
                            }
                        }
                        int[][] tmp = dp;
                        dp = ndp;
                        ndp = tmp;
                    }
                    for (int x = 0; x < 2; x++) {
                        for (int y = 0; y < 2; y++) {
                            if (x == y && y == first) {
                                dp[x][y] = Integer.MAX_VALUE;
                            }
                            if (y == first && first == second) {
                                dp[x][y] = Integer.MAX_VALUE;
                            }
                            res = Math.min(res, dp[x][y]);
                        }
                    }
                }
            }
            out.println(res);
        }
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