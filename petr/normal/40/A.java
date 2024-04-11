import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Template {
    private void solve() {
        int x = nextInt();
        int y = nextInt();
        double d = Math.sqrt(x * x + y * y);
        if (x == 0 || y == 0 || d == Math.round(d)) {
            writer.println("black");
        } else {
            int dd = (int) Math.floor(d);
            if (dd % 2 == 1 ^ x > 0 ^ y > 0) {
                writer.println("white");
            } else {
                writer.println("black");
            }
        }
    }


    public static void main(String[] args) {
        new Template().run();
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    private void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            writer = new PrintWriter(System.out);
            tokenizer = null;
            solve();
            reader.close();
            writer.close();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    private String nextToken() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    private int nextInt() {
        return Integer.parseInt(nextToken());
    }

    private long nextLong() {
        return Long.parseLong(nextToken());
    }

    private double nextDouble() {
        return Double.parseDouble(nextToken());
    }
}