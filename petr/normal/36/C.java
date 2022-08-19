import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Plates implements Runnable {
    private void solve() throws IOException {
        int n = nextInt();
        double[] offset = new double[n];
        int[] h = new int[n];
        int[] r = new int[n];
        int[] R = new int[n];
        double res = 0.0;
        for (int i = 0; i < n; ++i) {
            h[i] = nextInt();
            r[i] = nextInt();
            R[i] = nextInt();
            offset[i] = 0;
            for (int j = 0; j < i; ++j) {
                offset[i] = Math.max(offset[i], offset[j]);
                if (r[i] >= R[j]) {
                    offset[i] = Math.max(offset[i], offset[j] + h[j]);
                } else {
                    if (r[i] > r[j]) {
                        offset[i] = Math.max(offset[i], offset[j] + h[j] * ((r[i] - r[j]) / (R[j] - r[j] + 0.0)));
                    }
                    if (R[i] > r[j] && R[i] <= R[j]) {
                        offset[i] = Math.max(offset[i], offset[j] + h[j] * ((R[i] - r[j]) / (R[j] - r[j] + 0.0)) - h[i]);
                    }
                    if (R[i] > R[j]) {
                        offset[i] = Math.max(offset[i], offset[j] + h[j] - h[i] * ((R[j] - r[i]) / (R[i] - r[i] + 0.0)));
                    }
                }
            }
            res = Math.max(res, offset[i] + h[i]);
        }
        writer.println(res);
    }

    public static void main(String[] args) {
        new Plates().run();
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