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

    private static final int MOD = (int) (1e9+7);
    public static final int N = 7;
    public static final int NN = 128;

    private void solve() throws IOException {
        int[] w = new int[N];
        for (int i = 0; i < N; i++) {
            w[i] = nextInt();
        }
        int[] start = new int[2];
        start[1] = 1;
        int[] a = start;
        for (int h = 0; h < N; h++) if (w[h] > 0) {
            int nn = (1 << (h + 1));
            {
                int[] aa = new int[nn];
                for (int i = 0; i < a.length; i++) {
                    aa[i - a.length + nn] = a[i];
                }
                a = aa;
            }
            int[][] q = new int[nn][];
            int[] t = new int[nn];
            for (int i = 0; i < nn; i++) {
                t[i] = 1;
                q[i] = add(t, h + 1);
                t[i] = 0;
            }
            q = pow(q, w[h]);
            int[] aa = new int[nn];
            for (int i = 0; i < nn; i++) {
                for (int j = 0; j < nn; j++) {
                    aa[j] = (int) ((aa[j] + 1l * a[i] * q[i][j]) % MOD);
                }
            }
            a = aa;
        }
        out.println(a[a.length - 1]);
    }

    private int[][] pow(int[][] a, int b) {
        int n = a.length;
        if (b == 0) {
            int[][] res = new int[n][n];
            for (int i = 0; i < n; i++) {
                res[i][i] = 1;
            }
            return res;
        }
        if (b % 2 == 0) {
            int[][] aa = mult(a, a);
            return pow(aa, b / 2);
        } else {
            int[][] aa = pow(a, b - 1);
            return mult(aa, a);
        }
    }

    private int[][] mult(int[][] a, int[][] b) {
        int n = a.length;
        int[][] c = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    c[i][k] = (int) ((c[i][k] + 1l * a[i][j] * b[j][k]) % MOD);
                }
            }
        }
        return c;
    }

    private int[] add(int[] a, int n) {
        int nn = (1 << (n + 1));
        int[][] d = new int[n + 1][nn];
        for (int i = 0; i < nn / 2; i++) {
            d[0][(i << 1) + 1] = a[i + a.length - (1 << n)];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < nn; j++) if (d[i][j] > 0) {
                int q = (j >> i) & 3;
                for (int k = 0; k < 4; k++) {
                    if (q == 3 && k == 3) continue;
                    int jj = (j - (q << i) + (k << i));
                    d[i + 1][jj] += d[i][j];
                    while (d[i + 1][jj] >= MOD) {
                        d[i + 1][jj] -= MOD;
                    }
                }
            }
        }
        int[] res = new int[a.length];
        for (int i = 0; i < (1 << n); i++) {
            res[i + a.length - (1 << n)] = d[n][i + (1 << n)];
        }
        return res;
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