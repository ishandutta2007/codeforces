import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Roads implements Runnable {
    long[] deltas;
    long[] maxes;

    void update(int root, int rl, int rr, int left, int right, long by) {
        right = Math.min(right, rr);
        left = Math.max(left, rl);
        if (right < left)
            return;
        if (right == rr && left == rl) {
            deltas[root] += by;
            maxes[root] += by;
        } else {
            int rm = (rl + rr) / 2;
            update(root * 2 + 1, rl, rm, left, right, by);
            update(root * 2 + 2, rm + 1, rr, left, right, by);
            maxes[root] = deltas[root] + Math.max(maxes[root * 2 + 1], maxes[root * 2 + 2]);
        }
    }

    private void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        n += 2;
        long[] cost = new long[n];
        for (int i = 1; i < n - 1; ++i)
            cost[i] = nextLong();
        int[] left = new int[m];
        int[] right = new int[m];
        long[] pay = new long[m];
        int[] nextSameRight = new int[m];
        int[] firstByRight = new int[n];
        Arrays.fill(firstByRight, -1);
        for (int i = 0; i < m; ++i) {
            left[i] = nextInt();
            right[i] = nextInt();
            pay[i] = nextLong();
            nextSameRight[i] = firstByRight[right[i]];
            firstByRight[right[i]] = i;
        }
        deltas = new long[4 * n + 10];
        maxes = new long[4 * n + 10];
        for (int i = 1; i < n; ++i) {
            long curRes = maxes[0];
            update(0, 0, n - 1, 0, i - 1, -cost[i]);
            int cur = firstByRight[i];
            while (cur >= 0) {
                update(0, 0, n - 1, 0, left[cur] - 1, pay[cur]);
                cur = nextSameRight[cur];
            }
            update(0, 0, n - 1, i, i, curRes);
        }
        writer.println(maxes[0]);
    }

    public static void main(String[] args) {
        new Roads().run();
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