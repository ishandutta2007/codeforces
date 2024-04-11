import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.HashMap;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; ++i) a[i] = in.nextInt();
            int[] right = new int[n];
            int[] left = new int[n];
            Arrays.fill(right, n);
            Arrays.fill(left, -1);
            for (int bit = 0; bit < 30; ++bit) {
                int prev = -1;
                for (int i = 0; i < n; ++i) {
                    if ((a[i] & (1 << bit)) == 0) {
                        left[i] = Math.max(left[i], prev);
                    } else {
                        prev = i;
                    }
                }
                prev = n;
                for (int i = n - 1; i >= 0; --i) {
                    if ((a[i] & (1 << bit)) == 0) {
                        right[i] = Math.min(right[i], prev);
                    } else {
                        prev = i;
                    }
                }
            }
            HashMap<Integer, Integer> lastSeen = new HashMap<>();
            for (int i = 0; i < n; ++i) {
                Integer old = lastSeen.get(a[i]);
                if (old != null)
                    left[i] = Math.max(left[i], old);
                lastSeen.put(a[i], i);
            }
            long res = n * (long) (n + 1) / 2;
            for (int i = 0; i < n; ++i) {
                res -= (i - left[i]) * (long) (right[i] - i);
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