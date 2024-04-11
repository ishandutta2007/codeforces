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
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        Arrays.sort(a);
        int lo = 0;
        int hi = n / 3 + 1;
        int[][] res = null;
        while (hi > lo + 1) {
            int m = (lo + hi) / 2;
            int[][] r = new int[3][m];
            int k = 0;
            boolean ok = true;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < m; j++) {
                    while (k < n && (i > 0 && a[k] == r[i - 1][j])) k++;
                    if (k == n) {
                        ok = false;
                        break;
                    }
                    r[i][j] = a[k++];
                }
                if (!ok) break;
            }
            if (ok) {
                lo = m;
                res = r;
            } else {
                hi = m;
            }
        }
        out.println(lo);
        for (int i = 0; i < lo; i++) {
            out.println(res[2][i] + " " + res[1][i] + " " + res[0][i]);
        }
        out.close();

    }


}