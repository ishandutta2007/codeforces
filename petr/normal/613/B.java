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
            long A = in.nextLong();
            long cf = in.nextInt();
            long cm = in.nextInt();
            long m = in.nextLong();
            long[] a = new long[n];
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextLong() * n + i;
            }
            Random random = new Random(5431531543151L + System.currentTimeMillis());
            for (int i = 0; i < n; ++i) {
                int j = i + random.nextInt(n - i);
                long t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
            Arrays.sort(a);
            int[] b = new int[n];
            for (int i = 0; i < n; ++i) {
                b[i] = (int) (a[i] % n);
                a[i] /= n;
            }
            long[] growAllTo = new long[n];
            for (int i = 1; i < n; ++i) {
                growAllTo[i] = growAllTo[i - 1] + i * (a[i] - a[i - 1]);
            }
            long needForCap = 0;
            int canGrow = n;
            long maxPower = -1;
            int maxCap = -1;
            int maxCanGrow = -1;
            long maxGrowTo = -1;
            for (int cap = 0; cap <= n; ++cap) {
                if (cap > 0) {
                    needForCap += A - a[n - cap];
                }
                if (needForCap > m) break;
                if (canGrow > n - cap) canGrow = n - cap;
                while (canGrow > 0 && growAllTo[canGrow - 1] + needForCap > m) {
                    --canGrow;
                }
                long power = cf * cap;
                long growTo = 0;
                if (cap == n) {
                    power += cm * A;
                } else if (canGrow > 0) {
                    growTo = Math.min(A, a[canGrow - 1] + (m - growAllTo[canGrow - 1] - needForCap) / canGrow);
                    power += cm * growTo;
                }
                if (power > maxPower) {
                    maxPower = power;
                    maxCap = cap;
                    maxCanGrow = canGrow;
                    maxGrowTo = growTo;
                }
            }
            out.println(maxPower);
            for (int i = 0; i < maxCanGrow; ++i) {
                a[i] = maxGrowTo;
            }
            for (int i = 0; i < maxCap; ++i) {
                a[n - 1 - i] = A;
            }
            long[] res = new long[n];
            for (int i = 0; i < n; ++i) {
                res[b[i]] = a[i];
            }
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}