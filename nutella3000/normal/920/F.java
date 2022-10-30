import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    static int div[], d[];
    static void build_d() {
        int n = (int) 1e6 + 1;
        div = new int [n];
        d = new int [n];
        div[1] = 1;
        for(int i = 1;i < n;i++) {
            if (div[i] != 1) continue;
            for(int j = 2 * i;j < n;j += i) {
                div[j] = i;
            }
        }
        d[1] = 1;
        d[2] = 2;
        for(int i = 3;i < n;i++) {
            int cnt = 0;
            int var = i;
            if (div[i] == 1) {
                d[i] = 2;
                continue;
            }

            while(var % div[i] == 0) {
                var /= div[i];
                cnt++;
            }
            d[i] = d[var] * (cnt + 1);
        }
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        build_d();
        int n = nextInt();
        int m = nextInt();
        int a[] = new int [n];
        for(int i = 0;i < n;i++) a[i] = nextInt();
        segment_tree b = new segment_tree(a);
        dsu c = new dsu(n);
        while(m-- > 0) {
            int t = nextInt();
            int l = nextInt() - 1;
            int r = nextInt() - 1;
            if (t == 1) {
                int v = c.get(l);
                while(v <= r) {
                    a[v] = d[a[v]];
                    b.set(v, a[v]);
                    if (v == n - 1) break;
                    if (a[v] <= 2) c.union(v, v + 1);
                    v = c.get(v + 1);
                }
            }else{
                pw.println(b.get(l, r));
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

class dsu {
    int parent[];
    dsu(int n) {
        parent = new int [n];
        for(int i = 0;i < n;i++) parent[i] = i;
    }

    int get(int v) {
        if (v == parent[v]) return v;
        return parent[v] = get(parent[v]);
    }

    void union(int a, int b) {
        parent[get(a)] = get(b);
    }
}


class segment_tree {
    long sum[];
    int last;

    segment_tree(int a[]) {
        int n = a.length;
        last = n - 1;
        sum = new long [4 * n];
        build(0, 0, last, a);
    }

    void build(int v, int l, int r, int a[]) {
        if (l == r) {
            sum[v] = a[l];
            return;
        }

        int m = ((l + r) >> 1);

        build(v * 2 + 1, l, m, a);
        build(v * 2 + 2, m + 1, r, a);
        sum[v] = sum[v * 2 + 1] + sum[v * 2 + 2];
    }

    void set(int id, int x) {
        set(0, 0, last, id, x);
    }

    void set(int v, int l, int r, int id, int x) {
        if (l > id || r < id) return;
        if (l == id && r == id) {
            sum[v] = x;
            return;
        }
        int m = ((l + r) >> 1);
        set(v * 2 + 1, l, m, id, x);
        set(v * 2 + 2, m + 1, r, id, x);
        sum[v] = sum[v * 2 + 1] + sum[v * 2 + 2];
    }

    long get(int l, int r) {
        return get(0, 0, last, l, r);
    }

    long get(int v, int l, int r, int left, int right) {
        if (l > right || r < left) return 0;
        if (l >= left && r <= right) return sum[v];
        int m = ((l + r) >> 1);
        return get(v * 2 + 1, l, m, left, right) + get(v * 2 + 2, m + 1, r, left, right);
    }


}