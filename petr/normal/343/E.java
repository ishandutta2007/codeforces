import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Set;
import java.util.Iterator;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Collection;
import java.util.HashSet;
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
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    static class Edge {
        Edge rev;
        Vertex dest;
        int cap;

        Edge(Vertex dest, int cap) {
            this.dest = dest;
            this.cap = cap;
        }
    }

    static class Vertex {
        Set<Vertex> cont = null;
        Vertex repr = null;
        List<Edge> adj = new ArrayList<Edge>(1);
        int ptr = 0;
        boolean mark;
        int id;

        public void dfsCollectAll(Set<Vertex> eAll, Vertex parent) {
            eAll.addAll(cont);
            for (Edge e : adj)
                if (e.dest != parent)
                    e.dest.dfsCollectAll(eAll, this);
        }

        public void dfsCollectAll2(Set<Vertex> eAll, Vertex parent) {
            eAll.add(this);
            for (Edge e : adj)
                if (e.dest != parent)
                    e.dest.dfsCollectAll2(eAll, this);
        }

        public int flowDfs(Vertex t, int max) {
            if (mark) return 0;
            mark = true;
            if (this == t) return max;
            int startPtr = ptr;
            do {
                Edge e = adj.get(ptr);
                if (e.cap > 0) {
                    int by = e.dest.flowDfs(t, Math.min(e.cap, max));
                    if (by > 0) {
                        e.cap -= by;
                        e.rev.cap += by;
                        return by;
                    }
                }
                ptr = (ptr + 1) % adj.size();
            } while (ptr != startPtr);
            return 0;
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        Vertex[] sourceGraph = new Vertex[n];
        for (int i = 0; i < n; ++i) {
            sourceGraph[i] = new Vertex();
            sourceGraph[i].id = i + 1;
        }
        for (int i = 0; i < m; ++i) {
            Vertex a = sourceGraph[in.nextInt() - 1];
            Vertex b = sourceGraph[in.nextInt() - 1];
            int c = in.nextInt();
            createEdge(a, b, c);
        }
        List<Vertex> treeGraph = new ArrayList<Vertex>();
        Vertex start = new Vertex();
        start.cont = new HashSet<Vertex>();
        for (Vertex v : sourceGraph) start.cont.add(v);
        treeGraph.add(start);
        int flowSum = 0;
        while (true) {
            Vertex X = null;
            for (Vertex x : treeGraph)
                if (x.cont.size() >= 2) {
                    X = x;
                    break;
                }
            if (X == null) break;
            List<Vertex> contractedGraph = new ArrayList<Vertex>();
            for (Vertex v : sourceGraph) v.repr = null;
            for (Edge e : X.adj) {
                Set<Vertex> eAll = new HashSet<Vertex>();
                e.dest.dfsCollectAll(eAll, X);
                Vertex er = new Vertex();
                er.cont = eAll;
                for (Vertex v : eAll)
                    v.repr = er;
                contractedGraph.add(er);
            }
            List<Vertex> interesting = new ArrayList<Vertex>(X.cont);
            Vertex s = null;
            Vertex t = null;
            for (Vertex v : interesting) {
                Vertex vr = new Vertex();
                v.repr = vr;
                contractedGraph.add(vr);
                if (s == null)
                    s = vr;
                else if (t == null)
                    t = vr;
                /*for (Edge e : v.adj) {
                    if (e.dest.repr != null)
                        createEdge(vr, e.dest.repr, e.cap);
                } */
            }
            for (Vertex v : sourceGraph)
                for (Edge e : v.adj) {
                    if (v.id < e.dest.id)
                        createEdge(v.repr, e.dest.repr, e.cap);
                }
            for (Vertex v : sourceGraph) if (v.repr == null) throw new RuntimeException();
            Set<Vertex> halfS = new HashSet<Vertex>();
            Set<Vertex> halfT = new HashSet<Vertex>();
            int mc = maxflow(s, t, halfS, halfT, contractedGraph);
            flowSum += mc;
            if (halfS.isEmpty() || halfT.isEmpty()) throw new RuntimeException();
            Vertex Xs = new Vertex();
            Xs.cont = new HashSet<Vertex>();
            Vertex Xt = new Vertex();
            Xt.cont = new HashSet<Vertex>();
            for (Vertex v : interesting)
                if (halfS.contains(v.repr)) {
                    Xs.cont.add(v);
                } else if (halfT.contains(v.repr)) {
                    Xt.cont.add(v);
                } else throw new RuntimeException();
            treeGraph.remove(X);
            treeGraph.add(Xs);
            treeGraph.add(Xt);
            for (Edge e : X.adj) {
                e.dest.adj.remove(e.rev);
                if (halfS.contains(e.dest.cont.iterator().next().repr))
                    if (halfT.contains(e.dest.cont.iterator().next().repr))
                        throw new RuntimeException();
                    else
                        createEdge(Xs, e.dest, e.cap);
                else if (halfT.contains(e.dest.cont.iterator().next().repr))
                    createEdge(Xt, e.dest, e.cap);
                else
                    throw new RuntimeException();
            }
            /*for (Vertex v : Xs.cont)
                out.print(v.id + " ");
            out.print("||| ");
            for (Vertex v : Xt.cont)
                out.print(v.id + " ");
            out.print("||| ");
            out.println(mc);*/
            createEdge(Xs, Xt, mc);
        }
        List<Vertex> best = new ArrayList<Vertex>();
        Set<Vertex> full = new HashSet<Vertex>(treeGraph);
        int bestCost = decompose(full, best);
        if (bestCost != flowSum) throw new RuntimeException();
        out.println(bestCost);
        for (Vertex v : best) {
            out.print(v.cont.iterator().next().id + " ");
        }
        out.println();
    }

    private int decompose(Set<Vertex> full, List<Vertex> best) {
        if (full.size() == 1) {
            best.add(full.iterator().next());
            return 0;
        }
        Vertex a = null;
        Vertex b = null;
        int c = (int) 1e9;
        for (Vertex v : full)
            for (Edge e : v.adj)
                if (full.contains(e.dest)) {
                    if (e.cap < c) {
                        c = e.cap;
                        a = v;
                        b = e.dest;
                    }
                }
        Set<Vertex> as = new HashSet<Vertex>();
        Set<Vertex> bs = new HashSet<Vertex>();
        a.dfsCollectAll2(as, b);
        b.dfsCollectAll2(bs, a);
        as.retainAll(full);
        bs.retainAll(full);
        c += decompose(as, best);
        c += decompose(bs, best);
        return c;
    }

    private int maxflow(Vertex s, Vertex t, Set<Vertex> halfS, Set<Vertex> halfT, List<Vertex> contractedGraph) {
        int res = 0;
        while (true) {
            for (Vertex v : contractedGraph) v.mark = false;
            int extra = s.flowDfs(t, (int) 1e9);
            if (extra == 0) break;
            res += extra;
        }
        for (Vertex v : contractedGraph)
            if (v.mark) halfS.add(v); else halfT.add(v);
        return res;
    }

    private void createEdge(Vertex a, Vertex b, int c) {
        Edge ab = new Edge(b, c);
        Edge ba = new Edge(a, c);
        ab.rev = ba;
        ba.rev = ab;
        a.adj.add(ab);
        b.adj.add(ba);
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
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