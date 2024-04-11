import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class C {

    private void solve() throws IOException {
        int n = nextInt();
        int[] a = new int[n];
        int m = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
            m = Math.min(m, a[i]);
        }
        int best = 0;
        int w = 1;
        for (int k = 1; k <= m; k++) {
            boolean ok = true;
            int ne = 0;
            int no = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] % k > 0) {
                    ok = false;
                    break;
                }
                if (a[i] / k % 2 == 1) {
                    no++;
                } else {
                    ne++;
                }
            }
            if (ok && no <= 1) {
                int res = k;
                if (no == 0) res *= 2;
                if (res > best) {
                    best = res;
                    w = k;
                }
            }
        }
        out.println(best);
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < n; j++) {
                int z = a[j] / w / 2;
                for (int t = 0; t < z; t++) {
                    out.print((char)('a' + j));
                }
            }
            for (int j = 0; j < n; j++) {
                int z = a[j] / w % 2;
                for (int t = 0; t < z; t++) {
                    out.print((char)('a' + j));
                }
            }
            for (int j = n - 1; j >= 0; j--) {
                int z = a[j] / w / 2;
                for (int t = 0; t < z; t++) {
                    out.print((char)('a' + j));
                }
            }
        }
        out.println();
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
        new C().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}