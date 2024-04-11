import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Cells implements Runnable {
    private void solve() throws IOException {
        int a = nextInt();
        int b = nextInt();
        int x1 = nextInt();
        int y1 = nextInt();
        int x2 = nextInt();
        int y2 = nextInt();
        int s1 = x1 + y1;
        int m1 = x1 - y1;
        int s2 = x2 + y2;
        int m2 = x2 - y2;
        s1 = divide(s1, 2 * a);
        m1 = divide(m1, 2 * b);
        s2 = divide(s2, 2 * a);
        m2 = divide(m2, 2 * b);
        writer.println(Math.max(Math.abs(s1 - s2), Math.abs(m1 - m2)));
        
    }

    private int divide(long x, long y) {
        long r = x / y - 1;
        while (y * (r + 1) <= x) ++r;
        return (int) r;
    }

    public static void main(String[] args) {
        new Cells().run();
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