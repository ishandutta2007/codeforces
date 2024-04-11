import java.io.*;
import java.util.*;

public class Template implements Runnable {
    private void solve() throws IOException {
        int n = nextInt();
        int p1 = nextInt();
        int p2 = nextInt();
        int p3 = nextInt();
        int t1 = nextInt();
        int t2 = nextInt();
        int[] l = new int[n];
        int[] r = new int[n];
        int res = 0;
        for (int i = 0; i < n; ++i) {
            l[i] = nextInt();
            r[i] = nextInt();
            res += p1 * (r[i] - l[i]);
        }
        for (int i = 0; i < n - 1; ++i) {
            int time = l[i + 1] - r[i];
            res += p1 * Math.min(t1, time) + p2 * Math.max(0, Math.min(t2, time - t1)) + p3 * Math.max(0, time - t1 - t2);
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