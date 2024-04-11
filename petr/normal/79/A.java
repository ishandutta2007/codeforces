import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Game implements Runnable {
    private void solve() throws IOException {
        int x = nextInt();
        int y = nextInt();
        int who = 0;
        while (y >= 2 && x * 100 + y * 10 >= 220) {
            int togo = 200;
            y -= 2;
            if (who == 0) {
                while (x >= 1 && togo >= 100) {
                    --x;
                    togo -= 100;
                }
                while (y >= 10 && togo >= 100) {
                    y -= 10;
                    togo -= 100;
                }
                if (togo != 0) throw new RuntimeException();
            } else {
                while (y >= 10 && togo >= 100) {
                    y -= 10;
                    togo -= 100;
                }
                while (x >= 1 && togo >= 100) {
                    --x;
                    togo -= 100;
                }
                if (togo != 0) throw new RuntimeException();
            }
            who = 1 - who;
        }
        if (who == 0) writer.println("Hanako"); else writer.println("Ciel");
    }

    public static void main(String[] args) {
        new Game().run();
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