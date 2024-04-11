import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class B {

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
        new B().solve();
    }

    private void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int q = nextInt();
        int[][] a = new int[n][m];
        for (int i = 0; i < n; i++) {
            String s = next();
            for (int j = 0; j < m; j++) {
                a[i][j] = s.charAt(j) - '0';
            }
        }
        int[][] sa = new int[n + 1][m + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                sa[i][j] = sa[i - 1][j] + sa[i][j - 1] - sa[i - 1][j - 1] + a[i - 1][j - 1];
            }
        }
        int[][][][] zz = new int[n][n][m][m];
        for (int t = 0; t < n; t++) {
            for (int b = t; b < n; b++) {
                for (int l = 0; l < m; l++) {
                    for (int r = l; r < m; r++) {
                        int s = sa[b + 1][r + 1] + sa[t][l] - sa[b + 1][l] - sa[t][r + 1];
                        if (s == 0) {
                            zz[t][b][l][r] = 1;
                        }
                    }
                }
            }
        }
        int[][][][] sz = new int[n + 1][n + 1][m + 1][m + 1];
        for (int t = n - 1; t >= 0; t--) {
            for (int b = 1; b <= n; b++) {
                for (int l = m - 1; l >= 0; l--) {
                    for (int r = 1; r <= m; r++) {
                        sz[t][b][l][r] = sz[t][b][l][r - 1] + zz[t][b - 1][l][r - 1];
                    }
                }
            }
        }
        for (int t = n - 1; t >= 0; t--) {
            for (int b = 1; b <= n; b++) {
                for (int l = m - 1; l >= 0; l--) {
                    for (int r = 1; r <= m; r++) {
                        sz[t][b][l][r] +=  sz[t][b][l + 1][r];
                    }
                }
            }
        }
        for (int t = n - 1; t >= 0; t--) {
            for (int b = 1; b <= n; b++) {
                for (int l = m - 1; l >= 0; l--) {
                    for (int r = 1; r <= m; r++) {
                        sz[t][b][l][r] +=  sz[t][b - 1][l][r];
                    }
                }
            }
        }
        for (int t = n - 1; t >= 0; t--) {
            for (int b = 1; b <= n; b++) {
                for (int l = m - 1; l >= 0; l--) {
                    for (int r = 1; r <= m; r++) {
                        sz[t][b][l][r] +=  sz[t + 1][b][l][r];
                    }
                }
            }
        }
        for (int i = 0; i < q; i++) {
            int t = nextInt() - 1;
            int l = nextInt() - 1;
            int b = nextInt();
            int r = nextInt();
            out.println(sz[t][b][l][r]);
        }
        out.close();

    }
}