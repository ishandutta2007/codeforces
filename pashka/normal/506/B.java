import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class B {

    private void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        init(n, m);
        for (int i = 0; i < m; i++) {
            addEdge(nextInt() - 1, nextInt() - 1);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (!z[i]) {
                pn = 0;
                dfs1(i);
                res += pn;
                boolean ok = true;
                for (int j = 0; j < pn; j++) {
                    if (dfs2(p[j])) {
                        ok = false;
                    }
                }
                if (ok) {
                    res--;
                }
            }
        }
        out.println(res);
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
        cp = new int[m];
        Arrays.fill(head, -1);
        z = new boolean[n];
        z2 = new int[n];
        p = new int[n];
    }

    void addEdge(int x, int y) {
        nx[last] = head[x];
        src[last] = x;
        dst[last] = y;
        cp[last] = 1;
        head[x] = last;
        last++;
        nx[last] = head[y];
        src[last] = y;
        dst[last] = x;
        cp[last] = 0;
        head[y] = last;
        last++;
    }


    private void dfs1(int x) {
        if (z[x]) return;
        p[pn++] = x;
        z[x] = true;
        int j = head[x];
        while (j >= 0) {
            int y = dst[j];
            dfs1(y);
            j = nx[j];
        }
    }

    private boolean dfs2(int x) {
        if (z2[x] == 1) return true;
        if (z2[x] == 2) return false;
        z2[x] = 1;
        int j = head[x];
        while (j >= 0) {
            int y = dst[j];
            if (cp[j] == 1) {
                if (dfs2(y)) return true;
            }
            j = nx[j];
        }
        z2[x] = 2;
        return false;
    }

    private static final long INF = Long.MAX_VALUE;

    int n, m;
    int[] head;
    int[] nx;
    int[] src;
    int[] dst;
    int[] cp;
    boolean[] z;
    int[] z2;
    int last;
    int[] p;
    int pn;

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
        new B().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}