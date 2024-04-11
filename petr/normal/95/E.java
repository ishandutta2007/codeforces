import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class LuckyCountry implements Runnable {
    static final int INF = 1000000;
    int n;
    int m;
    int[] roadDest;
    int[] roadNext;
    int[] roadFirst;
    boolean[] mark;
    int size;
    int[] allSizes;

    private void solve() throws IOException {
        n = nextInt();
        m = nextInt();
        roadDest = new int[2 * m];
        roadNext = new int[2 * m];
        roadFirst = new int[n];
        Arrays.fill(roadFirst, -1);
        for (int i = 0; i < m; ++i) {
            int u = nextInt() - 1;
            int v = nextInt() - 1;
            roadDest[2 * i] = v;
            roadNext[2 * i] = roadFirst[u];
            roadFirst[u] = 2 * i;
            roadDest[2 * i + 1] = u;
            roadNext[2 * i + 1] = roadFirst[v];
            roadFirst[v] = 2 * i + 1;
        }
        mark = new boolean[n];
        allSizes = new int[n + 1];
        for (int i = 0; i < n; ++i)
            if (!mark[i]) {
                size = 0;
                dfs(i);
                ++allSizes[size];
            }
        /*n = 100000;
        allSizes = new int[n + 1];
        int sum = 0;
        for (int i = 1; sum < n; ++i) {
            for (int step = 0; step < 5; ++step) {
                int next = Math.min(i, n - sum);
                if (next <= 0) break;
                sum += next;
                ++allSizes[next];
            }
        } */
        int[] best = doSums();
        int res = INF;
        for (int i = 1; i <= n; ++i)
            if (isLucky(i)) {
                res = Math.min(res, best[i]);
            }
        if (res >= INF) writer.println(-1); else writer.println(res - 1);
    }

    private int[] doSums() {
        int[] best = new int[n + 1];
        int[] minLeft = new int[n + 1];
        int[] minRight = new int[n + 1];
        Arrays.fill(best, INF);
        best[0] = 0;
        for (int size = 0; size <= n; ++size) {
            int cnt = allSizes[size];
            if (cnt == 0) continue;
            if (cnt <= 6) {
                for (int step = 0; step < cnt; ++step) {
                    for (int i = n - size; i >= 0; --i)
                        best[i + size] = Math.min(best[i + size], best[i] + 1);
                }
            } else {
                for (int rem = 0; rem < size; ++rem) {
                    int am = (n - rem) / size + 1;
                    for (int i = 0, at = rem; i < am; ++i, at += size) {
                        minLeft[i] = best[at] - i;
                        minRight[i] = best[at] - i;
                    }
                    for (int i = 0; i < am; ++i) {
                        if (i % (cnt + 1) == 0)
                            continue;
                        minLeft[i] = Math.min(minLeft[i], minLeft[i - 1]);
                    }
                    for (int i = am - 1; i >= 0; --i) {
                        if (i == (am - 1) || (i % (cnt + 1) == cnt))
                            continue;
                        minRight[i] = Math.min(minRight[i], minRight[i + 1]);
                    }
                    for (int i = 0, at = rem; i < am; ++i, at += size) {
                        int curBest = minLeft[i];
                        int si = i - cnt;
                        if (si >= 0)
                            curBest = Math.min(curBest, minRight[si]);
                        best[at] = curBest + i;
                    }
                }
            }
        }
        return best;
    }

    private boolean isLucky(int what) {
        while (what > 0) {
            int cur = what % 10;
            what /= 10;
            if (cur != 4 && cur != 7)
                return false;
        }
        return true;
    }

    private void dfs(int at) {
        if (mark[at]) return;
        ++size;
        mark[at] = true;
        for (int i = roadFirst[at]; i >= 0; i = roadNext[i]) {
            dfs(roadDest[i]);
        }
    }

    public static void main(String[] args) {
        new LuckyCountry().run();
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