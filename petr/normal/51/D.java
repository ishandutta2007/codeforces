import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;

public class Geometric implements Runnable {
    private void solve() throws IOException {
        int n = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = nextInt();
        }
        int[] zero = new int[n];
        int[] nonzero = new int[n];
        int nzero = 0;
        int nnonzero = 0;
        for (int i = 0; i < n; ++i)
            if (a[i] == 0)
                zero[nzero++] = i;
            else
                nonzero[nnonzero++] = i;
        if (nnonzero == 0) {
            writer.println(0);
            return;
        }
        if (nnonzero == 1) {
            if (nonzero[0] == 0)
                writer.println(0);
            else
                writer.println(1);
            return;
        }
        if (nnonzero == 2 && nzero > 0) {
            if (nonzero[0] == 0) {
                writer.println(1);
                return;
            }
        }
        if (nzero > 0) {
            if (nzero > 1) {
                writer.println(2);
                return;
            }
            if (check(a, zero[0])) {
                writer.println(1);
                return;
            } else {
                writer.println(2);
                return;
            }
        }
        if (check(a, -1)) {
            writer.println(0);
            return;
        }
        int total = 0;
        for (int i = 0; i < n - 2; ++i) {
            if (a[i] * a[i + 2] != a[i + 1] * a[i + 1]) {
                ++total;
                if (total > 3) {
                    writer.println(2);
                    return;
                }
                if (check(a, i) || check(a, i + 1) || check(a, i + 2)) {
                    writer.println(1);
                    return;
                }
            }
        }
        writer.println(2);
    }

    private boolean check(int[] a, int skip) {
        int first = 0;
        int second = 0;
        for (int i = 0; i < a.length; ++i) {
            if (i == skip)
                continue;
            int cur = a[i];
            if (first != 0) {
                if (first * cur != second * second)
                    return false;
            }
            first = second;
            second = cur;
        }
        return true;
    }

    public static void main(String[] args) {
        new Geometric().run();
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