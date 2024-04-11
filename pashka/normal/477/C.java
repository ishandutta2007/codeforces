import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class C {

    private void solve() throws IOException {
        String s = next();
        String p = next();
        int n = s.length();
        int m = p.length();
        int[] r = new int[n + 1];
        Arrays.fill(r, -1);

        for (int i = 0; i < n; i++) {
            int k = 0;
            int x = 0;
            for (int j = i; j < n; j++) {
                if (s.charAt(j) == p.charAt(k)) {
                    k++;
                }
                if (k == m) {
                    x = j + 1;
                    break;
                }
            }
            if (k == m) {
                for (int j = x; j <= n; j++) {
                    r[j] = i;
                }
            }
        }
        int[][] d = new int[n + 1][n + 1];
        Arrays.fill(d[0], Integer.MIN_VALUE);
        d[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            Arrays.fill(d[i], Integer.MIN_VALUE);
            for (int j = 0; j <= i; j++) {
                d[i][j] = d[i - 1][j];
            }
            for (int j = 1; j <= i; j++) {
                d[i][j] = Math.max(d[i][j], d[i - 1][j - 1]);
            }
            if (r[i] != -1) {
                int ii = r[i];
                int x = (i - ii) - p.length();
                for (int j = x; j <= i; j++) {
                    d[i][j] = Math.max(d[i][j], d[ii][j - x] + 1);
                }
            }
        }
        for (int j = 0; j <= n; j++) {
            out.print(d[n][j] + " ");
        }

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