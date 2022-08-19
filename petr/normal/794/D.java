import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.StringTokenizer;
import java.util.Set;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        static final int INF = (int) 1e9;

        void shortestPaths(TaskD.Vertex start, TaskD.Vertex[] vs) {
            for (TaskD.Vertex v : vs) v.dist = INF;
            start.dist = 0;
            TaskD.Vertex[] q = new TaskD.Vertex[vs.length];
            int qt = 0;
            int qh = 1;
            q[qt] = start;
            while (qt < qh) {
                TaskD.Vertex cur = q[qt++];
                for (TaskD.Vertex v : cur.adj) {
                    if (v.dist == INF) {
                        v.dist = cur.dist + 1;
                        v.prev = cur;
                        q[qh++] = v;
                    }
                }
            }
            if (qh != vs.length) throw new RuntimeException();
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            TaskD.Vertex[] vs = new TaskD.Vertex[n];
            for (int i = 0; i < n; ++i) {
                vs[i] = new TaskD.Vertex();
                vs[i].adj.add(vs[i]);
            }
            for (int i = 0; i < m; ++i) {
                TaskD.Vertex a = vs[in.nextInt() - 1];
                TaskD.Vertex b = vs[in.nextInt() - 1];
                a.adj.add(b);
                b.adj.add(a);
            }

            if (m == n * (long) (n - 1) / 2) {
                out.println("YES");
                for (int i = 0; i < n; ++i) {
                    if (i > 0) out.print(" ");
                    out.print(1);
                }
                out.println();
                return;
            }
            TaskD.Vertex a = null;
            for (TaskD.Vertex v : vs)
                if (v.adj.size() < n) {
                    a = v;
                }
            if (a == null) throw new RuntimeException();
            shortestPaths(a, vs);
            TaskD.Vertex c = null;
            TaskD.Vertex b = null;
            for (TaskD.Vertex v : vs)
                if (v.dist == 2) {
                    c = v;
                    b = v.prev;
                    break;
                }
            if (b == null) throw new RuntimeException();
            if (c == null) throw new RuntimeException();
            shortestPaths(b, vs);
            for (TaskD.Vertex v : vs)
                if (v.dist == 1) {
                    if (v.adj.contains(a) && v.adj.contains(c)) {
                        v.label = 0;
                        v.gotLabel = true;
                    } else if (v.adj.contains(a)) {
                        v.label = 1;
                        v.gotLabel = true;
                    } else if (v.adj.contains(c)) {
                        v.label = -1;
                        v.gotLabel = true;
                    } else {
                        out.println("NO");
                        return;
                    }
                } else if (v.dist == 0) {
                    v.label = 0;
                    v.gotLabel = true;
                }
            for (TaskD.Vertex v : vs)
                if (!v.gotLabel) {
                    v.findLabel();
                }
            int smallest = 0;
            for (TaskD.Vertex v : vs) smallest = Math.min(smallest, v.label);
            for (TaskD.Vertex v : vs) v.label -= smallest;
            int largest = 0;
            for (TaskD.Vertex v : vs) largest = Math.max(largest, v.label);
            long[] count = new long[largest + 1];
            for (TaskD.Vertex v : vs) ++count[v.label];
            long expected = 0;
            for (int i = 0; i <= largest; ++i) {
                expected += count[i] * (count[i] - 1) / 2;
                if (i + 1 <= largest) {
                    expected += count[i] * count[i + 1];
                }
            }
            if (expected != m) {
                out.println("NO");
                return;
            }
            for (TaskD.Vertex v : vs) {
                for (TaskD.Vertex u : v.adj) {
                    if (Math.abs(v.label - u.label) > 1) {
                        out.println("NO");
                        return;
                    }
                }
            }
            out.println("YES");
            for (int i = 0; i < vs.length; ++i) {
                if (i > 0) out.print(" ");
                out.print(vs[i].label + 1);
            }
            out.println();
        }

        static class Vertex {
            TaskD.Vertex prev;
            int dist;
            boolean gotLabel = false;
            int label;
            Set<TaskD.Vertex> adj = new HashSet<>();

            public void findLabel() {
                if (!prev.gotLabel) prev.findLabel();
                gotLabel = true;
                if (prev.label > 0) label = dist;
                else if (prev.label < 0) label = -dist;
                else label = 0;
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