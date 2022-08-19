import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
import java.util.Collections;
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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        int n;
        long m;
        int[] x;
        int[] y;
        long len;
        double d;
        List<TaskF.Event> events = new ArrayList<>();
        int global = 0;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            m = in.nextInt();
            x = new int[2 * n + 1];
            y = new int[2 * n + 1];
            for (int i = 0; i < n; ++i) {
                x[i] = in.nextInt();
                y[i] = in.nextInt();
            }
            for (int i = n; i < 2 * n + 1; ++i) {
                x[i] = x[i - n];
                y[i] = y[i - n];
            }
            len = 0;
            for (int i = 0; i < n; ++i) {
                int j = (i + 1) % n;
                len += Math.abs(x[i] - x[j]) + Math.abs(y[i] - y[j]);
            }
            double left = 0;
            double right = 4000;
            while (right - left > 1e-10 * Math.max(1, right)) {
                d = (left + right) / 2;
                if (canSync()) {
                    right = d;
                } else {
                    left = d;
                }
            }
            out.println(right);
        }

        private boolean canSync() {
            events.clear();
            global = 0;
            int i = 0;
            long oi = 0;
            int j = 0;
            long oj = 0;
            long togo = len;
            while (togo > 0) {
                long rem = (Math.abs(x[j + 1] - x[j]) + Math.abs(y[j + 1] - y[j])) * m - oj;
                long by = Math.min(rem, togo);
                oj += by;
                togo -= by;
                if (by == rem) {
                    ++j;
                    oj = 0;
                }
            }
            long offset = 0;
            while (i < n) {
                long remi = (Math.abs(x[i + 1] - x[i]) + Math.abs(y[i + 1] - y[i])) * m - oi;
                long remj = (Math.abs(x[j + 1] - x[j]) + Math.abs(y[j + 1] - y[j])) * m - oj;
                long by = Math.min(remi, remj);
                int dxi = sign(x[i + 1] - x[i]);
                int dyi = sign(y[i + 1] - y[i]);
                int dxj = sign(x[j + 1] - x[j]);
                int dyj = sign(y[j + 1] - y[j]);
                process(offset, by, x[i] * m + dxi * oi, y[i] * m + dyi * oi, dxi, dyi, x[j] * m + dxj * oj, y[j] * m + dyj * oj, dxj, dyj);
                oi += by;
                oj += by;
                offset += by;
                if (by == remi) {
                    ++i;
                    oi = 0;
                }
                if (by == remj) {
                    ++j;
                    oj = 0;
                }
            }
            if (global >= m) return true;
            Collections.sort(events, new Comparator<TaskF.Event>() {

                public int compare(TaskF.Event o1, TaskF.Event o2) {
                    return Double.compare(o1.when, o2.when);
                }
            });
            for (TaskF.Event e : events) {
                global += e.delta;
                if (global >= m) return true;
            }
            return false;
        }

        private void process(long offset, long len, long x1, long y1, int dx1, int dy1, long x2, long y2, int dx2, int dy2) {
            long x0 = x2 - x1;
            long y0 = y2 - y1;
            long vx = dx2 - dx1;
            long vy = dy2 - dy1;
            double a = vx * (double) vx + vy * (double) vy;
            double b = 2.0 * vx * x0 + 2.0 * vy * y0;
            double c = x0 * (double) x0 + y0 * (double) y0 - (d * m * d * m);
            double left;
            double right;
            if (a == 0) {
                if (b != 0) throw new RuntimeException();
                if (c >= 0) return;
                left = 0;
                right = len;
            } else {
                double d = b * b - 4 * a * c;
                if (d < 1e-12) return;
                d = Math.sqrt(d);
                left = Math.max(0, (-b - d) / (2 * a));
                right = Math.min(len, (-b + d) / (2 * a));
            }
            if (left >= right) return;
            left += offset;
            right += offset;
            double wLeft = Math.floor(left / this.len);
            double wRight = Math.floor(right / this.len);
            events.add(new TaskF.Event(left - wLeft * this.len, 1));
            events.add(new TaskF.Event(right - wRight * this.len, -1));
            global += (int) (wRight - wLeft);
        }

        int sign(int d) {
            if (d > 0) return 1;
            else if (d < 0) return -1;
            else return 0;
        }

        static class Event {
            double when;
            int delta;

            public Event(double when, int delta) {
                this.when = when;
                this.delta = delta;
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