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

    private int[] p;

    private void solve() throws IOException {
        int n = nextInt();
        int q = nextInt();
        init(n);
        p = new int[n];
        p[0] = -1;
        for (int i = 0; i < n - 1; i++) {
            p[i + 1] = nextInt() - 1;
            addEdge(i + 1, p[i + 1]);
        }
        dfs(0, -1);
        for (int i = 0; i < q; i++) {
            int x = nextInt() - 1;
            out.println(c[x] + 1);
        }
    }

    void init(int n) {
        this.n = n;
        this.m = (n - 1) * 2;
        last = 0;
        head = new int[n];
        nx = new int[m];
        dst = new int[m];
        d = new int[n];
        c = new int[n];
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
        d[x] = 1;
        int my = -1;
        int j = head[x];
        while (j >= 0) {
            int y = dst[j];
            if (y != p) {
                dfs(y, x);
                d[x] += d[y];
                if (my == -1 || d[y] > d[my]) {
                    my = y;
                }
            }
            j = nx[j];
        }
        if (my == -1 || d[my] * 2 <= d[x]) {
            c[x] = x;
        } else {
            int z = c[my];
            while ((d[x] - d[z]) * 2 > d[x]) {
                z = this.p[z];
            }
            c[x] = z;
        }
        return 0;
    }

    int n, m;
    int[] head;
    int[] nx;
    int[] dst;
    int[] d;
    int[] c;
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