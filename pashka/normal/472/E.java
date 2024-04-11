import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class E {

    private boolean[][] z;
    private boolean[][] zz;
    private int x, y;
    private int n, m;
    private int[][] a;
    private int[][] b;
    private int[][] px;
    private int[][] py;

    private void solve() throws IOException {
        n = nextInt();
        m = nextInt();
        a = new int[n][m];
        z = new boolean[n][m];
        zz = new boolean[n][m];
        px = new int[n][m];
        py = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = nextInt();
            }
        }
        b = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                b[i][j] = nextInt();
            }
        }
        if (n == 1) {
            for (int i = 0; i < m; i++) {
                x = 0;
                y = i;
                mn = 0;
                makeMove(x, y);
                for (int j = 0; j < m; j++)
                    if (j != i) {
                        moveTo(0, j);
                        boolean ok = true;
                        for (int k = 0; k < m; k++) {
                            if (a[0][k] != b[0][k]) {
                                ok = false;
                            }
                        }
                        if (ok) {
                            out.println(mn - 1);
                            for (int t = 0; t < mn; t++) {
                                out.println((moves[0][t] + 1) + " " + (moves[1][t] + 1));
                            }
                            return;
                        }
                    }
                moveTo(0, i);
            }
            out.println(-1);
            return;
        }
        if (m == 1) {
            for (int i = 0; i < n; i++) {
                x = i;
                y = 0;
                mn = 0;
                makeMove(x, y);
                for (int j = 0; j < n; j++)
                    if (j != i) {
                        moveTo(j, 0);
                        boolean ok = true;
                        for (int k = 0; k < n; k++) {
                            if (a[k][0] != b[k][0]) {
                                ok = false;
                            }
                        }
                        if (ok) {
                            out.println(mn - 1);
                            for (int t = 0; t < mn; t++) {
                                out.println((moves[0][t] + 1) + " " + (moves[1][t] + 1));
                            }
                            return;
                        }
                    }
                moveTo(i, 0);
            }
            out.println(-1);
            return;
        }
        x = -1;
        y = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == b[0][0]) {
                    x = i;
                    y = j;
                }
            }
        }
        if (x == -1) {
            out.println(-1);
            return;
        }
        makeMove(x, y);
        for (int i = n - 1; i >= 2; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (!put(i, j)) {
                    out.println(-1);
                    return;
                }
            }
        }
        for (int j = m - 1; j >= 2; j--) {
            for (int i = 1; i >= 0; i--) {
                if (!put(i, j)) {
                    out.println(-1);
                    return;
                }
            }
        }
        for (int j = 1; j >= 0; j--) {
            for (int i = 1; i >= 0; i--) {
                if (i + j > 0 && !put(i, j)) {
                    out.println(-1);
                    return;
                }
            }
        }

        out.println(mn - 1);
        for (int i = 0; i < mn; i++) {
            out.println((moves[0][i] + 1) + " " + (moves[1][i] + 1));
        }
    }

    private boolean put(int xx, int yy) {
        z[x][y] = true;
        int cx = -1;
        int cy = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!z[i][j] && a[i][j] == b[xx][yy]) {
                    cx = i;
                    cy = j;
                }
            }
        }
        if (cx == -1) {
            return false;
        }
        z[x][y] = false;
//        System.out.println(xx + " " + yy);
        while (cx != xx || cy != yy) {
            int dx = -1;
            int dy = -1;
            int min = 10000;
            for (int i = cx - 1; i <= cx + 1; i++) {
                for (int j = cy - 1; j <= cy + 1; j++) {
                    if (i >= 0 && i < n && j >= 0 && j < m && !z[i][j]) {
                        int d = Math.abs(xx - i) + Math.abs(yy - j);
                        if (d < min) {
                            min = d;
                            dx = i;
                            dy = j;
                        }
                    }
                }
            }
            z[cx][cy] = true;
            moveTo(dx, dy);
            z[cx][cy] = false;
            makeMove(cx, cy);
            cx = dx;
            cy = dy;
        }
        z[xx][yy] = true;
        return true;
    }

    int[] qx = new int[10000];
    int[] qy = new int[10000];

    private void moveTo(int dx, int dy) {
        for (boolean[] booleans : zz) {
            Arrays.fill(booleans, false);
        }
        zz[dx][dy] = true;
        int h = 0;
        int t = 1;
        qx[0] = dx;
        qy[0] = dy;
        while (t > h) {
            int i = qx[h];
            int j = qy[h];
            if (i == x && j == y) {
                while (x != dx || y != dy) {
                    makeMove(px[x][y], py[x][y]);
                }
                return;
            }
            h++;
            for (int ii = i - 1; ii <= i + 1; ii++) {
                for (int jj = j - 1; jj <= j + 1; jj++) {
                    if (ii >= 0 && ii < n && jj >= 0 && jj < m && !zz[ii][jj] && !z[ii][jj]) {
                        px[ii][jj] = i;
                        py[ii][jj] = j;
                        zz[ii][jj] = true;
                        qx[t] = ii;
                        qy[t] = jj;
                        t++;
                    }
                }
            }
        }
        throw new RuntimeException();
    }

    int mn = 0;
    int[][] moves = new int[2][1000000];

    private void makeMove(int xx, int yy) {
//        System.out.println(xx + " " + yy);
        moves[0][mn] = xx;
        moves[1][mn] = yy;
        int t = a[x][y];
        a[x][y] = a[xx][yy];
        a[xx][yy] = t;
        x = xx;
        y = yy;
        mn++;
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
        new E().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}