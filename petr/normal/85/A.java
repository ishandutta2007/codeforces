import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Domino implements Runnable {
    char[][] field;

    void put(int r1, int c1, int r2, int c2) {
        boolean[] used = new boolean[26];
        for (int r0 = Math.min(r1, r2) - 1; r0 <= Math.max(r1, r2) + 1; ++r0)
            for (int c0 = Math.min(c1, c2) - 1; c0 <= Math.max(c1, c2) + 1; ++c0) {
                if (r0 >= 0 && r0 < field.length && c0 >= 0 && c0 < field[r0].length) {
                    char ch = field[r0][c0];
                    if (ch != 0)
                        used[ch - 'a'] = true;
                }
            }
        for (int x = 0; x < 26; ++x)
            if (!used[x]) {
                field[r1][c1] = (char) ('a' + x);
                field[r2][c2] = (char) ('a' + x);
                return;
            }
    }

    private void solve() throws IOException {
        int n = nextInt();
        field = new char[4][n];
        for (int i = 0; i + 1 < n; i += 2) {
            put(0, i, 0, i + 1);
            put(1, i, 1, i + 1);
        }
        if (n % 2 != 0) {
            put(0, n - 1, 1, n - 1);
        }
        put(2, 0, 3, 0);
        for (int i = 1; i + 1 < n; i += 2) {
            put(2, i, 2, i + 1);
            put(3, i, 3, i + 1);
        }
        if (n % 2 == 0) {
            put(2, n - 1, 3, n - 1);
        }
        for (int i = 0; i < 4; ++i) {
            writer.println(String.valueOf(field[i]));
        }
    }

    public static void main(String[] args) {
        new Domino().run();
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