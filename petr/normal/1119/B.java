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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        Random random = new Random(543534151132L + System.currentTimeMillis());

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int h = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
            }

            int left = 0;
            int right = n + 1;
            while (right - left > 1) {
                int middle = (right + left) / 2;
                int[] b = Arrays.copyOf(a, middle);
                mySort(b);
                long got = h;
                for (int i = b.length - 1; i >= 0; i -= 2) {
                    got -= b[i];
                }
                if (got >= 0) {
                    left = middle;
                } else {
                    right = middle;
                }
            }
            out.println(left);

        }

        private void mySort(int[] s) {
            for (int i = 0; i < s.length; ++i) {
                int j = random.nextInt(i + 1);
                int t = s[i];
                s[i] = s[j];
                s[j] = t;
            }
            Arrays.sort(s);
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