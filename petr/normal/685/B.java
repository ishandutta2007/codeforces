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
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int q = in.nextInt();
            TaskB.Vertex[] vs = new TaskB.Vertex[n];
            for (int i = 0; i < n; ++i) {
                vs[i] = new TaskB.Vertex(i);
            }
            for (int i = 1; i < n; ++i) {
                TaskB.Vertex parent = vs[in.nextInt() - 1];
                vs[i].parent = parent;
                parent.children.add(vs[i]);
            }
            TaskB.Vertex root = vs[0];
            root.init();
            root.solve();
            for (int i = 0; i < q; ++i) {
                TaskB.Vertex v = vs[in.nextInt() - 1];
                out.println(v.centroid.index + 1);
            }
        }

        static class Vertex {
            TaskB.Vertex centroid;
            int index;
            int subtreeSize;
            TaskB.Vertex parent;
            List<TaskB.Vertex> children = new ArrayList<>(1);

            public Vertex(int index) {
                this.index = index;
            }

            void init() {
                subtreeSize = 1;
                for (TaskB.Vertex v : children) {
                    v.init();
                    subtreeSize += v.subtreeSize;
                }
            }

            public void solve() {
                TaskB.Vertex biggestChild = null;
                for (TaskB.Vertex v : children) {
                    v.solve();
                    if (biggestChild == null || biggestChild.subtreeSize < v.subtreeSize) {
                        biggestChild = v;
                    }
                }
                if (biggestChild == null) {
                    centroid = this;
                    return;
                }
                if (biggestChild.subtreeSize * 2 <= subtreeSize) {
                    centroid = this;
                    return;
                }
                centroid = biggestChild.centroid;
                while (centroid.subtreeSize * 2 <= subtreeSize) {
                    centroid = centroid.parent;
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