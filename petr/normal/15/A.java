import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Houses implements Runnable {
    private void solve() throws IOException {
        int n = nextInt();
        int t = nextInt();
        int[] x = new int[n];
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            x[i] = nextInt() * 2;
            a[i] = nextInt();
        }
        Set<Integer> res = new HashSet<Integer>();
        for (int i = 0; i < n; ++i) {
            if (valid(n, t, x, a, x[i] + a[i] + t))
                res.add(x[i] + a[i] + t);
            if (valid(n, t, x, a, x[i] - a[i] - t))
                res.add(x[i] - a[i] - t);
        }
        writer.println(res.size());
    }

    private boolean valid(int n, int t, int[] x, int[] a, int pos) {
        for (int i = 0; i < n; ++i) {
            if (Math.abs(pos - x[i]) < a[i] + t)
                return false;
        }
        return true;
    }

    public static void main(String[] args) {
        new Houses().run();
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