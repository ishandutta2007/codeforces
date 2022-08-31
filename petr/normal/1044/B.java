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
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            TaskB.Vertex[] vs = new TaskB.Vertex[n];
            for (int i = 0; i < n; ++i) {
                vs[i] = new TaskB.Vertex(i + 1);
            }
            for (int i = 0; i < n - 1; ++i) {
                TaskB.Vertex a = vs[in.nextInt() - 1];
                TaskB.Vertex b = vs[in.nextInt() - 1];
                a.adj.add(b);
                b.adj.add(a);
            }
            int k = in.nextInt();
            for (int i = 0; i < k; ++i) vs[in.nextInt() - 1].inSet = true;
            boolean[] otherSet = new boolean[n];
            k = in.nextInt();
            for (int i = 0; i < k; ++i) otherSet[in.nextInt() - 1] = true;
            int anyOther = 0;
            while (!otherSet[anyOther]) ++anyOther;
            out.println("B " + (anyOther + 1));
            out.flush();
            TaskB.Vertex start = vs[in.nextInt() - 1];
            TaskB.Vertex candidate = start.findInSet(null);
            out.println("A " + candidate.index);
            out.flush();
            int at = in.nextInt() - 1;
            if (otherSet[at]) {
                out.println("C " + candidate.index);
            } else {
                out.println("C -1");
            }
            out.flush();
        }

        static class Vertex {
            boolean inSet;
            int index;
            List<TaskB.Vertex> adj = new ArrayList<>();

            public Vertex(int index) {
                this.index = index;
            }

            public TaskB.Vertex findInSet(TaskB.Vertex parent) {
                if (inSet) return this;
                for (TaskB.Vertex v : adj) {
                    if (v != parent) {
                        TaskB.Vertex got = v.findInSet(this);
                        if (got != null) return got;
                    }
                }
                return null;
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