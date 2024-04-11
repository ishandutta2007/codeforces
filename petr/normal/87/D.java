import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Road implements Runnable {
    static class Vertex {
        int size = 1;
        Vertex parent = null;
        List<Edge> tmpList = new ArrayList<Edge>();

        Vertex getRoot() {
            if (parent == null) return this;
            parent = parent.getRoot();
            return parent;
        }

        public int tmpDfsSum(Vertex p) {
            int res = size;
            for (Edge e : tmpList) {
                Vertex dest = e.a == this ? e.b : e.a;
                if (dest != p)
                    res += dest.tmpDfsSum(this);
            }
            return res;
        }

        public int tmpDfs(Vertex p, int total) {
            int res = size;
            for (Edge e : tmpList) {
                Vertex dest = e.a == this ? e.b : e.a;
                if (dest != p) {
                    int inSubtree = dest.tmpDfs(this, total);
                    res += inSubtree;
                    e.beauty = (long) inSubtree * (total - inSubtree);
                }
            }
            tmpList.clear();
            return res;
        }
    }

    static class Edge implements Comparable<Edge> {
        Vertex a;
        Vertex b;
        int dist;
        long beauty;
        int id;

        public int compareTo(Edge edge) {
            return dist - edge.dist;
        }
    }

    private void solve() throws IOException {
        int n = nextInt();
        Vertex[] v = new Vertex[n];
        for (int i = 0; i < n; ++i) {
            v[i] = new Vertex();
        }
        Edge[] e = new Edge[n - 1];
        for (int i = 0; i < n - 1; ++i) {
            e[i] = new Edge();
            e[i].a = v[nextInt() - 1];
            e[i].b = v[nextInt() - 1];
            e[i].dist = nextInt();
            e[i].id = i + 1;
        }
        Arrays.sort(e);
        for (int i = 0; i < n - 1;) {
            int j = i;
            while (j < n - 1 && e[j].dist == e[i].dist) ++j;

            for (int k = i; k < j; ++k) {
                Edge edge = e[k];
                edge.a = edge.a.getRoot();
                edge.b = edge.b.getRoot();
                edge.a.tmpList.add(edge);
                edge.b.tmpList.add(edge);
            }
            for (int k = i; k < j; ++k) {
                if (!e[k].a.tmpList.isEmpty()) {
                    int total = e[k].a.tmpDfsSum(null);
                    e[k].a.tmpDfs(null, total);
                }
            }
            for (int k = i; k < j; ++k) {
                Edge edge = e[k];
                union(edge.a, edge.b);
            }
            i = j;
        }
        long max = -1;
        List<Integer> res = new ArrayList<Integer>();
        for (Edge edge : e) {
            if (edge.beauty > max) {
                max = edge.beauty;
                res.clear();
            }
            if (edge.beauty == max) {
                res.add(edge.id);
            }
        }
        writer.println(2 * max + " " + res.size());
        Collections.sort(res);
        for (int i = 0; i < res.size(); ++i) {
            if (i > 0) writer.print(" ");
            writer.print(res.get(i));
        }
        writer.println();
    }

    private void union(Vertex a, Vertex b) {
        a = a.getRoot();
        b = b.getRoot();
        if (a.size < b.size) {
            a.parent = b;
            b.size += a.size;
        } else {
            b.parent = a;
            a.size += b.size;
        }
    }

    public static void main(String[] args) {
        new Road().run();
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            writer = new PrintWriter(System.out);
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