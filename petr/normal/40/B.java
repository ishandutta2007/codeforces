import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Color {
    private void solve() {
        int n = nextInt();
        int m = nextInt();
        int x = nextInt();
        writer.println(getAm(n, m, x - 1) - getAm(n, m, x));
    }

    private int getAm(int n, int m, int x) {
        while (n > 0 && m > 0 && x > 0) {
            --x;
            n -= 2;
            m -= 2;
        }
        if (n < 0) n = 0;
        if (m < 0) m = 0;
        return (n * m + 1) / 2;
    }


    public static void main(String[] args) {
        new Color().run();
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