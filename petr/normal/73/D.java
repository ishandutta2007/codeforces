import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class FreeDiv implements Runnable {
    private void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int k = nextInt();
        int[] first = new int[n];
        int[] next = new int[2 * m];
        int[] dest = new int[2 * m];
        Arrays.fill(first, -1);
        for (int i = 0; i < m; ++i) {
            int a = nextInt() - 1;
            int b = nextInt() - 1;
            next[i * 2] = first[a];
            dest[i * 2] = b;
            first[a] = i * 2;
            next[i * 2 + 1] = first[b];
            dest[i * 2 + 1] = a;
            first[b] = i * 2 + 1;
        }
        int[] sizes = new int[n];
        int[] queue = new int[n];
        int ncomp = 0;
        boolean[] mark = new boolean[n];
        for (int start = 0; start < n; ++start) {
            if (mark[start]) continue;
            ++ncomp;
            int qh = 1;
            int qt = 0;
            queue[0] = start;
            mark[start] = true;
            ++sizes[ncomp - 1];
            while (qt < qh) {
                int cur = queue[qt++];
                int ce = first[cur];
                while (ce >= 0) {
                    int dst = dest[ce];
                    if (!mark[dst]) {
                        mark[dst] = true;
                        queue[qh++] = dst;
                        ++sizes[ncomp - 1];
                    }
                    ce = next[ce];
                }
            }
        }
        for (int i = 0; i < ncomp; ++i) sizes[i] = Math.min(sizes[i], k);
        int n1 = 0;
        for (int i = 0; i < ncomp; ++i) if (sizes[i] == 1) ++n1;
        if (k == 1) {
            writer.println(Math.max(0, ncomp - 2));
        } else {
            int extraDeg = 0;
            for (int i = 0; i < ncomp; ++i)
                extraDeg += Math.max(sizes[i] - 2, 0);
            writer.println((Math.max(n1 - extraDeg - 2, 0) + 1) / 2);
        }
    }

    public static void main(String[] args) {
        new FreeDiv().run();
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