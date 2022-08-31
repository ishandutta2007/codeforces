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
        int NUM_BITS = 19;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int q = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
            }
            int[] ql = new int[q];
            int[] qr = new int[q];
            int[] nextSameLeft = new int[q];
            int[] firstByLeft = new int[n];
            Arrays.fill(firstByLeft, -1);
            for (int i = 0; i < q; ++i) {
                ql[i] = in.nextInt() - 1;
                qr[i] = in.nextInt() - 1;
                nextSameLeft[i] = firstByLeft[ql[i]];
                firstByLeft[ql[i]] = i;
            }
            boolean[] answers = new boolean[q];
            int[][] earliest = new int[NUM_BITS][NUM_BITS];
            for (int i = 0; i < NUM_BITS; ++i) {
                Arrays.fill(earliest[i], n);
            }
            int[] better = new int[NUM_BITS];
            for (int i = n - 1; i >= 0; --i) {
                int x = a[i];
                Arrays.fill(better, n);
                for (int u = 0; u < NUM_BITS; ++u)
                    if ((x & (1 << u)) != 0) {
                        better[u] = i;
                        int[] cur = earliest[u];
                        for (int v = 0; v < NUM_BITS; ++v) {
                            if (cur[v] < better[v]) {
                                better[v] = cur[v];
                            }
                        }
                    }
                for (int u = 0; u < NUM_BITS; ++u)
                    if ((x & (1 << u)) != 0) {
                        System.arraycopy(better, 0, earliest[u], 0, NUM_BITS);
                    }

                int some = Integer.numberOfTrailingZeros(x);
                int qi = firstByLeft[i];
                while (qi >= 0) {
                    int dest = qr[qi];
                    int some2 = Integer.numberOfTrailingZeros(a[dest]);
                    answers[qi] = some < NUM_BITS && some2 < NUM_BITS && (earliest[some][some2] <= dest);
                    qi = nextSameLeft[qi];
                }
            }
            for (int i = 0; i < q; ++i) {
                if (answers[i]) {
                    out.println("Shi");
                } else {
                    out.println("Fou");
                }
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