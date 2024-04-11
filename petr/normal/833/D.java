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
        static final long MODULO = (long) (1e9 + 7);
        long res = 1;
        int n;

        private long pow(long a, long k) {
            if (k == 0) return 1;
            if (k % 2 == 0) {
                return pow(a * a % MODULO, k / 2);
            }
            return a * pow(a, k - 1) % MODULO;
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            Vertex[] vs = new Vertex[n];
            for (int i = 0; i < n; ++i) {
                vs[i] = new Vertex();
            }
            for (int i = 0; i < n - 1; ++i) {
                Vertex a = vs[in.nextInt() - 1];
                Vertex b = vs[in.nextInt() - 1];
                long value = in.nextLong();
                int color = in.nextInt();
                a.adj.add(new Edge(b, color, value));
                b.adj.add(new Edge(a, color, value));
            }

            Vertex root = vs[0];
            root.subtreeSizes(null);
            int[] colorCosts = new int[]{2, -1};
            root.countNegative(null, colorCosts);
            colorCosts = new int[]{-1, 2};
            root.countNegative(null, colorCosts);
            res = inv(res);
            root.countAll(null);
            out.println(res % MODULO);
        }

        private long inv(long res) {
            return pow(res, MODULO - 2);
        }

        class Edge {
            Vertex dest;
            int color;
            long value;

            public Edge(Vertex dest, int color, long value) {
                this.dest = dest;
                this.color = color;
                this.value = value;
            }

        }

        class PathCollection {
            int minCost = 0;
            long extraProd = 1;
            long[] prods = new long[]{1};
            int[] counts = new int[]{1};
            long[] prodsFenwick = new long[]{1};
            int[] countsFenwick = new int[]{1};

            public void expand() {
                int size = counts.length;
                int extra = (size + 1) / 2;
                long[] nprods = new long[size + 2 * extra];
                Arrays.fill(nprods, 1);
                int[] ncounts = new int[size + 2 * extra];
                System.arraycopy(prods, 0, nprods, extra, prods.length);
                System.arraycopy(counts, 0, ncounts, extra, counts.length);
                counts = ncounts;
                prods = nprods;
                rebuildCountsFenwick();
                rebuildProdsFenwick();
                minCost -= extra;
            }

            private void rebuildProdsFenwick() {
                prodsFenwick = new long[prods.length];
                Arrays.fill(prodsFenwick, 1);
                for (int i = 0; i < prods.length; ++i) {
                    prodsFenwickUpd(i, prods[i]);
                }
            }

            private void prodsFenwickUpd(int at, long by) {
                if (by == 1) return;
                while (at < prodsFenwick.length) {
                    prodsFenwick[at] = (prodsFenwick[at] * by) % MODULO;
                    at |= at + 1;
                }
            }

            private void rebuildCountsFenwick() {
                countsFenwick = new int[counts.length];
                for (int i = 0; i < counts.length; ++i) {
                    countsFenwickUpd(i, counts[i]);
                }
            }

            private void countsFenwickUpd(int at, int by) {
                if (by == 0) return;
                while (at < countsFenwick.length) {
                    countsFenwick[at] += by;
                    at |= at + 1;
                }
            }

            public void updateResult(int cost, int count, long prod) {
                if (count == 0) {
                    if (prod != 1) throw new RuntimeException();
                    return;
                }
                int lessThan = Math.min(-cost - minCost - 1, counts.length - 1);
                int cnt = countsFenwickGet(lessThan);
                long prd = prodsFenwickGet(lessThan);
                if (cnt > 0) {
                    prd = prd * pow(extraProd, cnt) % MODULO;
                    res = res * pow(prd, count) % MODULO * pow(prod, cnt) % MODULO;
                }
            }

            public void update(int cost, int count, long prod) {
                if (count == 0) {
                    if (prod != 1) throw new RuntimeException();
                    return;
                }
                while (minCost > cost || minCost + counts.length - 1 < cost) {
                    expand();
                }
                prod = prod * pow(inv(extraProd), count) % MODULO;
                counts[cost - minCost] += count;
                prods[cost - minCost] = prods[cost - minCost] * prod % MODULO;
                countsFenwickUpd(cost - minCost, count);
                prodsFenwickUpd(cost - minCost, prod);
            }

            private long prodsFenwickGet(int at) {
                long res = 1;
                while (at >= 0) {
                    res = res * prodsFenwick[at] % MODULO;
                    at = (at & (at + 1)) - 1;
                }
                return res;
            }

            private int countsFenwickGet(int at) {
                int res = 0;
                while (at >= 0) {
                    res += countsFenwick[at];
                    at = (at & (at + 1)) - 1;
                }
                return res;
            }

        }

        class Vertex {
            List<Edge> adj = new ArrayList<>();
            int subtreeSize;

            public void subtreeSizes(Vertex parent) {
                subtreeSize = 1;
                for (Edge e : adj)
                    if (e.dest != parent) {
                        e.dest.subtreeSizes(this);
                        subtreeSize += e.dest.subtreeSize;
                    }
            }

            public void countAll(Vertex parent) {
                for (Edge e : adj)
                    if (e.dest != parent) {
                        e.dest.countAll(this);
                        int u = e.dest.subtreeSize;
                        int v = n - u;
                        res = res * pow(e.value, u * (long) v) % MODULO;
                    }
            }

            public PathCollection countNegative(Vertex parent, int[] colorCosts) {
                Vertex firstChild = null;
                int firstColor = -1;
                long firstValue = 0;
                for (Edge e : adj)
                    if (e.dest != parent) {
                        if (firstChild == null || e.dest.subtreeSize > firstChild.subtreeSize) {
                            firstChild = e.dest;
                            firstColor = e.color;
                            firstValue = e.value;
                        }
                    }
                if (firstChild == null) {
                    return new PathCollection();
                }
                PathCollection p = firstChild.countNegative(this, colorCosts);
                p.minCost += colorCosts[firstColor];
                p.extraProd = (p.extraProd * firstValue) % MODULO;
                p.updateResult(0, 1, 1);
                p.update(0, 1, 1);
                for (Edge e : adj)
                    if (e.dest != parent && e.dest != firstChild) {
                        PathCollection q = e.dest.countNegative(this, colorCosts);
                        q.minCost += colorCosts[e.color];
                        q.extraProd = (q.extraProd * e.value) % MODULO;
                        for (int i = 0; i < q.counts.length; ++i) {
                            p.updateResult(q.minCost + i, q.counts[i], q.prods[i] * pow(q.extraProd, q.counts[i]) % MODULO);
                        }
                        for (int i = 0; i < q.counts.length; ++i) {
                            p.update(q.minCost + i, q.counts[i], q.prods[i] * pow(q.extraProd, q.counts[i]) % MODULO);
                        }
                    }
                return p;
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}