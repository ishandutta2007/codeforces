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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            TaskC.Vertex[] vs = new TaskC.Vertex[n];
            for (int i = 0; i < n; ++i) vs[i] = new TaskC.Vertex(i);
            for (int i = 0; i < m; ++i) {
                TaskC.Vertex a = vs[in.nextInt() - 1];
                TaskC.Vertex b = vs[in.nextInt() - 1];
                if (a.score < b.score) {
                    a.biggerNeighbors.add(b);
                } else {
                    b.biggerNeighbors.add(a);
                }
                ++a.deg;
                ++b.deg;
            }
            long res = 0;
            for (TaskC.Vertex v : vs) {
                res += v.biggerNeighbors.size() * (long) (v.deg - v.biggerNeighbors.size());
            }
            out.println(res);
            int q = in.nextInt();
            for (int qi = 0; qi < q; ++qi) {
                TaskC.Vertex v = vs[in.nextInt() - 1];
                res -= v.biggerNeighbors.size() * (long) (v.deg - v.biggerNeighbors.size());
                for (TaskC.Vertex u : v.biggerNeighbors) {
                    res -= u.biggerNeighbors.size() * (long) (u.deg - u.biggerNeighbors.size());
                    u.biggerNeighbors.add(v);
                    res += u.biggerNeighbors.size() * (long) (u.deg - u.biggerNeighbors.size());
                }
                v.biggerNeighbors.clear();
                v.score = n + qi;
                out.println(res);
            }
        }

        static class Vertex {
            int score;
            List<TaskC.Vertex> biggerNeighbors = new ArrayList<>();
            int deg;

            public Vertex(int score) {
                this.score = score;
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