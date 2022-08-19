import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Gifts implements Runnable {
    private void solve() throws IOException {
        int n = nextInt();
        int k = nextInt();
        int c = nextInt();
        boolean[] gift = new boolean[n + 1];
        for (int i = 0; i < c; ++i)
            gift[nextInt()] = true;
        gift[0] = true;
        int last = 0;
        for (int i = 1; i <= n; ++i) {
            if (gift[i])
                last = i;
            if (i - last >= k) {
                gift[i] = true;
                last = i;
            }
        }
        int res = -1;
        for (boolean x : gift)
            if (x) ++res;
        writer.println(res);
    }

    public static void main(String[] args) {
        new Gifts().run();
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