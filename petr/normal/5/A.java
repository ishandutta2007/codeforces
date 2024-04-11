import java.io.*;
import java.util.*;

public class Template implements Runnable {
    private void solve() throws IOException {
        int cnt = 0;
        long res = 0;
        while (true) {
            try {
                String line = reader.readLine();
                if (line.charAt(0) == '+')
                    ++cnt;
                else if (line.charAt(0) == '-')
                    --cnt;
                else {
                    res += (long) cnt * (line.length() - line.indexOf(':') - 1);

                }
            } catch (Exception e) {
                break;
            }
        }
        writer.println(res);
    }


    public static void main(String[] args) {
        new Template().run();
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