import java.util.ArrayList;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.List;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Collections;
import java.util.Comparator;
import java.io.IOException;
import java.util.StringTokenizer;

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
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    static int[] f;
    static Description tmp = new Description();

    static class Description {
        int leftOnes;
        int rightOnes;
        int total;
        int internalSum;
    }

    static class Vertex {
        Vertex parent;
        int subtreeSize;
        int depth;
        Vertex heavyRoot;
        int heavyIndex;
        int heavyCount;
        List<Edge> adj = new ArrayList<>(1);
        Description[] tree;

        void initParents(Vertex parent) {
            this.parent = parent;
            depth = (parent == null) ? 0 : 1 + parent.depth;
            subtreeSize = 1;
            for (Edge e : adj) {
                if (e.a == parent || e.b == parent) continue;
                if (e.b == this) {
                    Vertex t = e.a;
                    e.a = e.b;
                    e.b = t;
                }
                if (e.a != this) throw new RuntimeException();
                e.b.initParents(this);
                subtreeSize += e.b.subtreeSize;
            }
        }

        void initHeavy(boolean anew) {
            if (anew) {
                heavyRoot = this;
                heavyIndex = 0;
                heavyCount = 1;
            } else {
                heavyRoot = parent.heavyRoot;
                heavyIndex = 1 + parent.heavyIndex;
                ++heavyRoot.heavyCount;
            }
            Vertex max = null;
            for (Edge e : adj) {
                if (e.a != this) continue;
                if (max == null || e.b.subtreeSize > max.subtreeSize) max = e.b;
            }
            if (max != null) {
                max.initHeavy(false);
                for (Edge e : adj) {
                    if (e.a != this) continue;
                    if (e.b != max) e.b.initHeavy(true);
                }
            }
        }

        public void initTree(int root, int rl, int rr) {
            tree[root] = new Description();
            if (rl == rr) {
                tree[root].total = 1;
                return;
            }
            int rm = (rl + rr) / 2;
            initTree(root * 2 + 1, rl, rm);
            initTree(root * 2 + 2, rm + 1, rr);
            tree[root].total = tree[root * 2 + 1].total + tree[root * 2 + 2].total;
        }

        public void updateTree(int root, int rl, int rr, int at) {
            if (rl == rr) {
                tree[root].leftOnes = 1;
                tree[root].rightOnes = 1;
                tree[root].internalSum = 0;
                return;
            }
            int rm = (rl + rr) / 2;
            if (at <= rm) updateTree(root * 2 + 1, rl, rm, at); else updateTree(root * 2 + 2, rm + 1, rr, at);
            unite(tree[root * 2 + 1], tree[root * 2 + 2], tree[root]);
        }

        public void treePrepend(int root, int rl, int rr, int left, int right, Description prependTo) {
            if (left > right) return;
            if (left == rl && right == rr) {
                unite(tree[root], prependTo, prependTo);
                return;
            }
            int rm = (rl + rr) / 2;
            treePrepend(root * 2 + 2, rm + 1, rr, Math.max(left, rm + 1), right, prependTo);
            treePrepend(root * 2 + 1, rl, rm, left, Math.min(rm, right), prependTo);
        }
    }

    private static void unite(Description left, Description right, Description united) {
        tmp.leftOnes = left.leftOnes;
        if (left.leftOnes == left.total) tmp.leftOnes += right.leftOnes;
        tmp.rightOnes = right.rightOnes;
        if (right.rightOnes == right.total) tmp.rightOnes += left.rightOnes;
        tmp.internalSum = left.internalSum + right.internalSum;
        if (left.leftOnes < left.total && right.rightOnes < right.total)
            tmp.internalSum += f[left.rightOnes + right.leftOnes];
        united.total = left.total + right.total;
        united.leftOnes = tmp.leftOnes;
        united.rightOnes = tmp.rightOnes;
        united.internalSum = tmp.internalSum;
    }

    static class Edge {
        Vertex a;
        Vertex b;
        int weight;
        int isQuery;

        public Edge(Vertex a, Vertex b, int weight, int isQuery) {
            this.a = a;
            this.b = b;
            this.weight = weight;
            this.isQuery = isQuery;
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int q = in.nextInt();
        f = new int[n];
        for (int i = 1; i < n; ++i) {
            f[i] = in.nextInt();
        }
        Vertex[] vs = new Vertex[n];
        for (int i = 0; i < n; ++i) {
            vs[i] = new Vertex();
        }
        List<Edge> all = new ArrayList<>(n - 1 + q);
        for (int i = 0; i < n - 1; ++i) {
            Vertex a = vs[in.nextInt() - 1];
            Vertex b = vs[in.nextInt() - 1];
            int w = in.nextInt();
            Edge e = new Edge(a, b, w, -2);
            a.adj.add(e);
            b.adj.add(e);
            all.add(e);
        }
        Edge[] queries = new Edge[q];
        for (int i = 0; i < q; ++i) {
            Vertex a = vs[in.nextInt() - 1];
            Vertex b = vs[in.nextInt() - 1];
            int w = in.nextInt();
            Edge e = new Edge(a, b, w, -1);
            all.add(e);
            queries[i] = e;
        }

        Collections.sort(all, new Comparator<Edge>() {
            public int compare(Edge o1, Edge o2) {
                int delta = o2.weight - o1.weight;
                if (delta == 0) delta = o1.isQuery - o2.isQuery;
                return delta;
            }
        });

        Vertex root = vs[0];
        root.initParents(null);
        root.initHeavy(true);

        for (Vertex v : vs) if (v.heavyCount > 0) {
            v.tree = new Description[4 * v.heavyCount];
            v.initTree(0, 0, v.heavyCount - 1);
        }

        for (Edge event : all) {
            if (event.isQuery == -2) {
                Vertex v;
                if (event.a.parent == event.b)
                    v = event.a;
                else if (event.b.parent == event.a)
                    v = event.b;
                else
                    throw new RuntimeException();
                v.heavyRoot.updateTree(0, 0, v.heavyRoot.heavyCount - 1, v.heavyIndex);
            } else if (event.isQuery == -1) {
                Vertex a = event.a;
                Vertex b = event.b;
                Description ad = new Description();
                Description bd = new Description();
                while (a.heavyRoot != b.heavyRoot) {
                    if (a.heavyRoot.depth >= b.heavyRoot.depth) {
                        a.heavyRoot.treePrepend(0, 0, a.heavyRoot.heavyCount - 1, 0, a.heavyIndex, ad);
                        a = a.heavyRoot.parent;
                    } else {
                        b.heavyRoot.treePrepend(0, 0, b.heavyRoot.heavyCount - 1, 0, b.heavyIndex, bd);
                        b = b.heavyRoot.parent;
                    }
                }
                if (a.heavyIndex < b.heavyIndex) {
                    b.heavyRoot.treePrepend(0, 0, b.heavyRoot.heavyCount - 1, a.heavyIndex + 1, b.heavyIndex, bd);
                } else if (a.heavyIndex > b.heavyIndex) {
                    a.heavyRoot.treePrepend(0, 0, a.heavyRoot.heavyCount - 1, b.heavyIndex + 1, a.heavyIndex, ad);
                }
                int tt = ad.leftOnes;
                ad.leftOnes = ad.rightOnes;
                ad.rightOnes = tt;
                unite(ad, bd, ad);
                if (ad.leftOnes == ad.total) {
                    ad.internalSum += f[ad.leftOnes];
                } else {
                    ad.internalSum += f[ad.leftOnes] + f[ad.rightOnes];
                }
                event.isQuery = ad.internalSum;
            } else throw new RuntimeException();
        }


        for (Edge qq : queries) {
            out.println(qq.isQuery);
        }
    }
}

class InputReader {
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