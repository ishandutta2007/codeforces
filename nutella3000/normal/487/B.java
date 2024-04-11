import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int s = sc.nextInt();
        int l = sc.nextInt();
        int a[] = new int [n];
        int dp[] = new int [n];
        for(int i = 0;i < n;i++) dp[i] = inf;

        for(int i = 0;i < n;i++) a[i] = sc.nextInt();

        segment_tree a1 = new segment_tree(a);
        segment_tree dp1 = new segment_tree(dp);

        for(int i = 0;i < n;i++) {
            int id = a1.get_dist(i, s);
            if (i - id + 1 < l) continue;
            if (id == 0) dp[i] = 1;
            else {
                int left = i - l + 1;
                dp[i] = dp1.get_min(id - 1, left - 1) + 1;
            }
            dp1.set(i, dp[i]);
        }

        if (dp[n - 1] >= inf) pw.println(-1);
        else pw.println(dp[n - 1]);
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
    static int inf = (int) 1e9 + 7;
    int min[], max[];
    int last;

    segment_tree(int a[]) {
        int n = a.length;
        min = new int [4 * n];
        max = new int [4 * n];
        last = n - 1;
        build(0, 0, last, a);
    }

    void update(int v) {
        min[v] = Math.min(min[v * 2 + 1], min[v * 2 + 2]);
        max[v] = Math.max(max[v * 2 + 1], max[v * 2 + 2]);
    }

    void build(int v, int l, int r, int a[]) {
        if (l == r) {
            min[v] = a[l];
            max[v] = a[l];
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
            min[v] = x;
            max[v] = x;
            return;
        }
        int m = ((l + r) >> 1);
        set(v * 2 + 1, l, m, id, x);
        set(v * 2 + 2, m + 1, r, id, x);
        update(v);
    }

    int get_min(int l, int r) {
        return get_min(0, 0, last, l, r);
    }

    int get_min(int v, int l, int r, int left, int right) {
        if (l > right || r < left) return inf;
        if (l >= left && r <= right) return min[v];

        int m = ((l + r) >> 1);

        return Math.min(get_min(v * 2 + 1, l, m, left, right), get_min(v * 2 + 2, m + 1, r, left, right));
    }

    int get_max(int l, int r) {
        return get_max(0, 0, last, l, r);
    }

    int get_max(int v, int l, int r, int left, int right) {
        if (l > right || r < left) return -inf;
        if (l >= left && r <= right) return max[v];

        int m = ((l + r) >> 1);

        return Math.max(get_max(v * 2 + 1, l, m, left, right), get_max(v * 2 + 2, m + 1, r, left, right));
    }

    int get_dist(int r, int s) {
        return get_dist(0, 0, last, r, s, inf, -inf) + 1;
    }

    int get_dist(int v, int l, int r, int right, int s, int min1, int max1) {
        if (l > right) return -1;
        if (Math.max(max[v], max1) - Math.min(min[v], min1) <= s) return -1;
        if (l == r) return l;
        int m = ((l + r) >> 1);

        int ans = get_dist(v * 2 + 2, m + 1, r, right, s, min1, max1);
        min1 = Math.min(min1, get_min(m + 1, Math.min(r, right)));
        max1 = Math.max(max1, get_max(m + 1, Math.min(r, right)));
        if (ans == -1) ans = get_dist(v * 2 + 1, l, m, right, s, min1, max1);
        return ans;
    }

}