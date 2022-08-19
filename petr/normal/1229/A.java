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
            long[] a = new long[n];
            for (int i = 0; i < n; ++i) a[i] = in.nextLong();
            long[] b = new long[n];
            for (int i = 0; i < n; ++i) b[i] = in.nextLong();
            int[] deg = new int[n];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) if (i != j && (a[i] & a[j]) == a[i]) ++deg[i];
            }
            boolean[] take = new boolean[n];
            Arrays.fill(take, true);
            while (true) {
                boolean upd = false;
                for (int i = 0; i < n; ++i)
                    if (take[i] && deg[i] == 0) {
                        take[i] = false;
                        for (int j = 0; j < n; ++j) if (take[j] && i != j && (a[i] & a[j]) == a[j]) --deg[j];
                        upd = true;
                    }
                if (!upd) break;
            }
            long res = 0;
            for (int i = 0; i < n; ++i) if (take[i]) res += b[i];
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