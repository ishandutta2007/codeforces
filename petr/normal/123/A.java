import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class PrimePermutation implements Runnable {
    private void solve() throws IOException {
        String s = nextToken();
        int n = s.length();
        boolean[] mark = new boolean[n + 1];
        for (int i = 2; i <= n; ++i) {
            boolean prime = true;
            for (int j = 2; j * j <= i; ++j)
                if (i % j == 0) prime = false;
            if (prime) {
                if (2 * i <= n) {
                    for (int j = i; j <= n; j += i)
                        mark[j] = true;
                }
            }
        }
        int numMarked = 0;
        for (boolean value : mark) if (value) ++numMarked;
        int[] cnt = new int[26];
        for (int i = 0; i < s.length(); ++i)
            ++cnt[s.charAt(i) - 'a'];
        for (int i = 0; i < 26; ++i)
            if (cnt[i] >= numMarked) {
                char[] res = new char[n];
                for (int j = 0; j < n; ++j) {
                    if (mark[j + 1]) {
                        res[j] = (char) ('a' + i);
                        --cnt[i];
                    }
                }
                for (int j = 0; j < n; ++j) {
                    if (!mark[j + 1]) {
                        for (int k = 0; k < 26; ++k)
                            if (cnt[k] > 0) {
                                res[j] = (char) ('a' + k);
                                --cnt[k];
                                break;
                            }
                    }
                }
                writer.println("YES");
                writer.println(new String(res));
                return;
            }
        writer.println("NO");
    }

    public static void main(String[] args) {
        new PrimePermutation().run();
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