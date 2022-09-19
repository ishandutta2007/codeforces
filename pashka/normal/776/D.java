import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class D {

    private void solve() throws IOException {
        int m = nextInt();
        int n = nextInt();
        init(n, m);
        int[] st = new int[m];
        for (int i = 0; i < m; i++) {
            st[i] = 1 - nextInt();
        }
        int[] a = new int[m];
        int[] b = new int[m];
        Arrays.fill(a, -1);
        for (int i = 0; i < n; i++) {
            int k = nextInt();
            for (int j = 0; j < k; j++) {
                int x = nextInt() - 1;
                if (a[x] == -1) a[x] = i; else b[x] = i;
            }
        }
        for (int i = 0; i < m; i++) {
            addEdge(a[i], b[i], st[i]);
        }
        for (int i = 0; i < n; i++) {
            if (!z[i]) {
                if (!dfs(i, 0)) {
                    out.println("NO");
                    return;
                }
            }
        }
        out.println("YES");


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
        w = new int[m];
        ww = new int[n];
        Arrays.fill(head, -1);
        Arrays.fill(ww, -1);
        z = new boolean[n];
    }

    void addEdge(int x, int y, int ww) {
        nx[last] = head[x];
        src[last] = x;
        dst[last] = y;
        w[last] = ww;
        head[x] = last;
        last++;
        nx[last] = head[y];
        src[last] = y;
        dst[last] = x;
        w[last] = ww;
        head[y] = last;
        last++;
    }

    private boolean dfs(int x, int c) {
        if (z[x]) {
            return c == ww[x];
        }
        z[x] = true;
        ww[x] = c;
        int j = head[x];
        while (j >= 0) {
            int y = dst[j];
            if (!dfs(y, c ^ w[j])) {
                return false;
            }
            j = nx[j];
        }
        return true;
    }

    int n, m;
    int[] head;
    int[] nx;
    int[] src;
    int[] dst;
    int[] ww;
    int[] w;
    boolean[] z;
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
        new D().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}