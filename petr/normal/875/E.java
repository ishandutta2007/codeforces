import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        int[] interesting;
        TaskE.Fenwick leftFenwick;
        TaskE.Fenwick rightFenwick;
        int[] maxRight;
        int[] x;
        static final int INF = (int) 1e9;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt() + 2;
            x = new int[n];
            for (int i = 0; i < n; ++i) {
                x[i] = in.nextInt();
            }
            interesting = x.clone();
            Arrays.sort(interesting);
            leftFenwick = new TaskE.Fenwick(interesting.length);
            rightFenwick = new TaskE.Fenwick(interesting.length);
            maxRight = new int[x.length];
            int left = 0;
            int right = (int) 1e9;
            while (right - left > 1) {
                int middle = (left + right) / 2;
                if (enough(middle)) {
                    right = middle;
                } else {
                    left = middle;
                }
            }
            out.println(right);
        }

        private boolean enough(int maxJump) {
            leftFenwick.reset(x.length);
            rightFenwick.reset(x.length);
            for (int i = x.length - 1; i >= 0; --i) {
                int big = x[i] + maxJump + 1;
                int left = -1;
                int right = interesting.length;
                while (right - left > 1) {
                    int middle = (left + right) >> 1;
                    if (interesting[middle] >= big) {
                        right = middle;
                    } else {
                        left = middle;
                    }
                }
                maxRight[i] = rightFenwick.get(interesting.length - 1 - right);
                int small = x[i] - maxJump - 1;
                left = -1;
                right = interesting.length;
                while (right - left > 1) {
                    int middle = (left + right) >> 1;
                    if (interesting[middle] > small) {
                        right = middle;
                    } else {
                        left = middle;
                    }
                }
                maxRight[i] = Math.min(maxRight[i], leftFenwick.get(left));
                left = -1;
                right = interesting.length;
                while (right - left > 1) {
                    int middle = (left + right) >> 1;
                    if (interesting[middle] > x[i]) {
                        right = middle;
                    } else {
                        left = middle;
                    }
                }
                leftFenwick.upd(left, i);
                rightFenwick.upd(interesting.length - 1 - left, i);
            }
            int maxCan = 0;
            for (int i = 0; i + 1 < x.length; ++i) {
                if (i <= maxCan && Math.abs(x[i] - x[i + 1]) <= maxJump) {
                    maxCan = Math.max(maxCan, maxRight[i] - 1);
                }
            }
            return maxCan >= x.length - 1;
        }

        static class Fenwick {
            int[] a;

            public Fenwick(int n) {
                a = new int[n];
            }

            void reset(int start) {
                Arrays.fill(a, start);
            }

            void upd(int at, int by) {
                while (at < a.length) {
                    if (by < a[at]) a[at] = by;
                    at |= at + 1;
                }
            }

            int get(int upto) {
                int res = INF;
                while (upto >= 0) {
                    if (a[upto] < res) res = a[upto];
                    upto = (upto & (upto + 1)) - 1;
                }
                return res;
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