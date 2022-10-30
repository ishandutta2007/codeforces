import java.io.*;
import java.util.*;
public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        long a[] = new long [n];
        for(int i = 0;i < n;i++) a[i] = nextLong();
        int ans[] = new int [n];
        segment_tree b = new segment_tree(n);
        for(int i = n - 1;i >= 0;i--) {
            ans[i] = b.get(a[i]) + 1;
            b.set(ans[i] - 1);
        }
        for(int i = 0;i < n;i++) pw.print(ans[i] + " ");
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
    long min[], push[];
    boolean used[];
    int last;
    segment_tree(int n) {
        last = n - 1;
        min = new long [n * 4];
        push = new long [n * 4];
        used = new boolean[n * 4];
        build(0, 0, last);
    }

    void build(int v, int l, int r) {
        if (l == r) {
            min[v] = (long)(l + 1) * l / 2;
            return;
        }
        int m = ((l + r) >> 1);
        build(v * 2 + 1, l, m);
        build(v * 2 + 2, m + 1, r);
        min[v] = Math.min(min[v * 2 + 1], min[v * 2 + 2]);
    }

    void pushing(int v) {
        push[v * 2 + 1] += push[v];
        push[v * 2 + 2] += push[v];
        min[v * 2 + 1] += push[v];
        min[v * 2 + 2] += push[v];
        push[v] = 0;
    }

    void set(int l) {
        set(0, 0, last, l, last, l + 1);
    }

    void set(int v, int l, int r, int left, int right, int num) {
        if (l > right || r < left) return;
        if (l >= left && r <= right) {
            push[v] -= num;
            min[v] -= num;
            return;
        }
        pushing(v);
        int m = ((l + r) >> 1);
        set(v * 2 + 1, l, m, left, right, num);
        set(v * 2 + 2, m + 1, r, left, right, num);
        min[v] = Math.min(min[v * 2 + 1], min[v * 2 + 2]);
    }

    int get(long s) {
        return get(0, 0, last, s);
    }

    int get(int v, int l, int r, long s) {
        if (min[v] > s || used[v]) return -1;
        if (l == r) {
            used[v] = true;
            return l;
        }
        pushing(v);
        int m = ((l + r) >> 1);
        int ans = get(v * 2 + 2, m + 1, r, s);
        if (ans == -1) ans = get(v * 2 + 1, l, m, s);
        used[v] = used[v * 2 + 1] && used[v * 2 + 2];
        return ans;
    }
}