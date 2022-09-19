import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class D {

    private void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        boolean[][] a = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            String s = next();
            for (int j = 0; j < m; j++) {
                a[i][j] = s.charAt(j) == '*';
            }
//            System.out.println(Arrays.toString(a[i]));
        }

        boolean[][] z = new boolean[n][m];
        int[] qx = new int[n * m];
        int[] qy = new int[n * m];
        int h = 0;
        int t = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] && bad(a, i, j)) {
                    qx[t] = i;
                    qy[t] = j;
                    t++;
                    a[i][j] = false;
                    z[i][j] = true;
                }
            }
        }
//        System.out.println(t);
        while (t > h) {
            int i = qx[h];
            int j = qy[h];
            h++;
            for (int d = 0; d < 8; d++) {
                int ii = i + dx[d];
                int jj = j + dy[d];
                if (ii >= 0 && ii < a.length && jj >= 0 && jj < a[0].length) {
                    if (a[ii][jj] && !z[ii][jj] && bad(a, ii, jj)) {
                        qx[t] = ii;
                        qy[t] = jj;
                        t++;
                        a[ii][jj] = false;
                        z[ii][jj] = true;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j]) {
                    out.print("*");
                } else {
                    out.print(".");
                }
            }
            out.println();
        }

    }

    int[] dx = {-1, 0, 1, 0, 1, 1, -1, -1};
    int[] dy = {0, -1, 0, 1, 1, -1, 1, -1};

    private boolean bad(boolean[][] a, int i, int j) {
//        int q = 0;
//        for (int d = 0; d < 4; d++) {
//            int ii = i + dx[d];
//            int jj = j + dy[d];
//            if (ii >= 0 && ii < a.length && jj >= 0 && jj < a[0].length && !a[ii][jj]) {
//                q++;
//            }
//        }
        for (int d = 0; d < 4; d++) {
            int ii = i + dx[d];
            int jj = j + dy[d];
            if (ii >= 0 && ii < a.length && jj >= 0 && jj < a[0].length && !a[ii][jj]) {
                ii = i + dx[(d + 1) % 4];
                jj = j + dy[(d + 1) % 4];
                if (ii >= 0 && ii < a.length && jj >= 0 && jj < a[0].length && !a[ii][jj]) {
                    ii += dx[d];
                    jj += dy[d];
                    if (!a[ii][jj]) {
                        return true;
                    }
                }
            }
        }
        return false;
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