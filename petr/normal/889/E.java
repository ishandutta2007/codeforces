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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long[] a = new long[n];
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextLong();
                if (i > 0) a[i] = Math.min(a[i], a[i - 1]);
            }
            long[] offset = new long[n + 1];
            long[] u = new long[n + 1];
            int count = 1;
            offset[0] = 1;
            for (int i = n - 1; i >= 0; --i) {
                if (a[i] > offset[count - 1]) {
                    u[count] = offset[count - 1] * (i + 1);
                    offset[count] = a[i];
                    ++count;
                }
            }
            long[] query = new long[20 * n + 1];
            long[] delta = new long[20 * n + 1];
            long[] fullDelta = new long[20 * n + 1];
            int[] next = new int[20 * n + 1];
            int[] first = new int[count];
            Arrays.fill(first, -1);
            int queries = 0;
            while (count > 1) {
                int now = first[count - 1];
                while (true) {
                    long q = now < 0 ? offset[count - 1] : query[now];
                    long p = offset[count - 2];
                    long d = now < 0 ? fullDelta[count - 1] : delta[now];
                    long nq = q % p;
                    long whole = q / p;
                    if (whole <= 0) throw new RuntimeException();
                    fullDelta[count - 2] = Math.max(fullDelta[count - 2], d + u[count - 1] * (whole - 1));
                    if (nq > 0) {
                        long newDelta = d + u[count - 1] * whole;
                        int left = -1;
                        int right = count - 1;
                        while (right - left > 1) {
                            int middle = (left + right) >> 1;
                            if (nq > offset[middle]) {
                                left = middle;
                            } else {
                                right = middle;
                            }
                        }
                        if (nq == offset[right]) {
                            fullDelta[right] = Math.max(fullDelta[right], newDelta);
                        } else {
                            query[queries] = nq;
                            delta[queries] = newDelta;
                            next[queries] = first[right];
                            first[right] = queries;
                            ++queries;
                        }
                    }
                    if (now < 0) break;
                    now = next[now];
                }
                --count;
            }
            out.println(fullDelta[0]);
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