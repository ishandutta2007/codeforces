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

    private int n;
    private int[] x;
    private int[] y;
    private int[] p;

    private void solve() throws IOException {
        n = nextInt();
        x = new int[n];
        y = new int[n];
        p = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = nextInt();
            y[i] = nextInt();
        }
        for (int i = 0; i < n; i++) p[i] = i;
        bt(0, 1000001, 0, 1000001, n);
    }

    private void bt(int x1, int x2, int y1, int y2, int n) {
        if (n == 0) {
        } else if (n == 1) {
            out.println(p[0] + 1);
        } else {
//        System.out.println(x1 + " " + x2 + " " + n + " " + Arrays.toString(p));
            int xm = (x1 + x2) >> 1;
            int ym = (y1 + y2) >> 1;
            int q;
            q = 0;
            for (int i = 0; i < n; i++) {
                if (x[p[i]] < xm && y[p[i]] < ym) {
                    int t = p[i]; p[i] = p[q]; p[q] = t;
                    q++;
                }
            }
            bt(x1, xm, y1, ym, q);
            q = 0;
            for (int i = 0; i < n; i++) {
                if (x[p[i]] < xm && y[p[i]] >= ym) {
                    int t = p[i]; p[i] = p[q]; p[q] = t;
                    q++;
                }
            }
            bt(x1, xm, ym, y2, q);
            q = 0;
            for (int i = 0; i < n; i++) {
                if (x[p[i]] >= xm && y[p[i]] < ym) {
                    int t = p[i]; p[i] = p[q]; p[q] = t;
                    q++;
                }
            }
            bt(xm, x2, y1, ym, q);
            q = 0;
            for (int i = 0; i < n; i++) {
                if (x[p[i]] >= xm && y[p[i]] >= ym) {
                    int t = p[i]; p[i] = p[q]; p[q] = t;
                    q++;
                }
            }
            bt(xm, x2, ym, y2, q);
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