import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class SMS implements Runnable {
    private void solve() throws IOException {
        int n = nextInt();
        String text = reader.readLine();
        int start = 0;
        int res = 0;
        int cur = 0;
        for (int i = 0; i < text.length(); ++i) {
            if ("!?.".indexOf(text.charAt(i)) >= 0) {
                int len = i - start + 1;
                start = i + 2;
                if (cur > 0) cur += 1;
                cur += len;
                if (cur > n) {
                    ++res;
                    cur = len;
                    if (cur > n) {
                        writer.println("Impossible");
                        return;
                    }
                }
            }
        }
        if (cur > 0) ++res;
        writer.println(res);
    }


    public static void main(String[] args) {
        new SMS().run();
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