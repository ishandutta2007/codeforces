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
        int m = nextInt();
        int[] d = new int[m];
        int[] h = new int[m];
        for (int i = 0; i < m; i++) {
            d[i] = nextInt();
            h[i] = nextInt();
        }
        int res = Math.max(
                h[0] + d[0] - 1,
                h[m - 1] + n - d[m - 1]
        );
        for (int i = 0; i < m - 1; i++) {
            int h1 = h[i];
            int h2 = h[i + 1];
            int dd = d[i + 1] - d[i];
            if (h2 < h1) {
                int t = h1;
                h1 = h2;
                h2 = t;
            }
            int dh = h2 - h1;
            if (dh % 2 != dd % 2) {
                dd--;
            }
            int a = (dd + dh) / 2;
            int b = dd - a;
            if (a >= 0 && b >= 0) {
                res = Math.max(res, h1 + a);
            } else {
                out.println("IMPOSSIBLE");
                return;
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
        new C().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}