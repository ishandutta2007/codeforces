import java.util.ArrayList;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.List;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
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
    static int nextEnterTime;
    static Vertex componentToAssign;
    static Vertex[] visitSeq;
    static Vertex[] tree;
    static int visitSeqPtr;

    static class Vertex {
        Vertex component;
        Vertex biComponent;
        int enterTime = -1;
        int depth = -1;
        int positionInSeq = -1;
        int knowUp = 0;
        boolean allUp = false;
        List<Edge> outgo = new ArrayList<>(1);

        public int dfsForBridges(Edge forbidden) {
            component = componentToAssign;
            enterTime = nextEnterTime++;
            int res = enterTime;
            for (Edge e : outgo) {
                if (e == forbidden) continue;
                if (e.dest.enterTime >= 0) {
                    res = Math.min(res, e.dest.enterTime);
                } else {
                    int child = e.dest.dfsForBridges(e.rev);
                    if (child == e.dest.enterTime) {
                        e.isBridge = true;
                        e.rev.isBridge = true;
                    }
                    res = Math.min(res, child);
                }
            }
            return res;
        }

        public void dfsForBiComponent() {
            biComponent = componentToAssign;
            for (Edge e : outgo) {
                if (e.isBridge) continue;
                if (e.dest.biComponent == null) {
                    e.dest.dfsForBiComponent();
                }
            }
        }

        public void dfsForLca() {
            enterTime = nextEnterTime++;
            positionInSeq = visitSeqPtr;
            visitSeq[visitSeqPtr++] = this;
            for (Edge e : outgo) {
                if (e.dest.enterTime < 0) {
                    e.dest.depth = depth + 1;
                    e.dest.dfsForLca();
                    visitSeq[visitSeqPtr++] = this;
                }
            }
        }

        public boolean verify() {
            for (Edge e : outgo) {
                if (e.dest.depth == depth + 1) {
                    if (!e.dest.verify()) return false;
                    if (e.dest.knowUp > 1) {
                        if (knowUp > 0 && (allUp != e.dest.allUp)) {
                            return false;
                        }
                        allUp = e.dest.allUp;
                        knowUp = Math.max(knowUp, e.dest.knowUp - 1);
                    }
                }
            }
            return true;
        }
    }

    static class Edge {
        boolean isBridge;
        Edge rev;
        Vertex dest;
    }

    void addEdge(Vertex a, Vertex b) {
        Edge ab = new Edge();
        Edge ba = new Edge();
        ab.rev = ba;
        ab.dest = b;
        ba.rev = ab;
        ba.dest = a;
        a.outgo.add(ab);
        b.outgo.add(ba);
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int q = in.nextInt();
        Vertex[] v = new Vertex[n];
        for (int i = 0; i < n; ++i) {
            v[i] = new Vertex();
        }
        for (int i = 0; i < m; ++i) {
            Vertex a = v[in.nextInt() - 1];
            Vertex b = v[in.nextInt() - 1];
            addEdge(a, b);
        }

        nextEnterTime = 0;
        for (Vertex vv : v) if (vv.enterTime < 0) {
            componentToAssign = new Vertex();
            vv.dfsForBridges(null);
        }

        List<Vertex> biComponents = new ArrayList<>();
        for (Vertex vv : v) if (vv.biComponent == null) {
            componentToAssign = new Vertex();
            biComponents.add(componentToAssign);
            vv.dfsForBiComponent();
        }

        for (Vertex vv : v) {
            for (Edge e : vv.outgo) {
                if (vv.biComponent != e.dest.biComponent) {
                    Edge ne = new Edge();
                    ne.dest = e.dest.biComponent;
                    vv.biComponent.outgo.add(ne);
                }
            }
        }

        nextEnterTime = 1;
        visitSeq = new Vertex[2 * n + 5];
        visitSeqPtr = 0;
        for (Vertex comp : biComponents) if (comp.enterTime < 0) {
            comp.depth = 0;
            comp.dfsForLca();
        }

        tree = new Vertex[visitSeqPtr * 4 + 10];
        initTree(0, 0, visitSeqPtr - 1);

        for (int iq = 0; iq < q; ++iq) {
            Vertex s = v[in.nextInt() - 1];
            Vertex t = v[in.nextInt() - 1];
            if (s.component != t.component) {
                out.println("No");
                return;
            }
            s = s.biComponent;
            t = t.biComponent;
            Vertex lca = getTree(0, 0, visitSeqPtr - 1, Math.min(s.positionInSeq, t.positionInSeq), Math.max(s.positionInSeq, t.positionInSeq));
            if (s.depth > lca.depth) {
                if (s.knowUp > 0 && !s.allUp) {
                    out.println("No");
                    return;
                }
                s.allUp = true;
                s.knowUp = Math.max(s.knowUp, s.depth - lca.depth);
            }
            if (t.depth > lca.depth) {
                if (t.knowUp > 0 && t.allUp) {
                    out.println("No");
                    return;
                }
                t.allUp = false;
                t.knowUp = Math.max(t.knowUp, t.depth - lca.depth);
            }
        }

        for (Vertex comp : biComponents) if (comp.depth == 0) {
            if (!comp.verify()) {
                out.println("No");
                return;
            }
        }

        out.println("Yes");
    }

    private Vertex getTree(int root, int rl, int rr, int left, int right) {
        if (left > right) return null;
        if (rl == left && rr == right) {
            return tree[root];
        }
        int rm = (rl + rr) / 2;
        Vertex v1 = getTree(root * 2 + 1, rl, rm, left, Math.min(rm, right));
        Vertex v2 = getTree(root * 2 + 2, rm + 1, rr, Math.max(rm + 1, left), right);
        if (v1 == null) return v2;
        if (v2 == null) return v1;
        if (v1.enterTime < v2.enterTime) return v1; else return v2;
    }

    private void initTree(int root, int rl, int rr) {
        if (rl == rr) {
            tree[root] = visitSeq[rl];
        } else {
            int rm = (rl + rr) / 2;
            initTree(root * 2 + 1, rl, rm);
            initTree(root * 2 + 2, rm + 1, rr);
            if (tree[root * 2 + 1].enterTime < tree[root * 2 + 2].enterTime) {
                tree[root] = tree[root * 2 + 1];
            } else {
                tree[root] = tree[root * 2 + 2];
            }
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