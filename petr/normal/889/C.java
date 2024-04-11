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
        static final long MODULO = (long) (1e9 + 7);
        static int[] invs;
        static int[] facts;
        static int[] invfacts;

        static {
            int k = (int) 1e6;
            invs = new int[k + 2];
            invs[1] = 1;
            for (int i = 2; i <= k + 1; ++i) {
                invs[i] = (int) ((MODULO - (MODULO / i) * (long) invs[(int) (MODULO % i)] % MODULO) % MODULO);
            }
            facts = new int[k + 2];
            invfacts = new int[k + 2];
            facts[0] = 1;
            invfacts[0] = 1;
            for (int i = 1; i <= k + 1; ++i) {
                facts[i] = (int) (facts[i - 1] * (long) i % MODULO);
                invfacts[i] = (int) (invfacts[i - 1] * (long) invs[i] % MODULO);
            }
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();
            long[] res = new long[n + 1];
            long[] prefixSum = new long[n + 1];
            res[1] = 1;
            prefixSum[1] = 1;
            for (int i = 2; i <= n; ++i) {
                res[i] = prefixSum[i - 1] - prefixSum[Math.max(1, i - k) - 1];
                if (res[i] < 0) res[i] += MODULO;
                res[i] = res[i] * invs[i - 1] % MODULO;
                prefixSum[i] = (prefixSum[i - 1] + res[i]) % MODULO;
            }
            long sum = 0;
            for (int i = 1; i <= n; ++i) {
                sum = (sum + res[i] * facts[n - 1] % MODULO) % MODULO;
            }
            long ret = ((facts[n] - sum) % MODULO + MODULO) % MODULO;
            out.println(ret);
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