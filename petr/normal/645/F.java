import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        static final int MAX = (int) 1e6 + 1;
        static final int MODULO = (int) (1e9 + 7);

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();
            int q = in.nextInt();
            int[] invs = new int[n + q + 1];
            invs[1] = 1;
            for (int i = 2; i < invs.length; ++i) {
                invs[i] = (int) ((MODULO - (MODULO / i) * (long) invs[MODULO % i] % MODULO) % MODULO);
            }
            int[] ways = new int[n + q + 1];
            ways[k - 1] = 1;
            for (int i = k; i < ways.length; ++i) {
                ways[i] = (int) (ways[i - 1] * (long) i % MODULO * invs[i - k + 1] % MODULO);
            }
            int[] count = new int[MAX];
            int[] divisors = new int[100000];
            int[] w = new int[MAX];
            int[] primes = new int[1000];
            long res = 0;
            for (int i = 0; i < n + q; ++i) {
                int ndiv = 0;
                int nprime = 0;
                int a = in.nextInt();
                int tmp = a;
                for (int j = 1; j * j <= a; ++j)
                    if (a % j == 0) {
                        divisors[ndiv++] = j;
                        if (j > 1 && tmp % j == 0) {
                            primes[nprime++] = j;
                            while (tmp % j == 0) tmp /= j;
                        }
                    }
                if (tmp > 1) {
                    primes[nprime++] = tmp;
                }
                for (int t = ndiv - 1; t >= 0; --t) {
                    int j = divisors[t];
                    if (j * j < a) {
                        divisors[ndiv++] = a / j;
                    }
                }
                for (int t = 0; t < ndiv; ++t) {
                    int x = count[divisors[t]];
                    w[divisors[t]] = ways[x];
                }
                for (int s = 0; s < nprime; ++s) {
                    int p = primes[s];
                    for (int u = 0; u < ndiv; ++u) {
                        int d = divisors[u];
                        if (a / d % p == 0) {
                            w[d] -= w[d * p];
                            if (w[d] < 0) w[d] += MODULO;
                        }
                    }
                }
                for (int t = 0; t < ndiv; ++t) {
                    int d = divisors[t];
                    res += w[d] * (long) d;
                    res %= MODULO;
                    ++count[d];
                }
                if (i >= n) {
                    out.println(res);
                }
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