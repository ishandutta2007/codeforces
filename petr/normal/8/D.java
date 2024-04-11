import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Geometry implements Runnable {
    private void solve() throws IOException {
        double t1 = nextInt();
        double t2 = nextInt();
        double[] x = new double[3];
        double[] y = new double[3];
        for (int i = 0; i < 3; ++i) {
            x[i] = nextInt();
            y[i] = nextInt();
        }
        double[] d = new double[3];
        for (int i = 0; i < 3; ++i) {
            int a = (i + 1) % 3;
            int b = (i + 2) % 3;
            d[i] = Math.sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));
        }
        if (d[1] + d[0] <= d[2] + t2) {
            writer.printf("%.10f\n", Math.min(d[2] + t2, d[0] + d[1] + t1));
        } else {
            double deltaAlpha = Math.abs(Math.atan2(y[1] - y[0], x[1] - x[0]) - Math.atan2(y[2] - y[0], x[2] - x[0]));
            if (deltaAlpha > Math.PI) {
                deltaAlpha = 2 * Math.PI - deltaAlpha;
            }
            double l = 0;
            double r = Math.min(d[2] + t2 / 2, d[1] + t1 / 2);
            for (int step = 0; step < 100; ++step) {
                double m = (l + r) / 2;
                double freedom0 = d[2] + t2 - m;
                boolean enough = true;
                double alpha = (m * m + d[2] * d[2] - freedom0 * freedom0) / (2 * m * d[2]);
                if (alpha < -1)
                    alpha = -1;
                if (alpha > 1)
                    alpha = 1;
                alpha = Math.acos(alpha);
                double freedom1 = d[1] + t1 - m;
                double beta = (m * m + d[1] * d[1] - freedom1 * freedom1) / (2 * m * d[1]);
                if (beta < -1)
                    beta = -1;
                if (beta > 1)
                    beta = 1;
                beta = Math.acos(beta);
                if (alpha + beta < deltaAlpha)
                    enough = false;
                if (enough)
                    l = m;                 
                else
                    r = m;
            }
            double leeway = Math.min(d[1] + t1 - d[0] - d[2], t2);
            if (leeway > -1e-9)
                l = Math.max(l, leeway + d[2]);
            double u = (d[2] + t2 - d[1] - t1 + d[0]) / 2.0;
            if (u > 0 && u < d[0]) {
                double aa = Math.atan2(y[2] - y[1], x[2] - x[1]);
                double xx = x[1] + Math.cos(aa) * u;
                double yy = y[1] + Math.sin(aa) * u;
                double dx = xx - x[0];
                double dy = yy - y[0];
                leeway = d[2] + t2 - u - Math.sqrt(dx * dx + dy * dy);
                if (leeway > 1e-9)
                    l = Math.max(l, d[2] + t2 - u);
            }
            writer.printf("%.10f\n", l);
        }
    }


    public static void main(String[] args) {
        new Geometry().run();
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