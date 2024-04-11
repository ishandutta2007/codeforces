import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class F {

    private void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        if (m == 0) {
            out.println(1);
            return;
        }
        DFS dfs = new DFS();
        DFS dfs2 = new DFS();
        dfs.init(n, m + n);
        dfs2.init(m + 1, m);
        for (int i = 0; i < n; i++) {
            dfs.addEdge(i, (i + 1) % n);
        }
        for (int i = 0; i < m; i++) {
            int x = nextInt() - 1;
            int y = nextInt() - 1;
            dfs.addEdge(x, y);
        }
        dfs.sortEdges();
        int[][] comp = new int[m + 1][];
        int k = 0;
        for (int i = 0; i < dfs.m; i++) {
            if (!dfs.z[i]) {
                dfs.z[i] = true;
                int j = dfs.nx[i ^ 1];
                int q = 1;
                while (j != i) {
                    dfs.z[j] = true;
                    j = dfs.nx[j ^ 1];
                    q++;
                }
                if (q == n) {
                    continue;
                }
                comp[k] = new int[q + 1];
                comp[k][0] = dfs.dst[i];
                dfs.ccc[i] = k;
                j = dfs.nx[i ^ 1];
                q = 1;
                while (j != i) {
                    comp[k][q] = dfs.dst[j];
                    dfs.ccc[j] = k;
                    j = dfs.nx[j ^ 1];
                    q++;
                }
                Arrays.sort(comp[k]);
                {
                    int l = 0;
                    int r = q;
                    while (l < r) {
                        int t = comp[k][l];
                        comp[k][l] = comp[k][r];
                        comp[k][r] = t;
                        l++;
                        r--;
                    }
                }
                comp[k][q] = k;
                k++;
            }
        }
        for (int i = 0; i < dfs.m; i += 2) {
            int x = dfs.ccc[i];
            int y = dfs.ccc[i ^ 1];
            if (x != -1 && y != -1) {
                dfs2.addEdge(x, y);
            }
        }
        Arrays.sort(comp, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                for (int i = 0; i < o1.length; i++) {
                    if (o1[i] < o2[i]) {
                        return -1;
                    } else if (o1[i] > o2[i]) {
                        return 1;
                    }
                }
                return 0;
            }
        });
        build(dfs2, 0, 0);
        for (int i = 0; i < comp.length; i++) {
            out.println(dfs2.ccc[comp[i][comp[i].length - 1]] + 1);
        }
    }

    private void build(DFS dfs, int root, int c) {
        if (c >= 20) {
            throw new RuntimeException();
        }
        int w = dfs.dfs(root, -1, 1000000000);
        int cc = -dfs.dfs(root, -1, w / 2);
        dfs.ccc[cc] = c;
        int j = dfs.head[cc];
        while (j >= 0) {
            int y = dfs.dst[j];
            if (dfs.ccc[y] == -1) {
                build(dfs, y, c + 1);
            }
            j = dfs.nx[j];
        }
    }

    public class DFS {

        public int[] ccc;

        void init(int n, int m) {
            m *= 2;
            this.n = n;
            this.m = 0;
            head = new int[n];
            nx = new int[m];
            dst = new int[m];
            src = new int[m];
            ccc = new int[Math.max(n, m)];
            Arrays.fill(ccc, -1);
            Arrays.fill(head, -1);
            z = new boolean[Math.max(n, m)];
        }

        void addEdge(int x, int y) {
            nx[m] = head[x];
            src[m] = x;
            dst[m] = y;
            head[x] = m;
            m++;
            nx[m] = head[y];
            src[m] = y;
            dst[m] = x;
            head[y] = m;
            m++;
        }

        private int dfs(int x, int p, int sz) {
            int j = head[x];
            int s = 1;
            while (j >= 0) {
                int y = dst[j];
                if (y != p && ccc[y] == -1) {
                    int w = dfs(y, x, sz);
                    if (w <= 0) return w;
                    s += w;
                }
                j = nx[j];
            }
            if (s >= sz) return -x;
            else return s;
        }

        int n;
        int[] head;
        int[] nx;
        int[] src;
        int[] dst;
        boolean[] z;
        int m;

        public void sortEdges() {
            int[] temp = new int[n];
            for (int x = 0; x < n; x++) {
                int j = head[x];
                int c = 0;
                while (j >= 0) {
                    temp[c++] = j;
                    j = nx[j];
                }
                if (c > 0) {
                    sort(temp, 0, c - 1);
                    for (int i = 0; i < c - 1; i++) {
                        if (dst[temp[i + 1]] <= dst[temp[i]]) throw new RuntimeException();
                    }
                    for (int i = 0; i < c; i++) {
                        nx[temp[i]] = temp[(i + 1) % c];
                    }
                }
            }
        }

        public void sort(int[] a, int l, int r) {
            int x = dst[a[(l + r) / 2]];
            int i = l;
            int j = r;
            while (i <= j) {
                while (dst[a[i]] < x) i++;
                while (dst[a[j]] > x) j--;
                if (i <= j) {
                    int t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                    i++;
                    j--;
                }
            }
            if (i < r) sort(a, i, r);
            if (l < j) sort(a, l, j);
        }
    }
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
        new F().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}