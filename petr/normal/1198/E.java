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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        static final int INF = (int) 1.1e9;
        static List<TaskE.Vertex> vs = new ArrayList<>();

        private long maxFlow(TaskE.Vertex source, TaskE.Vertex sink) {
            for (TaskE.Vertex v : vs) {
                for (TaskE.Edge e : v.outgo) {
                    e.flow = 0;
                }
            }
            long res = 0;
            while (true) {
                for (TaskE.Vertex v : vs) v.mark = false;
                long by = source.dfs(sink, INF);
                if (by == 0) break;
                res += by;
            }
            return res;
        }

        TaskE.Edge addEdge(TaskE.Vertex a, TaskE.Vertex b, long cap) {
            TaskE.Edge ab = new TaskE.Edge();
            TaskE.Edge ba = new TaskE.Edge();
            ab.rev = ba;
            ba.rev = ab;
            ab.cap = cap;
            ba.cap = 0;
            ab.dest = b;
            ba.dest = a;
            a.outgo.add(ab);
            b.outgo.add(ba);
            return ab;
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            TaskE.Vertex source = new TaskE.Vertex();
            TaskE.Vertex sink = new TaskE.Vertex();
            in.nextInt();
            int m = in.nextInt();
            if (m == 0) {
                out.println(0);
                return;
            }
            int[] x = new int[2 * m];
            int[] y = new int[2 * m];
            for (int i = 0; i < m; ++i) {
                x[i * 2] = in.nextInt() - 1;
                y[i * 2] = in.nextInt() - 1;
                x[i * 2 + 1] = in.nextInt();
                y[i * 2 + 1] = in.nextInt();
            }
            int[] sx = x.clone();
            int[] sy = y.clone();
            Arrays.sort(sx);
            Arrays.sort(sy);
            TaskE.Vertex[] vx = new TaskE.Vertex[sx.length - 1];
            for (int i = 0; i < vx.length; ++i) {
                vx[i] = new TaskE.Vertex();
                addEdge(source, vx[i], sx[i + 1] - sx[i]);
            }
            TaskE.Vertex[] vy = new TaskE.Vertex[sy.length - 1];
            for (int i = 0; i < vy.length; ++i) {
                vy[i] = new TaskE.Vertex();
                addEdge(vy[i], sink, sy[i + 1] - sy[i]);
            }
            TaskE.Vertex[] vmid = new TaskE.Vertex[m];
            for (int i = 0; i < vmid.length; ++i) {
                vmid[i] = new TaskE.Vertex();
                for (int j = 0; j < vx.length; ++j)
                    if (sx[j] >= x[2 * i] && sx[j + 1] <= x[2 * i + 1]) {
                        addEdge(vx[j], vmid[i], INF);
                    }
                for (int j = 0; j < vy.length; ++j)
                    if (sy[j] >= y[2 * i] && sy[j + 1] <= y[2 * i + 1]) {
                        addEdge(vmid[i], vy[j], INF);
                    }
            }
            out.println(maxFlow(source, sink));
        }

        static class Edge {
            TaskE.Vertex dest;
            long cap;
            long flow;
            TaskE.Edge rev;

        }

        static class Vertex {
            boolean mark = false;
            int ptr = 0;
            List<TaskE.Edge> outgo = new ArrayList<>();

            public Vertex() {
                vs.add(this);
            }

            public long dfs(TaskE.Vertex sink, long max) {
                if (this == sink) return max;
                mark = true;
                for (int i = 0; i < outgo.size(); ++i) {
                    TaskE.Edge e = outgo.get(ptr);
                    if (e.flow < e.cap && !e.dest.mark) {
                        long by = Math.min(max, e.cap - e.flow);
                        by = e.dest.dfs(sink, by);
                        if (by > 0) {
                            e.flow += by;
                            e.rev.flow -= by;
                            return by;
                        }
                    }
                    ++ptr;
                    if (ptr == outgo.size()) ptr = 0;
                }
                return 0;
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