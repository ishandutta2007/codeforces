import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class HappySum implements Runnable {
    private void solve() throws IOException {
        int n = nextInt();
        for (int n4 = 0;; ++n4) {
            int rest = n - 4 * n4;
            if (rest < 0) {
                System.out.println(-1);
                return;
            }
            if (rest % 7 != 0)
                continue;
            int n7 = rest / 7;
            for (int i = 0; i < n4; ++i)
                System.out.print('4');
            for (int i = 0; i < n7; ++i)
                System.out.print('7');
            System.out.println();
            return;
        }
    }

    public static void main(String[] args) {
        new HappySum().run();
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