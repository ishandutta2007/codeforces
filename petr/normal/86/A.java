import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class MaxProd implements Runnable {
    private void solve() throws IOException {
        long l = nextLong();
        long r = nextLong();
        long p10 = 1;
        long res = 0;
        while (p10 <= r) {
            long left = Math.max(l, p10);
            long right = Math.min(p10 * 10 - 1, r);
            if (left <= right) {
                long middle = (p10 * 10 - 1) / 2;
                if (middle < left)
                    middle = left;
                if (middle > right)
                    middle = right;
                res = Math.max(res, middle * (p10 * 10 - 1 - middle));
            }
            p10 *= 10;
        }
        writer.println(res);
    }

    public static void main(String[] args) {
        new MaxProd().run();
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