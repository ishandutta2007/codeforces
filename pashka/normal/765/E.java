import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class E {

    private void solve() throws IOException {
        int n = nextInt();
        init(n);
        for (int i = 0; i < n - 1; i++) {
            int x = nextInt() - 1;
            int y = nextInt() - 1;
            addEdge(x, y);
        }
        dfs(0, -1);
        int a = 0;
        for (int i = 0; i < n; i++) {
            if (h[i] > h[a]) a = i;
        }
        dfs(a, -1);
        int b = 0;
        for (int i = 0; i < n; i++) {
            if (h[i] > h[b]) b = i;
        }
        int c = b;
        for (int i = 0; i < h[b] / 2; i++) {
            c = pp[c];
        }

//        System.out.println(a + " " + b + " " + c);

        dfs2(c, -1);
//        System.out.println(Arrays.toString(pp));
//        System.out.println(Arrays.toString(h));
        if (pp[c] == 1) {
            int res = h[c];
            while (res % 2 == 0)
                res /= 2;
            out.println(res);
        } else {
            int aa = -1;
            int bb = -1;
            int j = head[c];
            while (j >= 0) {
                int y = dst[j];
                if (pp[y] == 0) {
                    out.println(-1);
                    return;
                }
                if (aa == -1) {
                    aa = h[y];
                } else if (h[y] != aa) {
                    if (bb == -1) {
                        bb = h[y];
                    } else if (h[y] != bb) {
                        out.println(-1);
                        return;
                    }
                }
                j = nx[j];
            }
            int res = aa + bb + 2;
            while (res % 2 == 0)
                res /= 2;
            out.println(res);
        }
    }

    void init(int n) {
        this.n = n;
        this.m = (n - 1) * 2;
        last = 0;
        head = new int[n];
        nx = new int[m];
        dst = new int[m];
        h = new int[n];
        pp = new int[n];
        Arrays.fill(head, -1);
    }


    void addEdge(int x, int y) {
        nx[last] = head[x];
        dst[last] = y;
        head[x] = last;
        last++;
        nx[last] = head[y];
        dst[last] = x;
        head[y] = last;
        last++;
    }

    private int dfs(int x, int p) {
        pp[x] = p;
        h[x] = p == -1 ? 0 : h[p] + 1;
        int j = head[x];
        while (j >= 0) {
            int y = dst[j];
            if (y != p) {
                dfs(y, x);
            }
            j = nx[j];
        }
        return 0;
    }

    private int dfs2(int x, int p) {
        int j = head[x];
        boolean first = true;
        while (j >= 0) {
            int y = dst[j];
            if (y != p) {
                dfs2(y, x);
                if (first) {
                    pp[x] = pp[y];
                    h[x] = h[y] + 1;
                    first = false;
                } else {
                    if (pp[y] == 0 || pp[x] == 0 || h[x] != h[y] + 1) {
                        pp[x] = 0;
                    }
                }
            }
            j = nx[j];
        }
        if (first) {
            pp[x] = 1;
            h[x] = 0;
        }
        return 0;
    }

    int n, m;
    int[] head;
    int[] nx;
    int[] dst;
    int[] h;
    int[] pp;
    int last;


    // ------------------

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
        new E().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}