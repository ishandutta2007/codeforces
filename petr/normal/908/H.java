import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.util.Random;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskH solver = new TaskH();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskH {
        int modulo;

        public TaskH() {
            Random random = new Random(57315734513L + System.currentTimeMillis());
            modulo = (int) 1e9 + random.nextInt((int) 1e8);
            while (!prime(modulo)) ++modulo;
        }

        private boolean prime(int modulo) {
            for (int i = 2; i * i <= modulo; ++i) if (modulo % i == 0) return false;
            return true;
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            String[] g = new String[n];
            for (int i = 0; i < n; ++i) {
                g[i] = in.next();
            }
            int[] comp = new int[n];
            int ncomp = 0;
            for (int i = 0; i < n; ++i)
                if (comp[i] == 0) {
                    ++ncomp;
                    rec(comp, ncomp, i, g, n);
                    int size = 0;
                    for (int x : comp) if (x == ncomp) ++size;
                    if (size == 1) {
                        comp[i] = -1;
                        --ncomp;
                    }
                }
            boolean[][] d = new boolean[ncomp][ncomp];
            for (int i = 0; i < n; ++i)
                if (comp[i] > 0) {
                    for (int j = 0; j < n; ++j)
                        if (g[i].charAt(j) == 'X' && comp[j] > 0) {
                            d[comp[i] - 1][comp[j] - 1] = true;
                            d[comp[j] - 1][comp[i] - 1] = true;
                        }
                }
            for (int i = 0; i < ncomp; ++i)
                if (d[i][i]) {
                    out.println(-1);
                    return;
                }
            out.println(n - 1 + minColors(ncomp, d));
        }

        private int minColors(int n, boolean[][] g) {
            if (n == 0) return 0;
            int[] adj = new int[n];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (g[i][j]) {
                        adj[i] |= 1 << j;
                    }
                }
            }
            int total = 1 << n;
            int[] a = new int[total];
            int[] s = new int[total];
            a[0] = 1;
            for (int i = 1; i < total; ++i) {
                int j = Integer.numberOfTrailingZeros(i);
                a[i] = a[i - (1 << j)] + a[(i - (1 << j)) & ~adj[j]];
                if (a[i] >= modulo) a[i] -= modulo;
            }
            for (int i = 0; i < total; ++i) {
                s[i] = 1 - 2 * ((n - Integer.bitCount(i)) & 1);
            }
            for (int k = 1; k < n; ++k) {
                long sum = 0;
                for (int i = 0; i < total; ++i) {
                    long cur = ((s[i] * (long) a[i]) % modulo);
                    s[i] = (int) cur;
                    sum += cur;
                }
                if (sum % modulo != 0) return k;
            }
            return n;
        }

        private void rec(int[] comp, int ncomp, int i, String[] g, int n) {
            comp[i] = ncomp;
            for (int j = 0; j < n; ++j)
                if (comp[j] == 0 && g[i].charAt(j) == 'A') {
                    rec(comp, ncomp, j, g, n);
                }
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}