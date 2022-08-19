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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        static int n;
        static List<TaskD.Vertex> pairs = new ArrayList<>();

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
            TaskD.Vertex root = vs[0];
            List<TaskD.Vertex> stack = new ArrayList<>();
            stack.add(root);
            while (!stack.isEmpty()) {
                TaskD.Vertex cur = stack.get(stack.size() - 1);
                if (cur.state == 0) {
                    cur.state = 1;
                    for (TaskD.Vertex v : cur.adj)
                        if (v != cur.parent) {
                            v.parent = cur;
                            stack.add(v);
                        }
                } else {
                    cur.state = 2;
                    cur.process();
                    stack.remove(stack.size() - 1);
                }
            }

            if ((n * (long) n - root.bestAnswer) % 2 != 0) throw new RuntimeException();
            out.println((n * (long) n - root.bestAnswer) / 2 + n * (long) (n - 1) / 2);
        }

        static class Vertex implements Comparable<TaskD.Vertex> {
            List<TaskD.Vertex> adj = new ArrayList<>();
            long subtreeSize;
            long bestPathDown;
            long bestAnswer = -1;
            TaskD.Vertex parent;
            int state = 0;

            public void process() {
                subtreeSize = 1;
                for (TaskD.Vertex v : adj)
                    if (v != parent) {
                        subtreeSize += v.subtreeSize;
                    }
                Collections.sort(adj);
                bestPathDown = subtreeSize * subtreeSize;
                bestAnswer = n * (long) n;
                long prevSubtreeSize = -1;
                for (TaskD.Vertex v : adj)
                    if (v != parent) {
                        bestPathDown = Math.min(bestPathDown, (subtreeSize - v.subtreeSize) * (subtreeSize - v.subtreeSize) + v.bestPathDown);
                        bestAnswer = Math.min(bestAnswer, v.bestPathDown + (n - v.subtreeSize) * (n - v.subtreeSize));
                        bestAnswer = Math.min(bestAnswer, v.bestAnswer);
                        for (TaskD.Vertex prev : pairs) {
                            long curAnswer = v.bestPathDown + (n - v.subtreeSize - prev.subtreeSize) * (n - v.subtreeSize - prev.subtreeSize);
                            if (curAnswer >= bestAnswer) break;
                            curAnswer += prev.bestPathDown;
                            if (curAnswer < bestAnswer) {
                                bestAnswer = curAnswer;
                            }
                        }
                        if (v.subtreeSize != prevSubtreeSize) {
                            pairs.add(v);
                            prevSubtreeSize = v.subtreeSize;
                        }
                    }
                pairs.clear();
            }

            public int compareTo(TaskD.Vertex o) {
                int z = Long.compare(o.subtreeSize, subtreeSize);
                if (z == 0)
                    z = Long.compare(bestPathDown, o.bestPathDown);
                return z;
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