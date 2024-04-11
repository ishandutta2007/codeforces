import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Collections;
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
        static final long MODULO = (long) (1e9 + 7);
        static final int MAX_N = 100000;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long[] invs = new long[MAX_N + 1];
            invs[1] = 1;
            for (int i = 2; i < invs.length; ++i) {
                invs[i] = (MODULO - (MODULO / i) * invs[((int) (MODULO % i))] % MODULO) % MODULO;
            }
            int m = in.nextInt();
            int len = in.next().length();
            List<Query> queries = new ArrayList<>();
            for (int i = 0; i < m; ++i) {
                int t = in.nextInt();
                if (t == 1) {
                    len = in.next().length();
                } else if (t == 2) {
                    queries.add(new Query(queries.size(), len, in.nextInt()));
                } else throw new RuntimeException();
            }
            Collections.sort(queries);
            int left = 0;
            while (left < queries.size()) {
                int right = left;
                len = queries.get(left).len;
                while (right < queries.size() && queries.get(right).len == len) ++right;
                while (left < right && queries.get(left).n < len) {
                    ++left;
                }
                if (left < right) {
                    int n = len;
                    long cur = 1;
                    long comb = 1;
                    for (int i = left; i < right; ++i) {
                        Query q = queries.get(i);
                        while (n < q.n) {
                            ++n;
                            comb = comb * (n - 1) % MODULO * invs[n - len] % MODULO * 25 % MODULO;
                            cur = (cur * 26 + comb) % MODULO;
                        }
                        q.answer = cur;
                    }
                    left = right;
                }
            }

            long[] res = new long[queries.size()];
            for (Query q : queries) {
                res[q.index] = q.answer;
            }

            for (long x : res) {
                out.println(x);
            }
        }

        static class Query implements Comparable<Query> {
            int index;
            int len;
            int n;
            long answer = 0;

            public Query(int index, int len, int n) {
                this.index = index;
                this.len = len;
                this.n = n;
            }


            public int compareTo(Query o) {
                int z = len - o.len;
                if (z == 0) z = n - o.n;
                return z;
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