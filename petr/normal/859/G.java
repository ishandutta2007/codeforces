import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        TaskG solver = new TaskG();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskG {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            String s = in.next();
            int[] primes = new int[100];
            int nprimes = 0;
            int rem = n;
            for (int p = 2; p <= rem; ++p)
                if (rem % p == 0) {
                    while (rem % p == 0) rem /= p;
                    primes[nprimes++] = p;
                }
            primes = Arrays.copyOf(primes, nprimes);
            int prod = 1;
            for (int x : primes) prod *= x;
            int indep = n / prod;
            long[] a = new long[prod];
            for (int i = 0; i < indep; ++i) {
                for (int j = 0; j < prod; ++j) {
                    a[j] = s.charAt(i + j * indep) - '0';
                }
                if (!can(primes, a)) {
                    out.println("NO");
                    return;
                }
            }
            out.println("YES");
        }

        private boolean can(int[] primes, long[] a) {
            long[] b = new long[a.length];
            for (int p : primes) {
                for (int i = 0; i < a.length; ++i) {
                    b[i] = a[i] - a[(i + a.length / p) % a.length];
                }
                long[] t = a;
                a = b;
                b = t;
            }
            for (long x : a) if (x != 0) return false;
            return true;
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