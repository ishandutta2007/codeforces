import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.*;
public class Main {
    static long inf = (long) 1e15 + 7;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        char h[] = next().toCharArray();
        segment_tree a = new segment_tree(h);
        for(int q = nextInt();q > 0;q--) {
            int t = nextInt();
            int o1 = nextInt();
            if (t == 1) {
                a.set(o1 - 1, next().charAt(0) - 'a');
            }else{
                pw.println(a.get(o1 - 1, nextInt() - 1));
            }
        }
        pw.close();
    }

    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");
    static PrintWriter pw;

    static String next() throws IOException {
        while (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }
}


class segment_tree {
    int cnt[][], last;
    segment_tree(char h[]) {
        int n = h.length;
        cnt = new int [4 * n][26];
        last = n - 1;
        build(0, 0, last, h);
    }

    void build(int v, int l, int r, char h[]) {
        if (l == r) {
            cnt[v][h[l] - 'a']++;
            return;
        }

        int m = ((l + r) >> 1);
        build(v * 2 + 1, l, m, h);
        build(v * 2 + 2, m + 1, r, h);

        for(int i = 0;i < 26;i++) {
            cnt[v][i] = cnt[v * 2 + 1][i] + cnt[v * 2 + 2][i];
        }
    }

    void set(int id, int x) {
        set(0, 0, last, id, x);
    }

    void set(int v, int l, int r, int id, int x) {
        if (l > id || r < id) return;
        if (l == id && r == id) {
            for(int i = 0;i < 26;i++) cnt[v][i] = 0;
            cnt[v][x]++;
            return;
        }

        int m = ((l + r) >> 1);
        set(v * 2 + 1, l, m, id, x);
        set(v * 2 + 2, m + 1, r, id, x);

        for(int i = 0;i < 26;i++) {
            cnt[v][i] = cnt[v * 2 + 1][i] + cnt[v * 2 + 2][i];
        }
    }

    int get(int l, int r) {
        int a[] = get(0, 0, last, l, r);
        int ans = 0;
        for(int i = 0;i < 26;i++) if (a[i] > 0) ans++;
        return ans;
    }

    int[] get(int v, int l, int r, int left, int right) {
        if (l > right || r < left) return new int[26];
        if (l >= left && r <= right) {
            return cnt[v].clone();
        }
        int m = ((l + r) >> 1);
        int one[] = get(v * 2 + 1, l, m, left, right);
        int two[] = get(v * 2 + 2, m + 1, r, left, right);
        int ans[] = new int [26];
        for(int i = 0;i < 26;i++) ans[i] = one[i] + two[i];
        return ans;
    }

}