import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {

    private void solve() throws IOException {
        int n = nextInt();
        int d = nextInt();
        int[] min = new int[n];
        int[] max = new int[n];
        for (int i = 0; i < n; i++) {
            min[i] = nextInt();
            max[i] = nextInt();
        }
        int s = 0;
        int[] r = new int[n];
        for (int i = 0; i < n; i++) {
            r[i] = min[i];
            s += r[i];
        }
        if (s < d) {
            for (int i = 0; i < n; i++) {
                if (s < d) {
                    int k = Math.min(d - s, max[i] - r[i]);
                    s += k;
                    r[i] += k;
                }
            }
        }
        if (s == d) {
            writer.println("YES");
            for (int i = 0; i < n; i++) {
                writer.print(r[i] + " ");
            }
            writer.println();
        } else {
            writer.println("NO");
        }
    }

    public static void main(String[] args) throws InterruptedException {
        new B().run();
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