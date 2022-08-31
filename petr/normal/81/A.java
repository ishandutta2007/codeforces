import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Repeatinhg implements Runnable {
    private void solve() throws IOException {
        String s = nextToken();
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < s.length(); ++i) {
            if (res.length() > 0 && res.charAt(res.length() - 1) == s.charAt(i)) {
                res.deleteCharAt(res.length() - 1);
            } else {
                res.append(s.charAt(i));
            }
        }
        writer.println(res.toString());
    }

    public static void main(String[] args) {
        new Repeatinhg().run();
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