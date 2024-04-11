import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class A {

    private void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int b = nextInt();
        int mod = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        int[][][] d = new int[2][m + 1][b + 1];
        d[0][0][0] = 1;
        for (int i = 1; i <= n; i++) {
            int ii = i % 2;
            for (int[] ints : d[ii]) {
                Arrays.fill(ints, 0);
            }
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= b; k++) {
                    d[ii][j][k] = d[1 - ii][j][k];
                    if (j > 0 && k >= a[i - 1]) {
                        d[ii][j][k] += d[ii][j - 1][k - a[i - 1]];
                        while (d[ii][j][k] >= mod) {
                            d[ii][j][k] -= mod;
                        }
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i <= b; i++) {
            res += d[n % 2][m][i];
            res %= mod;
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
        new A().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}