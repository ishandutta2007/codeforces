import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Coins implements Runnable {
    private void solve() throws IOException {
        int n = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i)
            a[i] = nextInt();
        int res = Integer.MAX_VALUE;
        for (int i = 1; i < n; ++i)
            for (int j = i; j < n; ++j) {
                int tmp = a[i - 1] - 1;
                int am = 0;
                int w = 0;
                for (int k = 0; k <= j; ++k) {
                    int cnt = tmp / a[k];
                    tmp %= a[k];
                    am += cnt;
                    w += a[k] * cnt;
                }
                w += a[j];
                ++am;
                if (am < greedy(a, w)) {
                    res = Math.min(res, w);
                }
            }
        if (res == Integer.MAX_VALUE)
            res = -1;
        writer.println(res);
    }
                                   
    private int greedy(int[] a, int x) {
        int res = 0;
        for (int b : a) {
            res += x / b;
            x %= b;
        }
        return res;
    }


    public static void main(String[] args) {
        new Coins().run();
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