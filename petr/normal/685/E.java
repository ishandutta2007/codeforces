import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.util.Comparator;
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
            int m = in.nextInt();
            int q = in.nextInt();
            TaskE.Road[] roads = new TaskE.Road[m];
            for (int i = 0; i < m; ++i) {
                TaskE.Road r = new TaskE.Road();
                r.u = in.nextInt() - 1;
                r.v = in.nextInt() - 1;
                roads[i] = r;
            }
            TaskE.Query[] queries = new TaskE.Query[q];
            for (int i = 0; i < q; ++i) {
                TaskE.Query t = new TaskE.Query();
                t.l = in.nextInt() - 1;
                t.r = in.nextInt() - 1;
                t.s = in.nextInt() - 1;
                t.t = in.nextInt() - 1;
                queries[i] = t;
            }
            TaskE.Query[] unsortedQueries = queries.clone();
            Arrays.sort(queries, new Comparator<TaskE.Query>() {

                public int compare(TaskE.Query o1, TaskE.Query o2) {
                    return Integer.compare(o1.r, o2.r);
                }
            });
            int[][] latest = new int[n][n];
            for (int[] x : latest) Arrays.fill(x, -1);
            int qid = 0;
            for (int time = 0; time < m; ++time) {
                TaskE.Road r = roads[time];
                int u = r.u;
                int v = r.v;
                int[] lu = latest[u];
                int[] lv = latest[v];
                lu[v] = lv[u] = time;
                for (int o = 0; o < n; ++o) {
                    int ou = lu[o];
                    int ov = lv[o];
                    if (ou < ov) {
                        lu[o] = ov;
                    } else {
                        lv[o] = ou;
                    }
                }
                while (qid < queries.length && queries[qid].r == time) {
                    queries[qid].res = queries[qid].l <= latest[queries[qid].t][queries[qid].s];
                    ++qid;
                }
            }
            if (qid != queries.length) throw new RuntimeException();
            for (TaskE.Query t : unsortedQueries) {
                if (t.res) {
                    out.println("Yes");
                } else {
                    out.println("No");
                }
            }
        }

        static class Query {
            int l;
            int r;
            int s;
            int t;
            boolean res;

        }

        static class Road {
            int u;
            int v;

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