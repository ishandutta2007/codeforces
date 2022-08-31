import java.io.*;
import java.util.*;

public class Template implements Runnable {
    private void solve() throws IOException {
        int n = nextInt();
        int d = nextInt();
        long last = nextInt();
        long res = 0;
        for (int i = 0; i < n - 1; ++i) {
            long cur = nextInt();
            if (cur <= last) {
                long by = (last + d - cur) / d;
                res += by;
                last = cur + by * d;
            } else {
                last = cur;
            }
        }
        writer.println(res);
    }


    public static void main(String[] args) {
        new Template().run();
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