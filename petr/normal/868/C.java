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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();
            int[] am = new int[1 << k];
            for (int i = 0; i < n; ++i) {
                int v = 0;
                for (int j = 0; j < k; ++j) v = v * 2 + in.nextInt();
                ++am[v];
            }
            for (int subset = 1; subset < (1 << k); ++subset) {
                int s = 0;
                boolean found = false;
                for (int v = 0; v < am.length; ++v) {
                    if (am[v] > 0 && Integer.bitCount(v & subset) * 2 <= Integer.bitCount(subset)) {
                        found = true;
                    }
                }
                if (!found) {
                    out.println("NO");
                    return;
                }
            }
            if (k == 4) {
                int numOnly3 = 0;
                for (int i = 0; i < k; ++i) {
                    boolean only3 = true;
                    for (int v = 0; v < am.length; ++v)
                        if (am[v] > 0 && (v & (1 << i)) == 0) {
                            if (Integer.bitCount(v) < 3) only3 = false;
                        }
                    if (only3) ++numOnly3;
                }
                int num1 = 0;
                for (int v = 0; v < am.length; ++v) if (am[v] > 0 && Integer.bitCount(v) == 1) num1 += am[v];
                if (num1 < numOnly3) {
                    out.println("NO");
                    return;
                }
            }
            out.println("YES");
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