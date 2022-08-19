import java.io.*;
import java.util.*;

public class Template implements Runnable {
    private void solve() throws IOException {
        int n = nextInt();
        int at = 1;
        for (int i = 0; i < (n - 1); ++i) {
            at += (i + 1);
            while (at > n) at -= n;
            if (i > 0) writer.print(" ");
            writer.print(at);
        }
        writer.println();
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