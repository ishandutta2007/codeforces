import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Words implements Runnable {
    private void solve() throws IOException {
        int n = nextInt();
        int k = nextInt();
        String ps = nextToken();
        int[] p = new int[ps.length()];
        for (int i = 0; i < p.length; ++i)
            p[i] = ps.charAt(i) - 'a';
        String ms = nextToken();
        boolean[] match = new boolean[ms.length()];
        for (int i = 0; i < match.length; ++i)
            match[i] = ms.charAt(i) != '0';
        int[] l = new int[p.length + 1];
        for (int i = 2; i <= p.length; ++i) {
            int cur = l[i - 1];
            while (true) {
                if (p[cur] == p[i - 1]) {
                    ++cur;
                    break;
                }
                if (cur == 0) break;
                cur = l[cur];
            }
            l[i] = cur;
        }
        String[] way = new String[p.length + 1];
        way[0] = "";
        for (int i = 0; i < n; ++i) {
            String[] nway = new String[p.length + 1];
            for (int prev = 0; prev <= p.length; ++prev) {
                if (way[prev] == null)
                    continue;
                for (int c = 0; c < k; ++c) {
                    int cur = prev;
                    while (true) {
                        if (cur == p.length) {
                            cur = l[cur];
                            continue;
                        }
                        if (p[cur] == c) {
                            ++cur;
                            break;
                        }
                        if (cur == 0) break;
                        cur = l[cur];
                    }
                    if (nway[cur] == null) {
                        nway[cur] = way[prev] + (char) ('a' + c);
                    }
                }
            }
            if (i >= p.length - 1) {
                if (match[i - p.length + 1]) {
                    for (int j = 0; j < p.length; ++j)
                        nway[j] = null;
                } else {
                    nway[p.length] = null;
                }
            }
            way = nway;
        }
        String res = null;
        for (String x : way)
            if (x != null) {
                res = x;
                break;
            }
        if (res == null) res = "No solution";
        writer.println(res);
    }

    public static void main(String[] args) {
        new Words().run();
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