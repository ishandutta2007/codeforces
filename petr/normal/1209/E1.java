import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        TaskE2 solver = new TaskE2();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskE2 {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            TaskE2.Column[] columns = new TaskE2.Column[m];
            for (int i = 0; i < m; ++i) columns[i] = new TaskE2.Column(new int[n]);
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    columns[j].vals[i] = in.nextInt();
                }
            }
            for (int i = 0; i < m; ++i) columns[i].initMax();
            Arrays.sort(columns, new Comparator<TaskE2.Column>() {

                public int compare(TaskE2.Column o1, TaskE2.Column o2) {
                    return o2.max - o1.max;
                }
            });
            if (columns.length > n) {
                columns = Arrays.copyOf(columns, n);
            }
            out.println(solveOne(columns));
        }

        private int solveOne(TaskE2.Column[] columns) {
            int n = columns[0].vals.length;
            int[] best = new int[1 << n];
            int[] next = new int[1 << n];
            int[] tmp = new int[1 << n];
            for (TaskE2.Column c : columns) {
                System.arraycopy(best, 0, next, 0, best.length);
                for (int rot = 0; rot < n; ++rot) {
                    System.arraycopy(best, 0, tmp, 0, best.length);
                    for (int i = 0, pos = rot; i < n; ++i, ++pos) {
                        if (pos >= n) pos = 0;
                        int val = c.vals[pos];
                        for (int j = 0; j < tmp.length; ++j)
                            if ((j & (1 << i)) == 0) {
                                tmp[j ^ (1 << i)] = Math.max(tmp[j ^ (1 << i)], tmp[j] + val);
                            }
                    }
                    for (int j = 0; j < tmp.length; ++j) {
                        next[j] = Math.max(next[j], tmp[j]);
                    }
                }
                int[] aa = best;
                best = next;
                next = aa;
            }
            return best[best.length - 1];
        }

        static class Column {
            int[] vals;
            int max;

            public Column(int[] vals) {
                this.vals = vals;
            }

            void initMax() {
                max = 0;
                for (int x : vals) max = Math.max(max, x);
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