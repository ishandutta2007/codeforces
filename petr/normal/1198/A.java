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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int bits = Math.min(25, in.nextInt() * 8 / n);
            int maxUnique = 1 << bits;
            int[] a = new int[n];
            for (int i = 0; i < n; ++i) a[i] = in.nextInt();
            Random random = new Random(5734153453315151L + System.currentTimeMillis());
            for (int i = 0; i < n; ++i) {
                int j = random.nextInt(i + 1);
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
            Arrays.sort(a);
            int[] uid = new int[n];
            for (int i = 1; i < n; ++i) {
                uid[i] = uid[i - 1];
                if (a[i] > a[i - 1]) ++uid[i];
            }
            int left = 0;
            int res = n;
            for (int right = 0; right < n; ++right) {
                while (left <= right && uid[right] - uid[left] + 1 > maxUnique) ++left;
                res = Math.min(res, n - (right - left + 1));
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

    }
}