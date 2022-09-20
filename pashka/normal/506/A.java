import org.omg.PortableInterceptor.INACTIVE;

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
        int n = 30001;
        int m = nextInt();
        int d = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < m; i++) {
            a[nextInt()]++;
        }
        int maxd = d;
        {
            int k = d;
            while (k < n) {
                maxd++;
                k += maxd;
            }
        }
        int mind = d;
        {
            int k = d;
            while (mind > 1 && k < n) {
                mind--;
                k += mind;
            }
        }
        int dd = maxd - mind + 1;
        int[][] q = new int[n][dd];
        for (int[] ints : q) {
            Arrays.fill(ints, Integer.MIN_VALUE);
        }
        q[d][d - mind] = a[d];
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < dd; j++) if (q[i][j] > Integer.MIN_VALUE) {
                res = Math.max(res, q[i][j]);
                for (int jj = j - 1; jj <= j + 1; jj++) {
                    if (jj >= 0) {
                        int ii = i + (mind + jj);
                        if (ii < n) {
                            q[ii][jj] = Math.max(q[ii][jj], q[i][j] + a[ii]);
                        }
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
        new A().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}