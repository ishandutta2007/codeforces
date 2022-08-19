import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;
import java.util.ArrayList;

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
        List<Vertex> found2 = new ArrayList<>();

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            Vertex[] vs = new Vertex[n];
            for (int i = 0; i < n; ++i) vs[i] = new Vertex(i + 1);
            for (int i = 0; i < m; ++i) {
                Vertex a = vs[in.nextInt() - 1];
                Vertex b = vs[in.nextInt() - 1];
                a.adj.add(b);
                b.adj.add(a);
            }
            Vertex source = vs[0];
            Vertex target = vs[n - 1];
            bfs(n, source, null);
            int res = target.dist;
            Vertex[] resSeq = null;
            if (res < Integer.MAX_VALUE) {
                resSeq = new Vertex[res + 1];
                int pos = res;
                Vertex at = target;
                while (at != null) {
                    resSeq[pos--] = at;
                    at = at.prev;
                }
                if (pos != -1) throw new RuntimeException();
            }

            if (res > 4) {
                source.mark1 = true;
                for (Vertex v : source.adj) {
                    v.mark1 = true;
                }
                outer1:
                for (Vertex v : source.adj) {
                    for (Vertex w : v.adj) {
                        if (!w.mark1) {
                            res = 4;
                            resSeq = new Vertex[]{source, v, w, source, target};
                            break outer1;
                        }
                    }
                }
            }

            if (res > 5) {
                source.mark1 = false;
                outer2:
                for (Vertex v : source.adj)
                    if (!v.mark2) {
                        found2.clear();
                        v.dfs2();
                        for (Vertex x : found2) {
                            for (Vertex y : found2) y.mark3 = false;
                            x.mark3 = true;
                            for (Vertex e : x.adj) if (e.mark2) e.mark3 = true;
                            for (Vertex y : found2)
                                if (!y.mark3) {
                                    for (Vertex a : vs) a.dist = Integer.MAX_VALUE;
                                    bfs(n, x, source);
                                    for (Vertex z : found2)
                                        if (z.dist == 2) {
                                            res = 5;
                                            resSeq = new Vertex[]{source, x, z.prev, z, x, target};
                                            break outer2;
                                        }
                                    throw new RuntimeException();
                                }
                        }
                    }
            }

            if (res == Integer.MAX_VALUE) {
                out.println(-1);
            } else {
                out.println(res);
                for (Vertex v : resSeq) {
                    out.print(v.id + " ");
                }
                out.println();
            }
        }

        private void bfs(int n, Vertex source, Vertex forbidden) {
            Vertex[] queue = new Vertex[n];
            int qt = 0;
            int qh = 1;
            queue[0] = source;
            source.dist = 0;
            while (qt < qh) {
                Vertex cur = queue[qt++];
                for (Vertex v : cur.adj)
                    if (v != forbidden && v.dist == Integer.MAX_VALUE) {
                        v.dist = cur.dist + 1;
                        v.prev = cur;
                        queue[qh++] = v;
                    }
            }
        }

        class Vertex {
            int id;
            int dist = Integer.MAX_VALUE;
            Vertex prev = null;
            boolean mark1 = false;
            boolean mark2 = false;
            boolean mark3 = false;
            List<Vertex> adj = new ArrayList<>();

            public Vertex(int id) {
                this.id = id;
            }

            public void dfs2() {
                found2.add(this);
                mark2 = true;
                for (Vertex v : adj) if (v.mark1 && !v.mark2) v.dfs2();
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