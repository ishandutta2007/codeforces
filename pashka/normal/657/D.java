import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class D {

    private static final double EPS = 1e-9;

    private void solve() throws IOException {
        int n = nextInt();
        Problem[] problems = new Problem[n];
        for (int i = 0; i < n; i++) {
            problems[i] = new Problem();
        }
        for (int i = 0; i < n; i++) {
            problems[i].p = nextInt();
        }
        for (int i = 0; i < n; i++) {
            problems[i].t = nextInt();
        }

        Arrays.sort(problems);

        int l = 0;
        long tt = 0;
        while (l < n) {
            int r = l + 1;
            while (r < n) {
                long d = problems[r].p * problems[l].t - problems[l].p * problems[r].t;
                if (d != 0) break;
                r++;
            }

            for (int i = l; i < r; i++) {
                problems[i].minTime = tt + problems[i].t;
            }

            for (int i = l; i < r; i++) {
                tt += problems[i].t;
            }

            for (int i = l; i < r; i++) {
                problems[i].maxTime = tt;
            }

            l = r;
        }

        Arrays.sort(problems, new Comparator<Problem>() {
            @Override
            public int compare(Problem o1, Problem o2) {
                return Long.compare(o1.p, o2.p);
            }
        });

//        for (Problem problem : problems) {
//            System.out.println(problem.p + " " +problem.t + " " +problem.minTime + " " + problem.maxTime);
//        }

        double[] x = new double[2 * n + 2];
        double[] y = new double[2 * n + 2];
        int m = 2;
        x[0] = 1;
        x[1] = 0;
        double[] aa = new double[2 * n + 2];
        double[] bb = new double[2 * n + 2];

        double res = 1;

        l = 0;
        while (l < n) {
            int r = l + 1;
            while (r < n && problems[r].p == problems[l].p) {
                r++;
            }
            for (int i = l; i < r; i++) {
                double b = problems[i].p;
                double a = -1.0 * problems[i].p * problems[i].maxTime / tt;
                int ll = -1;
                int rr = m;
                while (rr > ll + 1) {
                    int mm = (ll + rr) / 2;
                    double v = a * x[mm] + b;
                    if (v < y[mm] - EPS) {
                        ll = mm;
                    } else {
                        rr = mm;
                    }
                }

//                System.out.println(a + " " + b);
//                System.out.println(problems[i].p + " " + problems[i].t + " " + ll);

                if (ll == -1) {
                    continue;
                }
                if (rr == m) {
                    res = 0;
                    continue;
                }

                double xx = (bb[ll] - b) / (a - aa[ll]);

                if (xx < 0) xx = 0;
                if (xx > 1) xx = 1;

//                System.out.println(problems[i].p + " " + problems[i].t + " " + xx);


                if (Double.isNaN(xx)) continue;
                res = Math.min(res, xx);
            }

            for (int i = l; i < r; i++) {
                double b = problems[i].p;
                double a = -1.0 * problems[i].p * problems[i].minTime / tt;
                while (m > 0 && y[m - 1] < a * x[m - 1] + b + EPS) {
                    m--;
                }
                if (m == 0) {
                    x[0] = 1;
                    y[0] = a + b;
                    aa[0] = a;
                    bb[0] = b;
                    m++;
                } else {
                    double xx = (bb[m - 1] - b) / (a - aa[m - 1]);
                    double yy = a * xx + b;

                    if (xx < 0) xx = 0;
                    if (xx > 1) xx = 1;

                    x[m] = xx;
                    y[m] = yy;
                    aa[m] = a;
                    bb[m] = b;
                    m++;
                }
                x[m] = 0;
                y[m] = b;
                m++;

            }

//            for (int i = 0; i < m; i++) {
//                System.out.println("(" + x[i] + " " + y[i] + " " + aa[i] + " " + bb[i] + ")");
//            }

            l = r;
        }

        out.println(res);
    }

    class Problem implements Comparable<Problem> {
        long t, p;
        long minTime, maxTime;

        @Override
        public int compareTo(Problem o) {
            long d = o.p * t - p * o.t;
            if (d != 0) {
                return Long.signum(d);
            } else {
                return Long.compare(p, o.p);
            }
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