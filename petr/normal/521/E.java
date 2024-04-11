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
    int nextEntryTime;
    int[] edgeParent;

    int getEdgeClass(Edge e) {
        int root = e.index;
        while (edgeParent[root] != root) {
            root = edgeParent[root];
        }
        int tmp = e.index;
        while (tmp != root) {
            int nxt = edgeParent[tmp];
            edgeParent[tmp] = root;
            tmp = nxt;
        }
        return root;
    }

    class Edge {
        Vertex src;
        Vertex dest;
        int index;

        public Edge(Vertex src, Vertex dest, int index) {
            this.src = src;
            this.dest = dest;
            this.index = index;
        }

        void union(Edge other) {
            int c1 = getEdgeClass(this);
            int c2 = getEdgeClass(other);
            if (c1 != c2) edgeParent[c1] = c2;
        }
    }


    class Vertex {
        int index;
        int entryTime = -1;
        int adjGeneration = 0;
        int inStack = -1;
        int cycleIndex = -1;
        boolean mark = false;
        List<Edge> adj = new ArrayList<>(1);

        public Vertex(int index) {
            this.index = index;
        }

        public int dfs() {
            entryTime = nextEntryTime++;
            int res = entryTime;
            Edge curComp = null;
            for (Edge e : adj) {
                Vertex v = e.dest;
                if (v.entryTime < 0) {
                    int cres = v.dfs();
                    if (cres < entryTime) {
                        if (curComp == null) curComp = e; else curComp.union(e);
                    }
                    res = Math.min(res, cres);
                } else {
                    if (v.entryTime < entryTime) {
                        res = Math.min(res, v.entryTime);
                        if (curComp == null) curComp = e;
                        else curComp.union(e);
                    }
                }
            }
            return res;
        }

        public List<Vertex> findPathToCycle(int forbiddenCycleIndex) {
            if (cycleIndex == forbiddenCycleIndex) return null;
            if (cycleIndex >= 0) {
                List<Vertex> res = new ArrayList<>();
                res.add(this);
                return res;
            }
            if (mark) return null;
            mark = true;
            for (Edge e : adj) {
                List<Vertex> cres = e.dest.findPathToCycle(forbiddenCycleIndex);
                if (cres != null) {
                    cres.add(this);
                    return cres;
                }
            }
            return null;
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        Vertex[] vertices = new Vertex[n];
        for (int i = 0; i < n; ++i) vertices[i] = new Vertex(i + 1);
        for (int i = 0; i < m; ++i) {
            Vertex a = vertices[in.nextInt() - 1];
            Vertex b = vertices[in.nextInt() - 1];
            a.adj.add(new Edge(a, b, i));
            b.adj.add(new Edge(b, a, i));
        }
        edgeParent = new int[m];
        for (int i = 0; i < m; ++i) edgeParent[i] = i;
        nextEntryTime = 0;
        for (Vertex v : vertices) {
            if (v.entryTime < 0) v.dfs();
        }
        @SuppressWarnings("unchecked")
        List<Edge>[] byRoot = new List[m];
        for (Vertex v : vertices)
            for (Edge e : v.adj) {
                int r = getEdgeClass(e);
                if (byRoot[r] == null) byRoot[r] = new ArrayList<>(2);
                byRoot[r].add(e);
            }
        for (Vertex v : vertices) v.adj.clear();
        int generation = 0;
        Vertex[] stack = new Vertex[n];
        for (int ri = 0; ri < m; ++ri) {
            List<Edge> rl = byRoot[ri];
            if (rl == null) continue;
            if (rl.size() == 2) continue;
            ++generation;
            for (Edge e : rl) {
                if (e.src.adjGeneration < generation) {
                    e.src.adjGeneration = generation;
                    e.src.adj.clear();
                    e.src.inStack = -1;
                    e.src.cycleIndex = -1;
                    e.src.mark = false;
                }
                e.src.adj.add(e);
            }
            int sp = 1;
            stack[0] = rl.get(0).src;
            stack[0].inStack = 0;
            int cycleStart = -1;
            int cycleLen = -1;
            outer: while (true) {
                for (Edge e : stack[sp - 1].adj) {
                    Vertex v = e.dest;
                    if (v.inStack >= 0 && v.inStack != sp - 2) {
                        cycleStart = v.inStack;
                        cycleLen = sp - cycleStart;
                        for (int i = v.inStack; i < sp; ++i) {
                            stack[i].cycleIndex = i - cycleStart;
                        }
                        break outer;
                    }
                }
                for (Edge e : stack[sp - 1].adj) {
                    Vertex v = e.dest;
                    if (v.inStack < 0) {
                        v.inStack = sp;
                        stack[sp++] = v;
                        continue outer;
                    }
                }
                throw new RuntimeException();
            }
            for (int ci = cycleStart; ci < sp; ++ci) {
                Vertex cv = stack[ci];
                for (Edge e : cv.adj) {
                    if (e.dest.cycleIndex < 0 || (e.dest.cycleIndex != (cv.cycleIndex + 1) % cycleLen && e.dest.cycleIndex != (cv.cycleIndex + cycleLen - 1) % cycleLen)) {
                        List<Vertex> path = e.dest.findPathToCycle(cv.cycleIndex);
                        if (path == null) {
                            throw new RuntimeException();
                        }
                        path.add(cv);
                        List<Vertex> path2 = new ArrayList<>();
                        for (int i = path.get(0).cycleIndex; i != cv.cycleIndex; i = (i + 1) % cycleLen) {
                            path2.add(stack[cycleStart + i]);
                        }
                        path2.add(cv);
                        List<Vertex> path3 = new ArrayList<>();
                        for (int i = path.get(0).cycleIndex; i != cv.cycleIndex; i = (i + cycleLen - 1) % cycleLen) {
                            path3.add(stack[cycleStart + i]);
                        }
                        path3.add(cv);
                        out.println("YES");
                        out.print(path.size());
                        for (Vertex v : path) out.print(" " + v.index);
                        out.println();
                        out.print(path2.size());
                        for (Vertex v : path2) out.print(" " + v.index);
                        out.println();
                        out.print(path3.size());
                        for (Vertex v : path3) out.print(" " + v.index);
                        out.println();
                        return;
                    }
                }
            }
        }
        out.println("NO");
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