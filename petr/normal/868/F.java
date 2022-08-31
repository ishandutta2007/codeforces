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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        static final long INF = (long) 1e18;
        int[] cntRight;
        long cntRightSum;
        int cntRightLastIncluded;
        int cntRightFirstIncluded;
        int[] a;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();
            a = new int[n + 1];
            for (int i = 0; i < n; ++i) {
                a[i + 1] = in.nextInt();
            }
            long[][] best = new long[k + 1][n + 1];
            cntRight = new int[n + 1];
            long sofar = 0;
            for (int i = 0; i < n; ++i) {
                sofar += cntRight[a[i + 1]];
                ++cntRight[a[i + 1]];
                best[1][i + 1] = sofar;
            }
            Arrays.fill(cntRight, 0);
            cntRightLastIncluded = n;
            cntRightFirstIncluded = n + 1;
            for (int j = 2; j <= k; ++j) {
                Arrays.fill(best[j], INF);
                best[j][0] = 0;
                propagate(best[j - 1], best[j], 1, n, 1, n);
            }
            out.println(best[k][n]);
        }

        void shiftTo(int firstIncluded, int lastIncluded) {
            while (cntRightLastIncluded < lastIncluded) {
                ++cntRightLastIncluded;
                cntRightSum += cntRight[a[cntRightLastIncluded]]++;
            }
            while (cntRightFirstIncluded > firstIncluded) {
                --cntRightFirstIncluded;
                cntRightSum += cntRight[a[cntRightFirstIncluded]]++;
            }
            while (cntRightLastIncluded > lastIncluded) {
                cntRightSum -= --cntRight[a[cntRightLastIncluded]];
                --cntRightLastIncluded;
            }
            while (cntRightFirstIncluded < firstIncluded) {
                cntRightSum -= --cntRight[a[cntRightFirstIncluded]];
                ++cntRightFirstIncluded;
            }
        }

        private void propagate(long[] old, long[] nxt, int left, int right, int searchLeft, int searchRight) {
            if (left > right) return;
            int mid = (left + right) / 2;
            int bestPos = -1;
            for (int pos = searchRight; pos >= searchLeft; --pos) {
                if (pos <= mid) {
                    shiftTo(pos, mid);
                    if (old[pos - 1] + cntRightSum < nxt[mid]) {
                        nxt[mid] = old[pos - 1] + cntRightSum;
                        bestPos = pos;
                    }
                }
            }
            if (bestPos < 0) {
                throw new RuntimeException();
            }
            propagate(old, nxt, left, mid - 1, searchLeft, bestPos);
            propagate(old, nxt, mid + 1, right, bestPos, searchRight);
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