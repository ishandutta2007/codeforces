import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Expression implements Runnable {
    static final int MODULO = 1000003;

    private void solve() throws IOException {
        String s = nextToken();

        boolean[] digit = new boolean[s.length()];
        for (int i = 0; i < s.length(); ++i) {
            digit[i] = (s.charAt(i) >= '0' && s.charAt(i) <= '9');
        }
        int n = 0;
        int[] a = new int[s.length()];
        if (digit[0]) {
            a[n++] = 0;
        }
        for (int start = 0; start < s.length(); ++start) {
            if (!digit[start] && (start == 0 || digit[start - 1])) {
                int len = 1;
                while (start + len < s.length() && !digit[start + len])
                    ++len;
                if (start + len >= s.length()) {
                    writer.println(0);
                    return;
                }
                int startPm = 0;
                if (start > 0)
                    startPm = 1;
                for (int i = startPm; i < len; ++i) {
                    char ch = s.charAt(start + i);
                    if (ch != '+' && ch != '-') {
                        writer.println(0);
                        return;
                    }
                }
                a[n++] = len - startPm;
            }
        }
        long[] res = new long[n + 1];
        int[] inv = new int[3000];
        for (int i = 1; i < inv.length; ++i) {
            inv[i] = pow(i, MODULO - 2);
        }
        res[1] = 1;
        for (int i = 0; i < n; ++i) {
            res[0] = 0;
            long[] nres = new long[n + 1];
            int comb = 1;
            for (int numOpen = 0; numOpen <= n; ++numOpen) {
                if (numOpen > 0 && a[i] > 0)
                    comb = (int) (comb * (long) (numOpen + a[i]) % MODULO * inv[numOpen] % MODULO);
                for (int oldOpen = 0; oldOpen + numOpen <= n; ++oldOpen) {
                    int newOpen = oldOpen + numOpen - 1;
                    if (newOpen < 0) continue;
                    if (newOpen > n - i - 1) break;
                    nres[newOpen] += res[oldOpen] * (long) comb;
                }
            }
            for (int j = 0; j <= n; ++j)
                nres[j] %= MODULO;
            res = nres;
        }
        writer.println(res[0]);
    }

    private int pow(int a, int k) {
        if (k == 0)
            return 1;
        if (k % 2 == 0) {
            a = (int) ((long) a * a % MODULO);
            return pow(a, k / 2);
        }
        return (int) ((long) a * pow(a, k - 1) % MODULO);
    }

    public static void main(String[] args) {
        new Expression().run();
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