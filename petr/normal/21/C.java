import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Stripe implements Runnable {
    private void solve() throws IOException {
        int n = nextInt();
        long[] a = new long[n];
        long sum = 0;
        for (int i = 0; i < n; ++i) {
            a[i] = nextInt();
            sum += a[i];
        }
        if (sum % 3 != 0) {
            writer.println(0);
            return;
        }
        sum /= 3;
        long[] left = new long[n + 1];
        long[] right = new long[n + 1];
        int amRight = 0;
        for (int i = 0; i < n; ++i) {
            left[i + 1] = left[i] + a[i];
            right[i + 1] = right[i] + a[n - 1 - i];
            if (i + 1 <= n - 2 && right[i + 1] == sum)
                ++amRight;
        }
        long res = 0;
        for (int i = 1; i <= n - 2; ++i) {
            if (n - i <= n - 2 && right[n - i] == sum)
                --amRight;
            if (i > 0 && left[i] == sum)
                res += amRight;
        }
        writer.println(res);
    }

    public static void main(String[] args) {
        new Stripe().run();
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