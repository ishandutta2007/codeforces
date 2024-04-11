import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

public class TwoPaths implements Runnable {
    static class Edge {
        Vertex destination;
        Edge sameEdgeOtherDirection;
        private int id;
        boolean covered = false;

        Edge(Vertex destination, Edge sameEdgeOtherDirection, int id) {
            this.destination = destination;
            this.sameEdgeOtherDirection = sameEdgeOtherDirection;
            this.id = id;
        }
    }

    static class Vertex {
        List<Edge> adj = new ArrayList<Edge>();
        int dfsPosition = -1;
        boolean mark = false;
        Edge prevDist = null;
        int component = -1;

        public void dfs(int id) {
            if (mark)
                return;
            if (component != -1)
                throw new RuntimeException();
            mark = true;
            component = id;
            for (Edge e : adj)
                e.destination.dfs(id);
        }
    }

    static class Path {
        Vertex start;
        List<Edge> edges = new ArrayList<Edge>();

        public void printOut(PrintWriter writer) {
            writer.println(edges.size());
            boolean first = true;
            for (Edge e : edges) {
                if (first) first = false; else writer.print(" ");
                writer.print(e.id);
            }
            writer.println();
        }
    }

    static final int MAX_VERTEX = 10000;

    private void solve() throws IOException {
        int m = nextInt();
        Vertex[] v = new Vertex[MAX_VERTEX];
        for (int i = 0; i < MAX_VERTEX; ++i)
            v[i] = new Vertex();
        for (int i = 0; i < m; ++i) {
            int a = nextInt() - 1;
            int b = nextInt() - 1;
            Edge ab = new Edge(v[b], null, i + 1);;
            Edge ba = new Edge(v[a], null, i + 1);;
            ab.sameEdgeOtherDirection = ba;
            ba.sameEdgeOtherDirection = ab;
            v[a].adj.add(ab);
            v[b].adj.add(ba);
        }
        if (m < 2) {
            writer.println(-1);
            return;
        }
        int components = 0;
        for (Vertex x : v) {
            if (!x.adj.isEmpty()) {
                if (!x.mark) {
                    x.dfs(components++);
                }
            }
        }
        if (components > 2) {
            writer.println(-1);
            return;
        }
        if (components == 2) {
            Path p1 = buildPathForComponent(v, 0);
            Path p2 = buildPathForComponent(v, 1);
            if (p1 == null || p2 == null) {
                writer.println(-1);
                return;
            }
            p1.printOut(writer);
            p2.printOut(writer);
        } else {
            Vertex[] odds = new Vertex[4];
            int numOdds = 0;
            for (Vertex x : v) {
                if (x.adj.size() % 2 != 0) {
                    ++numOdds;
                    if (numOdds > 4) {
                        writer.println(-1);
                        return;
                    }
                    odds[numOdds - 1] = x;
                }
            }
            if (numOdds <= 2) {
                Path p = buildPathForComponent(v, 0);
                Edge last = p.edges.get(p.edges.size() - 1);
                p.edges.remove(p.edges.size() - 1);
                p.printOut(writer);
                writer.println(1);
                writer.println(last.id);
            } else {
                Path[] p = findTwoPaths(odds, v);
                if (p == null) {
                    writer.println(-1);
                    return;
                }
                p[0].printOut(writer);
                p[1].printOut(writer);
            }
        }
    }

    private Path[] findTwoPaths(Vertex[] ends, Vertex[] v) {
        Path[] res = new Path[2];
        Path p = buildShortestPath(ends[0], ends[1]);
        for (Edge e : p.edges) {
            e.covered = true;
            e.sameEdgeOtherDirection.covered = true;
        }
        for (Vertex x : v) x.dfsPosition = 0;
        res[0] = buildEulerianPath(ends[2]);
        for (Edge e : p.edges) {
            e.covered = false;
            e.sameEdgeOtherDirection.covered = false;
        }
        for (Vertex x : v) x.dfsPosition = 0;
        res[1] = buildEulerianPath(ends[0]);
        return res;
    }

    private Path buildShortestPath(Vertex a, Vertex b) {
        Queue<Vertex> q = new ArrayDeque<Vertex>();
        q.add(a);
        Edge sentinel = new Edge(null, null, -1);
        a.prevDist = sentinel;
        while (!q.isEmpty()) {
            Vertex cur = q.poll();
            for (Edge e : cur.adj) {
                if (e.covered)
                    continue;
                if (e.destination.prevDist != null)
                    continue;
                e.destination.prevDist = e.sameEdgeOtherDirection;
                q.add(e.destination);
                if (e.destination == b) {
                    Path res = new Path();
                    cur = b;
                    while (cur != a) {
                        res.edges.add(cur.prevDist);
                        cur = cur.prevDist.destination;
                    }
                    return res;
                }
            }
        }
        return null;
    }

    private Path buildPathForComponent(Vertex[] v, int componentId) {
        Vertex[] odds = new Vertex[2];
        int numOdds = 0;
        Vertex any = null;
        for (Vertex x : v)
            if (x.component == componentId) {
                any = x;
                if (x.adj.size() % 2 != 0) {
                    ++numOdds;
                    if (numOdds > 2)
                        return null;
                    odds[numOdds - 1] = x;
                }
            }
        if (numOdds > 0)
            any = odds[0];
        for (Vertex x : v) x.dfsPosition = 0;
        Path p = buildEulerianPath(any);
        return p;
    }

    private Path buildEulerianPath(Vertex start) {
        Path res = new Path();
        Stack<Vertex> dfsStack = new Stack<Vertex>();
        Stack<Edge> dfsBy = new Stack<Edge>();
        dfsStack.add(start);
        start.dfsPosition = 0;
        while (!dfsStack.isEmpty()) {
            Vertex last = dfsStack.peek();
            boolean anyNew = false;
            for (int i = last.dfsPosition; i < last.adj.size(); ++i) {
                Edge e = last.adj.get(i);
                last.dfsPosition = i + 1;
                if (!e.covered) {
                    anyNew = true;
                    e.covered = true;
                    e.sameEdgeOtherDirection.covered = true;
                    dfsStack.add(e.destination);
                    dfsBy.add(e.sameEdgeOtherDirection);
                    break;
                }
            }
            if (!anyNew) {
                if (res.edges.isEmpty()) {
                    res.start = last;
                }
                dfsStack.pop();
                if (!dfsBy.isEmpty())
                    res.edges.add(dfsBy.pop());
            }
        }
        return res;
    }

    public static void main(String[] args) {
        new TwoPaths().run();
    }

    static final String IN_FILE = "input.txt";
    static final String OUT_FILE = "output.txt";

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    public void run() {
        try {
            reader = new BufferedReader(new FileReader(IN_FILE));
            tokenizer = null;
            writer = new PrintWriter(OUT_FILE);
            solve();
            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}