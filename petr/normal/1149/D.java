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
        void addEdge(TaskD.Vertex a, TaskD.Vertex b, int c) {
            a.outgo.add(new TaskD.Edge(b, c));
            b.outgo.add(new TaskD.Edge(a, c));
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            int a = in.nextInt();
            int b = in.nextInt();
            TaskD.Vertex[] vs = new TaskD.Vertex[n];
            for (int i = 0; i < n; ++i) {
                vs[i] = new TaskD.Vertex(i);
            }
            for (TaskD.Vertex v : vs) {
                v.representative = v;
                v.size = 1;
            }
            for (int i = 0; i < m; ++i) {
                TaskD.Vertex u = vs[in.nextInt() - 1];
                TaskD.Vertex v = vs[in.nextInt() - 1];
                int c = in.nextInt();
                addEdge(u, v, c);
                if (c == a) {
                    if (u.representative != v.representative) {
                        TaskD.Vertex src = u.representative;
                        TaskD.Vertex dst = v.representative;
                        dst.size += src.size;
                        for (TaskD.Vertex t : vs) if (t.representative == src) t.representative = dst;
                    }
                }
            }
            int tags = 0;
            for (TaskD.Vertex v : vs) {
                if (v.representative == v && v.size >= 4) {
                    for (TaskD.Vertex u : vs) if (u.representative == v) u.tag = tags;
                    ++tags;
                }
            }

            long[] lens = new long[(n + 1) * (n + 1)];
            for (int i = 0; i <= n; ++i) {
                for (int j = 0; j <= n; ++j) {
                    lens[i * (n + 1) + j] = ((a * i + b * j) * (long) (n + 1) + i) * (n + 1) + j;
                }
            }
            Arrays.sort(lens);
            int[] lenId = new int[(n + 1) * (n + 1)];
            for (int pos = 0; pos < lens.length; ++pos) {
                long val = lens[pos];
                int rj = (int) (val % (n + 1));
                val /= n + 1;
                int ri = (int) (val % (n + 1));
                lenId[ri * (n + 1) + rj] = pos;
            }

            int start = 0;
            if (vs[0].tag >= 0) start |= 1 << vs[0].tag;
            int[] dist = new int[n << tags];
            Arrays.fill(dist, lens.length);
            dist[start] = 0;
            int OFFSET = dist.length;
            int[] next = new int[OFFSET + lens.length];
            int[] prev = new int[OFFSET + lens.length];
            for (int i = 0; i < lens.length; ++i) {
                next[OFFSET + i] = prev[OFFSET + i] = OFFSET + i;
            }
            next[start] = OFFSET;
            prev[start] = OFFSET;
            next[prev[start]] = start;
            prev[next[start]] = start;

            for (int what = 0; what < lens.length; ++what) {
                long val = lens[what];
                int rj = (int) (val % (n + 1));
                val /= n + 1;
                int ri = (int) (val % (n + 1));
                int extraa = lens.length;
                if (ri < n) {
                    extraa = lenId[(ri + 1) * (n + 1) + rj];
                }
                int extrab = lens.length;
                if (rj < n) {
                    extrab = lenId[ri * (n + 1) + rj + 1];
                }
                if (extraa <= what || extrab <= what) throw new RuntimeException();
                int cur = next[OFFSET + what];
                while (cur < OFFSET) {
                    int at = cur >> tags;
                    TaskD.Vertex vat = vs[at];
                    int mask = cur & ((1 << tags) - 1);
                    for (TaskD.Edge e : vat.outgo) {
                        TaskD.Vertex d = e.dest;
                        int nat = d.index;
                        int dest = (nat << tags) | mask;
                        if (e.cost == a) {
                            if (d.tag >= 0) {
                                if ((mask & (1 << d.tag)) == 0) throw new RuntimeException();
                            }
                            if (extraa < dist[dest]) {
                                if (dist[dest] < lens.length) {
                                    next[prev[dest]] = next[dest];
                                    prev[next[dest]] = prev[dest];
                                }
                                dist[dest] = extraa;
                                next[dest] = OFFSET + dist[dest];
                                prev[dest] = prev[next[dest]];
                                prev[next[dest]] = dest;
                                next[prev[dest]] = dest;
                            }
                        } else {
                            if (d.representative == vat.representative) continue;
                            if (d.tag >= 0) {
                                if ((mask & (1 << d.tag)) != 0) continue;
                                dest |= 1 << d.tag;
                            }
                            if (extrab < dist[dest]) {
                                if (dist[dest] < lens.length) {
                                    next[prev[dest]] = next[dest];
                                    prev[next[dest]] = prev[dest];
                                }
                                dist[dest] = extrab;
                                next[dest] = OFFSET + dist[dest];
                                prev[dest] = prev[next[dest]];
                                prev[next[dest]] = dest;
                                next[prev[dest]] = dest;
                            }
                        }
                    }
                    cur = next[cur];
                }
            }
            int[] res = new int[n];
            Arrays.fill(res, lens.length);
            for (int i = 0; i < dist.length; ++i) {
                res[i >> tags] = Math.min(res[i >> tags], dist[i]);
            }
            for (int x : res) {
                out.print(lens[x] / (n + 1) / (n + 1));
                out.print(" ");
            }
            out.println();
        }

        static class Edge {
            TaskD.Vertex dest;
            int cost;

            public Edge(TaskD.Vertex dest, int cost) {
                this.dest = dest;
                this.cost = cost;
            }

        }

        static class Vertex {
            int index;
            int tag = -1;
            TaskD.Vertex representative;
            int size;
            List<TaskD.Edge> outgo = new ArrayList<>();

            public Vertex(int index) {
                this.index = index;
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