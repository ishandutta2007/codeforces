import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Vacuum implements Runnable {
    static final double EPS = 1e-9;
    long[] x;
    long[] y;
    double[] alpha;
    double[] asum;
    int n;

    private void solve() throws IOException {
        n = nextInt();
        x = new long[2 * n + 1];
        y = new long[2 * n + 1];
        for (int i = 0; i < n; ++i) {
            x[i] = nextInt();
            y[i] = nextInt();
        }
        if ((x[2] - x[1]) * (y[1] - y[0]) - (x[1] - x[0]) * (y[2] - y[1]) > 0) {
            for (int i = 0; i < n - 1 - i; ++i) {
                long t = x[i];
                x[i] = x[n - 1 - i];
                x[n - 1 - i] = t;
                t = y[i];
                y[i] = y[n - 1 - i];
                y[n - 1 - i] = t;
            }
        }
        for (int i = n; i <= 2 * n; ++i) {
            x[i] = x[i - n];
            y[i] = y[i - n];
        }
        alpha = new double[2 * n + 1];
        for (int i = 0; i <= 2 * n; ++i) {
            alpha[i] = Math.atan2(y[i % n] - y[(i + n - 1) % n], x[i % n] - x[(i + n - 1) % n]);
            while (i > 0 && alpha[i] < alpha[i - 1]) {
                alpha[i] += 2 * Math.PI;
            }
        }
        asum = new double[2 * n + 1];
        for (int i = 0; i < 2 * n; ++i) {
            asum[i + 1] = asum[i] + (y[i + 1] - y[i]) * (x[i + 1] + x[i]) / 2.0;
        }
        int b = 1;
        int a = 0;
        double res = 1e100;
        while (a < n && b < 2 * n) {
            if (b >= a + n) {
                ++a;
                continue;
            }
            double la = alpha[a];
            double ra = alpha[a + 1];
            double lb = alpha[b];
            double rb = alpha[b + 1];
            if (la + Math.PI / 2 > rb + EPS) {
                ++b;
            } else if (ra + Math.PI / 2 < la + EPS) {
                ++a;
            } else {
                double lc = Math.max(la + Math.PI / 2, lb);
                double rc = Math.min(ra + Math.PI / 2, rb);
                res = Math.min(res, check(lc - Math.PI / 2, a, lc, b));
                res = Math.min(res, check(rc - Math.PI / 2, a, rc, b));
                if (ra + Math.PI / 2 > rb + EPS) {
                    ++b;
                } else {
                    ++a;
                }
            }
        }
        writer.println(Math.abs(res));
    }

    private double check(double la, int a, double lb, int b) {
        double dx = x[a] - x[b];
        double dy = y[a] - y[b];
        double res = (dx * dx + dy * dy) * Math.sin(2.0 * (Math.atan2(-dy, -dx) - la)) / 4.0;
        res -= (asum[b] - asum[a] + dy * (x[a] + x[b]) / 2.0);
        return res;
    }

    public static void main(String[] args) {
        new Vacuum().run();
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