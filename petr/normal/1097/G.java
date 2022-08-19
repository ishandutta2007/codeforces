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
        TaskG solver = new TaskG();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskG {
        static final long MODULO = (long) 1e9 + 7;
        static final long BIG = Long.MAX_VALUE - Long.MAX_VALUE % MODULO;
        static final int[] ONE = new int[]{1};
        int k;
        int n;
        long[] globalRes;
        int[] p2;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            k = in.nextInt();
            globalRes = new long[k + 1];
            p2 = new int[n + 1];
            p2[0] = 1;
            for (int i = 1; i <= n; ++i) p2[i] = (int) (2 * p2[i - 1] % MODULO);
            Vertex[] vs = new Vertex[n];
            for (int i = 0; i < n; ++i) vs[i] = new Vertex();
            for (int i = 0; i < n - 1; ++i) {
                Vertex a = vs[in.nextInt() - 1];
                Vertex b = vs[in.nextInt() - 1];
                a.adj.add(b);
                b.adj.add(a);
            }
            vs[0].dfs(null);
            long[][] ways = new long[k + 1][k + 1];
            ways[0][0] = 1;
            for (int i = 1; i <= k; ++i) {
                for (int j = 1; j <= k; ++j) {
                    ways[i][j] = j * (ways[i - 1][j] + ways[i - 1][j - 1]) % MODULO;
                }
            }
            long sum = 0;
            for (int i = 1; i <= k; ++i) {
                long s = globalRes[i];
                s %= MODULO;
                sum = (sum + s * ways[k][i]) % MODULO;
            }
            out.println(sum);
        }

        class Vertex {
            int[] res;
            int subtreeSize;
            List<Vertex> adj = new ArrayList<>();

            public void dfs(Vertex parent) {
                subtreeSize = 1;
                int[] prod = ONE;
                for (Vertex child : adj)
                    if (child != parent) {
                        child.dfs(this);
                        subtreeSize += child.subtreeSize;
                    }
                int mult = 2;//p2[n - subtreeSize];
                for (Vertex child : adj)
                    if (child != parent) {
                        int[] c = child.res;
                        prod = mul(prod, c);
                        subFrom(globalRes, c, 1);
                    }
                addTo(globalRes, prod, mult);
                res = insertEdge(prod);
            }

            private int[] insertEdge(int[] a) {
                int len = a.length + 1;
                if (len > k) len = k + 1;
                int[] b = new int[len];
                b[0] = a[0] * 2;
                if (b[0] >= MODULO) b[0] -= MODULO;
                for (int i = 1; i < len; ++i) {
                    long s = a[i - 1];
                    if (i < a.length) s += a[i];
                    if (s >= MODULO) s -= MODULO;
                    s = s * 2;
                    if (s >= MODULO) s -= MODULO;
                    b[i] = (int) s;
                }
                b[1] -= 1;
                if (b[1] < 0) b[1] += MODULO;
                return b;
            }

            private void addTo(long[] a, int[] b, int mult) {
                for (int i = 0; i < b.length; ++i) {
                    long s = a[i] + b[i] * (long) mult;
                    if (s < 0) s -= BIG;
                    a[i] = s;
                }
            }

            private void subFrom(long[] a, int[] b, int mult) {
                for (int i = 0; i < b.length; ++i) {
                    long s = a[i] + (MODULO - b[i]) * (long) mult;
                    if (s < 0) s -= BIG;
                    a[i] = s;
                }
            }

            private int[] mul(int[] a, int[] b) {
                int len = a.length + b.length - 1;
                if (len > k) len = k + 1;
                int[] c = new int[len];
                for (int i = 0; i < len; ++i) {
                    long s = 0;
                    int left = Math.max(0, i - (b.length - 1));
                    int right = Math.min(a.length - 1, i);
                    for (int ia = left; ia <= right; ++ia) {
                        int ib = i - ia;
                        s += a[ia] * (long) b[ib];
                        if (s < 0) s -= BIG;
                    }
                    c[i] = (int) (s % MODULO);
                }
                return c;
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