import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
        static int[] firstChild;
        static int[] nextSibling;
        static int nextId;
        int[] answers;
        int[] max;
        int n;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            TaskD.Vertex[] vs = new TaskD.Vertex[n];
            for (int i = 0; i < n; ++i) vs[i] = new TaskD.Vertex();
            for (int i = 0; i < n - 1; ++i) {
                TaskD.Vertex a = vs[in.nextInt() - 1];
                TaskD.Vertex b = vs[in.nextInt() - 1];
                a.adj.add(b);
                b.adj.add(a);
            }
            nextId = 0;
            firstChild = new int[n];
            nextSibling = new int[n];
            vs[0].dfs(null);

            int k = 1;
            answers = new int[n + 1];
            max = new int[n];
            Arrays.fill(answers, -1);
            solveOne(1);
            outer:
            while (k < n) {
                int step = 1;
                while (true) {
                    int dest = Math.min(n, k + step);
                    solveOne(dest);
                    if (answers[dest] != answers[k]) {
                        step /= 2;
                        break;
                    } else if (dest == n) {
                        k = dest;
                        continue outer;
                    } else {
                        k = dest;
                        step *= 2;
                    }
                }
                while (step > 0 && k < n) {
                    int dest = Math.min(n, k + step);
                    solveOne(dest);
                    if (answers[dest] == answers[k]) {
                        k = dest;
                    }
                    step /= 2;
                }
                if (k < n) {
                    ++k;
                    solveOne(k);
                }
            }

            int sofar = answers[1];
            for (int i = 1; i <= n; ++i) {
                if (answers[i] >= 0) sofar = Math.min(sofar, answers[i]);
                out.println(sofar);
            }
        }

        private void solveOne(int k) {
            if (answers[k] >= 0) return;
            int got = 0;
            for (int i = n - 1; i >= 0; --i) {
                int max1 = 0;
                int max2 = 0;
                int j = firstChild[i];
                while (j >= 0) {
                    if (max[j] > max1) {
                        max2 = max1;
                        max1 = max[j];
                    } else if (max[j] > max2) {
                        max2 = max[j];
                    }
                    j = nextSibling[j];
                }
                if (max1 + 1 + max2 >= k) {
                    ++got;
                    max[i] = 0;
                } else {
                    max[i] = max1 + 1;
                }
            }
            answers[k] = got;
        }

        static class Vertex {
            List<TaskD.Vertex> adj = new ArrayList<>();

            public int dfs(TaskD.Vertex parent) {
                int id = nextId++;
                firstChild[id] = -1;
                for (TaskD.Vertex v : adj)
                    if (v != parent) {
                        int cid = v.dfs(this);
                        nextSibling[cid] = firstChild[id];
                        firstChild[id] = cid;
                    }
                return id;
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