import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Paint implements Runnable {
    private void solve() throws IOException {
        String[] d = new String[8];
        for (int i = 0; i < 8; ++i)
            d[i] = nextToken();
        int res = 100;
        for (int set = 0; set < (1 << 16); ++set) {
            boolean ok = true;
            for (int r = 0; r < 8; ++r)
                for (int c = 0; c < 8; ++c) {
                    if (d[r].charAt(c) == 'B' ^ ((set & (1 << r)) != 0 || (set & (1 << (c + 8))) != 0)) {
                        ok = false;
                    }
                }
            if (ok) {
                int cur = Integer.bitCount(set);
                if (cur < res)
                    res = cur;
            }
        }
        writer.println(res);
    }


    public static void main(String[] args) {
        new Paint().run();
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