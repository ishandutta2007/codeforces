import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
        static final int MAXV = 7001;
        static final int LEN = (MAXV >> 6) + 1;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int q = in.nextInt();
            StringBuilder res = new StringBuilder();
            boolean[] prime = new boolean[MAXV];
            Arrays.fill(prime, 2, prime.length, true);
            for (int i = 2; i * i < MAXV; ++i)
                if (prime[i]) {
                    for (int j = i * i; j < MAXV; j += i) prime[j] = false;
                }
            long[][] a = new long[n][LEN];
            long[][] base = new long[MAXV][LEN];
            for (int j = 1; j < MAXV; ++j) {
                for (int i = j; i < MAXV; i += j) {
                    base[i][j >> 6] |= (1L << (j & 63));
                }
            }
            long[][] answerMask = new long[MAXV][LEN];
            for (int i = 0; i < MAXV; ++i) {
                answerMask[i][i >> 6] |= (1L << (i & 63));
            }
            for (int p = 0; p < MAXV; ++p)
                if (prime[p]) {
                    for (int i = 1; i * p < MAXV; ++i) {
                        long[] u = answerMask[i];
                        long[] v = answerMask[i * p];
                        for (int k = 0; k < LEN; ++k) {
                            u[k] ^= v[k];
                        }
                    }
                }

            for (int qi = 0; qi < q; ++qi) {
                int kind = in.nextInt();
                switch (kind) {
                    case 1: {
                        long[] x = a[in.nextInt() - 1];
                        long[] v = base[in.nextInt()];
                        System.arraycopy(v, 0, x, 0, LEN);
                        break;
                    }

                    case 2: {
                        long[] x = a[in.nextInt() - 1];
                        long[] y = a[in.nextInt() - 1];
                        long[] z = a[in.nextInt() - 1];
                        for (int i = 0; i < LEN; ++i) {
                            x[i] = y[i] ^ z[i];
                        }
                        break;
                    }

                    case 3: {
                        long[] x = a[in.nextInt() - 1];
                        long[] y = a[in.nextInt() - 1];
                        long[] z = a[in.nextInt() - 1];
                        for (int i = 0; i < LEN; ++i) {
                            x[i] = y[i] & z[i];
                        }
                        break;
                    }

                    case 4: {
                        long[] x = a[in.nextInt() - 1];
                        long[] v = answerMask[in.nextInt()];
                        int s = 0;
                        for (int i = 0; i < LEN; ++i) {
                            s += Long.bitCount(x[i] & v[i]);
                        }
                        res.append((char) ('0' + (s & 1)));
                        break;
                    }

                    default:
                        throw new RuntimeException();
                }
            }
            out.println(res.toString());
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