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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        static final long MODULO = 998244353;

        long pow(long a, long k) {
            long res = 1;
            while (k > 0) {
                if ((k & 1) != 0) res = res * a % MODULO;
                a = a * a % MODULO;
                k >>= 1;
            }
            return res;
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long n = in.nextInt();
            long[] invs = new long[(int) (n + 1)];
            invs[1] = 1;
            for (int i = 2; i <= n; ++i) {
                invs[i] = (MODULO - invs[((int) (MODULO % i))] * (MODULO / i) % MODULO) % MODULO;
                if (invs[i] * i % MODULO != 1) throw new RuntimeException();
            }
            long[] fact = new long[invs.length];
            long[] invfact = new long[invs.length];
            fact[0] = 1;
            invfact[0] = 1;
            for (int i = 1; i < invs.length; ++i) {
                fact[i] = i * fact[i - 1] % MODULO;
                invfact[i] = invs[i] * invfact[i - 1] % MODULO;
            }
            long[] comb = new long[(int) (n + 1)];
            for (int a = 0; a <= n; ++a) {
                comb[a] = fact[(int) n] % MODULO * invfact[a] % MODULO * invfact[(int) (n - a)] % MODULO;
            }
            long res = 0;
            for (int a = 1; a <= n; ++a) {
                long z = 2 * pow(3, n * (n - a) + a) * comb[a] % MODULO;
                if (a % 2 == 0) {
                    res -= z;
                } else {
                    res += z;
                }
            }
            for (int a = 1; a <= n; ++a) {
                long u = pow(3, (n - a));
                long m = 3 * comb[a] % MODULO;
                long s = pow(1 - u, n) - pow(-u, n);
                s %= MODULO;
                s *= m;
                s %= MODULO;
                if ((n - a) % 2 == 0)
                    res -= s;
                else
                    res += s;
            }
            res %= MODULO;
            res += MODULO;
            res %= MODULO;
            out.println(res);
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