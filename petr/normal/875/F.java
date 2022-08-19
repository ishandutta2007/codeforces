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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            TaskF.Prince[] prince = new TaskF.Prince[n];
            TaskF.Princess[] princess = new TaskF.Princess[m];
            for (int i = 0; i < n; ++i) {
                prince[i] = new TaskF.Prince();
                prince[i].parent = prince[i];
                prince[i].totalPrinces = 1;
            }
            for (int i = 0; i < m; ++i) {
                princess[i] = new TaskF.Princess();
                princess[i].a = prince[in.nextInt() - 1];
                princess[i].b = prince[in.nextInt() - 1];
                princess[i].w = in.nextInt();
            }
            Arrays.sort(princess, new Comparator<TaskF.Princess>() {

                public int compare(TaskF.Princess o1, TaskF.Princess o2) {
                    return o2.w - o1.w;
                }
            });
            long res = 0;
            for (TaskF.Princess p : princess) {
                TaskF.Prince ra = get(p.a);
                TaskF.Prince rb = get(p.b);
                if (ra != rb) {
                    rb.totalPrinces += ra.totalPrinces;
                    rb.totalPrincesses += ra.totalPrincesses;
                    ra.parent = rb;
                }
                if (rb.totalPrincesses < rb.totalPrinces) {
                    ++rb.totalPrincesses;
                    res += p.w;
                }
            }
            out.println(res);
        }

        private TaskF.Prince get(TaskF.Prince a) {
            TaskF.Prince res = a;
            while (res.parent != res) res = res.parent;
            TaskF.Prince tmp = a;
            while (tmp.parent != res) {
                TaskF.Prince nxt = tmp.parent;
                tmp.parent = res;
                tmp = nxt;
            }
            return res;
        }

        static class Prince {
            TaskF.Prince parent;
            int totalPrinces;
            int totalPrincesses;

        }

        static class Princess {
            TaskF.Prince a;
            TaskF.Prince b;
            int w;

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