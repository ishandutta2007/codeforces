import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class C {

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    PrintStream out = System.out;

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
        new C().solve();
    }

    private void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int d = nextInt();
        int[] a = new int[m];
        int[] b = new int[m];
        int[] t = new int[m];
        for (int i = 0; i < m; i++) {
            a[i] = nextInt() - 1;
            b[i] = nextInt();
            t[i] = nextInt();
        }
        long[] dd = new long[n];
        long[] dd2 = new long[n];
        for (int i = 0; i < n; i++) {
            dd[i] = b[0] - Math.abs(i - a[0]);
        }
        int[] q = new int[n];
//        System.out.println(Arrays.toString(dd));
        for (int i = 1; i < m; i++) {
            int dt = t[i] - t[i - 1];
            int dx = (int) Math.min(dt * 1L * d, n);
            int r = 0;
            int hh = 0;
            int tt = 1;
            q[0] = 0;
            for (int j = 0; j < n; j++) {
                while (tt > hh && q[hh] < j - dx) {
                    hh++;
                }
                while (r < j + dx && r < n - 1) {
                    r++;
                    while (tt > hh && dd[r] > dd[q[tt - 1]]) {
                        tt--;
                    }
                    q[tt] = r;
                    tt++;
                }
                dd2[j] = dd[q[hh]] + b[i] - Math.abs(j - a[i]);
            }
            long[] _ = dd;
            dd = dd2;
            dd2 = _;
//            System.out.println(Arrays.toString(dd));
        }
        long res = dd[0];
        for (int i = 0; i < n; i++) {
            res = Math.max(res, dd[i]);
        }
        out.println(res);
        out.close();

    }

}