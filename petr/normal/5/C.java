import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Parens implements Runnable {
    private void solve() throws IOException {
        String s = nextToken();
        int n = s.length() + 1;
        int[] balance = new int[n];
        balance[0] = 0;
        int min = 0;
        int max = 0;
        for (int i = 1; i < n; ++i) {
            if (s.charAt(i - 1) == '(')
                balance[i] = balance[i - 1] + 1;
            else
                balance[i] = balance[i - 1] - 1;
            min = Math.min(min, balance[i]);
            max = Math.max(max, balance[i]);
        }
        int[] sameLeft = new int[n];
        int[] first = new int[max - min + 1];
        Arrays.fill(first, -1);
        for (int i = 0; i < n; ++i) {
            sameLeft[i] = first[balance[i] - min];
            first[balance[i] - min] = i;
        }
        int[] answer = new int[n];
        answer[0] = 0;
        for (int i = 1; i < n; ++i) {
            if (balance[i - 1] > balance[i]) {
                int j = sameLeft[i];
                if (j >= 0) {
                    answer[i] = answer[j] + i - j;
                }
            }
        }
        max = 0;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (answer[i] > max) {
                max = answer[i];
                cnt = 1;
            } else if (answer[i] == max) {
                ++cnt;
            }
        }
        if (max == 0)
            cnt = 1;
        writer.println(max + " " + cnt);
    }


    public static void main(String[] args) {
        new Parens().run();
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