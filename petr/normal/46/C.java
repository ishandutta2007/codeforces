import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Homyak implements Runnable {
    private void solve() throws IOException {
        int n = nextInt();
        String seq = nextToken();
        int nh = 0;
        int nt = 0;
        for (int i = 0; i < n; ++i)
            if (seq.charAt(i) == 'H')
                ++nh;
            else
                ++nt;
        int res = n;
        for (int delta = 0; delta < n; ++delta) {
            int changed = 0;
            int at = delta;
            for (int i = 0; i < nh; ++i) {
                if (seq.charAt(at) != 'H')
                    ++changed;
                ++at;
                if (at >= n)
                    at = 0;
            }
            for (int i = 0; i < nt; ++i) {
                if (seq.charAt(at) != 'T')
                    ++changed;
                ++at;
                if (at >= n)
                    at = 0;
            }
            res = Math.min(res, changed / 2);
        }
        writer.println(res);
    }

    public static void main(String[] args) {
        new Homyak().run();
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