import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Fractal implements Runnable {
    private void solve() throws IOException {
        int n = nextInt();
        int k = nextInt();
        String[] mask = new String[n];
        for (int i = 0; i < n; ++i) mask[i] = nextToken();
        int size = (int) Math.pow(n, k);
        boolean[][] res = new boolean[size][size];
        doit(0, 0, size, n, k, res, mask);
        for (int x = 0; x < size; ++x) {
            for (int y = 0; y < size; ++y) {
                if (res[x][y]) writer.print("*"); else writer.print(".");
            }
            writer.println();
        }
    }

    private void doit(int dx, int dy, int size, int n, int k, boolean[][] res, String[] mask) {
        if (size == 1)
            return;
        size /= n;
        for (int x = 0; x < n; ++x)
            for (int y = 0; y < n; ++y)
                if (mask[x].charAt(y) == '*') {
                    for (int xx = 0; xx < size; ++xx)
                        for (int yy = 0; yy < size; ++yy)
                            res[dx + x * size + xx][dy + y * size + yy] = true;
                } else {
                    doit(dx + x * size, dy + y * size, size, n, k, res, mask);
                }
    }

    public static void main(String[] args) {
        new Fractal().run();
    }

    static final String IN_FILE = "input.txt";
    static final String OUT_FILE = "output.txt";

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    public void run() {
        try {
            reader = new BufferedReader(new FileReader(IN_FILE));
            tokenizer = null;
            writer = new PrintWriter(OUT_FILE);
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