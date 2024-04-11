import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Bag implements Runnable {
    private void solve() throws IOException {
        int xs = nextInt();
        int ys = nextInt();
        int n = nextInt();
        int[] x = new int[n];
        int[] y = new int[n];
        for (int i = 0; i < n; ++i) {
            x[i] = nextInt();
            y[i] = nextInt();
        }
        int[][] pair = new int[n][n];
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                pair[i][j] = (x[i] - xs) * (x[i] - xs) + (y[i] - ys) * (y[i] - ys) + (x[j] - xs) * (x[j] - xs) + (y[j] - ys) * (y[j] - ys) + (x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]);
        int[] single = new int[n];
        for (int i = 0; i < n; ++i) {
            single[i] = 2 * ((x[i] - xs) * (x[i] - xs) + (y[i] - ys) * (y[i] - ys));
        }
        int[] best = new int[1 << n];
        int[] prev = new int[1 << n];
        for (int set = 1; set < (1 << n); ++set) {
            int i;
            for (i = 0; i < n; ++i)
                if ((set & (1 << i)) != 0)
                    break;
            best[set] = best[set ^ (1 << i)] + single[i];
            prev[set] = i + 1;
            for (int j = i + 1; j < n; ++j)
                if ((set & (1 << j)) != 0) {
                    int cur = best[set ^ (1 << i) ^ (1 << j)] + pair[i][j];
                    if (cur < best[set]) {
                        best[set] = cur;
                        prev[set] = (i + 1) * 100 + (j + 1);
                    }
                }
        }
        writer.println(best[(1 << n) - 1]);
        int now = (1 << n) - 1;
        writer.print("0");
        while (now > 0) {
            int what = prev[now];
            int wa = what % 100 - 1;
            int wb = what / 100 - 1;
            if (wa >= 0) {
                writer.print(" ");
                writer.print(wa + 1);
                now ^= 1 << wa;
            }
            if (wb >= 0) {
                writer.print(" ");
                writer.print(wb + 1);
                now ^= 1 << wb;
            }
            writer.print(" ");
            writer.print("0");
        }
        writer.println();
    }


    public static void main(String[] args) {
        new Bag().run();
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