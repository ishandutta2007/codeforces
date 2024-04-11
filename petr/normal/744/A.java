import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.Arrays;
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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            int k = in.nextInt();
            TaskA.Vertex[] v = new TaskA.Vertex[n];
            for (int i = 0; i < n; ++i) {
                v[i] = new TaskA.Vertex();
            }
            for (int i = 0; i < k; ++i) {
                v[in.nextInt() - 1].capital = true;
            }
            for (int i = 0; i < m; ++i) {
                TaskA.Vertex a = v[in.nextInt() - 1];
                TaskA.Vertex b = v[in.nextInt() - 1];
                a.adj.add(b);
                b.adj.add(a);
            }
            int[] sizes = new int[k];
            int ptr = 0;
            for (TaskA.Vertex vv : v)
                if (vv.capital) {
                    sizes[ptr++] = vv.dfs();
                }
            Arrays.sort(sizes);
            int s = 0;
            int e = 0;
            for (int i = 0; i < k - 1; ++i) {
                s += sizes[i];
                e += sizes[i] * (sizes[i] - 1) / 2;
            }
            s = n - s;
            e += s * (s - 1) / 2;
            out.println(e - m);
        }

        static class Vertex {
            boolean capital = false;
            List<TaskA.Vertex> adj = new ArrayList<>();
            boolean mark = false;

            public int dfs() {
                if (mark) return 0;
                mark = true;
                int res = 1;
                for (TaskA.Vertex v : adj) res += v.dfs();
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