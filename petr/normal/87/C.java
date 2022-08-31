import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Game implements Runnable {
    private void solve() throws IOException {
        int n = nextInt();
        int[] grundy = new int[n + 1];
        int[] seen = new int[n + 2];
        int[] minMoves = new int[n + 1];
        Arrays.fill(minMoves, Integer.MAX_VALUE);
        Arrays.fill(seen, -1);
        for (int i = 0; i <= n; ++i) {
            for (int count = 2; count * (count + 1) / 2 <= i; ++count) {
                int first = (i - (count * (count - 1)) / 2);
                if (first % count != 0) continue;
                first /= count;
                int xor = 0;
                for (int j = 0; j < count; ++j) xor ^= grundy[first + j];
                seen[xor] = i;
                if (xor == 0) minMoves[i] = Math.min(minMoves[i], count);
            }
            int j;
            for (j = 0; seen[j] == i; ++j);
            grundy[i] = j;
        }
        if (minMoves[n] == Integer.MAX_VALUE)
            writer.println(-1);
        else
            writer.println(minMoves[n]);
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