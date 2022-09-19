import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class F {

    private static final long MOD = (long) (1e9+7);

    private void solve() throws IOException {
        int n = nextInt();
        int h = nextInt();
        int w = nextInt();
        String s = next();
        int[] dx = new int[n];
        int[] dy = new int[n];
        for (int i = 0; i < n; i++) {
            int d = "UDLR".indexOf(s.charAt(i));
            dx[i] = new int[]{0, 0, -1, 1}[d];
            dy[i] = new int[]{-1, 1, 0, 0}[d];
        }
        int[] x1 = new int[w + h];
        int[] x2 = new int[w + h];
        int[] y1 = new int[w + h];
        int[] y2 = new int[w + h];
        int[] p = new int[w + h];

        int m = 1;
        int x = 0;
        int y = 0;
        boolean ok = false;
        for (int i = 0; i < n; i++) {
            x += dx[i];
            y += dy[i];
            if (x < x1[m - 1] || x > x2[m - 1] || y < y1[m - 1] || y > y2[m - 1]) {
                x1[m] = Math.min(x1[m - 1], x);
                x2[m] = Math.max(x2[m - 1], x);
                y1[m] = Math.min(y1[m - 1], y);
                y2[m] = Math.max(y2[m - 1], y);
                p[m] = i + 1;
                m++;
                if ((x2[m - 1] - x1[m - 1] + 1) > w || (y2[m - 1] - y1[m - 1] + 1) > h) {
                    ok = true;
                    break;
                }
            }
        }

        int sx = x;
        int sy = y;

        if (!ok) {
            if (x == 0 && y == 0) {
                out.println(-1);
                return;
            }
            int[] q = new int[m];
            int qn = 0;
            int xx1 = x1[m - 1];
            int xx2 = x2[m - 1];
            int yy1 = y1[m - 1];
            int yy2 = y2[m - 1];
            for (int i = 0; i < m; i++) {
                int xxx1 = x + x1[i];
                int yyy1 = y + y1[i];
                int xxx2 = x + x2[i];
                int yyy2 = y + y2[i];
                if (xxx1 < xx1 || xxx2 > xx2 || yyy1 < yy1 || yyy2 > yy2) {
                    q[qn++] = i;
                    xx1 = Math.min(xx1, xxx1);
                    xx2 = Math.max(xx2, xxx2);
                    yy1 = Math.min(yy1, yyy1);
                    yy2 = Math.max(yy2, yyy2);
                }
            }

            x = 0;
            y = 0;
            int nn = 0;

            while (true) {
                x += sx;
                y += sy;
                nn += n;
                nn %= MOD;
                for (int i = 0; i < qn; i++) {
                    x1[m] = Math.min(x1[m - 1], x + x1[q[i]]);
                    x2[m] = Math.max(x2[m - 1], x + x2[q[i]]);
                    y1[m] = Math.min(y1[m - 1], y + y1[q[i]]);
                    y2[m] = Math.max(y2[m - 1], y + y2[q[i]]);
                    p[m] = p[q[i]] + nn;
                    p[m] %= MOD;
                    m++;
                    if ((x2[m - 1] - x1[m - 1] + 1) > w || (y2[m - 1] - y1[m - 1] + 1) > h) {
                        ok = true;
                        break;
                    }
                }
                if (ok) break;
            }
        }
//        for (int i = 0; i < m; i++) {
//            System.out.println(x1[i] + " " + x2[i] + " " + y1[i] + " " + y2[i] + " " + p[i]);
//        }
        long res = 0;
        for (int i = 0; i < m - 1; i++) {
            int h1 = y2[i] - y1[i] + 1;
            int h2 = y2[i + 1] - y1[i + 1] + 1;
            int w1 = x2[i] - x1[i] + 1;
            int w2 = x2[i + 1] - x1[i + 1] + 1;
            if (h2 > h1) {
                res += 1l * p[i + 1] * (w - w1 + 1);
                res %= MOD;
            } else {
                res += 1l * p[i + 1] * (h - h1 + 1);
                res %= MOD;
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
        new F().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}