import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Bomb implements Runnable {
    private void solve() throws IOException {
        int n = nextInt();
        int k = nextInt();
        double need = 1.0 - nextDouble() / 1000.0;
        int x0 = nextInt();
        int y0 = nextInt();
        double[] d = new double[n];
        for (int i = 0; i < n; ++i) {
            double x = nextDouble();
            double y = nextDouble();
            d[i] = (x - x0) * (x - x0) + (y - y0) * (y - y0);
        }
        double left = 0.0;
        double right = 10000.0;
        for (int step = 0; step < 100; ++step) {
            double middle = (left + right) / 2;
            double sq = middle * middle;
            double[] pr = new double[n + 1];
            pr[0] = 1.0;
            for (int i = 0; i < n; ++i) {
                double c = 1 - d[i] / sq;
                double cp = c >= 0 ? 1 : Math.exp(1 - d[i] / sq);
                for (int j = n - 1; j >= 0; --j) {
                    pr[j + 1] += cp * pr[j];
                    pr[j] *= 1 - cp;
                }
            }
            double sum = 0;
            for (int i = k; i <= n; ++i)
                sum += pr[i];
            if (sum >= need)
                right = middle;
            else
                left = middle;
        }
        writer.println(String.format("%.20f", right).replace(',', '.'));
    }

    public static void main(String[] args) {
        new Bomb().run();
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