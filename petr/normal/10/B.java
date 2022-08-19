import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Cinema implements Runnable {
    private void solve() throws IOException {
        int n = nextInt();
        int k = nextInt();
        boolean[][] used = new boolean[k][k];
        for (int i = 0; i < n; ++i) {
            int m = nextInt();
            int bestx = -1;
            int bestyl = -1;
            int bestyr = -1;
            int best = Integer.MAX_VALUE;
            for (int x = 0; x < k; ++x)
                for (int xl = 0; xl + m <= k; ++xl) {
                    int xr = xl + m - 1;
                    int sum = 0;
                    for (int j = xl; j <= xr; ++j)
                        if (used[x][j]) {
                            sum = -1;
                            break;
                        } else {
                            sum += Math.abs(x - k / 2) + Math.abs(j - k / 2);
                        }
                    if (sum < 0)
                        continue;
                    if (sum < best) {
                        best = sum;
                        bestx = x;
                        bestyl = xl;
                        bestyr = xr;
                    }
                }
            if (bestx < 0)
                writer.println(-1);
            else {
                writer.println((bestx + 1) + " " + (bestyl + 1) + " " + (bestyr + 1));
                for (int j = bestyl; j <= bestyr; ++j)
                    used[bestx][j] = true;
            }
        }
    }


    public static void main(String[] args) {
        new Cinema().run();
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