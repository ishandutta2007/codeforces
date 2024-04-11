import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Polygon implements Runnable {
    private void solve() throws IOException {
        int n = nextInt();
        long[] x = new long[n];
        long[] y = new long[n];
        for (int i = 0; i < n; ++i) {
            x[i] = nextLong();
            y[i] = nextLong();
        }
        int t = nextInt();
        for (int it = 0; it < t; ++it) {
            long px = nextLong();
            long py = nextLong();
            long res = 0;
            for (int i = 0; i < n; ++i) {
                long x1 = x[i];
                long y1 = y[i];
                int ii = i + 1;
                if (ii == n) ii = 0;
                long x2 = x[ii];
                long y2 = y[ii];
                if ((x2 - x1) * (py - y1) - (y2 - y1) * (px - x1) >= 0) {
                    res = -1;
                    break;
                }
            }
            if (res < 0) {
                writer.println(0);
                continue;
            }
            int j = 0;
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                while (true) {
                    int jj = j + 1;
                    if (jj == n) jj = 0;
                    if ((x[jj] - x[i]) * (py - y[i]) - (y[jj] - y[i]) * (px - x[i]) > 0)
                        break;
                    j = jj;
                    ++cnt;
                }
                res += (long) cnt * (cnt - 1) / 2;
                res += (long) (n - 1 - cnt) * (n - 1 - cnt - 1) / 2;
                --cnt;
            }
            if (res % 2 != 0) throw new RuntimeException();
            res /= 2;
            res = (long) n * (n - 1) * (n - 2) / 6 - res;
            writer.println(res);
        }
    }

    public static void main(String[] args) {
        new Polygon().run();
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