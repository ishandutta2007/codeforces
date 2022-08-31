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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        static final int INF = (int) 2e9;
        public static final int MAXLOG = 10;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[][] min = new int[2 * MAXLOG][n];
            for (int i = 0; i < MAXLOG; ++i) {
                for (int b = 0; b < 2; ++b) {
                    int cnt = 0;
                    for (int j = 0; j < n; ++j) {
                        if (((j >> i) & 1) == b) ++cnt;
                    }
                    if (cnt == 0) {
                        Arrays.fill(min[i * 2 + b], INF);
                        continue;
                    }
                    out.println(cnt);
                    boolean first = true;
                    for (int j = 0; j < n; ++j) {
                        if (((j >> i) & 1) == b) {
                            if (first) first = false;
                            else out.print(" ");
                            out.print(j + 1);
                        }
                    }
                    out.println();
                    out.flush();
                    for (int j = 0; j < n; ++j) {
                        min[i * 2 + b][j] = in.nextInt();
                    }
                }
            }
            out.println(-1);
            for (int j = 0; j < n; ++j) {
                if (j > 0) out.print(" ");
                int res = INF;
                for (int i = 0; i < MAXLOG; ++i) {
                    for (int b = 0; b < 2; ++b) {
                        if (((j >> i) & 1) != b) {
                            res = Math.min(res, min[i * 2 + b][j]);
                        }
                    }
                }
                out.print(res);
            }
            out.println();
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