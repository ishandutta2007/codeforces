import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Parking implements Runnable {
    private void solve() throws IOException {
        int L = nextInt();
        int b = nextInt();
        int f = nextInt();
        int n = nextInt();
        int[] pos = new int[n];
        int[] len = new int[n];
        Arrays.fill(pos, -1);
        for (int i = 0; i < n; ++i) {
            int kind = nextInt();
            int what = nextInt();
            if (kind == 1) {
                int best = L + 1;
                for (int after = -1; after < i; ++after) {
                    int at = 0;
                    if (after >= 0) {
                        if (pos[after] < 0)
                            continue;
                        at = pos[after] + len[after] + b;
                    }
                    if (at + what > L)
                        continue;
                    boolean ok = true;
                    for (int j = 0; j < i; ++j)
                        if (pos[j] >= 0 && pos[j] + len[j] + b > at && pos[j] < at + what + f) {
                            ok = false;
                            break;
                        }
                    if (ok) {
                        best = Math.min(best, at);
                    }
                }
                if (best > L) {
                    writer.println(-1);
                } else {
                    writer.println(best);
                    pos[i] = best;
                    len[i] = what;
                }
            } else {
                --what;
                pos[what] = -1;
            }
        }
    }

    public static void main(String[] args) {
        new Parking().run();
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