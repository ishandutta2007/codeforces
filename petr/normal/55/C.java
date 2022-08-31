import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Cake implements Runnable {
    private void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int k = nextInt();
        boolean wins = false;
        for (int i = 0; i < k; ++i) {
            int x = nextInt();
            int y = nextInt();
            if (x <= 5 || y <= 5 || x >= n - 4 || y >= m - 4)
                wins = true;
        }
        if (wins) writer.println("YES"); else writer.println("NO");
    }

    public static void main(String[] args) {
        new Cake().run();
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