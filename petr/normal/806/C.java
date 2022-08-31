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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long[] a = new long[n];
            int na = 0;
            int[] p2 = new int[60];
            int[] r2 = new int[60];
            for (int i = 0; i < n; ++i) {
                long x = in.nextLong();
                if ((x & (x - 1)) == 0) {
                    ++p2[Long.numberOfTrailingZeros(x)];
                } else {
                    a[na++] = x;
                }
            }
            n = na;
            a = Arrays.copyOf(a, n);
            Arrays.sort(a);
            int max = p2[0];
            int left = 0;
            int right = max + 1;
            outer:
            while (right - left > 1) {
                int middle = (left + right) / 2;
                r2[0] = middle;
                for (int i = 1; i < r2.length; ++i) {
                    r2[i] = Math.min(p2[i], r2[i - 1]);
                }
                int ptr = a.length - 1;
                int total = 0;
                for (int i = p2.length - 1; i >= 0; --i) {
                    while (ptr >= 0 && a[ptr] >= (1L << i)) {
                        --ptr;
                        ++total;
                    }
                    total += p2[i] - r2[i];
                    if (total > r2[i]) {
                        left = middle;
                        continue outer;
                    }
                }
                right = middle;
            }
            if (right > max) {
                out.println(-1);
            } else {
                out.print(right);
                for (int i = right + 1; i <= max; ++i) {
                    out.print(" ");
                    out.print(i);
                }
                out.println();
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}