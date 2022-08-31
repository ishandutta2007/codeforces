import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Morrowindows implements Runnable {
    private void solve() throws IOException {
        int n = nextInt();
        int x = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) a[i] = nextInt();
        boolean[] prime = new boolean[2000000];
        Arrays.fill(prime, true);
        for (int i = 2; i * i < prime.length; ++i) {
            if (prime[i])
                for (int j = i * i; j < prime.length; j += i)
                    prime[j] = false;
        }
        prime[0] = false;
        prime[1] = false;
        int res = 0;
        for (int aa : a) {
            if (aa == 1) {
                if (x <= 2) {
                    writer.println(0);
                } else {
                    writer.println(1);
                }
                return;
            }
            if (aa < x && aa < prime.length && prime[aa]) {
                prime[aa] = false;
                ++res;
            }
        }
        for (int i = 2; i < x; ++i)
            if (prime[i]) {
                writer.println(-1);
                return;
            }
        writer.println(res);
    }

    public static void main(String[] args) {
        new Morrowindows().run();
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