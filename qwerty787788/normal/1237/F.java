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

    int mul(int x, int y) {
        return (int) (x * 1L * y % mod);
    }

    final int MAX = 3605;
    int[][] c = new int[MAX][MAX];

    void solve() {
        c[0][0] = 1;
        for (int i = 1; i < MAX; i++) {
            c[i][0] = 1;
            for (int j = 1; j < MAX; j++) {
                c[i][j] = add(c[i - 1][j - 1], c[i - 1][j]);
            }
        }
        int[] fact = new int[MAX];
        fact[0] = 1;
        for (int i = 1; i < MAX; i++) {
            fact[i] = mul(fact[i - 1], i);
        }
        int h = in.nextInt();
        int w = in.nextInt();
        boolean[] rows = new boolean[h];
        boolean[] cols = new boolean[w];
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                rows[in.nextInt() - 1] = true;
                cols[in.nextInt() - 1] = true;
            }
        }
        int emptyRows = empty(rows);
        int emptyCols = empty(cols);
        int[] ways2rows = ways2(rows);
        int[] ways2cols = ways2(cols);
        int res = 0;
        for (int cntVertical = 0; cntVertical < ways2rows.length; cntVertical++) {
            for (int cntHorizontal = 0; cntHorizontal < ways2cols.length && cntVertical * 2 + cntHorizontal <= emptyRows && cntVertical + cntHorizontal * 2 <= emptyCols; cntHorizontal++) {
                int ways = mul(ways2rows[cntVertical], c[emptyRows - cntVertical * 2][cntHorizontal]);
                ways = mul(ways, mul(ways2cols[cntHorizontal], c[emptyCols - cntHorizontal * 2][cntVertical]));
                ways = mul(ways, fact[cntVertical]);
                ways = mul(ways, fact[cntHorizontal]);
                res = add(res, ways);
            }
        }
        out.println(res);
    }

    int empty(boolean[] a) {
        int res = 0;
        for (boolean z : a) {
            res += z ? 0 : 1;
        }
        return res;
    }

    int[] ways2(boolean[] a) {
        int n = a.length;
        int[] dp = new int[n / 2 + 1];
        int[] ndp = new int[dp.length];
        dp[0] = 1;
        for (int i = 0; i < a.length; ) {
            if (a[i]) {
                i++;
                continue;
            }
            int j = i;
            while (j != a.length && !a[j]) {
                j++;
            }
            Arrays.fill(ndp, 0);
            int len = j - i;
            for (int cur = 0; cur < dp.length; cur++) {
                if (dp[cur] == 0) {
                    continue;
                }
                for (int add = 0; add * 2 <= len; add++) {
                    ndp[cur + add] = add(ndp[cur + add], mul(dp[cur], c[len - add][add]));
                }
            }
            int[] tmp = dp;
            dp = ndp;
            ndp = tmp;
            i = j;
        }
        return dp;
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