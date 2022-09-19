import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class D {

    class Evenlope implements Comparable<Evenlope> {
        int w;
        int h;
        int n;
        Evenlope(int w, int h, int n) {
            this.w = w;
            this.h = h;
            this.n = n;
        }
        public int compareTo(Evenlope o) {
            return w - o.w;
        }
    }

    private void solve() throws IOException {
        int n = nextInt();

        Evenlope base = new Evenlope(nextInt(), nextInt(), 0);
        Evenlope[] e = new Evenlope[n];

        for (int i = 0; i < n; i++) {
            e[i] = new Evenlope(nextInt(), nextInt(), i + 1);
        }

        Arrays.sort(e);

        int[] d = new int[n];
        int[] p = new int[n];
        int res = 0;
        int ls = -1;
        for (int i = 0; i < n; i++) {
            if (e[i].w <= base.w || e[i].h <= base.h) {
                d[i] = 0;
                p[i] = -1;
            } else {
                d[i] = 1;
                p[i] = -1;
                for (int j = 0; j < i; j++) {
                    if (e[j].w < e[i].w && e[j].h < e[i].h && d[j] > 0) {
                        if (d[j] + 1 > d[i]) {
                            d[i] = d[j] + 1;
                            p[i] = j;
                        }
                    }
                }
            }
            if (d[i] > res) {
                res = d[i];
                ls = i;
            }
        }
        writer.println(res);
        if (res > 0) {
            printRev(p, e, ls);
        }
    }

    private void printRev(int[] p, Evenlope[] e, int i) {
        if (i >= 0) {
            printRev(p, e, p[i]);
            writer.print(e[i].n + " ");
        }

    }

    public static void main(String[] args) throws InterruptedException {
        new D().run();
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