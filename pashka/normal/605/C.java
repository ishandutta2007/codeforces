import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Random;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class C {

    private double[] x, y;
    int[] p;

    private void solve() throws IOException {
        int n = nextInt();
        double tx = nextInt();
        double ty = nextInt();
        x = new double[n];
        y = new double[n];
        for (int i = 0; i < n; i++) {
            x[i] = nextInt();
            y[i] = nextInt();
        }
        p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
        sort(0, n - 1);
        int m = 0;
        for (int i = 0; i < n; i++) {
            while (m > 0 && y[p[m - 1]] <= y[p[i]]) m--;
            p[m++] = p[i];
        }
        n = 0;
        for (int i = 0; i < m; i++) {
            while (n >= 2 && vect(p[n - 2], p[n - 1], p[i]) > 0) {
                n--;
            }
            p[n++] = p[i];
        }

        double res = 1e100;
        for (int i = 0; i < n; i++) {
//            System.out.println(x[p[i]] + " " + y[p[i]]);
            res = Math.min(res, Math.max(tx / x[p[i]], ty / y[p[i]]));
        }
        for (int i = 0; i < n - 1; i++) {
            double x1 = x[p[i]];
            double y1 = y[p[i]];
            double x2 = x[p[i + 1]];
            double y2 = y[p[i + 1]];
            double t = (tx * y1 - ty * x1) / (ty * (x2 - x1) - tx * (y2 - y1));
            if (t > 0 && t < 1) {
                double xx = x1 + t * (x2 - x1);
                double yy = y1 + t * (y2 - y1);
//                System.out.println(xx + " " + yy);
                res = Math.min(res, Math.max(tx / xx, ty / yy));
            }
        }
        out.println(res);
    }

    private double vect(int a, int b, int c) {
        double x1 = x[b] - x[a];
        double y1 = y[b] - y[a];
        double x2 = x[c] - x[a];
        double y2 = y[c] - y[a];
        return x1 * y2 - x2 * y1;
    }

    Random random = new Random();

    private void sort(int l, int r) {
        int i = l;
        int j = r;
        double xx = x[p[l + random.nextInt(r - l + 1)]];
        while (i <= j) {
            while (x[p[i]] < xx) i++;
            while (x[p[j]] > xx) j--;
            if (i <= j) {
                int t = p[i]; p[i] = p[j]; p[j] = t;
                i++; j--;
            }
        }
        if (i < r) sort(i, r);
        if (l < j) sort(l, j);
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