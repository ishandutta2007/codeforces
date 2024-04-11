import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Root implements Runnable {
    private void solve() throws IOException {
        int n = nextInt();
        long res = 0;
        int[] am = new int[10];
        for (int i = 1; i <= n; ++i) {
            int sum = (i % 9 + 8) % 9 + 1;
            ++am[sum];
        }
        for (int a = 1; a < 10; ++a) {
            for (int b = 1; b < 10; ++b) {
                int c = ((a * b) % 9 + 8) % 9 + 1;
                res += (long) am[a] * am[b] * am[c];
            }
        }
        for (int a = 1; a <= n; ++a) {
            res -= n / a;
        }
        writer.println(res);
    }


    public static void main(String[] args) {
        new Root().run();
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