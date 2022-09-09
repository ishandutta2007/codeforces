import java.io.*;
import java.util.*;

public class Main {
    FastScanner in;
    PrintWriter out;


    void solve() {
        int n = in.nextInt();
        long START = System.currentTimeMillis();
        boolean[][] g = new boolean[n][n];
        Random rnd = new Random(123);
        for (int i = 0; i < n; i++) {
            char[] s = in.next().toCharArray();
            for (int j = 0; j < n; j++) {
                g[i][j] = s[j] == '1';
            }
        }
        // what is already used, (who was last) * (ans)
        long[][] dp = new long[1 << n][];
        for (int used = 1; used < 1 << n; used++) {
            int last = Integer.bitCount(used);
            int inAns = 1 << (last - 1);
            dp[used] = new long[last * inAns];
        }
        for (int first = 0; first < n; first++) {
            dp[1 << first][0] = 1;
        }
        long[] result = new long[1 << (n - 1)];
        int[] ids = new int[n];
        int[] idsNext = new int[n];
        for (int used = 1; used < 1 << n; used++) {
            int last = Integer.bitCount(used);
            int inAns = 1 << (last - 1);
            int idsSz = 0;
            int idsNextSz = 0;
            for (int i = 0; i < n; i++) {
                if (((1 << i) & used) != 0) {
                    ids[idsSz++] = i;
                } else {
                    idsNext[idsNextSz++] = i;
                }
            }
            for (int lastId = 0; lastId < last; lastId++) {
                for (int ans = 0; ans < inAns; ans++) {
                    int dpPos = ans * last + lastId;
                    long ways = dp[used][dpPos];
                    if (ways == 0) {
                        continue;
                    }
                    int realLastId = ids[lastId];
                    int it = 0;
                    if (idsNextSz == 0) {
                        result[ans] += ways;
                    }
                    for (int nextId = 0; nextId < n - last; nextId++) {
                        int next = idsNext[nextId];
                        int bit = g[realLastId][next] ? 1 : 0;
                        int nAns = (ans << 1) + bit;
                        while (it < idsSz && ids[it] < next) {
                            it++;
                        }
                        dp[used | (1 << next)][nAns * (last + 1) + it] += ways;
                    }
                }
            }
        }
        for (int mask = 0; mask < result.length; mask++) {
            out.print(result[mask] + " ");
        }
        System.err.println(System.currentTimeMillis() - START);
    }

    final int mod = 988244353;

    int mul(int x, int y) {
        return (int) ((x * 1L * y) % mod);
    }

    void run() {
        try {
            in = new FastScanner(new File("Main.in"));
            out = new PrintWriter(new File("Main.out"));

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
        new Main().runIO();
    }
}