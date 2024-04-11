import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
import java.util.Collections;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            TaskB.Vertex[] v = new TaskB.Vertex[n];
            for (int i = 0; i < n; ++i) v[i] = new TaskB.Vertex(in.nextInt());
            for (int i = 0; i < m; ++i) {
                TaskB.Vertex a = v[in.nextInt() - 1];
                TaskB.Vertex b = v[in.nextInt() - 1];
                a.outgo.add(new TaskB.Edge(b, i + 1));
                b.outgo.add(new TaskB.Edge(a, i + 1));
            }
            TaskB.Vertex root = v[0];
            for (TaskB.Vertex vv : v)
                if (vv.d < 0) {
                    root = vv;
                    break;
                }
            List<TaskB.Edge> answer = new ArrayList<>();
            root.dfs(answer);
            if (root.d >= 0 && root.d != root.got) {
                out.println(-1);
            } else {
                out.println(answer.size());
                Collections.sort(answer, new Comparator<TaskB.Edge>() {

                    public int compare(TaskB.Edge o1, TaskB.Edge o2) {
                        return o1.index - o2.index;
                    }
                });
                for (TaskB.Edge e : answer) {
                    out.println(e.index);
                }
            }
        }

        static class Edge {
            TaskB.Vertex dest;
            int index;

            public Edge(TaskB.Vertex dest, int index) {
                this.dest = dest;
                this.index = index;
            }

        }

        static class Vertex {
            int d;
            int got = -1;
            List<TaskB.Edge> outgo = new ArrayList<>();

            public Vertex(int d) {
                this.d = d;
            }

            public void dfs(List<TaskB.Edge> answer) {
                got = 0;
                for (TaskB.Edge e : outgo)
                    if (e.dest.got < 0) {
                        e.dest.dfs(answer);
                        if (e.dest.d >= 0 && e.dest.d != e.dest.got) {
                            answer.add(e);
                            e.dest.got ^= 1;
                            got ^= 1;
                        }
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