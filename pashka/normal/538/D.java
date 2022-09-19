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
        char[][] a = new char[n][n];
        for (int i = 0; i < n; i++) {
            String s = next();
            for (int j = 0; j < n; j++) {
                a[i][j] = s.charAt(j);
            }
        }
        boolean[][] mv = new boolean[2 * n][2 * n];
        for (boolean[] booleans : mv) {
            Arrays.fill(booleans, true);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) if (a[i][j] == '.') {
                for (int ii = 0; ii < n; ii++) {
                    for (int jj = 0; jj < n; jj++) if (a[ii][jj] == 'o') {
                        mv[i - ii + n][j - jj + n] = false;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) if (a[i][j] == 'x') {
                boolean ok = false;
                for (int ii = 0; ii < n; ii++) {
                    for (int jj = 0; jj < n; jj++) if (a[ii][jj] == 'o') {
                        if (mv[i - ii + n][j - jj + n]) {
                            ok = true;
                        }
                    }
                }
                if (!ok) {
                    out.println("NO");
                    return;
                }
            }
        }
        out.println("YES");
        for (int i = 0; i < 2 * n - 1; i++) {
            for (int j = 0; j < 2 * n - 1; j++) {
                out.print((i == n - 1 && j == n - 1) ? 'o' : mv[i + 1][j + 1] ? 'x' : '.');
            }
            out.println();
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
        new D().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}