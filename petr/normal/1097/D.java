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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        static final long MODULO = (long) 1e9 + 7;
        long[] invs;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            invs = new long[100];
            invs[1] = 1;
            for (int i = 2; i < invs.length; ++i) {
                invs[i] = (MODULO - invs[((int) (MODULO % i))] * (MODULO / i) % MODULO) % MODULO;
                if (invs[i] * i % MODULO != 1) throw new RuntimeException();
            }

            long n = in.nextLong();
            int k = in.nextInt();
            long res = 1;
            for (long p = 2; p * p <= n; ++p) {
                int pw = 0;
                while (n % p == 0) {
                    n /= p;
                    ++pw;
                }
                if (pw > 0) {
                    res = res * solvePrime(p, pw, k) % MODULO;
                }
            }
            if (n > 1) {
                res = res * solvePrime(n, 1, k) % MODULO;
            }
            out.println(res);
        }

        private long solvePrime(long p, int pw, int k) {
            long[] pr = new long[pw + 1];
            pr[pw] = 1;
            for (int i = 0; i < k; ++i) {
                long s = 0;
                for (int j = pw; j >= 0; --j) {
                    s += pr[j] * invs[j + 1];
                    s %= MODULO;
                    pr[j] = s;
                }
            }
            long sum = 0;
            long pow = 1;
            for (int i = 0; i <= pw; ++i) {
                sum = (sum + pow * pr[i]) % MODULO;
                pow = pow * p % MODULO;
            }
            return sum;
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}