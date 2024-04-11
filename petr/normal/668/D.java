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
        int[] fenwick;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            Query[] qs = new Query[n];
            int[] res = new int[n];
            Arrays.fill(res, -1);
            for (int i = 0; i < n; ++i) {
                qs[i] = new Query();
                qs[i].index = i;
                int kind = in.nextInt();
                if (kind == 1) {
                    qs[i].delta = 1;
                } else if (kind == 2) {
                    qs[i].delta = -1;
                }
                qs[i].when = in.nextInt();
                qs[i].what = in.nextInt();
            }
            Arrays.sort(qs);
            fenwick = new int[n];
            int i = 0;
            while (i < n) {
                int j = i;
                while (j < n && qs[j].what == qs[i].what) ++j;
                for (int k = i; k < j; ++k) {
                    Query q = qs[k];
                    if (q.delta == 0) {
                        res[q.index] = fget(q.index);
                    } else {
                        fupd(q.index, q.delta);
                    }
                }
                for (int k = i; k < j; ++k) {
                    Query q = qs[k];
                    if (q.delta == 0) {
                    } else {
                        fupd(q.index, -q.delta);
                    }
                }
                i = j;
            }
            for (int j = 0; j < n; ++j) if (res[j] >= 0) out.println(res[j]);
        }

        private void fupd(int at, int by) {
            while (at < fenwick.length) {
                fenwick[at] += by;
                at |= at + 1;
            }
        }

        private int fget(int at) {
            int res = 0;
            while (at >= 0) {
                res += fenwick[at];
                at = (at & (at + 1)) - 1;
            }
            return res;
        }

        static class Query implements Comparable<Query> {
            int index;
            int when;
            int what;
            int delta;


            public int compareTo(Query o) {
                int z = what - o.what;
                if (z != 0) return z;
                return when - o.when;
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