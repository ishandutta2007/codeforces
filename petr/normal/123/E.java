import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Labyrinth implements Runnable {
    int[] src;
    int[] dst;
    int[] first;
    int[] next;
    int[] sumEnterProb;
    long[] sumPairProb;
    int[] x;
    int[] y;
    int sumx;
    int sumy;

    private void solve() throws IOException {
        int n = nextInt();
        src = new int[2 * (n - 1)];
        dst = new int[2 * (n - 1)];
        first = new int[n];
        Arrays.fill(first, -1);
        next = new int[2 * (n - 1)];
        x = new int[n];
        y = new int[n];
        for (int i = 0; i < n - 1; ++i) {
            int a = nextInt() - 1;
            int b = nextInt() - 1;
            src[2 * i] = a;
            dst[2 * i] = b;
            next[2 * i] = first[a];
            first[a] = 2 * i;
            src[2 * i + 1] = b;
            dst[2 * i + 1] = a;
            next[2 * i + 1] = first[b];
            first[b] = 2 * i + 1;
        }
        sumx = 0;
        sumy = 0;
        for (int i = 0; i < n; ++i) {
            x[i] = nextInt();
            y[i] = nextInt();
            sumx += x[i];
            sumy += y[i];
        }
        sumEnterProb = new int[2 * (n - 1)];
        rec1(0, -1);
        sumPairProb = new long[2 * (n - 1)];
        rec2(0, -1);
        rec3(0, -1, 0);
        long total = (n - 1) * (long) sumx * sumy;
        for (int i = 0; i < (2 * (n - 1)); ++i)
            total -= sumPairProb[i];
        writer.println(total / (double) (sumx * (long) sumy));
    }

    private void rec3(int root, int parent, long sum) {
        long s = 0;
        int edge = first[root];
        while (edge >= 0) {
            if (dst[edge] != parent) {
                s += sumPairProb[edge];
            }
            edge = next[edge];
        }
        edge = first[root];
        while (edge >= 0) {
            if (dst[edge] != parent) {
                sumPairProb[edge ^ 1] = sum + y[root] * (long) sumEnterProb[edge ^ 1] + s - sumPairProb[edge];
                rec3(dst[edge], root, sumPairProb[edge ^ 1]);
            }
            edge = next[edge];
        }
    }

    private long rec2(int root, int parent) {
        int edge = first[root];
        long s = 0;
        while (edge >= 0) {
            if (dst[edge] != parent) {
                long r = rec2(dst[edge], root) + y[dst[edge]] * (long) sumEnterProb[edge];
                sumPairProb[edge] = r;
                s += r;
            }
            edge = next[edge];
        }
        return s;
    }

    private int rec1(int root, int parent) {
        int edge = first[root];
        int s = x[root];
        while (edge >= 0) {
            if (dst[edge] != parent) {
                int r = rec1(dst[edge], root);
                sumEnterProb[edge] = r;
                sumEnterProb[edge ^ 1] = sumx - r;
                s += r;
            }
            edge = next[edge];
        }
        return s;
    }

    public static void main(String[] args) {
        new Labyrinth().run();
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