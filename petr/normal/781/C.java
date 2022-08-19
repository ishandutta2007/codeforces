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
        int totalLines;
        int curLine;
        int maxLine;
        Vertex last;
        PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            int k = in.nextInt();
            Vertex[] vs = new Vertex[n];
            for (int i = 0; i < n; ++i) {
                vs[i] = new Vertex(i + 1);
            }
            for (int i = 0; i < m; ++i) {
                Vertex a = vs[in.nextInt() - 1];
                Vertex b = vs[in.nextInt() - 1];
                a.adj.add(b);
                b.adj.add(a);
            }
            if (n == 1) {
                for (int i = 0; i < k; ++i) {
                    out.println("1 1");
                }
                return;
            }
            totalLines = 0;
            curLine = 0;
            maxLine = (2 * n + k - 1) / k;
            this.out = out;
            vs[0].dfs();
            while (curLine > 0) {
                last = last.adj.get(0);
                last.print();
            }
            if (totalLines > k) throw new RuntimeException();
            for (int i = totalLines; i < k; ++i) {
                out.println("1 1");
            }
        }

        class Vertex {
            int index;
            List<Vertex> adj = new ArrayList<>();
            boolean mark = false;

            public Vertex(int index) {
                this.index = index;
            }

            public void print() {
                if (curLine > 0) out.print(" ");
                else out.print(maxLine + " ");
                out.print(index);
                last = this;
                ++curLine;
                if (curLine == maxLine) {
                    ++totalLines;
                    curLine = 0;
                    out.println();
                    last = null;
                }
            }

            public void dfs() {
                mark = true;
                print();
                for (Vertex v : adj) {
                    if (v.mark) continue;
                    v.dfs();
                    print();
                }
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