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
        init(n, n - 1);
        for (int i = 0; i < n - 1; i++) {
            addEdge(nextInt() - 1, nextInt() - 1);
        }
        dfs(0, -1, 0);
        out.println(leafN - q1[0] + 1);
        out.println(q2[0]);
    }

    int leafN;

    void init(int n, int m) {
        m *= 2;
        this.n = n;
        this.m = m;
        last = 0;
        head = new int[n];
        nx = new int[m];
        dst = new int[m];
        q1 = new int[n];
        q2 = new int[n];
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

    private int dfs(int x, int p, int st) {
        int j = head[x];
        if (st == 0) {
            q1[x] = Integer.MAX_VALUE;
        } else {
            q2[x] = Integer.MAX_VALUE;
        }
        boolean leaf = true;
        while (j >= 0) {
            int y = dst[j];
            if (y != p) {
                leaf = false;
                dfs(y, x, 1 - st);
                if (st == 0) {
                    q1[x] = Math.min(q1[x], q1[y]);
                    q2[x] += q2[y];
                } else {
                    q1[x] += q1[y];
                    q2[x] = Math.min(q2[x], q2[y]);
                }
            }
            j = nx[j];
        }
        if (leaf) {
            leafN++;
            q1[x] = 1;
            q2[x] = 1;
        }
        return 0;
    }

    int n, m;
    int[] head;
    int[] nx;
    int[] dst;
    int last;
    int[] q1;
    int[] q2;


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