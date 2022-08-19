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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        int cycleBegin;
        int cycleEnd;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            int[] e1 = new int[m];
            int[] e2 = new int[m];
            boolean[] inv1 = new boolean[m];
            boolean[] inv2 = new boolean[m];
            Arrays.fill(e1, -1);
            Arrays.fill(e2, -1);
            for (int i = 0; i < n; ++i) {
                int k = in.nextInt();
                for (int j = 0; j < k; ++j) {
                    int v = in.nextInt();
                    int vv = Math.abs(v) - 1;
                    if (e1[vv] < 0) {
                        e1[vv] = i;
                        inv1[vv] = v < 0;
                    } else {
                        e2[vv] = i;
                        inv2[vv] = v < 0;
                    }
                }
            }

            boolean[] done = new boolean[n];
            int[] vals = new int[m];
            Arrays.fill(vals, -1);

            Node[] nodes = new Node[n];
            for (int i = 0; i < n; ++i) nodes[i] = new Node(i);

            for (int i = 0; i < m; ++i) {
                if (e1[i] < 0) continue;
                if (e2[i] < 0) {
                    vals[i] = inv1[i] ? 0 : 1;
                    done[e1[i]] = true;
                    continue;
                }
                if (inv1[i] == inv2[i]) {
                    vals[i] = inv1[i] ? 0 : 1;
                    done[e1[i]] = true;
                    done[e2[i]] = true;
                    continue;
                }
                nodes[e1[i]].adj.add(new Edge(nodes[e2[i]], i, inv1[i] ? 0 : 1));
                nodes[e2[i]].adj.add(new Edge(nodes[e1[i]], i, inv2[i] ? 0 : 1));
            }

            for (int i = 0; i < n; ++i)
                if (done[i]) {
                    dfs(vals, done, i, nodes);
                }

            Edge[] stack = new Edge[n + 1];
            int[] inStack = new int[n + 1];
            Arrays.fill(inStack, -1);

            for (int i = 0; i < n; ++i)
                if (!done[i]) {
                    if (!dfs2(i, nodes, stack, inStack, 0, null)) {
                        out.println("NO");
                        return;
                    }
                    for (int j = cycleBegin + 1; j <= cycleEnd; ++j) {
                        Edge e = stack[j];
                        done[e.dest.index] = true;
                        vals[e.varIndex] = 1 - e.val;
                    }
                    for (int j = cycleBegin + 1; j <= cycleEnd; ++j) {
                        Edge e = stack[j];
                        dfs(vals, done, e.dest.index, nodes);
                    }
                }

            out.println("YES");
            for (int i = 0; i < m; ++i) out.print(Math.max(vals[i], 0));
            out.println();
        }

        private boolean dfs2(int at, Node[] nodes, Edge[] stack, int[] inStack, int sp, Edge via) {
            inStack[at] = sp;
            stack[sp++] = via;
            for (Edge e : nodes[at].adj) {
                if (via != null && e.varIndex == via.varIndex) continue;
                if (inStack[e.dest.index] >= 0) {
                    cycleBegin = inStack[e.dest.index];
                    cycleEnd = sp;
                    stack[sp] = e;
                    return true;
                }
                if (inStack[e.dest.index] == -1) {
                    if (dfs2(e.dest.index, nodes, stack, inStack, sp, e)) return true;
                }
            }
            inStack[at] = -2;
            return false;
        }

        private void dfs(int[] vals, boolean[] done, int at, Node[] nodes) {
            for (Edge e : nodes[at].adj) {
                if (!done[e.dest.index]) {
                    done[e.dest.index] = true;
                    vals[e.varIndex] = 1 - e.val;
                    dfs(vals, done, e.dest.index, nodes);
                }
            }
        }

        static class Edge {
            Node dest;
            int varIndex;
            int val;

            public Edge(Node dest, int varIndex, int val) {
                this.dest = dest;
                this.varIndex = varIndex;
                this.val = val;
            }

        }

        static class Node {
            int index;
            List<Edge> adj = new ArrayList<>(1);

            public Node(int index) {
                this.index = index;
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