import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Lines implements Runnable {
    private void solve() throws IOException {
        int a1 = nextInt();
        int b1 = nextInt();
        int c1 = nextInt();
        int a2 = nextInt();
        int b2 = nextInt();
        int c2 = nextInt();
        if (a1 == 0 && b1 == 0 && c1 != 0) {
            writer.println(0);
            return;
        }
        if (a2 == 0 && b2 == 0 && c2 != 0) {
            writer.println(0);
            return;
        }
        if (a1 == 0 && b1 == 0 && c1 == 0) {
            writer.println(-1);
            return;
        }
        if (a2 == 0 && b2 == 0 && c2 == 0) {
            writer.println(-1);
            return;
        }
        int z = a1 * b2 - b1 * a2;
        if (z == 0) {
            int x = c1 * b2 - b1 * c2;
            int y = a1 * c2 - c1 * a2;
            if (x == 0 && y == 0) {
                writer.println(-1);
            } else {
                writer.println(0);
            }
        } else {
            writer.println(1);
        }
    }

    public static void main(String[] args) {
        new Lines().run();
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