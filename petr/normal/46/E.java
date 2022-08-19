import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Lara implements Runnable {
    private void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        long[][] a = new long[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                a[i][j] = nextInt();
                if (j > 0)
                    a[i][j] += a[i][j - 1];
            }
        }
        long[][] best = new long[n][m];
        for (int j = 0; j < m; ++j) {
            best[0][j] = a[0][j];
        }
        for (int i = 1; i < n; ++i) {
            Arrays.fill(best[i], -(Long.MAX_VALUE / 10));
            if (i % 2 == 0) {
                for (int j = 1; j < m; ++j) {
                    best[i][j] = Math.max(best[i][j - 1] - a[i][j - 1] + a[i][j], best[i - 1][j - 1] + a[i][j]);
                }
            } else {
                for (int j = m - 2; j >= 0; --j) {
                    best[i][j] = Math.max(best[i][j + 1] - a[i][j + 1] + a[i][j], best[i - 1][j + 1] + a[i][j]);
                }
            }
        }
        long res = -(Long.MAX_VALUE / 10);
        for (long x : best[n - 1])
            res = Math.max(res, x);
        writer.println(res);
    }

    public static void main(String[] args) {
        new Lara().run();
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