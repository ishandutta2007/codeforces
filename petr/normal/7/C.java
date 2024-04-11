import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Line implements Runnable {
    private void solve() throws IOException {
        long a = nextInt();
        long b = nextInt();
        long c = nextInt();
        long x = a;
        long y = b;
        long xp = 1;
        long xq = 0;
        long yp = 0;
        long yq = 1;
        if (x < 0) {
            x = -x;
            xp = -1;
        }
        if (y < 0) {
            y = -y;
            yq = -1;
        }
        while (y > 0) {
            long by = x / y;
            long t = x - by * y;
            long tp = xp - by * yp;
            long tq = xq - by * yq;
            x = y;
            xp = yp;
            xq = yq;
            y = t;
            yp = tp;
            yq = tq;
        }
        if (c % x != 0) {
            writer.println(-1);
        } else {
            long p = xp;
            long q = xq;
            long z;
            if (b == 0) {
                z = - q / a;
            } else {
                z = p / b;
            }
            p -= z * b;
            q += z * a;
            p *= -c / x;
            q *= -c / x;
            writer.println(p + " " + q);
        }
    }


    public static void main(String[] args) {
        new Line().run();
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