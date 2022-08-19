import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Random;
import java.util.StringTokenizer;

public class Nim implements Runnable {
    private void solve() throws IOException {
        /*Random r = new Random(140374304831910L);
        for (int i = 0; i < 1000000; ++i) {
            long x = Math.abs(r.nextLong() % 1000000000000000L);
            long m = r.nextInt(1000) + 1;
            if (segmentXor(x, m) != segmentXor2(x, m))
                throw new RuntimeException();
        }*/
        int n = nextInt();
        long res = 0;
        for (int i = 0; i < n; ++i) {
            long x = nextLong();
            long m = nextLong();
            res = res ^ segmentXor(x, m);
        }
        if (res == 0) {
            writer.println("bolik");
        } else {
            writer.println("tolik");
        }
    }

    private long segmentXor(long x, long m) {
        if (m == 1)
            return x;
        if (m == 0)
            return 0;
        if (x % 2 != 0)
            return x ^ segmentXor(x + 1, m - 1);
        if (m % 2 != 0)
            return (x + m - 1) ^ segmentXor(x, m - 1);
        if ((m / 2) % 2 == 0)
            return 0;
        else
            return 1;
    }

    private long segmentXor2(long x, long m) {
        long res = 0;
        for (int i = 0; i < m; ++i)
            res ^= (x + i);
        return res;
    }

    public static void main(String[] args) {
        new Nim().run();
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