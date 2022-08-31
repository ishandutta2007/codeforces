import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.Random;
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
            Random random = new Random(547315735151L);
            int n = in.nextInt();
            int m = in.nextInt();
            int[] x = new int[n];
            for (int i = 0; i < n; ++i) {
                x[i] = in.nextInt();
            }
            shuffle(x, random);
            Arrays.sort(x);
            x = Arrays.copyOf(x, n + 1);
            x[n] = (int) 1e9;
            int[] numBlocks = new int[n + 1];
            for (int i = 0; i < m; ++i) {
                int x1 = in.nextInt();
                int x2 = in.nextInt();
                in.nextInt();
                if (x1 != 1) continue;
                int left = -1;
                int right = n + 1;
                while (right - left > 1) {
                    int middle = (left + right) / 2;
                    if (x[middle] <= x2) left = middle;
                    else right = middle;
                }
                if (left >= 0)
                    ++numBlocks[left];
            }
            for (int i = n - 1; i >= 0; --i) numBlocks[i] += numBlocks[i + 1];
            int res = Integer.MAX_VALUE;
            for (int where = 0; where <= n; ++where) {
                res = Math.min(res, where + numBlocks[where]);
            }
            out.println(res);
        }

        private void shuffle(int[] a, Random random) {
            for (int i = 1; i < a.length; ++i) {
                int j = random.nextInt(i + 1);
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
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