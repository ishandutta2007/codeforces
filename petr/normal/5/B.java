import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Center implements Runnable {
    private void solve() throws IOException {
        List<String> lines = new ArrayList<String>();
        while (true) {
            try {
                String line = reader.readLine();
                if (line == null)
                    break;
                lines.add(line);
            } catch (Exception e) {
                break;
            }
        }
        int maxLen = 0;
        for (String x : lines)
            maxLen = Math.max(maxLen, x.length());
        boolean sw = false;
        for (int i = 0; i < maxLen + 2; ++i)
            writer.print('*');
        writer.println();
        for (String x : lines) {
            writer.print('*');
            int delta = maxLen - x.length();
            int rdelta;
            if (delta % 2 == 0) {
                delta /= 2;
                rdelta = delta;
            } else {
                if (sw) {
                    rdelta = (delta - 1) / 2;
                    delta = (delta + 1) / 2;
                    sw = false;
                } else {
                    rdelta = (delta + 1) / 2;
                    delta = (delta - 1) / 2;
                    sw = true;
                }
            }
            for (int i = 0; i < delta; ++i)
                writer.print(' ');
            writer.print(x);
            for (int i = 0; i < rdelta; ++i)
                writer.print(' ');
            writer.println('*');
        }
        for (int i = 0; i < maxLen + 2; ++i)
            writer.print('*');
        writer.println();
    }


    public static void main(String[] args) {
        new Center().run();
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