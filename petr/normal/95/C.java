import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Taxi implements Runnable {
    static final long INF = Long.MAX_VALUE / 3;

    static class Vertex {
        int id;
        List<Edge> outgoing = new ArrayList<Edge>();
        boolean mark;

        Vertex(int id) {
            this.id = id;
        }
    }

    static class Edge {
        Vertex dest;
        long length;

        Edge(Vertex dest, long length) {
            this.dest = dest;
            this.length = length;
        }
    }

    static class QueueItem implements Comparable<QueueItem> {
        final Vertex what;
        final long distance;

        QueueItem(Vertex what, long distance) {
            this.what = what;
            this.distance = distance;
        }

        public int compareTo(QueueItem queueItem) {
            if (distance < queueItem.distance)
                return -1;
            else if (distance > queueItem.distance)
                return 1;
            return what.id - queueItem.what.id;
        }
    }

    private void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int start = nextInt() - 1;
        int finish = nextInt() - 1;
        Vertex[] v = new Vertex[n];
        for (int i = 0; i < n; ++i) v[i] = new Vertex(i);
        for (int i = 0; i < m; ++i) {
            int a = nextInt() - 1;
            int b = nextInt() - 1;
            long length = nextLong();
            v[a].outgoing.add(new Edge(v[b], length));
            v[b].outgoing.add(new Edge(v[a], length));
        }
        long[] t = new long[n];
        long[] c = new long[n];
        for (int i = 0; i < n; ++i) {
            t[i] = nextLong();
            c[i] = nextLong();
        }
        long[][] dist = new long[n][n];
        for (int i = 0; i < n; ++i)
            Arrays.fill(dist[i], INF);
        PriorityQueue<QueueItem> items = new PriorityQueue<QueueItem>();
        for (int s = 0; s < n; ++s) {
            items.clear();
            for (Vertex vv : v) vv.mark = false;
            items.add(new QueueItem(v[s], 0));
            while (!items.isEmpty()) {
                QueueItem item = items.poll();
                if (item.what.mark) continue;
                item.what.mark = true;
                dist[s][item.what.id] = item.distance;
                for (Edge e : item.what.outgoing) {
                    if (e.dest.mark) continue;
                    items.add(new QueueItem(e.dest, item.distance + e.length));
                }
            }
        }
        long[] best = new long[n];
        boolean[] mark = new boolean[n];
        Arrays.fill(best, INF);
        best[start] = 0;
        while (true) {
            long min = INF;
            int minAt = -1;
            for (int i = 0; i < n; ++i)
                if (best[i] < min && !mark[i]) {
                    min = best[i];
                    minAt = i;
                }
            if (minAt < 0) break;
            mark[minAt] = true;
            for (int i = 0; i < n; ++i)
                if (dist[minAt][i] <= t[minAt])
                    best[i] = Math.min(best[i], best[minAt] + c[minAt]);
        }
        long res = best[finish];
        if (res >= INF) res = -1;
        writer.println(res);
    }

    public static void main(String[] args) {
        new Taxi().run();
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