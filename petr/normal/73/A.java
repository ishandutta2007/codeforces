import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Oblivion implements Runnable {
    private void solve() throws IOException {
        int[] x = new int[3];
        for (int i = 0; i < 3; ++i) x[i] = nextInt();
        int k = nextInt();
        int[] r = new int[3];
        Arrays.fill(r, 1);
        while (k > 0) {
            int best = Integer.MAX_VALUE;
            int bi = -1;
            for (int i = 0; i < 3; ++i) {
                if (r[i] == x[i]) continue;
                if (r[i] < best) {
                    best = r[i];
                    bi = i;
                }
            }
            if (bi < 0) break;
            --k;
            ++r[bi];
        }
        writer.println((long) r[0] * r[1] * r[2]);
    }

    public static void main(String[] args) {
        new Oblivion().run();
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