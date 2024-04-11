import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;
    static int n, m;
    static boolean cat[];
    static ArrayList<Integer> gr[];
    static int ans;
    static int dp[];

    static void scan() throws IOException {
        n = sc.nextInt();
        m = sc.nextInt() + 1;
        cat = new boolean[n];
        dp = new int [n];
        gr = new ArrayList[n];
        for(int i = 0;i < n;i++) gr[i] = new ArrayList<>();
        for(int i = 0;i < n;i++) if (sc.nextInt() == 1) cat[i] = true;
        for(int i = 0;i < n - 1;i++) {
            int v1 = sc.nextInt() - 1;
            int v2 = sc.nextInt() - 1;
            gr[v1].add(v2);
            gr[v2].add(v1);
        }
        dfs1(0, -1);
        ans = dp[0];
        dfs2(0, -1, 0);
        pw.println(ans);
    }

    static void dfs1(int v, int pr) {
        for(int to : gr[v]) {
            if (to != pr) {
                dfs1(to, v);
                dp[v] += dp[to];
            }
        }
        if (dp[v] == 0) dp[v] = 1;
    }

    static void dfs2(int v, int pr, int cnt) {
        if (cat[v]) cnt++;
        else cnt = 0;
        if (cnt >= m)  {
            ans -= dp[v];
            return;
        }
        for(int to : gr[v]) {
            if (to != pr) {
                dfs2(to, v, cnt);
            }
        }
    }


    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        scan();
        pw.close();
    }

    static Scanner sc;
    static PrintWriter pw;

    static class Scanner {
        BufferedReader br;
        StringTokenizer st = new StringTokenizer("");

        Scanner(InputStream in) throws FileNotFoundException {
            br = new BufferedReader(new InputStreamReader(in));
        }

        Scanner(String in) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(in));
        }

        String next() throws IOException {
            while (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }
}

class segment_tree {
    long max[][][];
    int last;

    segment_tree(int a[]) {
        int n = a.length;
        max = new long[4 * n][2][2];
        last = n - 1;
        build(0, 0, last, a);
    }

    void update(int v) {
        int l = v * 2 + 1, r = v * 2 + 2;
        long l_00 = max[l][0][0], l_01 = Math.max(max[l][0][1], l_00),
                l_10 = max[l][1][0], l_11 = Math.max(max[l][1][1], l_10);
        long r_00 = max[r][0][0], r_01 = Math.max(max[r][0][1], r_00),
                r_10 = max[r][1][0], r_11 = Math.max(max[r][1][1], r_10);

        max[v][0][0] = Math.max(l_01 + r_00, l_00 + r_10);
        max[v][0][1] = Math.max(l_01 + r_01, l_00 + r_11);
        max[v][1][0] = Math.max(l_11 + r_00, l_10 + r_10);
        max[v][1][1] = Math.max(l_11 + r_01, l_10 + r_11);
    }

    void build(int v, int l, int r, int a[]) {
        if (l == r) {
            max[v][1][1] = a[l];
            return;
        }
        int m = ((l + r) >> 1);
        build(v * 2 + 1, l, m, a);
        build(v * 2 + 2, m + 1, r, a);
        update(v);
    }

    void set(int id, int x) {
        set(0, 0, last, id, x);
    }

    void set(int v, int l, int r, int id, int x) {
        if (l > id || r < id) return;
        if (l == id && r == id) {
            max[v][1][1] = x;
            return;
        }
        int m = ((l + r) >> 1);
        set(v * 2 + 1, l, m, id, x);
        set(v * 2 + 2, m + 1, r, id, x);
        update(v);
    }

    long get() {
        return Math.max(Math.max(Math.max(max[0][1][0], max[0][0][1]), max[0][0][0]), max[0][1][1]);
    }
}