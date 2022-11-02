import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static int inf = 998244353;

    static long f1(int c[]) {
        int n = c.length;
        if (n == 0) return 1;
        int mod = inf;
        long dp[][] = new long[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) dp[i][j] = 1;
        }
        for (int len = 2; len <= n; len++) {
            for (int l = 0; l < n; l++) {
                int r = (l + len - 1);
                if (r >= n) break;
                int id = -1;
                int min = inf;
                for (int i = l; i <= r; i++) {
                    if (min > c[i]) {
                        min = c[i];
                        id = i;
                    }
                }
                long left = 0;
                for (int i = l; i <= id; i++) {
                    int i1 = Math.max(i - 1, l);
                    int id1 = Math.max(id - 1, i);
                    left += (dp[l][i1] * dp[i][id1]) % mod;
                }
                left %= mod;
                dp[l][r] = 0;
                for (int i = id; i <= r; i++) {
                    int i1 = Math.min(i + 1, r);
                    int id1 = Math.min(id + 1, i);
                    long right = (dp[id1][i] * dp[i1][r]) % mod;
                    dp[l][r] = (dp[l][r] + right * left) % mod;
                }
            }
        }
        return dp[0][n - 1];
    }

    static int n, m, c[], in[], out[];

    static void build() throws IOException {
        n = nextInt();
        m = nextInt();
        c = new int[m];
        in = new int[n + 1];
        out = new int[n + 1];
        for (int i = 0; i < m; i++) {
            c[i] = nextInt();
            out[c[i]] = i;
        }
        for (int i = m - 1; i >= 0; i--) {
            in[c[i]] = i;
        }
        in[0] = -1;
        out[0] = m;
    }

    static boolean zero() {
        for (int i = 0; i < m; i++) {
            for (int j = c[i] + 1; j <= n; j++) {
                if (in[j] < i && out[j] > i) return true;
            }
        }
        return false;
    }

    static long solve() {
        if (zero()) return 0;
        TreeMap<Integer, Integer> lines = new TreeMap<>();
        long ans = 1;
        for (int i = n; i >= 0; i--) {
            ArrayList<ArrayList<Integer>> new_c = new ArrayList<>();
            int last_out = -1231;
            while (lines.higherKey(in[i]) != null && lines.higherKey(in[i]) < out[i]) {
                int left = lines.higherKey(in[i]);
                if (last_out != left - 1) {
                    new_c.add(new ArrayList<>());
                }
                last_out = out[c[left]];

                new_c.get(new_c.size() - 1).add(c[left]);
                lines.remove(left);
            }
            for (ArrayList<Integer> plu : new_c) {
                int s[] = new int[plu.size()];
                TreeMap<Integer, Integer> squeeze = new TreeMap<>();
                for (int j = 0; j < plu.size(); j++) squeeze.put(plu.get(j), j);
                int num = 1;
                for (Map.Entry<Integer, Integer> j : squeeze.entrySet()) {
                    s[j.getValue()] = num;
                    num++;
                }
                ans = (ans * f1(s)) % inf;
            }
            lines.put(in[i], out[i]);
        }
        return ans;
    }


    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        build();
        pw.println(solve());
        pw.close();
    }

    static BufferedReader br;

    static StringTokenizer st = new StringTokenizer("");
    static PrintWriter pw;
    /*static String next() throws IOException {
        int c = br.read();
        while (Character.isWhitespace(c)) c = br.read();
        StringBuilder sb = new StringBuilder();
        while (!Character.isWhitespace(c)) {
            sb.appendCodePoint(c);
            c = br.read();
        }
        return sb.toString();
    }*/

    static String next() throws IOException {
        if (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    static Double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}

class pair {
    int x, y;

    pair(int a, int b) {
        x = a;
        y = b;
    }

    pair() {
    }
}