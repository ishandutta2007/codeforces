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

        long pow(long a, long k) {
            if (k == 0) return 1;
            if (k % 2 == 0) return pow(a * a % MODULO, k / 2);
            return a * pow(a, k - 1) % MODULO;
        }

        long inv(long a) {
            return pow(a, MODULO - 2);
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int k = in.nextInt();
            int pa = in.nextInt();
            int pb = in.nextInt();
            long pra = pa * inv(pa + pb) % MODULO;
            long prb = pb * inv(pa + pb) % MODULO;
            long invpra = inv(pra);
            long invprb = inv(prb);
            int[][] expect = new int[k + 1][];
            for (int togo = 1; togo <= k; ++togo) {
                expect[togo] = new int[togo + 1];
                expect[togo][togo] = (int) ((togo + (1 - prb + MODULO) * invprb) % MODULO);
                for (int have = togo - 1; have >= 0; --have) {
                    {
                        // get a
                        expect[togo][have] = (int) ((expect[togo][have] + (have == 0 ? 1 : pra) * expect[togo][have + 1]) % MODULO);
                    }
                    if (have > 0) {
                        // get b
                        int ntogo = togo - have;
                        int extra = have;
                        int nhave = have;
                        if (have > ntogo) {
                            extra += have - ntogo;
                            nhave = ntogo;
                        }
                        expect[togo][have] = (int) ((expect[togo][have] + prb * (extra + expect[ntogo][nhave])) % MODULO);
                    }
                }
            }
            out.println(expect[k][0]);
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