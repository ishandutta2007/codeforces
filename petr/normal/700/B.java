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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        int k;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            k = in.nextInt();
            Vertex[] vs = new Vertex[n];
            for (int i = 0; i < n; ++i) vs[i] = new Vertex();
            for (int i = 0; i < 2 * k; ++i) {
                vs[in.nextInt() - 1].uni = true;
            }
            for (int i = 0; i < n - 1; ++i) {
                Vertex a = vs[in.nextInt() - 1];
                Vertex b = vs[in.nextInt() - 1];
                a.adj.add(b);
                b.adj.add(a);
            }
            vs[0].dfs(null);
            out.println(vs[0].accumulated);
        }

        class Vertex {
            boolean uni = false;
            List<Vertex> adj = new ArrayList<>(1);
            int totalChildren;
            int goingUp;
            long accumulated;

            public void dfs(Vertex parent) {
                totalChildren = uni ? 1 : 0;
                goingUp = uni ? 1 : 0;
                for (Vertex child : adj) {
                    if (child == parent) continue;
                    child.dfs(this);
                    totalChildren += child.totalChildren;
                    goingUp += child.goingUp;
                    accumulated += child.accumulated;
                }
                int atMost = 2 * k - totalChildren;
                if (goingUp > atMost) {
                    goingUp = atMost;
                }
                accumulated += goingUp;
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