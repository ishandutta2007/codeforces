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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            int[][] words = new int[n][];
            for (int i = 0; i < n; ++i) {
                words[i] = new int[in.nextInt()];
                for (int j = 0; j < words[i].length; ++j) {
                    words[i][j] = in.nextInt() - 1;
                }
            }
            TaskC.Vertex[] capitalize = new TaskC.Vertex[m];
            List<TaskC.Vertex> all = new ArrayList<>();
            for (int i = 0; i < m; ++i) {
                capitalize[i] = new TaskC.Vertex();
                capitalize[i].negation = new TaskC.Vertex();
                capitalize[i].negation.negation = capitalize[i];
                all.add(capitalize[i]);
                all.add(capitalize[i].negation);
            }
            for (int i = 0; i + 1 < n; ++i) {
                boolean alreadyLess = false;
                for (int j = 0; j < Math.min(words[i].length, words[i + 1].length); ++j) {
                    if (words[i][j] != words[i + 1][j]) {
                        int a = words[i][j];
                        int b = words[i + 1][j];
                        if (a > b) {
                            addEdge(capitalize[a].negation, capitalize[a]);
                            addEdge(capitalize[b], capitalize[b].negation);
                        } else {
                            addEdge(capitalize[b], capitalize[a]);
                        }
                        alreadyLess = true;
                        break;
                    }
                }
                if (!alreadyLess) {
                    if (words[i].length > words[i + 1].length) {
                        out.println("No");
                        return;
                    }
                }
            }
            if (!solveTwoSAT(all)) {
                out.println("No");
                return;
            }
            out.println("Yes");
            int numCap = 0;
            for (TaskC.Vertex v : capitalize) if (v.solution) ++numCap;
            out.println(numCap);
            for (int i = 0; i < m; ++i)
                if (capitalize[i].solution) {
                    out.print(i + 1 + " ");
                }
            out.println();
        }

        private boolean solveTwoSAT(List<TaskC.Vertex> all) {
            for (TaskC.Vertex v : all) v.used = false;
            List<TaskC.Vertex> order = new ArrayList<>();
            for (TaskC.Vertex v : all)
                if (!v.used) {
                    v.dfs1(order);
                }
            for (TaskC.Vertex v : all) v.component = -1;
            Collections.reverse(order);
            int nextComponent = 0;
            for (TaskC.Vertex v : order)
                if (v.component < 0) {
                    v.dfs2(nextComponent++);
                }
            for (TaskC.Vertex v : all) {
                if (v.component == v.negation.component)
                    return false;
                v.solution = v.component > v.negation.component;
            }
            return true;
        }

        private void addEdge(TaskC.Vertex p, TaskC.Vertex q) {
            p.forward.add(q);
            q.backward.add(p);
            q.negation.forward.add(p.negation);
            p.negation.backward.add(q.negation);
        }

        static class Vertex {
            TaskC.Vertex negation;
            boolean used;
            boolean solution;
            int component;
            List<TaskC.Vertex> forward = new ArrayList<>();
            List<TaskC.Vertex> backward = new ArrayList<>();

            public void dfs1(List<TaskC.Vertex> order) {
                used = true;
                for (TaskC.Vertex v : forward) {
                    if (!v.used) v.dfs1(order);
                }
                order.add(this);
            }

            public void dfs2(int comp) {
                component = comp;
                for (TaskC.Vertex v : backward) {
                    if (v.component < 0) v.dfs2(comp);
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