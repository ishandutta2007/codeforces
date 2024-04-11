import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9;
    static int n, k, a[][];
    static int ver[][], hor[][];
    static int min_ans = 0;
    static void scan() throws IOException {
        n = nextInt();
        k = nextInt();
        char h[][] = new char[n][n];
        a = new int [n][n];
        ver = new int [2][n];
        hor = new int [2][n];
        for(int i = 0;i < n;i++) {
            h[i] = next().toCharArray();
            for(int j = 0;j < n;j++) {
                if (h[i][j] == 'W') a[i][j] = 0;
                else a[i][j] = 1;
            }
        }
        for(int i = 0;i < n;i++) {
            ver[1][i] = inf;
            hor[1][i] = inf;
            for(int j = 0;j < n;j++) {
                if (a[i][j] == 1) hor[1][i] = j;
                if (a[j][i] == 1) ver[1][i] = j;
            }
            for(int j = n - 1;j >= 0;j--) {
                if (a[i][j] == 1) hor[0][i] = j;
                if (a[j][i] == 1) ver[0][i] = j;
            }
            if (hor[1][i] == inf) min_ans++;
            if (ver[1][i] == inf) min_ans++;
        }
    }

    static int solve() {
        int ans = 0;
        for(int i = 0;i + k <= n;i++) {
            segment_tree a = new segment_tree(n);
            int b[] = new int [n];
            for(int j = 0;j < n;j++) if (ver[0][j] >= i && ver[1][j] < i + k) b[j] = 1;
            int sum = 0;
            for(int j = 0;j < k;j++) sum += b[j];
            a.add(0, 0, sum);
            for(int j = k;j < n;j++) {
                sum += b[j] - b[j - k];
                a.add(j - k + 1, j - k + 1, sum);
            }
            for(int j = i;j < i + k;j++) {
                if (hor[1][j] - hor[0][j] > k) continue;
                a.add(hor[1][j] - k + 1, hor[0][j], 1);
            }
            ans = Math.max(ans, min_ans + a.get());
        }
        return ans;
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        scan();
        pw.println(solve());
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
    int push[];
    segment_tree(int n) {
        last = n - 1;
        max = new int [4 * n];
        push = new int [4 * n];
    }

    void pushing(int v) {
        push[v * 2 + 1] += push[v];
        push[v * 2 + 2] += push[v];
        max[v * 2 + 1] += push[v];
        max[v * 2 + 2] += push[v];
        push[v] = 0;
    }

    void add(int l, int r, int sum) {
        add(0, 0, last, l, r, sum);
    }

    void add(int v, int l, int r, int left, int right, int sum) {
        if (l > right || r < left) return;
        if (l >= left && r <= right) {
            max[v] += sum;
            push[v] += sum;
            return;
        }
        pushing(v);
        int m = ((l + r) >> 1);
        add(v * 2 + 1, l, m, left, right, sum);
        add(v * 2 + 2, m + 1, r, left, right, sum);
        max[v] = Math.max(max[v * 2 + 1], max[v * 2 + 2]);
    }

    int get() {
        return max[0];
    }
}