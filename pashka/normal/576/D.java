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
public class D {

    private int n;

    private void solve() throws IOException {
        n = nextInt();
        int m = nextInt();
        int[][] e = new int[m + 1][3];
        for (int i = 0; i < m; i++) {
            e[i][0] = nextInt() - 1;
            e[i][1] = nextInt() - 1;
            e[i][2] = nextInt();
        }
        e[m][0] = n - 1;
        e[m][1] = n - 1;
        e[m][2] = 2000000000;
        Arrays.sort(e, new Comparator<int[]>() {
            public int compare(int[] o1, int[] o2) {
                return Integer.compare(o1[2], o2[2]);
            }
        });

        boolean[] cur = new boolean[n];
        boolean[] next = new boolean[n];
        cur[0] = true;

        boolean[] a = new boolean[n * n];
        boolean[] pow = new boolean[n * n];
        boolean[] temp = new boolean[n * n];
        a[n * n - 1] = true;

        int t = 0;
        for (int i = 0; i <= m; i++) {
            int dt = e[i][2] - t;
            pow(a, temp, pow, dt);
            multV(cur, pow, next);
            if (next[n - 1]) {
                int l = -1;
                int r = dt;
                while (r > l + 1) {
                    int mm = (l + r) / 2;
                    pow(a, temp, pow, mm);
                    multV(cur, pow, next);
                    if (next[n - 1]) {
                        r = mm;
                    } else {
                        l = mm;
                    }
                }
                out.println(t + r);
                return;
            } else {
                boolean[] _ = cur; cur = next; next = _;
                a[e[i][0] * n + e[i][1]] = true;
                t = e[i][2];
            }
//            System.out.println(t + " " + Arrays.toString(cur));
        }
        out.println("Impossible");
    }

    private void multV(boolean[] cur, boolean[] a, boolean[] res) {
        Arrays.fill(res, false);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[j] |= cur[i] && a[i * n + j];
            }
        }
    }

    private void pow(boolean[] a, boolean[] temp, boolean[] res, int p) {
        if (p == 0) {
            Arrays.fill(res, false);
            for (int i = 0; i < n; i++) {
                res[i * n + i] = true;
            }
        } else {
            if (p % 2 == 0) {
                pow(a, res, temp, p / 2);
                mult(temp, temp, res);
            } else {
                pow(a, res, temp, p - 1);
                mult(a, temp, res);
            }
        }
    }

    private void mult(boolean[] a, boolean[] b, boolean[] res) {
        Arrays.fill(res, false);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) if (a[i * n + j]) {
                for (int k = 0; k < n; k++) if (b[j * n + k]) {
                    res[i * n + k] = true;
                }
            }
        }
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
        new D().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}