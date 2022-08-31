import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Square {
    private void solve() {
        int n1 = nextInt();
        int x1 = nextInt();
        int n2 = nextInt();
        int dx = Math.abs(nextInt() - x1);
        /*for (int n1 = 1; n1 <= 10; ++n1)
            for (int n2 = 2; n2 <= 10; ++n2)
                for (int dx = 1; dx <= 10; ++dx) {
                    long res = doit(n1, n2, dx);
                    long res2 = doit2(n1, n2, dx);
                    if (res != res2) {
                        throw new RuntimeException();
                    }
                }*/
        long res = doit(n1, n2, dx);
        writer.println(res);
    }

    static class Vertex {
        List<Vertex> adj = new ArrayList<Vertex>();
        boolean mark = false;

        public void dfs() {
            if (mark) return;
            mark = true;
            for (Vertex v : adj) v.dfs();
        }
    }

    private long doit2(int n1, int n2, int dx) {
        List<List<Vertex>> onFirst = new ArrayList<List<Vertex>>();
        List<List<Vertex>> onSecond = new ArrayList<List<Vertex>>();
        List<Vertex> all = new ArrayList<Vertex>();
        for (int i = 1; i <= n1; ++i) {
            onFirst.add(new ArrayList<Vertex>());
            Vertex v = new Vertex();
            onFirst.get(i - 1).add(v);
            all.add(v);
            v = new Vertex();
            onFirst.get(i - 1).add(v);
            all.add(v);
        }
        for (int i = 1; i <= n2; ++i) {
            onSecond.add(new ArrayList<Vertex>());
            Vertex v = new Vertex();
            onSecond.get(i - 1).add(v);
            all.add(v);
            v = new Vertex();
            onSecond.get(i - 1).add(v);
            all.add(v);
        }
        for (int i = 1; i <= n1; ++i)
            for (int j = 1; j <= n2; ++j) {
                if (Math.abs(i - j) == dx || Math.abs(i + j) == dx) {
                    Vertex v = new Vertex();
                    all.add(v);
                    onFirst.get(i - 1).add(v);
                    onSecond.get(j - 1).add(v);
                } else if (Math.abs(i - j) < dx && dx < Math.abs(i + j)) {
                    Vertex v = new Vertex();
                    all.add(v);
                    onFirst.get(i - 1).add(v);
                    onSecond.get(j - 1).add(v);
                    v = new Vertex();
                    all.add(v);
                    onFirst.get(i - 1).add(v);
                    onSecond.get(j - 1).add(v);
                }
            }
        for (List<Vertex> list : onFirst) {
            for (int i = 0; i < list.size(); ++i) {
                list.get(i).adj.add(list.get((i + 1) % list.size()));
                list.get(i).adj.add(list.get((i + list.size() - 1) % list.size()));
            }
        }
        for (List<Vertex> list : onSecond) {
            for (int i = 0; i < list.size(); ++i) {
                list.get(i).adj.add(list.get((i + 1) % list.size()));
                list.get(i).adj.add(list.get((i + list.size() - 1) % list.size()));
            }
        }
        return getFaces(all);
    }

    private long getFaces(List<Vertex> all) {
        long components = 0;
        long vertixes = all.size();
        long edges = 0;
        for (Vertex v : all) {
            edges += v.adj.size();
            if (!v.mark) {
                ++components;
                v.dfs();
            }
        }
        edges /= 2;
        return 1 + components + edges - vertixes;
    }

    private long doit(int n1, int n2, int dx) {
        long totalEdges = 0;
        long totalVertices = 0;
        long extra = 0;
        boolean anyIntersection = false;
        for (int step = 0; step < 2; ++step) {
            for (int i1 = 1; i1 <= n1; ++i1) {
                int i2 = Math.abs(dx - i1);
                int num = 0;
                if (i2 >= 1 && i2 <= n2) {
                    ++num;
                }
                i2 = dx + i1;
                if (i2 >= 1 && i2 <= n2) {
                    ++num;
                }
                int left = Math.max(Math.abs(dx - i1) + 1, 1);
                int right = Math.min(dx + i1 - 1, n2);
                if (right >= left) {
                    num += (right - left + 1) * 2;
                }
                totalVertices += num;
                totalEdges += num;
                if (num == 0) {
                    ++extra;
                } else {
                    anyIntersection = true;
                }
            }
            int tmp = n1;
            n1 = n2;
            n2 = tmp;
        }
        if (totalVertices % 2 != 0)
            throw new RuntimeException();
        long res = extra + 2 - totalVertices / 2 + totalEdges - (anyIntersection ? 0 : 1);
        return res;
    }


    public static void main(String[] args) {
        new Square().run();
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    private void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            writer = new PrintWriter(System.out);
            tokenizer = null;
            solve();
            reader.close();
            writer.close();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    private String nextToken() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    private int nextInt() {
        return Integer.parseInt(nextToken());
    }

    private long nextLong() {
        return Long.parseLong(nextToken());
    }

    private double nextDouble() {
        return Double.parseDouble(nextToken());
    }
}