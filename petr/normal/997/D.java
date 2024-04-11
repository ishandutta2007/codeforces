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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        static final long MODULO = 998244353;
        private static long[] invs;
        private static long[] fact;
        private static long[] invfact;

        static {
            invs = new long[5000];
            invs[1] = 1;
            for (int i = 2; i < invs.length; ++i) {
                invs[i] = (MODULO - invs[((int) (MODULO % i))] * (MODULO / i) % MODULO) % MODULO;
                if (invs[i] * i % MODULO != 1) throw new RuntimeException();
            }
            fact = new long[invs.length];
            invfact = new long[invs.length];
            fact[0] = 1;
            invfact[0] = 1;
            for (int i = 1; i < invs.length; ++i) {
                fact[i] = i * fact[i - 1] % MODULO;
                invfact[i] = invs[i] * invfact[i - 1] % MODULO;
            }
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n1 = in.nextInt();
            int n2 = in.nextInt();
            int k = in.nextInt();
            TaskD.Vertex[] tree1 = readTree(n1, in);
            TaskD.Vertex[] tree2 = readTree(n2, in);
            long[] w1 = solveOne(n1, tree1, k);
            long[] w2 = solveOne(n2, tree2, k);
            long res = 0;
            for (int a = 0; a <= k; ++a) {
                res = res + w1[a] * w2[k - a] % MODULO * fact[k] % MODULO * invfact[a] % MODULO * invfact[k - a] % MODULO;
            }
            res %= MODULO;
            res += MODULO;
            res %= MODULO;
            out.println(res);
        }

        private long[] solveOne(int n, TaskD.Vertex[] tree, int k) {
            TaskD.Description desc = tree[0].doit(null, k);
            return desc.overallCycles;
        }

        private TaskD.Vertex[] readTree(int n, InputReader in) {
            TaskD.Vertex[] v = new TaskD.Vertex[n];
            for (int i = 0; i < n; ++i) v[i] = new TaskD.Vertex();
            for (int i = 0; i < n - 1; ++i) {
                TaskD.Vertex a = v[in.nextInt() - 1];
                TaskD.Vertex b = v[in.nextInt() - 1];
                a.adj.add(b);
                b.adj.add(a);
            }
            return v;
        }

        static class Description {
            long[] overallCycles;
            long[] cyclesFromRoot;

        }

        static class Vertex {
            List<TaskD.Vertex> adj = new ArrayList<>();

            public TaskD.Description doit(TaskD.Vertex skip, int k) {
                TaskD.Description res = new TaskD.Description();
                res.overallCycles = new long[k + 1];
                res.cyclesFromRoot = new long[k + 1];
                res.cyclesFromRoot[0] = 1;
                res.overallCycles[0] = 1;
                long[] singleStep = new long[k + 1];
                for (TaskD.Vertex child : adj) {
                    if (child == skip) continue;
                    TaskD.Description desc = child.doit(this, k);
                    for (int i = 0; i <= k; ++i) {
                        res.overallCycles[i] = (res.overallCycles[i] + desc.overallCycles[i]) % MODULO;
                        if (i + 2 <= k) singleStep[i + 2] = (singleStep[i + 2] + desc.cyclesFromRoot[i]) % MODULO;
                    }
                }
                for (int old = 0; old <= k; ++old) {
                    long w = res.cyclesFromRoot[old];
                    for (int a = 2; old + a <= k; ++a) {
                        res.cyclesFromRoot[old + a] = (res.cyclesFromRoot[old + a] + w * singleStep[a]) % MODULO;
                        res.overallCycles[old + a] = (res.overallCycles[old + a] + w * singleStep[a] % MODULO * a) % MODULO;
                    }
                }
                return res;
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