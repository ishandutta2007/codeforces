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
        int n;
        int[] a;
        int[] count;
        int[] maxValPlusBefore;
        int[] minValPlusAfter;
        static final int INF = (int) 1e9;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            a = new int[n];
            for (int i = 0; i < n; ++i) a[i] = in.nextInt();
            long[] toSort = new long[n];
            for (int i = 0; i < n; ++i) {
                toSort[i] = (((long) a[i]) << 32) | i;
            }
            Arrays.sort(toSort);
            int[] position = new int[n];
            Arrays.fill(position, -1);
            for (int i = 0; i < n; ++i) {
                position[(int) (toSort[i] & ((1L << 32) - 1))] = i;
            }
            for (int x : position) if (x < 0) throw new RuntimeException();
            count = new int[4 * n + 10];
            maxValPlusBefore = new int[4 * n + 10];
            minValPlusAfter = new int[4 * n + 10];
            Arrays.fill(maxValPlusBefore, -INF);
            Arrays.fill(minValPlusAfter, INF);
            for (int i = 0; i < n; ++i) {
                int p = position[i];
                treeUpd(0, 0, n - 1, p, a[i]);
                int lowest = findValPlusBeforeAtLeast(0, 0, n - 1, 0);
                int totalAfter = findCountSince(0, 0, n - 1, lowest);
                int res = -(i + 1 - totalAfter) + totalAfter;
                res = Math.min(res, findMinValPlusAfterSince(0, 0, n - 1, lowest));
                out.println(res);
            }
        }

        private int findMinValPlusAfterSince(int root, int rl, int rr, int at) {
            if (rl >= at)
                return minValPlusAfter[root];
            if (rr < at)
                return INF;
            int rm = (rl + rr) >> 1;
            return Math.min(findMinValPlusAfterSince(root * 2 + 1, rl, rm, at) + count[root * 2 + 2], findMinValPlusAfterSince(root * 2 + 2, rm + 1, rr, at));
        }

        private int findCountSince(int root, int rl, int rr, int at) {
            if (rl >= at)
                return count[root];
            if (rr < at)
                return 0;
            int rm = (rl + rr) >> 1;
            return findCountSince(root * 2 + 1, rl, rm, at) + findCountSince(root * 2 + 2, rm + 1, rr, at);
        }

        private int findValPlusBeforeAtLeast(int root, int rl, int rr, int bound) {
            if (bound > maxValPlusBefore[root]) return INF;
            if (rl == rr) {
                return rl;
            }
            int rm = (rl + rr) >> 1;
            int res = findValPlusBeforeAtLeast(root * 2 + 1, rl, rm, bound);
            if (res < INF) return res;
            return findValPlusBeforeAtLeast(root * 2 + 2, rm + 1, rr, bound - count[root * 2 + 1]);
        }

        private void treeUpd(int root, int rl, int rr, int at, int val) {
            if (rl == rr) {
                count[root] = 1;
                minValPlusAfter[root] = val;
                maxValPlusBefore[root] = val;
            } else {
                int rm = (rl + rr) >> 1;
                if (at <= rm) {
                    treeUpd(root * 2 + 1, rl, rm, at, val);
                } else {
                    treeUpd(root * 2 + 2, rm + 1, rr, at, val);
                }
                refresh(root);
            }
        }

        private void refresh(int root) {
            int c1 = root * 2 + 1;
            int c2 = root * 2 + 2;
            count[root] = count[c1] + count[c2];
            minValPlusAfter[root] = Math.min(minValPlusAfter[c1] + count[c2], minValPlusAfter[c2]);
            maxValPlusBefore[root] = Math.max(maxValPlusBefore[c1], maxValPlusBefore[c2] + count[c1]);
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