import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        static final long INF = (long) 1.001e9;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long[][] d = new long[n][n];
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    d[i][j] = d[j][i] = in.nextInt();
                }
                d[i][i] = INF;
            }
            long mn = INF;
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    mn = Math.min(mn, d[i][j]);
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    d[i][j] -= mn;
            long[] dist = new long[n];
            for (int i = 0; i < n; ++i) {
                dist[i] = 2 * INF;
                for (int j = 0; j < n; ++j) {
                    dist[i] = Math.min(dist[i], 2 * d[i][j]);
                }
            }
            boolean[] mark = new boolean[n];
            while (true) {
                long best = 3 * INF;
                int bi = -1;
                for (int i = 0; i < n; ++i)
                    if (!mark[i] && dist[i] < best) {
                        best = dist[i];
                        bi = i;
                    }
                if (bi < 0) break;
                mark[bi] = true;
                for (int i = 0; i < n; ++i) dist[i] = Math.min(dist[i], dist[bi] + d[bi][i]);
            }
            for (int i = 0; i < n; ++i) {
                out.println(mn * (long) (n - 1) + dist[i]);
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