import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
            long la = in.nextLong();
            long ra = in.nextLong();
            long ta = in.nextLong();
            long lb = in.nextLong();
            long rb = in.nextLong();
            long tb = in.nextLong();
            long g = gcd(ta, tb);
            long by = la / g * g;
            la -= by;
            ra -= by;
            by = lb / g * g;
            lb -= by;
            rb -= by;
            out.println(Math.max(intersect(la, ra, lb, rb), Math.max(intersect(la + g, ra + g, lb, rb), intersect(la, ra, lb + g, rb + g))));
        }

        private long intersect(long la, long ra, long lb, long rb) {
            long res = Math.min(ra, rb) - Math.max(la, lb) + 1;
            if (res < 0) res = 0;
            return res;
        }

        private long gcd(long a, long b) {
            while (b > 0) {
                long t = a % b;
                a = b;
                b = t;
            }
            return a;
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}