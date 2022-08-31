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
            long k = in.nextLong();
            int[] a = new int[n];
            int numInteresting = 0;
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
                numInteresting += 2 * (int) Math.ceil(Math.sqrt(a[i])) + 10;
            }
            long[] interesting = new long[numInteresting];
            numInteresting = 1;
            interesting[0] = 1L << 32;
            long base = 0;
            long step = 0;
            for (int x : a) {
                step += x;
                int pw = 0;
                for (int d = 1; ; ) {
                    int w = (x + d - 1) / d;
                    if (d > 1) {
                        interesting[numInteresting++] = ((long) d << 32) | (pw - w);
                    }
                    if (w == 1) break;
                    pw = w;
                    d = (x + w - 2) / (w - 1);
                }
            }
            interesting = Arrays.copyOf(interesting, numInteresting);
            Arrays.sort(interesting);
            long res = 0;
            int pd = 1;
            for (int i = 0; i < numInteresting; ++i) {
                int d = (int) (interesting[i] >> 32);
                base += step * (d - pd);
                pd = d;
                int dstep = (int) (interesting[i] & ((1L << 32) - 1));
                base -= dstep * d;
                step -= dstep;
                if (base <= k) {
                    long upto = d + (k - base) / step;
                    res = Math.max(res, upto);
                }
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}