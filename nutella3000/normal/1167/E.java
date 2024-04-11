import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
public class Main {
    static int inf = (int) 1e9 + 7;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int x = nextInt();
        int a[] = new int [n];
        for(int i = 0;i < n;i++) a[i] = nextInt();
        segment_tree b = new segment_tree(n, a);
        int f[] = new int [n];
        f[n - 1] = 1;
        TreeSet<Integer> who = new TreeSet<>();
        who.add(a[n - 1]);
        for(int i = n - 2;i >= 0;i--) {
            if (a[i] <= f[i + 1]) f[i] = f[i + 1];
            else{
                if (who.higher(f[i + 1]) == null || a[i] <= who.higher(f[i + 1])) f[i] = f[i + 1];
                else{
                    f[i] = who.lower(a[i]);
                }
            }
            who.add(a[i]);
        }
        long ans = 0;
        ArrayList<Integer> id[] = new ArrayList[x + 1];
        for(int i = 0;i <= x;i++) id[i] = new ArrayList<>();
        for(int i = 0;i < n;i++) {
            id[a[i]].add(i);
        }
        int max1 = -1;
        int left = 0;
        for(int j : id[1]) {
            max1 = Math.max(b.get(left, j), max1);
            left = j + 1;
        }
        ans += x - f[0] + 1;
        for(int i = 2;i <= x;i++) {
            max1 = Math.max(max1, i);
            if (left == n) ans += x + 1 - max1;
            else ans += x - Math.max(max1, f[left]) + 1;
            if (id[i].isEmpty()) continue;
            if (left > id[i].get(0)) {
                break;
            }
            for(int j : id[i]) {
                max1 = Math.max(b.get(left, j), max1);
                left = j + 1;
            }
        }
        pw.print(ans);
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
    int max[], last;
    segment_tree(int n, int a[]) {
        max = new int [n * 4];
        last = n - 1;
        build(0, 0, last, a);
    }
    void build(int v, int l, int r,int a[]) {
        if (l == r) {
            max[v] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(v * 2 + 1, l,m, a);
        build(v * 2 + 2, m + 1, r, a);
        max[v] = Math.max(max[v * 2 + 1], max[v  * 2 + 2]);
    }
    int get(int v, int l, int r, int left, int right) {
        if (l > right || r < left) return -1;
        if (l >= left && r <= right) return max[v];
        int m = (l + r) / 2;
        return Math.max(get(v * 2 + 1, l, m, left, right), get(v * 2 + 2, m + 1, r, left, right));
    }
    int get(int l, int r) {
        return get(0, 0, last, l, r);
    }
}