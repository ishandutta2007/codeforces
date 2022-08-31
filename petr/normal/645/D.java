import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
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
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            Vertex[] v = new Vertex[n];
            for (int i = 0; i < n; ++i) {
                v[i] = new Vertex();
            }
            for (int i = 0; i < m; ++i) {
                Vertex a = v[in.nextInt() - 1];
                Vertex b = v[in.nextInt() - 1];
                a.outgo.add(new Edge(b, i + 1));
            }
            List<Vertex> topSort = new ArrayList<>();
            for (Vertex start : v) {
                start.ts(topSort);
            }
            if (topSort.size() != n) throw new RuntimeException();
            int res = -1;
            for (int i = 0; i + 1 < n; ++i) {
                Vertex a = topSort.get(i);
                Vertex b = topSort.get(i + 1);
                Edge found = null;
                for (Edge e : b.outgo) if (e.dest == a) found = e;
                if (found == null) {
                    out.println(-1);
                    return;
                }
                res = Math.max(res, found.index);
            }
            out.println(res);
        }

        static class Edge {
            Vertex dest;
            int index;

            public Edge(Vertex dest, int index) {
                this.dest = dest;
                this.index = index;
            }

        }

        static class Vertex {
            boolean visited = false;
            List<Edge> outgo = new ArrayList<>(1);

            public void ts(List<Vertex> topSort) {
                if (visited) return;
                visited = true;
                for (Edge e : outgo) e.dest.ts(topSort);
                topSort.add(this);
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