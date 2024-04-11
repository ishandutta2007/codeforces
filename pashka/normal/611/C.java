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
        int h = nextInt();
        int w = nextInt();
        char[][] a = new char[h][w];
        for (int i = 0; i < h; i++) {
            String s = next();
            for (int j = 0; j < w; j++) {
                a[i][j] = s.charAt(j);
            }
        }
        int[][] t = new int[h][w];
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) if (a[i][j] == '.') {
                if (i < h - 1 && a[i + 1][j] == '.') t[i][j]++;
                if (j < w - 1 && a[i][j + 1] == '.') t[i][j]++;
            }
        }
        int[][] s = new int[h + 1][w + 1];
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                s[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + t[i][j];
            }
        }
        int[][] vv = new int[h][w + 1];
        for (int i = 0; i < h - 1; i++) {
            for (int j = 0; j < w; j++) {
                vv[i][j + 1] = vv[i][j];
                if (a[i][j] == '.' && a[i + 1][j] == '.') {
                    vv[i][j + 1]++;
                }
            }
        }
        int[][] hh = new int[h + 1][w];
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w - 1; j++) {
                hh[i + 1][j] = hh[i][j];
                if (a[i][j] == '.' && a[i][j + 1] == '.') {
                    hh[i + 1][j]++;
                }
            }
        }

        int q = nextInt();
        for (int i = 0; i < q; i++) {
            int r1 = nextInt() - 1;
            int c1 = nextInt() - 1;
            int r2 = nextInt();
            int c2 = nextInt();
            int res = s[r2][c2] + s[r1][c1] - s[r2][c1] - s[r1][c2];
            res -= vv[r2 - 1][c2] - vv[r2 - 1][c1];
            res -= hh[r2][c2 - 1] - hh[r1][c2 - 1];
            out.println(res);
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