import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Palin implements Runnable {
    long BASE = 14783621;

    private void solve() throws IOException {
        String line = nextToken();
        long h1 = 0;
        long h2 = 0;
        long pBase = 1;
        long res = 0;
        int[] val = new int[line.length() / 2 + 1];
        for (int i = 0; i < line.length(); ++i) {
            h1 = h1 * BASE + line.charAt(i);
            h2 = h2 + line.charAt(i) * pBase;
            pBase *= BASE;
            int cur = 0;
            if (h1 == h2) {
                cur = val[(i + 1) / 2] + 1;
            }
            res += cur;
            if (i + 1 < val.length)
                val[i + 1] = cur;
        }
        writer.println(res);
    }


    public static void main(String[] args) {
        new Palin().run();
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