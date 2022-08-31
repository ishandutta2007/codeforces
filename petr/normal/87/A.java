import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Trains implements Runnable {
    private void solve() throws IOException {
        long now = 0;
        long a = nextInt();
        long b = nextInt();
        long na = a;
        long nb = b;
        long ta = 0;
        long tb = 0;
        int cur = a < b ? 1 : 0;
        while (true) {
            long nnow = Math.min(na, nb);
            if (cur == 0) ta += nnow - now; else tb += nnow - now;
            if (na == nnow && nb == nnow)
                break;
            if (na == nnow) {
                na += a;
                cur = 0;
            } else {
                nb += b;
                cur = 1;
            }
            now = nnow;
        }
        if (ta > tb) writer.println("Dasha"); else if (ta < tb) writer.println("Masha"); else writer.println("Equal");
    }

    public static void main(String[] args) {
        new Trains().run();
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