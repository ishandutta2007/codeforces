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
        static final int MODULO = (int) (1e9 + 7);

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n0 = in.nextInt();
            int m0 = in.nextInt();
            int[] first = new int[10 * (n0 + 12 * m0)];
            int[] next = new int[2 * (7 * m0)];
            int[] dest = new int[2 * (7 * m0)];
            int n = n0;
            int m = 0;
            Arrays.fill(first, -1);
            for (int i = 1; i <= m0; ++i) {
                int x = in.nextInt() - 1;
                int y = in.nextInt() - 1;
                for (int iter = 0; iter < 2; ++iter) {
                    int tmp = i;
                    int cur = iter == 0 ? x : y;
                    while (tmp > 0) {
                        int d = tmp % 10;
                        tmp /= 10;
                        int nxt = (tmp == 0 ? (iter == 0 ? y : x) : n++);
                        dest[m] = cur;
                        next[m] = first[10 * nxt + d];
                        first[10 * nxt + d] = m;
                        ++m;
                        cur = nxt;
                    }
                }
            }
            int[] dist = new int[n];
            Arrays.fill(dist, -1);
            dist[0] = 0;
            int[] queue = new int[n + 1];
            boolean[] blockStart = new boolean[n + 1];
            int qt = 0;
            int qh = 1;
            blockStart[0] = true;
            queue[0] = 0;
            blockStart[1] = true;
            while (qt < qh) {
                int qm = qt + 1;
                while (qm < qh && !blockStart[qm]) ++qm;
                for (int d = 0; d < 10; ++d) {
                    for (int i = qt; i < qm; ++i) {
                        int cur = queue[i];
                        int e = first[cur * 10 + d];
                        while (e >= 0) {
                            int b = dest[e];
                            if (dist[b] < 0) {
                                dist[b] = (int) ((dist[cur] * (long) 10 + d) % MODULO);
                                queue[qh++] = b;
                            }
                            e = next[e];
                        }
                    }
                    blockStart[qh] = true;
                }
                qt = qm;
            }
            for (int i = 1; i < n0; ++i) {
                if (dist[i] < 0) throw new RuntimeException();
                out.println(dist[i]);
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