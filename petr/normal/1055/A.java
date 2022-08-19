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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        private static final String NO = "NO";
        private static final String YES = "YES";

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int s = in.nextInt() - 1;
            int[] a = new int[n];
            int[] b = new int[n];
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
            }
            for (int i = 0; i < n; ++i) {
                b[i] = in.nextInt();
            }
            if (a[0] == 0) {
                out.println(NO);
                return;
            }
            if (a[s] > 0) {
                out.println(YES);
                return;
            }
            if (b[s] == 0) {
                out.println(NO);
                return;
            }
            for (int i = s + 1; i < n; ++i) {
                if (a[i] > 0 && b[i] > 0) {
                    out.println(YES);
                    return;
                }
            }
            out.println(NO);
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