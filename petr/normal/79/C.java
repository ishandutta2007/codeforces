import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class BoringStrings implements Runnable {
    private void solve() throws IOException {
        String s = nextToken();
        int n = nextInt();
        String[] b = new String[n];
        for (int i = 0; i < n; ++i) {
            b[i] = nextToken();
        }

        int len = 0;
        int pos = 0;
        int left = 0;
        for (int i = 1; i <= s.length(); ++i) {
            String cur = s.substring(0, i);
            for (String x : b) {
                if (cur.endsWith(x)) {
                    left = Math.max(left, i - x.length() + 1);
                }
            }
            if (i - left > len) {
                len = i - left;
                pos = left;
            }
        }
        writer.println(len + " " + pos);
    }

    public static void main(String[] args) {
        new BoringStrings().run();
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