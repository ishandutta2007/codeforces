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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int height = in.nextInt();
            int width = in.nextInt();
            int n1 = in.nextInt();
            int n2 = in.nextInt();
            int v = in.nextInt();
            int[] p1 = new int[n1];
            for (int i = 0; i < n1; ++i) p1[i] = in.nextInt();
            int[] p2 = new int[n2];
            for (int i = 0; i < n2; ++i) p2[i] = in.nextInt();
            int nq = in.nextInt();
            for (int iq = 0; iq < nq; ++iq) {
                int r1 = in.nextInt();
                int c1 = in.nextInt();
                int r2 = in.nextInt();
                int c2 = in.nextInt();
                if (r1 == r2) {
                    out.println(Math.abs(c1 - c2));
                } else {
                    long res = Long.MAX_VALUE;
                    int pos = Arrays.binarySearch(p1, c1);
                    if (pos < 0) pos = -(pos + 1);
                    if (pos >= 0 && pos < p1.length) {
                        res = Math.min(res, Math.abs(p1[pos] - c1) + Math.abs(p1[pos] - c2) + Math.abs(r1 - r2));
                    }
                    --pos;
                    if (pos >= 0 && pos < p1.length) {
                        res = Math.min(res, Math.abs(p1[pos] - c1) + Math.abs(p1[pos] - c2) + Math.abs(r1 - r2));
                    }
                    pos = Arrays.binarySearch(p2, c1);
                    if (pos < 0) pos = -(pos + 1);
                    if (pos >= 0 && pos < p2.length) {
                        res = Math.min(res, Math.abs(p2[pos] - c1) + Math.abs(p2[pos] - c2) + (Math.abs(r1 - r2) + v - 1) / v);
                    }
                    --pos;
                    if (pos >= 0 && pos < p2.length) {
                        res = Math.min(res, Math.abs(p2[pos] - c1) + Math.abs(p2[pos] - c2) + (Math.abs(r1 - r2) + v - 1) / v);
                    }
                    out.println(res);
                }
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