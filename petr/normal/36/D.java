import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class NewChess implements Runnable {
    private void solve() throws IOException {
        int t = nextInt();
        int k = nextInt();
        for (int i = 0; i < t; ++i) {
            int n = nextInt() - 1;
            int m = nextInt() - 1;
            if (Math.min(n, m) % (k + 1) == k) {
                writer.println("+");
            } else {
                int inside = Math.min(n, m) / (k + 1) % 2;
                if (k == 1)
                    inside = 0;
                if ((inside + n + m) % 2 == 0) {
                    writer.println("-");
                } else {
                    writer.println("+");
                }
            }
        }
    }

    public static void main(String[] args) {
        new NewChess().run();
    }

    static final String IN_FILE = "input.txt";
    static final String OUT_FILE = "output.txt";

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    public void run() {
        try {
            reader = new BufferedReader(new FileReader(IN_FILE));
            tokenizer = null;
            writer = new PrintWriter(OUT_FILE);
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