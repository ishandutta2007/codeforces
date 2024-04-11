import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Jumps implements Runnable {
    private void solve() throws IOException {
        int n = nextInt();
        boolean[] visited = new boolean[n];
        int at = 0;
        visited[at] = true;
        for (int by = 1; by < n; ++by) {
            at = (at + by) % n;
            visited[at] = true;
        }
        boolean[] res = visited.clone();
        for (int cur = at; cur != 0; cur = (cur + at) % n) {
            for (int i = 0; i < n; ++i) {
                if (visited[i])
                    res[(cur + i) % n] = true;
            }
        }
        for (boolean x : res)
            if (!x) {
                writer.println("NO");
                return;
            }
        writer.println("YES");
    }

    public static void main(String[] args) {
        new Jumps().run();
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