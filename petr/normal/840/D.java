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
        int BUBEN = 120;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            // zzzzz
            Random random = new Random(94739534513L + System.currentTimeMillis());
            int n = in.nextInt();
            int q = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
            }
            int buben = (int) Math.round(Math.sqrt(n));
            TaskD.Query[] queries = new TaskD.Query[q];
            for (int i = 0; i < q; ++i) {
                queries[i] = new TaskD.Query();
                queries[i].l = in.nextInt() - 1;
                queries[i].r = in.nextInt();
                queries[i].k = in.nextInt();
                queries[i].bucket = queries[i].l / buben;
            }
            TaskD.Query[] originalQueries = queries.clone();
            Arrays.sort(queries, new Comparator<TaskD.Query>() {

                public int compare(TaskD.Query o1, TaskD.Query o2) {
                    if (o1.bucket != o2.bucket) return o1.bucket - o2.bucket;
                    if (o1.r != o2.r) {
                        if ((o1.bucket & 1) == 0) return o1.r - o2.r;
                        else return o2.r - o1.r;
                    }
                    return o1.l - o2.l;
                }
            });
            int[] counts = new int[n + 1];
            int cl = 0;
            int cr = 0;
            for (TaskD.Query qq : queries) {
                while (cr < qq.r) {
                    ++counts[a[cr++]];
                }
                while (cl > qq.l) {
                    ++counts[a[--cl]];
                }
                while (cr > qq.r) {
                    --counts[a[--cr]];
                }
                while (cl < qq.l) {
                    --counts[a[cl++]];
                }
                int res = -1;
                int need = (qq.r - qq.l) / qq.k + 1;
                for (int attempt = 0; attempt < BUBEN; ++attempt) {
                    int x = a[qq.l + random.nextInt(qq.r - qq.l)];
                    if (counts[x] >= need) {
                        if (res < 0 || res > x) res = x;
                    }
                }
                qq.answer = res;
            }
            for (TaskD.Query qq : originalQueries) {
                out.println(qq.answer);
            }
        }

        static class Query {
            int l;
            int r;
            int k;
            int answer;
            int bucket;

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