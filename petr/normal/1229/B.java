import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;
import java.util.ArrayList;

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
        static final long MODULO = (long) 1e9 + 7;

        private long gcd(long a, long b) {
            while (b > 0) {
                long t = a % b;
                a = b;
                b = t;
            }
            return a;
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            Vertex[] vs = new Vertex[n];
            for (int i = 0; i < n; ++i) vs[i] = new Vertex(in.nextLong());
            for (int i = 0; i < n - 1; ++i) {
                Vertex a = vs[in.nextInt() - 1];
                Vertex b = vs[in.nextInt() - 1];
                a.adj.add(b);
                b.adj.add(a);
            }

            long res = vs[0].solve(null);
            out.println(res);
        }

        class Vertex {
            List<Vertex> adj = new ArrayList<>();
            long[] val;
            int[] count;
            int am;
            long x;

            public Vertex(long x) {
                this.x = x;
            }

            public long solve(Vertex parent) {
                val = new long[1 + (parent == null ? 0 : parent.am)];
                count = new int[val.length];
                am = 1;
                val[0] = x;
                count[0] = 1;
                if (parent != null) {
                    for (int i = 0; i < parent.am; ++i) {
                        long g = gcd(val[am - 1], parent.val[i]);
                        if (g == val[am - 1]) {
                            count[am - 1] += parent.count[i];
                        } else {
                            val[am] = g;
                            count[am] = parent.count[i];
                            ++am;
                        }
                    }
                }
                long res = 0;
                for (int i = 0; i < am; ++i) {
                    res += val[i] * count[i];
                }
                for (Vertex v : adj)
                    if (v != parent) {
                        res += v.solve(this);
                    }
                res %= MODULO;
                return res;
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