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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] p = new int[n];
            p[0] = -1;
            for (int i = 1; i < n; ++i) {
                p[i] = in.nextInt() - 1;
            }
            long[] s = new long[n];
            for (int i = 0; i < n; ++i) s[i] = in.nextLong();
            long[] min = new long[n];
            Arrays.fill(min, Long.MAX_VALUE);
            for (int i = 1; i < n; ++i) {
                if (s[i] >= 0 && s[p[i]] < 0) {
                    min[p[i]] = Math.min(min[p[i]], s[i]);
                }
            }
            for (int i = 1; i < n; ++i)
                if (s[i] < 0) {
                    long got = min[i];
                    if (got == Long.MAX_VALUE) got = s[p[i]];
                    s[i] = got;
                }
            long res = s[0];
            for (int i = 1; i < n; ++i) {
                if (s[i] < s[p[i]]) {
                    out.println(-1);
                    return;
                }
                res += s[i] - s[p[i]];
            }
            out.println(res);
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