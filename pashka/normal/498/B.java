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
        double[] p = new double[n];
        int[] t = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = nextInt() * 0.01;
            t[i] = nextInt();
        }
        double[][] d = new double[2][m + 1];
        double[][] d2 = new double[2][m + 1];
        d[0][0] = 1;
        d2[0][0] = 1;
        double res = 0;
        for (int i = 0; i <= n; i++) {
            int i1 = i % 2;
            int i2 = (i + 1) % 2;
            double pp = i == n ? 0 : Math.pow(1 - p[i], t[i]);
            for (int j = 0; j < m; j++) {
                if (i == n) {
                    d[i1][j + 1] += d[i1][j];
                } else {
                    int jj = j + t[i];
                    if (jj <= m) {
                        d[i1][jj] -= d2[i1][j] * pp;
                        d[i2][jj] += d2[i1][j] * pp;
                        d2[i2][jj] += d2[i1][j] * pp;
                    }
                    d[i2][j + 1] += d[i1][j] * p[i];
                    d2[i2][j + 1] += d[i1][j] * p[i];
                    d[i1][j + 1] += d[i1][j] * (1 - p[i]);
                }
            }
            res += i * d[i1][m];
            Arrays.fill(d[i1], 0);
            Arrays.fill(d2[i1], 0);
        }

        out.println(res);
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
        new B().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}