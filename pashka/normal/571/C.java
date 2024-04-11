import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class C {

    private void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        init(n, m);
        int[] t = new int[m];
        boolean[] res = new boolean[m];
        Arrays.fill(res, true);
        for (int i = 0; i < n; i++) {
            int k = nextInt();
            for (int j = 0; j < k; j++) {
                int x = nextInt();
                int xx = Math.abs(x) - 1;
                int s = Integer.signum(x);
                if (t[xx] == 0) {
                    t[xx] = s * (i + 1);
                } else {
                    int ii = Math.abs(t[xx]) - 1;
                    int ss = Integer.signum(t[xx]);
                    // i, s -- ii, ss
                    if (s == ss) {
                        res[xx] = (s == 1);
                        mk[i] = true;
                        mk[ii] = true;
                        continue;
                    }
                    if (s == -1) {
                        addEdge(i, ii, xx);
                    } else {
                        addEdge(ii, i, xx);
                    }
                    t[xx] = n + 1;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            if (t[i] != 0 && t[i] != n + 1) {
                int x = Math.abs(t[i]) - 1;
                res[i] = (t[i] > 0);
                mk[x] = true;
            }
        }
        for (int i = 0; i < n; i++) {
            if (!z[i]) {
                dfs(i, -1);
                if (!mk[i]) {
                    out.println("NO");
                    return;
                }
            }
        }
        for (int i = 0; i < this.m; i++) {
            if (mkE[i]) {
                res[ids[i]] = (i % 2 == 0);
            }
        }
        out.println("YES");
        for (int i = 0; i < m; i++) {
            out.print(res[i] ? "1" : "0");
        }
        out.println();

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
        Arrays.fill(head, -1);
        z = new boolean[n];
        mk = new boolean[n];
        mkE = new boolean[m];
        ids = new int[m];
    }

    void addEdge(int x, int y, int id) {
        nx[last] = head[x];
        src[last] = x;
        dst[last] = y;
        ids[last] = id;
        head[x] = last;

        last++;
        nx[last] = head[y];
        src[last] = y;
        dst[last] = x;
        ids[last] = id;
        head[y] = last;
        last++;
    }


    private void dfs(int x, int lE) {
        z[x] = true;
        int j = head[x];
        while (j >= 0) {
            if ((j ^ 1) != lE) {
                int y = dst[j];
                if (z[y]) {
                    if (!mkE[j ^ 1]) {
                        mk[y] = true;
                        mkE[j] = true;
                    }
                } else {
                    dfs(y, j);
                    if (mk[y]) {
                        mkE[j ^ 1] = true;
                        mk[x] = true;
                    } else {
                        mkE[j] = true;
                    }
                }
            }
            j = nx[j];
        }
    }

    int n, m;
    int[] head;
    int[] nx;
    int[] src;
    int[] dst;
    boolean[] z;
    boolean[] mk;
    boolean[] mkE;
    int[] ids;
    int last;





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
        new C().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}