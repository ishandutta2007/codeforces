import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Celebration implements Runnable {
    private void solve() throws IOException {
        int n = nextInt();
        int[] p = new int[n];
        int[] depth = new int[n];
        for (int i = 0; i < n; ++i) p[i] = nextInt() - 1;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            calcDepth(i, p, depth);
            res = Math.max(res, depth[i]);
        }
        writer.println(res);
    }

    private void calcDepth(int at, int[] p, int[] depth) {
        if (depth[at] > 0)
            return;
        depth[at] = 1;
        if (p[at] >= 0) {
            calcDepth(p[at], p, depth);
            depth[at] += depth[p[at]];
        }
    }

    public static void main(String[] args) {
        new Celebration().run();
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