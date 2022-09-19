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
public class E {

    private int[] l;
    private int[] r;
    private int[] s;
    private int[] t;
    private int[] p;

    private void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int q = nextInt();
        int[] x = new int[m];
        int[] y = new int[m];
        for (int i = 0; i < m; i++) {
            x[i] = nextInt() - 1;
            y[i] = nextInt() - 1;
        }
        l = new int[q];
        r = new int[q];
        s = new int[q];
        t = new int[q];
        p = new int[q];
        for (int i = 0; i < q; i++) {
            l[i] = nextInt() - 1;
            r[i] = nextInt() - 1;
            s[i] = nextInt() - 1;
            t[i] = nextInt() - 1;
            p[i] = i;
        }
        sort(0, q - 1);

        int[][] d = new int[n][n];
        for (int[] ints : d) {
            Arrays.fill(ints, m);
        }
        int cq = 0;
        boolean[] res = new boolean[q];
        for (int j = 0; j < n; j++) {
            d[j][j] = 0;
        }
        for (int i = m - 1; i >= 0; i--) {
            int[] xx = d[x[i]];
            int[] yy = d[y[i]];
            for (int j = 0; j < n; j++) {
                int a = xx[j];
                int b = yy[j];
                xx[j] = yy[j] = a < b ? a : b;
            }
            xx[y[i]] = i;
            yy[x[i]] = i;
            while (cq < q && l[p[cq]] == i) {
                res[p[cq]] = d[s[p[cq]]][t[p[cq]]] <= r[p[cq]];
                cq++;
            }
        }
        for (int i = 0; i < q; i++) {
            out.println(res[i] ? "Yes" : "No");
        }
    }

    Random random = new Random();

    private void sort(int l, int r) {
        int i = l;
        int j = r;
        int xx = this.l[p[l + random.nextInt(r - l + 1)]];
        while (i <= j) {
            while (this.l[p[i]] > xx) i++;
            while (this.l[p[j]] < xx) j--;
            if (i <= j) {
                int t = p[i]; p[i] = p[j]; p[j] = t;
                i++; j--;
            }
        }
        if (i < r) sort(i, r);
        if (l < j) sort(l, j);
    }


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