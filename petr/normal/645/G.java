import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskG solver = new TaskG();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskG {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            double a = in.nextInt();
            Point[] p = new Point[n];
            for (int i = 0; i < n; ++i) {
                p[i] = new Point();
                p[i].x = in.nextInt();
                p[i].y = in.nextInt();
            }
            for (int i = 0; i < n; ++i) {
                double x1 = (p[i].x - a) / 2;
                double y1 = p[i].y / 2;
                double r1 = Math.sqrt((x1 + a) * (x1 + a) + y1 * y1);
                double d = Math.sqrt(x1 * x1 + y1 * y1);
                p[i].x1 = x1;
                p[i].y1 = y1;
                p[i].r1 = r1;
                p[i].d = d;
                p[i].polar = Math.atan2(y1, x1);
            }
            double left = 0.0;
            double right = 2 * a;
            Event[] events = new Event[2 * n];
            for (int i = 0; i < events.length; ++i) {
                events[i] = new Event();
            }
            int[] stack = new int[2 * n];
            outer:
            while (right - left > Math.max(1, right) * 1e-9) {
                double mid = (left + right) / 2;
                double r0 = mid / 2;
                int nev = 0;
                for (int i = 0; i < n; ++i) {
                    Point pp = p[i];
                    double r1 = pp.r1;
                    double d = pp.d;
                    if (d + r1 <= r0) {
                        right = mid;
                        continue outer;
                    }
                    double cosa = (r0 * r0 + d * d - r1 * r1) / (2 * r0 * d);
                    if (cosa < 1 && cosa > -1) {
                        double alpha = Math.acos(cosa);
                        double a1 = norm(pp.polar + alpha);
                        double a2 = norm(pp.polar - alpha);
                        events[nev].alpha = a1;
                        events[nev].what = i;
                        ++nev;
                        events[nev].alpha = a2;
                        events[nev].what = i;
                        ++nev;
                    }
                }
                Arrays.sort(events, 0, nev);
                int sp = 0;
                for (int i = 0; i < nev; ++i) {
                    int cur = events[i].what;
                    if (sp > 0 && stack[sp - 1] == cur) --sp;
                    else stack[sp++] = cur;
                }
                if (sp == 0) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            out.println(String.format("%.15f", right));
        }

        private double norm(double v) {
            while (v >= Math.PI) v -= 2 * Math.PI;
            while (v < -Math.PI) v += 2 * Math.PI;
            return v;
        }

        static class Point {
            double x;
            double y;
            double x1;
            double y1;
            double r1;
            double polar;
            double d;

        }

        static class Event implements Comparable<Event> {
            double alpha;
            int what;


            public int compareTo(Event o) {
                return Double.compare(alpha, o.alpha);
            }

        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}