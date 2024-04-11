import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
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
        TaskE solver = new TaskE();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
         out.close();
    }

    static class TaskE {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            TaskE.Vertex[] vs = new TaskE.Vertex[n];
            for (int i = 0; i < n; ++i) {
                vs[i] = new TaskE.Vertex();
            }
            int m = in.nextInt();
            for (int i = 0; i < m; ++i) {
                TaskE.Vertex a = vs[in.nextInt() - 1];
                TaskE.Vertex b = vs[in.nextInt() - 1];
                a.adj.add(b);
                b.adj.add(a);
            }
            for (TaskE.Vertex v : vs)
                if (!v.visited) {
                    List<TaskE.Vertex> stack = new ArrayList<>();
                    List<TaskE.Vertex> cycle = v.findCycle(stack);
                    if (cycle != null) {
                        for (TaskE.Vertex vv : cycle) vv.value = 1;
                        out.println("YES");
                        for (TaskE.Vertex vv : vs) out.print(vv.value + " ");
                        out.println();
                        return;
                    }
                }
            for (TaskE.Vertex v : vs)
                if (v.adj.size() >= 4) {
                    v.value = 2;
                    for (TaskE.Vertex vv : v.adj) vv.value = 1;
                    out.println("YES");
                    for (TaskE.Vertex vv : vs) out.print(vv.value + " ");
                    out.println();
                    return;
                }
            for (TaskE.Vertex v : vs)
                if (v.adj.size() >= 3) {
                    TaskE.Vertex vv = v.findDeg3Except(v, null);
                    if (vv != null) {
                        v.value = 2;
                        for (TaskE.Vertex vvv : v.adj) if (vvv.value == 0) vvv.value = 1;
                        for (TaskE.Vertex vvv : vv.adj) if (vvv.value == 0) vvv.value = 1;
                        out.println("YES");
                        for (TaskE.Vertex vvv : vs) out.print(vvv.value + " ");
                        out.println();
                        return;
                    }
                }
            for (TaskE.Vertex v : vs)
                if (v.adj.size() >= 3) {
                    List<List<TaskE.Vertex>> chains = new ArrayList<>();
                    double totalSavings = 0;
                    for (TaskE.Vertex vv : v.adj) {
                        List<TaskE.Vertex> chain = new ArrayList<>();
                        vv.findChain(chain, v);
                        totalSavings += 0.5 * chain.size() / (chain.size() + 1);
                        chains.add(chain);
                    }
                    if (totalSavings >= 1 - 1e-14) {
                        for (List<TaskE.Vertex> c : chains) {
                            while (c.size() > 1) {
                                TaskE.Vertex last = c.remove(c.size() - 1);
                                totalSavings = 0;
                                for (List<TaskE.Vertex> chain : chains) {
                                    totalSavings += 0.5 * chain.size() / (chain.size() + 1);
                                }
                                if (totalSavings < 1 - 1e-14) {
                                    c.add(last);
                                    break;
                                }
                            }
                        }
                        int q = 1;
                        for (List<TaskE.Vertex> c : chains) {
                            for (int size = 0; size < c.size(); ++size) {
                                long cp = (size + 1);
                                long cq = (size + 2);
                                q *= cq;
                            }
                        }
                        if (q > (int) 1e6) throw new RuntimeException();
                        v.value = q;
                        for (List<TaskE.Vertex> c : chains) {
                            int cv = q;
                            for (int size = c.size() - 1; size >= 0; --size) {
                                if (cv % (size + 2) != 0) throw new RuntimeException();
                                cv /= (size + 2);
                                cv *= (size + 1);
                                c.get(c.size() - 1 - size).value = cv;
                            }
                        }
                        out.println("YES");
                        for (TaskE.Vertex vvv : vs) out.print(vvv.value + " ");
                        out.println();
                        return;
                    }
                }
            out.println("NO");
        }

        static class Vertex {
            boolean visited = false;
            int inStack = -1;
            int value = 0;
            List<TaskE.Vertex> adj = new ArrayList<>();

            public List<TaskE.Vertex> findCycle(List<TaskE.Vertex> stack) {
                if (inStack >= 0 && stack.size() - inStack >= 3) {
                    return new ArrayList<>(stack.subList(inStack, stack.size()));
                }
                if (visited) return null;
                visited = true;
                inStack = stack.size();
                stack.add(this);
                for (TaskE.Vertex v : adj) {
                    List<TaskE.Vertex> cycle = v.findCycle(stack);
                    if (cycle != null) return cycle;
                }
                stack.remove(stack.size() - 1);
                inStack = -1;
                return null;
            }

            public TaskE.Vertex findDeg3Except(TaskE.Vertex v, TaskE.Vertex parent) {
                if (adj.size() >= 3 && this != v) {
                    value = 2;
                    return this;
                }
                for (TaskE.Vertex vv : adj)
                    if (vv != parent) {
                        TaskE.Vertex u = vv.findDeg3Except(v, this);
                        if (u != null) {
                            vv.value = 2;
                            return u;
                        }
                    }
                return null;
            }

            public void findChain(List<TaskE.Vertex> chain, TaskE.Vertex parent) {
                chain.add(this);
                for (TaskE.Vertex vv : adj)
                    if (vv != parent) {
                        vv.findChain(chain, this);
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