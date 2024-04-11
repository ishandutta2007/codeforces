import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Graph implements Runnable {
    static final long INF = 1000000000000000000L;

    private void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int[] deg = new int[n];
        long[][] dist = new long[n][n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dist[i][j] = (i == j) ? 0 : INF;
        long total = 0;
        for (int i = 0; i < m; ++i) {
            int a = nextInt() - 1;
            int b = nextInt() - 1;
            int w = nextInt();
            dist[a][b] = Math.min(dist[a][b], w);
            dist[b][a] = Math.min(dist[b][a], w);
            ++deg[a];
            ++deg[b];
            total += w;
        }
        ++deg[0];
        ++deg[0];
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    dist[i][j] = Math.min(dist[i][k] + dist[k][j], dist[i][j]);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (deg[i] > 0 && deg[j] > 0 && dist[i][j] >= INF) {
                    writer.println(-1);
                    return;
                }
        int no = 0;
        int[] o = new int[n];
        for (int i = 0; i < n; ++i) if (deg[i] % 2 != 0) {
            o[no++] = i;
        }
        long[] best = new long[1 << no];
        Arrays.fill(best, INF);
        best[0] = 0;
        for (int i = 0; i + 1 < best.length; ++i) if (best[i] < INF) {
            int j;
            for (j = 0; j < no; ++j)
                if ((i & (1 << j)) == 0)
                    break;
            for (int k = j + 1; k < no; ++k)
                if ((i & (1 << k)) == 0) {
                    int next = i | (1 << j) | (1 << k);
                    best[next] = Math.min(best[next], best[i] + dist[o[j]][o[k]]);
                }
        }
        writer.println(total + best[best.length - 1]);
    }

    public static void main(String[] args) {
        new Graph().run();
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