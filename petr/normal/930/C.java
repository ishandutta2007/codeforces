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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        static final int INF = (int) 1e9;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            int[] delta = new int[m + 1];
            for (int i = 0; i < n; ++i) {
                int l = in.nextInt() - 1;
                int r = in.nextInt();
                ++delta[l];
                --delta[r];
            }
            int[] cover = new int[m];
            for (int i = 0; i < m; ++i) {
                cover[i] = delta[i];
                if (i > 0) cover[i] += cover[i - 1];
            }
            int[] a = maxNonDecreasing(cover);
            int[] b = maxNonDecreasing(reverse(cover));
            int res = 0;
            for (int i = 0; i <= m; ++i) {
                res = Math.max(res, a[i] + b[m - i]);
            }
            out.println(res);
        }

        private int[] maxNonDecreasing(int[] cover) {
            int n = cover.length;
            int[] res = new int[n + 1];
            int[] best = new int[n + 1];
            Arrays.fill(best, INF);
            best[0] = 0;
            int maxSoFar = 0;
            for (int i = 0; i < n; ++i) {
                int cur = cover[i];
                int left = 0;
                int right = maxSoFar + 1;
                while (right - left > 1) {
                    int middle = (left + right) >> 1;
                    if (best[middle] <= cur) {
                        left = middle;
                    } else {
                        right = middle;
                    }
                }
                if (left == maxSoFar) ++maxSoFar;
                best[right] = cur;
                res[i + 1] = maxSoFar;
            }
            return res;
        }

        int[] reverse(int[] x) {
            int[] y = new int[x.length];
            for (int i = 0; i < x.length; ++i) y[i] = x[x.length - 1 - i];
            return y;
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