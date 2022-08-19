import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Outside implements Runnable {
    private void solve() throws IOException {
        int n = nextInt();
        String data = nextToken();
        int delta = -1;
        int last = -1;
        for (int i = 0; i < n; ++i) {
            if (data.charAt(i) == '1') {
                if (last != -1) {
                    int cur = i - last;
                    if (delta != -1) {
                        if (delta != cur) {
                            writer.println("NO");
                            return;
                        }
                    }
                    delta = cur;
                }
                last = i;
            }
        }
        writer.println("YES");
    }

    public static void main(String[] args) {
        new Outside().run();
    }

    static final String IN_FILE = "input.txt";
    static final String OUT_FILE = "output.txt";

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    public void run() {
        try {
            reader = new BufferedReader(new FileReader(IN_FILE));
            tokenizer = null;
            writer = new PrintWriter(OUT_FILE);
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