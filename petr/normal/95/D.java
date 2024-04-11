import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Horses implements Runnable {
    static int MAX_LENGTH = 1100;
    static int MODULO = 1000000007;
    int k;
    int[][] cnt;

    private void solve() throws IOException {
        int t = nextInt();
        k = nextInt();
        cnt = new int[MAX_LENGTH][k + 1];
        for (int i = 0; i <= k; ++i)
            cnt[0][i] = 1;
        for (int len = 1; len < MAX_LENGTH; ++len) {
            for (int i = 0; i <= k; ++i) {
                if (i > 0) {
                    cnt[len][i] = (int) (8 * (long) cnt[len - 1][i - 1] % MODULO);
                } else {
                    cnt[len][i] = (int) ((8 * (long) cnt[len - 1][0] + 2 * (long) cnt[len - 1][k]) % MODULO);
                }
            }
        }
        for (int i = 0; i < t; ++i) {
            String left = nextToken();
            String right = nextToken();
            long bad = (eval(right, true) - eval(left, false) + MODULO) % MODULO;
            long good = (evalStupid(right, true) - evalStupid(left, false) + MODULO) % MODULO;
            long res = (good - bad + MODULO) % MODULO;
            writer.println(res);
        }
    }

    private long evalStupid(String max, boolean inclusive) {
        long res = 0;
        for (int i = 0; i < max.length(); ++i) {
            res = (res * 10 + max.charAt(i) - '0') % MODULO;
        }
        if (!inclusive) res += MODULO - 1;
        return res % MODULO;
    }

    private long eval(String max, boolean inclusive) {
        return evalAt(max, 0, inclusive, 0);
    }

    private long evalAt(String max, int numEqual, boolean inclusive, int numMustNot47) {
        if (numEqual == max.length()) {
            if (inclusive)
                return 1;
            else
                return 0;
        }
        int maxDigit = max.charAt(numEqual) - '0';
        long res = 0;
        for (int digit = 0; digit <= maxDigit; ++digit) {
            int nextMust;
            if (digit == 4 || digit == 7) {
                if (numMustNot47 > 0)
                    continue;
                nextMust = k;
            } else {
                nextMust = numMustNot47 - 1;
                if (nextMust < 0) nextMust = 0;
            }
            if (digit < maxDigit) {
                res += cnt[max.length() - numEqual - 1][nextMust];
            } else {
                res += evalAt(max, numEqual + 1, inclusive, nextMust);
            }
            res %= MODULO;
        }
        return res;
    }

    public static void main(String[] args) {
        new Horses().run();
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