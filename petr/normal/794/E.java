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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; ++i) a[i] = in.nextInt();
            int[] res = new int[n];
            for (int i = 0; i < n; ++i) res[n - 1] = Math.max(res[n - 1], a[i]);
            for (int i = 0; i + 1 < n; ++i) {
                int got = Math.max(a[i], a[i + 1]);
                int left = i;
                int right = n - i - 2;
                int need = Math.max(right, left) - Math.min(right, left);
                res[need] = Math.max(res[need], got);
            }
            for (int i = 0; i + 2 < n; ++i) {
                int got = Math.min(a[i + 1], Math.max(a[i], a[i + 2]));
                int left = i;
                int right = n - i - 3;
                int need = Math.max(right, left) - Math.min(right, left);
                res[need] = Math.max(res[need], got);
            }
            for (int i = 2; i < n; ++i) res[i] = Math.max(res[i], res[i - 2]);
            for (int i = 0; i < n; ++i) {
                if (i > 0) out.print(" ");
                out.print(res[i]);
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