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
import java.util.Comparator;
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
        Random random = new Random(543534151132L + System.currentTimeMillis());

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long[] s = new long[n];
            for (int i = 0; i < n; ++i) {
                s[i] = in.nextLong();
            }
            mySort(s);
            int q = in.nextInt();
            TaskD.Query[] queries = new TaskD.Query[q];
            for (int i = 0; i < q; ++i) {
                long l = in.nextLong();
                long r = in.nextLong();
                queries[i] = new TaskD.Query(r - l);
            }
            TaskD.Query[] originalQueries = queries.clone();
            Arrays.sort(queries, new Comparator<TaskD.Query>() {

                public int compare(TaskD.Query o1, TaskD.Query o2) {
                    return Long.compare(o1.dist, o2.dist);
                }
            });

            long[] distances = new long[n - 1];
            for (int i = 0; i + 1 < n; ++i) {
                distances[i] = s[i + 1] - s[i];
            }
            mySort(distances);

            int distancePtr = 0;
            long each = n;
            long at = 0;
            long curAnswer = 0;

            for (int qi = 0; qi < queries.length; ++qi) {
                long need = queries[qi].dist;
                while (distancePtr < distances.length && distances[distancePtr] <= need) {
                    curAnswer += each * (distances[distancePtr] - at);
                    at = distances[distancePtr];
                    --each;
                    ++distancePtr;
                }
                curAnswer += each * (need + 1 - at);
                at = need + 1;
                queries[qi].answer = curAnswer;
            }

            for (TaskD.Query qq : originalQueries) {
                out.print(qq.answer + " ");
            }
            out.println();
        }

        private void mySort(long[] s) {
            for (int i = 0; i < s.length; ++i) {
                int j = random.nextInt(i + 1);
                long t = s[i];
                s[i] = s[j];
                s[j] = t;
            }
            Arrays.sort(s);
        }

        static class Query {
            long dist;
            long answer = -1;

            public Query(long dist) {
                this.dist = dist;
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