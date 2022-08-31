import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        static final String UNKNOWN = "UNKNOWN";
        static final String OPEN = "OPEN";
        static final String CLOSED = "CLOSED";
        static final String CORRECT = "CORRECT";
        static final String INCORRECT = "INCORRECT";
        static final int INF = (int) 1e9;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int[] max = new int[3];
            for (int i = 0; i < 3; ++i) max[i] = in.nextInt();
            int n = in.nextInt();
            int m = in.nextInt();
            int k = in.nextInt();
            int[] minOpen = new int[3];
            int[] maxOpen = new int[3];
            Arrays.fill(minOpen, INF);
            Arrays.fill(maxOpen, -INF);
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < 3; ++j) {
                    int at = in.nextInt() - 1;
                    minOpen[j] = Math.min(minOpen[j], at);
                    maxOpen[j] = Math.max(maxOpen[j], at);
                }
            }
            TaskE.Closed[] firstBy0 = new TaskE.Closed[max[0]];
            for (int i = 0; i < m; ++i) {
                TaskE.Closed c = new TaskE.Closed();
                for (int j = 0; j < 3; ++j) {
                    c.coord[j] = in.nextInt() - 1;
                }
                c.nextBy0 = firstBy0[c.coord[0]];
                firstBy0[c.coord[0]] = c;
            }
            TaskE.Query[] queries = new TaskE.Query[k + 1];
            for (int i = -1; i < k; ++i) {
                TaskE.Query q = new TaskE.Query();
                queries[i + 1] = q;
                if (i >= 0) {
                    for (int j = 0; j < 3; ++j) {
                        q.coord[j] = in.nextInt() - 1;
                    }
                } else {
                    for (int j = 0; j < 3; ++j) {
                        q.coord[j] = minOpen[j];
                    }
                }
            }

            for (int stage = 0; stage < 2; ++stage) {
                List<TaskE.Query> stageQueries = new ArrayList<>();
                for (TaskE.Query q : queries) {
                    int qStage = q.coord[0] < minOpen[0] ? 0 : 1;
                    if (stage == qStage) stageQueries.add(q);
                }
                Collections.sort(stageQueries, new Comparator<TaskE.Query>() {

                    public int compare(TaskE.Query o1, TaskE.Query o2) {
                        return o1.coord[0] - o2.coord[0];
                    }
                });
                if (stage == 0) Collections.reverse(stageQueries);

                TaskE.MinFenwick[][] fenwicks = new TaskE.MinFenwick[2][2];
                for (int i = 0; i < 2; ++i) {
                    int maxCoord = i == 0 ? minOpen[1] : max[1] - minOpen[1];
                    for (int j = 0; j < 2; ++j) {
                        fenwicks[i][j] = new TaskE.MinFenwick(maxCoord);
                    }
                }

                for (int x = minOpen[0]; x <= maxOpen[0]; ++x) {
                    TaskE.Closed c = firstBy0[x];
                    while (c != null) {
                        updateFenwicks(minOpen, fenwicks, c);
                        c = c.nextBy0;
                    }
                }

                int[] qleft = new int[3];
                int[] qright = new int[3];
                int pos = stage == 0 ? minOpen[0] : maxOpen[0];
                int dir = stage == 0 ? -1 : 1;

                for (TaskE.Query q : stageQueries) {
                    while ((pos - q.coord[0]) * dir < 0) {
                        pos += dir;
                        TaskE.Closed c = firstBy0[pos];
                        while (c != null) {
                            updateFenwicks(minOpen, fenwicks, c);
                            c = c.nextBy0;
                        }
                    }
                    for (int j = 0; j < 3; ++j) {
                        qleft[j] = Math.min(minOpen[j], q.coord[j]);
                        qright[j] = Math.max(maxOpen[j], q.coord[j]);
                    }
                    boolean canBeOpen = true;
                    for (int i = 0; i < 2; ++i) {
                        int upto = i == 0 ? (minOpen[1] - 1 - qleft[1]) : (qright[1] - minOpen[1]);
                        for (int j = 0; j < 2; ++j) {
                            int got = fenwicks[i][j].get(upto);
                            if (j == 0) {
                                if (-got >= qleft[2]) canBeOpen = false;
                            } else {
                                if (got <= qright[2]) canBeOpen = false;
                            }
                        }
                    }
                    boolean canBeClosed = false;
                    for (int j = 0; j < 3; ++j)
                        if (q.coord[j] < minOpen[j] || q.coord[j] > maxOpen[j]) canBeClosed = true;
                    if (canBeOpen) {
                        if (canBeClosed) {
                            q.answer = UNKNOWN;
                        } else {
                            q.answer = OPEN;
                        }
                    } else {
                        if (canBeClosed) {
                            q.answer = CLOSED;
                        } else {
                            q.answer = INCORRECT;
                        }
                    }
                }
            }

            for (int i = 0; i < queries.length; ++i) {
                String a = queries[i].answer;
                if (a.equals(OPEN) && i == 0) a = CORRECT;
                out.println(a);
                if (a.equals(INCORRECT)) {
                    if (i > 0) throw new RuntimeException();
                    break;
                }
            }
        }

        private void updateFenwicks(int[] minOpen, TaskE.MinFenwick[][] fenwicks, TaskE.Closed c) {
            int i = c.coord[1] < minOpen[1] ? 0 : 1;
            int pi = i == 0 ? minOpen[1] - 1 - c.coord[1] : c.coord[1] - minOpen[1];
            int j = c.coord[2] < minOpen[2] ? 0 : 1;
            int pj = j == 0 ? -c.coord[2] : c.coord[2];
            fenwicks[i][j].upd(pi, pj);
        }

        static class Query {
            int[] coord = new int[3];
            String answer;

        }

        static class Closed {
            int[] coord = new int[3];
            TaskE.Closed nextBy0;

        }

        static class MinFenwick {
            int[] a;

            public MinFenwick(int n) {
                a = new int[n];
                Arrays.fill(a, INF);
            }

            void upd(int at, int by) {
                while (at < a.length) {
                    a[at] = Math.min(a[at], by);
                    at |= at + 1;
                }
            }

            int get(int upto) {
                int res = INF;
                while (upto >= 0) {
                    res = Math.min(res, a[upto]);
                    upto = (upto & (upto + 1)) - 1;
                }
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

    }
}