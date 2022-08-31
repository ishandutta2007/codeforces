import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Reform implements Runnable {
    static final long INF = 10000000000L;

    static enum SolutionMode {
        PUT_HERE,
        DECREASE_DOWN,
        NORMAL;
    }

    static class Result {
        int id;
        long[][] what;
        Result[][] byChild;
        SolutionMode[][] by;
        Result[] children;
    }

    private void solve() throws IOException {
        int n = nextInt();
        long[] d = new long[3 * n];
        Arrays.fill(d, INF);
        for (int i = 0; i < n; ++i) {
            d[i] = nextInt();
        }
        boolean[][] graph = new boolean[n][n];
        for (int i = 0; i < n - 1; ++i) {
            int a = nextInt() - 1;
            int b = nextInt() - 1;
            graph[a][b] = true;
            graph[b][a] = true;
        }
        Result what = doit(n, graph, d, 0, -1);
        writer.println(what.what[n][n]);
        boolean[] isCenter = new boolean[n];
        buildAnswer(what, n, n, n, isCenter);
        int[][] dist = new int[n][n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (i == j) dist[i][j] = 0; else if (graph[i][j]) dist[i][j] = 1; else dist[i][j] = n + 10;
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
        for (int i = 0; i < n; ++i) {
            int best = n + 10;
            int bj = -1;
            for (int j = 0; j < n; ++j) {
                if (isCenter[j] && dist[i][j] < best) {
                    best = dist[i][j];
                    bj = j;
                }
            }
            if (i > 0) writer.print(" ");
            writer.print(bj + 1);
        }
        writer.println();
    }

    private void buildAnswer(Result res, int n, int closestUp, int existsDown, boolean[] center) {
        switch (res.by[closestUp][existsDown]) {
            case PUT_HERE:
            {
                center[res.id] = true;
                for (Result child : res.children) {
                    buildAnswer(child, n, 1, n, center);
                }
                break;
            }
            case DECREASE_DOWN:
            {
                buildAnswer(res, n, closestUp, existsDown - 1, center);
                break;
            }
            case NORMAL:
            {
                for (Result child : res.children) {
                    int newReach = Math.min(existsDown + 1, Math.min(closestUp + 1, n));
                    if (child == res.byChild[closestUp][existsDown]) {
                        buildAnswer(child, n, newReach, existsDown - 1, center);
                    } else {
                        buildAnswer(child, n, newReach, n, center);
                    }
                }
                break;
            }
        }
    }

    private Result doit(int n, boolean[][] graph, long[] d, int root, int rootParent) {
        Result res = new Result();
        res.id = root;
        res.what = new long[n + 1][n + 1];
        res.by = new SolutionMode[n + 1][n + 1];
        res.byChild = new Result[n + 1][n + 1];
        Result[] children = new Result[n];
        int nchildren = 0;
        for (int child = 0; child < n; ++child)
            if (child != rootParent && graph[child][root])
            {
                children[nchildren++] = doit(n, graph, d, child, root);
            }
        {
            Result[] tmp = new Result[nchildren];
            System.arraycopy(children, 0, tmp, 0, tmp.length);
            children = tmp;
        }
        res.children = children;
        for (int i = 0; i <= n; ++i) Arrays.fill(res.what[i], INF);
        for (int closestUp = 1; closestUp <= n; ++closestUp) {
            for (int existsDown = 0; existsDown <= n; ++existsDown) {
                if (existsDown == 0) {
                    // Put something here.
                    long r = d[0];
                    for (Result child : children) {
                        r += child.what[1][n];
                    }
                    if (r < res.what[closestUp][existsDown]) {
                        res.what[closestUp][existsDown] = r;
                        res.by[closestUp][existsDown] = SolutionMode.PUT_HERE;
                    }
                } else {
                    if (res.what[closestUp][existsDown - 1] < res.what[closestUp][existsDown]) {
                        res.what[closestUp][existsDown] = res.what[closestUp][existsDown - 1];
                        res.by[closestUp][existsDown] = SolutionMode.DECREASE_DOWN;
                    }
                    long r = Math.min(d[closestUp], d[existsDown]);
                    long bestDelta = existsDown == n ? 0 : INF * 1000;
                    Result bestChild = null;
                    for (Result child : children) {
                        int newReach = Math.min(existsDown + 1, Math.min(closestUp + 1, n));
                        long alpha = child.what[newReach][n];
                        long beta = child.what[newReach][existsDown - 1];
                        r += alpha;
                        if (beta - alpha < bestDelta) {
                            bestDelta = beta - alpha;
                            bestChild = child;
                        }
                    }
                    if (r + bestDelta < res.what[closestUp][existsDown]) {
                        res.what[closestUp][existsDown] = r + bestDelta;
                        res.by[closestUp][existsDown] = SolutionMode.NORMAL;
                        res.byChild[closestUp][existsDown] = bestChild;
                    }
                }
            }
        }
        return res;
    }

    public static void main(String[] args) {
        new Reform().run();
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