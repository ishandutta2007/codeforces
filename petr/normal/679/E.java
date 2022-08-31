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
        long[] extra;
        long[] bad;
        long[] toNextJump;
        int[] ptr;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int numBad = 0;
            long pw = 1;
            while (pw <= Long.MAX_VALUE / 42) {
                ++numBad;
                pw *= 42;
            }
            bad = new long[numBad];
            numBad = 0;
            pw = 1;
            while (pw <= Long.MAX_VALUE / 42) {
                pw *= 42;
                bad[numBad++] = pw;
            }
            int n = in.nextInt();
            int q = in.nextInt();
            long[] start = new long[n];
            for (int i = 0; i < n; ++i) {
                start[i] = in.nextLong();
            }
            ptr = new int[4 * n + 10];
            Arrays.fill(ptr, -1);
            toNextJump = new long[4 * n + 10];
            extra = new long[4 * n + 10];
            initToNextJump(0, 0, n - 1, start);
            resolveNegatives(0, 0, n - 1, 0);
            if (toNextJump[0] < 0) throw new RuntimeException();
            for (int qi = 0; qi < q; ++qi) {
                int tpe = in.nextInt();
                if (tpe == 1) {
                    int a = in.nextInt() - 1;
                    out.println(retrieve(0, 0, n - 1, a));
                } else if (tpe == 2) {
                    int a = in.nextInt() - 1;
                    int b = in.nextInt() - 1;
                    long x = in.nextLong();
                    int xi = 0;
                    while (bad[xi] < x) {
                        ++xi;
                    }
                    resetSegment(0, 0, n - 1, a, b, x, xi, 0);
                    if (toNextJump[0] <= 0) throw new RuntimeException();
                } else if (tpe == 3) {
                    int a = in.nextInt() - 1;
                    int b = in.nextInt() - 1;
                    long x = in.nextLong();
                    incrementSegment(0, 0, n - 1, a, b, x);
                    resolveNegatives(0, 0, n - 1, 0);
                    while (toNextJump[0] <= 0) {
                        if (toNextJump[0] < 0) throw new RuntimeException();
                        incrementSegment(0, 0, n - 1, a, b, x);
                        resolveNegatives(0, 0, n - 1, 0);
                    }
                } else {
                    throw new RuntimeException();
                }
            }
        }

        private void incrementSegment(int root, int rl, int rr, int left, int right, long x) {
            if (left > right) return;
            if (rl == left && rr == right) {
                extra[root] += x;
                toNextJump[root] -= x;
                return;
            }
            if (ptr[root] >= 0) {
                ptr[root * 2 + 1] = ptr[root];
                extra[root * 2 + 1] = 0;
                toNextJump[root * 2 + 1] = toNextJump[root] + extra[root];
                ptr[root * 2 + 2] = ptr[root];
                extra[root * 2 + 2] = 0;
                toNextJump[root * 2 + 2] = toNextJump[root] + extra[root];
                ptr[root] = -1;
            }
            int rm = (rl + rr) >> 1;
            incrementSegment(root * 2 + 1, rl, rm, left, Math.min(right, rm), x);
            incrementSegment(root * 2 + 2, rm + 1, rr, Math.max(left, rm + 1), right, x);
            toNextJump[root] = Math.min(toNextJump[root * 2 + 1], toNextJump[root * 2 + 2]) - extra[root];
        }

        private void resetSegment(int root, int rl, int rr, int left, int right, long x, int xi, long totalExtra) {
            if (left > right) return;
            if (rl == left && rr == right) {
                extra[root] = x - totalExtra;
                ptr[root] = xi;
                toNextJump[root] = bad[xi] - extra[root];
                return;
            }
            totalExtra += extra[root];
            if (ptr[root] >= 0) {
                ptr[root * 2 + 1] = ptr[root];
                extra[root * 2 + 1] = 0;
                toNextJump[root * 2 + 1] = toNextJump[root] + extra[root];
                ptr[root * 2 + 2] = ptr[root];
                extra[root * 2 + 2] = 0;
                toNextJump[root * 2 + 2] = toNextJump[root] + extra[root];
                ptr[root] = -1;
            }
            int rm = (rl + rr) >> 1;
            resetSegment(root * 2 + 1, rl, rm, left, Math.min(right, rm), x, xi, totalExtra);
            resetSegment(root * 2 + 2, rm + 1, rr, Math.max(left, rm + 1), right, x, xi, totalExtra);
            toNextJump[root] = Math.min(toNextJump[root * 2 + 1], toNextJump[root * 2 + 2]) - extra[root];
        }

        private long retrieve(int root, int rl, int rr, int a) {
            long res = extra[root];
            if (ptr[root] < 0) {
                int rm = (rl + rr) >> 1;
                if (a <= rm) {
                    res += retrieve(root * 2 + 1, rl, rm, a);
                } else {
                    res += retrieve(root * 2 + 2, rm + 1, rr, a);
                }
            }
            return res;
        }

        private void resolveNegatives(int root, int rl, int rr, long totalExtra) {
            if (toNextJump[root] - totalExtra >= 0) return;
            totalExtra += extra[root];
            if (ptr[root] >= 0) {
                int pt = ptr[root];
                while (totalExtra > bad[pt]) {
                    ++pt;
                }
                ptr[root] = pt;
                toNextJump[root] = bad[pt] - extra[root];
            } else {
                int rm = (rl + rr) >> 1;
                resolveNegatives(root * 2 + 1, rl, rm, totalExtra);
                resolveNegatives(root * 2 + 2, rm + 1, rr, totalExtra);
                toNextJump[root] = Math.min(toNextJump[root * 2 + 1], toNextJump[root * 2 + 2]) - extra[root];
            }
        }

        private void initToNextJump(int root, int rl, int rr, long[] start) {
            if (rl == rr) {
                ptr[root] = 0;
                extra[root] = start[rl];
                toNextJump[root] = bad[0] - extra[root];
            } else {
                ptr[root] = -1;
                extra[root] = 0;
                int rm = (rl + rr) >> 1;
                initToNextJump(root * 2 + 1, rl, rm, start);
                initToNextJump(root * 2 + 2, rm + 1, rr, start);
                toNextJump[root] = Math.min(toNextJump[root * 2 + 1], toNextJump[root * 2 + 2]);
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}