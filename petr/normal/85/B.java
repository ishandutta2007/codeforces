import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Embassy implements Runnable {
    private void solve() throws IOException {
        int[] count = new int[3];
        for (int i = 0; i < 3; ++i)
            count[i] = nextInt();
        long[] serviceTime = new long[3];
        for (int i = 0; i < 3; ++i)
            serviceTime[i] = nextLong();
        int n = nextInt();
        long[] enterTime = new long[n];
        for (int i = 0; i < n; ++i)
            enterTime[i] = nextLong();
        long[] exitTime = new long[n];
        for (int i = 0; i < n; ++i)
            exitTime[i] = enterTime[i];
        for (int kind = 0; kind < 3; ++kind) {
            int cnt = Math.min(n, count[kind]);
            long[] freeAt = new long[cnt];
            for (int i = 0; i < n; ++i) {
                long gotAt = Math.max(freeAt[i % cnt], exitTime[i]) + serviceTime[kind];
                freeAt[i % cnt] = gotAt;
                exitTime[i] = gotAt;
            }
        }
        long res = 0;
        for (int i = 0; i < n; ++i)
            res = Math.max(res, exitTime[i] - enterTime[i]);
        writer.println(res);
    }

    public static void main(String[] args) {
        new Embassy().run();
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