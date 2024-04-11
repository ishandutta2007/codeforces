import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class F {

    private void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        boolean[][] a = new boolean[n][m];
        boolean[][] aa = new boolean[m][n];
        for (int i = 0; i < n; i++) {
            String s = next();
            for (int j = 0; j < m; j++) {
                aa[j][i] = a[i][j] = s.charAt(j) == '.';
            }
        }
        long s1 = calc(a, true);
        long s2 = calc(aa, false);
//        System.out.println(s1 + " " + s2);
        out.println(s1 + s2);
    }

    private long calc(boolean[][] a, boolean corners) {
        int n = a.length;
        int m = a[0].length;
        boolean[][] up = new boolean[n][m];
        up[0] = a[0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                up[i][j] = a[i][j] && up[i - 1][j];
            }
        }
        boolean[][] down = new boolean[n][m];
        down[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                down[i][j] = a[i][j] && down[i + 1][j];
            }
        }

        long res = 0;
        for (int i = 1; i < n - 1; i++) {
            int uu = 0;
            int dd = 0;
            int uuu = 0;
            int ddd = 0;
            for (int j = 1; j < m - 1; j++) {
                if (!a[i][j]) {
                    uu = 0; dd = 0; uuu = 0; ddd = 0;
                } else {
                    if (up[i][j]) res += (dd + uuu);
                    if (down[i][j]) res += (uu + ddd);
                    uuu = uu; ddd = dd;
                    if (up[i][j]) uu++;
                    if (down[i][j]) dd++;
                }
            }
        }
//        System.out.println(res);
        for (int j = 1; j < m - 1; j++) {
            if (down[0][j]) res++;
        }
//        System.out.println(res);
        if (corners) {
            for (int i = 1; i < n - 1; i++) {
                if (a[i][0]) for (int j = 1; j < m - 1; j++) {
                    if (!a[i][j]) break;
                    if (up[i][j]) res++;
                    if (down[i][j]) res++;
                }
                if (a[i][m - 1]) for (int j = m - 2; j >= 1; j--) {
                    if (!a[i][j]) break;
                    if (up[i][j]) res++;
                    if (down[i][j]) res++;
                }
            }
//            System.out.println(res);
        }
        return res;
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
        new F().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}