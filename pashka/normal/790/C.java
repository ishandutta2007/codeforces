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
        int n = nextInt();
        String s = next();
        int[][] a = new int[3][n];
        int[] na = new int[3];
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == 'V') {
                a[0][na[0]++] = i;
            } else if (s.charAt(i) == 'K') {
                a[1][na[1]++] = i;
            } else {
                a[2][na[2]++] = i;
            }
        }
        int[][][][] d = new int[na[0] + 1][na[1] + 1][na[2] + 1][2];
        for (int[][][] ints : d) {
            for (int[][] anInt : ints) {
                for (int[] ints1 : anInt) {
                    Arrays.fill(ints1, Integer.MAX_VALUE);
                }
            }
        }
        int[][][] p = new int[3][3][n];
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) if (x != y) {
                for (int i = 0; i < na[x]; i++) {
                    for (int j = 0; j < na[y]; j++) {
                        if (a[y][j] < a[x][i]) p[x][y][i]++;
                    }
                }
            }
        }
//        for (int x = 0; x < 3; x++) {
//            for (int i = 0; i < na[x]; i++) {
//                System.out.println(x + " " + i + " " + p[x][i]);
//            }
//        }
        d[0][0][0][1] = 0;
        for (int i = 0; i <= na[0]; i++) {
            for (int j = 0; j <= na[1]; j++) {
                for (int k = 0; k <= na[2]; k++) {
                    for (int q = 0; q < 2; q++) if (d[i][j][k][q] != Integer.MAX_VALUE) {
//                        System.out.println(i + " " + j + " " + k + " " + q + " " + d[i][j][k][q]);
                        if (i < na[0]) {
                            d[i + 1][j][k][0] = Math.min(d[i + 1][j][k][0], d[i][j][k][q] + Math.max(p[0][1][i] - j, 0) + Math.max(p[0][2][i] - k, 0));
                        }
                        if (j < na[1] && q == 1) {
                            d[i][j + 1][k][1] = Math.min(d[i][j + 1][k][1], d[i][j][k][q] + Math.max(p[1][0][j] - i, 0) + Math.max(p[1][2][j] - k, 0));
                        }
                        if (k < na[2]) {
                            d[i][j][k + 1][1] = Math.min(d[i][j][k + 1][1], d[i][j][k][q] + Math.max(p[2][0][k] - i, 0) + Math.max(p[2][1][k] - j, 0));
                        }
                    }
                }
            }
        }
        out.println(Math.min(d[na[0]][na[1]][na[2]][0], d[na[0]][na[1]][na[2]][1]));
    }

    // ------------------

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