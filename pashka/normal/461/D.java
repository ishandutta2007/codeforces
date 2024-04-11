import java.io.*;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class D {

    private static final long MOD = 1000000007;
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    PrintWriter out = new PrintWriter(System.out);

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static void main(String[] args) throws IOException {
        new D().solve();
    }

    private void solve() throws IOException {
//        int n = 29;
//        int[][] z = new int[n][n];
//        z[0][10] = 1;
//        for (int i = 1; i < n; i++) {
//            for (int j = 0; j < n; j++) {
//                if (i > 1) z[i][j] ^= z[i - 2][j];
//                if (j > 0) z[i][j] ^= z[i - 1][j - 1];
//                if (j < n - 1) z[i][j] ^= z[i - 1][j + 1];
//            }
//        }
//        for (int i = 0; i < n; i++) {
//            System.out.println(Arrays.toString(z[i]));
//        }
        int n = nextInt();
        int k = nextInt();
        int[] l = new int[k];
        int[] r = new int[k];
        int[] c = new int[k];
        for (int i = 0; i < k; i++) {
            int a = nextInt() - 1;
            int b = nextInt() - 1;
            l[i] = b - a;
            r[i] = b + a;
            if (l[i] < 0) {
                l[i] = -l[i];
            }
            if (r[i] >= n) {
                r[i] = n + n - 2 - r[i];
            }
            c[i] = next().equals("o") ? 1 : 0;
//            System.out.println(l[i] + " " + r[i] + " " + c[i]);
        }
        long res = 1;
        for (int d = 0; d < 2; d++) {
            int nn = (n + 1 - d) / 2;
//            System.out.println(nn);
            init(nn + 1, k);
            for (int i = 0; i < k; i++) {
                if ((l[i] & 1) == d) {
                    int ll = l[i] / 2;
                    int rr = r[i] / 2;
//                    System.out.println(ll + " " + rr + " " + c[i]);
                    addEdge(ll, rr + 1, c[i]);
                }
            }
            for (int i = 0; i <= nn; i++)
                if (!z[i]) {
                    if (!dfs(i, 0)) {
                        res = 0;
                    } else {
                        if (i > 0) {
                            res *= 2;
                            res %= MOD;
                        }
                        
                    }
                }
        }
        out.println(res);
        out.close();
    }

    void init(int n, int m) {
        m *= 2;
        this.n = n;
        this.m = m;
        last = 0;
        head = new int[n];
        nx = new int[m];
        dst = new int[m];
        src = new int[m];
        val = new int[m];
        Arrays.fill(head, -1);
        z = new boolean[n];
        color = new int[n];
    }

    void addEdge(int x, int y, int v) {
        nx[last] = head[x];
        src[last] = x;
        dst[last] = y;
        val[last] = v;
        head[x] = last;
        last++;
        nx[last] = head[y];
        src[last] = y;
        dst[last] = x;
        val[last] = v;
        head[y] = last;
        last++;
    }

    private boolean dfs(int x, int c) {
        if (z[x]) {
            return color[x] == c;
        }
        z[x] = true;
        color[x] = c;
        int j = head[x];
        while (j >= 0) {
            int y = dst[j];
            boolean res = dfs(y, (c + val[j]) % 2);
            if (!res) return false;
            j = nx[j];
        }
        return true;
    }

    int n, m;
    int[] head;
    int[] nx;
    int[] src;
    int[] dst;
    int[] val;
    int[] color;
    boolean[] z;
    int last;


}