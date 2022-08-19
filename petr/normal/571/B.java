import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
            }
            Random random = new Random(5437154351L + System.currentTimeMillis());
            for (int i = 0; i < n; ++i) {
                int j = i + random.nextInt(n - i);
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
            Arrays.sort(a);

            int[] b = new int[n];
            for (int i = 0; i < n - 1; ++i) {
                b[i] = a[i + 1] - a[i];
            }

            int res = a[a.length - 1] - a[0];

            int smallChains = k - n % k;
            int bigChains = n % k;
            int smallChainLength = n / k;

            int[] best = new int[]{0};
            for (int i = 0; i < k; ++i) {
                int[] nbest = new int[Math.min(smallChains + 1, best.length + 1)];
                Arrays.fill(nbest, Integer.MIN_VALUE);
                for (int old = 0; old < best.length; ++old)
                    if (best[old] > Integer.MIN_VALUE) {
                        if (old + 1 < nbest.length) {
                            nbest[old + 1] = Math.max(nbest[old + 1], best[old] + b[(i + 1) * smallChainLength + (i - old) - 1]);
                        }
                        if (i + 1 - old <= bigChains) {
                            nbest[old] = Math.max(nbest[old], best[old] + b[(i + 1) * smallChainLength + (i - old)]);
                        }
                    }
                best = nbest;
            }

            res -= best[smallChains];
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

    }
}