import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Tshirts implements Runnable {
    private void solve() throws IOException {
        int[] n = new int[5];
        for (int i = 0; i < 5; ++i)
            n[i] = nextInt();
        int k = nextInt();
        String[] sizes = new String[]{"S", "M", "L", "XL", "XXL"};
        for (int i = 0; i < k; ++i) {
            int u = 0;
            String cur = nextToken();
            for (int j = 0; j < sizes.length; ++j)
                if (sizes[j].equals(cur))
                    u = j;
            for (int delta = 0; delta <= 4; ++delta) {
                if (u + delta < 5 && n[u + delta] > 0) {
                    u += delta;
                    break;
                }
                if (u - delta >= 0 && n[u - delta] > 0) {
                    u -= delta;
                    break;
                }
            }
            --n[u];
            writer.println(sizes[u]);
        }
    }

    public static void main(String[] args) {
        new Tshirts().run();
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