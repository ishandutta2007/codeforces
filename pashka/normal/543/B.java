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

        int s1 = nextInt() - 1;
        int t1 = nextInt() - 1;
        int l1 = nextInt();
        int s2 = nextInt() - 1;
        int t2 = nextInt() - 1;
        int l2 = nextInt();

        int[][] d = new int[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(z, false);
            this.d = d[i];
            bfs(i);
        }
        int res = 0;
        if (d[s1][t1] > l1 || d[s2][t2] > l2) {
            out.println(-1);
            return;
        }
        res = Math.max(res, m - d[s1][t1] - d[s2][t2]);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (d[s1][i] + d[i][j] + d[j][t1] <= l1 &&
                        d[s2][i] + d[i][j] + d[j][t2] <= l2)
                    res = Math.max(res, m - d[s1][i] - d[s2][i] - d[t1][j] - d[t2][j] - d[i][j]);
                if (d[s1][i] + d[i][j] + d[j][t1] <= l1 &&
                        d[t2][i] + d[i][j] + d[j][s2] <= l2)
                    res = Math.max(res, m - d[s1][i] - d[t2][i] - d[t1][j] - d[s2][j] - d[i][j]);
//                System.out.println(i + " " + j + " " + res);
            }
        }
        out.println(res);
    }

    private void bfs(int s) {
        int[] q = new int[n];
        q[0] = s;
        d[s] = 0;
        z[s] = true;
        int h = 0;
        int t = 1;
        while (t > h) {
            int i = q[h++];
            int j = head[i];
            while (j >= 0) {
                int y = dst[j];
                if (!z[y]) {
                    d[y] = d[i] + 1;
                    z[y] = true;
                    q[t++] = y;
                }
                j = nx[j];
            }
        }

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
        d = new int[n];
    }

    void addEdge(int x, int y) {
        nx[last] = head[x];
        src[last] = x;
        dst[last] = y;
        head[x] = last;
        last++;
        nx[last] = head[y];
        src[last] = y;
        dst[last] = x;
        head[y] = last;
        last++;
    }


    int n, m;
    int[] head;
    int[] nx;
    int[] src;
    int[] dst;
    boolean[] z;
    int[] d;
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
        new B().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}