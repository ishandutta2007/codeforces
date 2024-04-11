import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class WinningStrategy implements Runnable {
    private void solve() throws IOException {
        int n = nextInt();
        double[] p = new double[n + 1];
        for (int i = 0; i <= n; ++i) {
            p[i] = nextDouble();
        }
        double left = 0;
        double right = 1;
        while (right - left > 1.5e-6) {
            double middle = (left + right) / 2;
            if (enough(n, p, middle))
                left = middle;
            else
                right = middle;
        }
        writer.println((left + right) / 2);
    }

    static final double INF = 1e100;

    private boolean enough(int n, double[] p, double need) {
        double[][] g = new double[2 * n + 1][2 * n + 1];
        for (int i = 0; i < g.length; ++i) {
            Arrays.fill(g[i], INF);
            g[i][i] = 0.0;
        }
        for (int i = 0; i < g.length; ++i) {
            for (int j = 0; j <= n && j <= i; ++j) {
                int ni = i + n - 2 * j;
                if (ni < 0 || ni >= g.length) continue;
                g[i][ni] = need - p[j];
            }
            if (i > 0)
                g[i][i - 1] = Math.min(g[i][i - 1], 0.0);
        }
        for (int k = 0; k < g.length; ++k)
            for (int i = 0; i < g.length; ++i)
                for (int j = 0; j < g.length; ++j) {
                    g[i][j] = Math.min(g[i][j], g[i][k] + g[k][j]);
                }
        for (int i = 0; i < g.length; ++i)
            if (g[i][i] < 0)
                return true;
        return false;
    }

    public static void main(String[] args) {
        new WinningStrategy().run();
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