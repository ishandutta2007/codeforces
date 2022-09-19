import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class H {

    private void solve() throws IOException {
        double a = nextInt();
        double b = nextInt();
        double c = nextInt();
        double d = nextInt();
        double l = 0;
        double r = 1e10;
        while (true) {
            double m = (l + r) / 2;
            if (l == m || r == m) break;
            double min = Double.POSITIVE_INFINITY;
            double max = Double.NEGATIVE_INFINITY;
            for (double aa : vals(a, m)) {
                for (double bb : vals(b, m)) {
                    for (double cc : vals(c, m)) {
                        for (double dd : vals(d, m)) {
                            double q = aa * dd - bb * cc;
                            if (q < min) min = q;
                            if (q > max) max = q;
                        }
                    }
                }
            }
            if (min <= 0 && max >= 0) {
                r = m;
            } else {
                l = m;
            }
        }
        out.println(r);
    }

    private double[] vals(double a, double m) {
        if (a - m < 0 && a + m > 0) {
            return new double[]{a - m, a + m, 0};
        } else {
            return new double[]{a - m, a + m};
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
        new H().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}