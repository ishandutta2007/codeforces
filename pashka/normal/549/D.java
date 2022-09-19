import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class D {

    private void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int[][] a = new int[n][m];
        for (int i = 0; i < n; i++) {
            String s = next();
            for (int j = 0; j < m; j++) {
                a[i][j] = s.charAt(j) == 'W' ? 1 : -1;
            }
        }
        int res = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) if (a[i][j] != 0) {
                res++;
                int k = a[i][j];
                for (int ii = 0; ii <= i; ii++) {
                    for (int jj = 0; jj <= j; jj++) {
                        a[ii][jj] -= k;
                    }
                }
            }
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
        new D().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}