import java.io.*;
import java.util.*;

public class Template implements Runnable {
    private void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        boolean[][] g = new boolean[n][n];
        for (int i = 0; i < m; ++i) {
            int a = nextInt() - 1;
            int b = nextInt() - 1;
            g[a][b] = true;
            g[b][a] = true;
        }
        /*for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                g[i][j] = true;*/
        long[] am = new long[n + 1];
        long[][] ways = new long[1 << (n - 1)][n];
        for (int start = 0; start < n; ++start) {
            for (int mask = 0; mask < (1 << (n - start - 1)); ++mask)
                for (int last = start; last < n; ++last) {
                    ways[mask][last - start] = 0;
                }
            ways[1 >> 1][0] = 1;
            for (int mask = 1; mask < (1 << (n - start)); mask += 2) {
                int cnt = 0;
                int tmp = mask;
                while (tmp > 0) {
                    ++cnt;
                    tmp = tmp & (tmp - 1);
                }
                for (int last = start; last < n; ++last)
                    if (ways[mask >> 1][last - start] > 0) {
                        long amm = ways[mask >> 1][last - start];
                        for (int i = start; i < n; ++i)
                            if ((mask & (1 << (i - start))) == 0 && g[last][i]) {
                                ways[(mask | (1 << (i - start))) >> 1][i - start] += amm;
                            }
                        if (g[last][start])
                            am[cnt] += ways[mask >> 1][last - start];
                    }
            }
        }
        long res = 0;
        for (int cnt = 3; cnt <= n; ++cnt) {
            if (am[cnt] % (2) != 0)
                throw new RuntimeException();
            res += am[cnt] / (2);
        }
        writer.println(res);
    }


    public static void main(String[] args) {
        new Template().run();
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