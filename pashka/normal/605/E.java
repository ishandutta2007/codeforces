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

    public static final double INF = 1e100;

    private void solve() throws IOException {
        int n = nextInt();
        double[][] a = new double[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = nextInt() * 0.01;
            }
        }
        double[] d = new double[n];
        Arrays.fill(d, INF);
        d[n - 1] = 0;
        boolean[] z = new boolean[n];
        double[] pp = new double[n];
        double[] s = new double[n];
        Arrays.fill(pp, 1);
        for (int i = 0; i < n; i++) {
            int x = 0;
            double min = INF;
            for (int j = 0; j < n; j++) {
                if (!z[j] && d[j] < min) {
                    min = d[j];
                    x = j;
                }
            }
//            System.out.println(x);
//            System.out.println(Arrays.toString(d));
            if (min == INF) break;
            z[x] = true;
            for (int y = 0; y < n; y++) {
                if (!z[y]) {
                    s[y] += a[y][x] * pp[y] * (d[x] + 1);
                    pp[y] *= (1 - a[y][x]);
                    if (pp[y] < 1) {
                        d[y] = (pp[y] + s[y]) / (1 - pp[y]);
                    }
                }
            }
        }
//        System.out.println(Arrays.toString(d));
        out.println(d[0]);


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