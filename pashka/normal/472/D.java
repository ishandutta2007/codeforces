import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Random;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class D {

    int[][] a;
    int[] d;

    private void solve() throws IOException {
        int n = nextInt();
        a = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = nextInt();
            }
        }
        for (int i = 0; i < n; i++) {
            if (a[i][i] > 0) {
                out.println("NO");
                return;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] != a[j][i]) {
                    out.println("NO");
                    return;
                }
                if (i != j && a[i][j] == 0) {
                    out.println("NO");
                    return;
                }
            }
        }
        int[][] b = new int[n * (n - 1) / 2][3];
        int c = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j < i) {
                    b[c][0] = a[i][j];
                    b[c][1] = i;
                    b[c][2] = j;
                    c++;
                }
            }
        }
        Arrays.sort(b, new Comparator<int[]>() {
            public int compare(int[] o1, int[] o2) {
                return Integer.compare(o1[0], o2[0]);
            }
        });
        p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
        init(n, n);
        for (int i = 0; i < c; i++) {
            int x = b[i][1];
            int y = b[i][2];
            if (get(x) != get(y)) {
                addEdge(x, y, a[x][y]);
                join(x, y);
            }
        }
        for (int i = 0; i < n; i++) {
            d = a[i];
            if (!dfs(i, -1, 0)) {
                out.println("NO");
                return;
            }
        }
        out.println("YES");
    }

    Random r = new Random(2334645756756534L);

    private void join(int x, int y) {
        x = get(x); y = get(y);
        if (r.nextBoolean()) {
            p[x] = y;
        } else {
            p[y] = x;
        }
    }

    private int get(int x) {
        if (p[x] != x) {
            p[x] = get(p[x]);
        }
        return p[x];
    }

    int[] p;



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

    private boolean dfs(int x, int p, int c) {
        int j = head[x];
        while (j >= 0) {
            int y = dst[j];
            if (y != p) {
                if (d[y] != 0l + c + val[j]) return false;
                if (!dfs(y, x, c + val[j])) {
                    return false;
                }
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
    int[] val;
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
        new D().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}