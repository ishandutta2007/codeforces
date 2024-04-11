import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class FirstDigit implements Runnable {
    private void solve() throws IOException {
        int n = nextInt();
        double[] pr = new double[n + 1];
        pr[0] = 1.0;
        for (int step = 0; step < n; ++step) {
            long l = nextLong();
            long r = nextLong();
            long one = getPrOne(l, r);
            double prOne = one / (double) (r - l + 1);
            double prOther = (r - l + 1 - one) / (double) (r - l + 1);
            for (int i = n - 1; i >= 0; --i) {
                pr[i + 1] += pr[i] * prOne;
                pr[i] *= prOther;
            }
        }
        int k = nextInt();
        double res = 0.0;
        for (int i = 0; i <= n; ++i)
            if (i * 100 >= n * k)
                res += pr[i];
        writer.println(res);
    }

    private long getPrOne(long l, long r) {
        long x = l;
        long total = 0;
        while (x <= r) {
            long p10 = 1;
            while (p10 <= x / 10)
                p10 *= 10;
            long first = x / p10;
            long toGo = Math.min(r - x + 1, p10 - (x % p10));
            if (first == 1) {
                total += toGo;
            }
            x += toGo;
        }
        return total;
    }

    public static void main(String[] args) {
        new FirstDigit().run();
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