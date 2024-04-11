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
        String[] s = new String[n];
        for (int i = 0; i < n; i++) {
            s[i] = next();
        }
        int[][] a = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = nextInt();
            }
        }
        int[][] d = new int[m][26];
        int[][] q = new int[m][26];
        int[][] w = new int[m][26];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                d[j][s[i].charAt(j) - 'a'] += (1 << i);
                q[j][s[i].charAt(j) - 'a'] += a[i][j];
                w[j][s[i].charAt(j) - 'a'] = Math.max(w[j][s[i].charAt(j) - 'a'], a[i][j]);
            }
        }
        int[] z = new int[1 << n];
        for (int x = 1; x < (1 << n); x++) {
            z[x] = Integer.MAX_VALUE;
            int i = 0;
            while ((x & (1 << i)) == 0) i++;
            for (int j = 0; j < m; j++) {
                z[x] = Math.min(z[x], z[x - (1 << i)] + a[i][j]);
                int c = s[i].charAt(j) - 'a';
//                if ((x & d[j][c]) == d[j][c]) {
//                    z[x] = Math.min(z[x], z[x - d[j][c]] + q[j][c] - w[j][c]);
//                }
                z[x] = Math.min(z[x], z[x & (~d[j][c])] + q[j][c] - w[j][c]);
            }
        }
        out.println(z[(1 << n) - 1]);
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