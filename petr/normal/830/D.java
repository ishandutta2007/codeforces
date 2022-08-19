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
        static final long MODULO = (long) (1e9 + 7);

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int k = in.nextInt();
            long[][] comb = new long[k + 2][k + 2];
            comb[0][0] = 1;
            for (int a = 1; a < comb.length; ++a) {
                comb[a][0] = 1;
                for (int b = 1; b < comb.length; ++b) {
                    comb[a][b] = (comb[a - 1][b] + comb[a - 1][b - 1]) % MODULO;
                }
            }
            long[] p2 = new long[k + 2];
            p2[0] = 1;
            for (int i = 1; i < p2.length; ++i) p2[i] = 2 * p2[i - 1] % MODULO;
            long[][] res = new long[k + 1][k + 2];
            long[] ways = new long[k + 2];

            res[0][0] = 1;
            for (int size = 1; size <= k; ++size) {
                ways[0] = 1;
                for (int numpaths = 1; numpaths <= k + 1; ++numpaths) {
                    ways[numpaths] = 0;
                    for (int left = 0; left <= numpaths; ++left) {
                        ways[numpaths] = (ways[numpaths] + res[size - 1][left] * res[size - 1][numpaths - left] % MODULO * comb[numpaths][left]) % MODULO;
                    }
                }
                res[size][0] = 1;
                for (int numpaths = 1; numpaths <= k + 1; ++numpaths) {
                    long sum = ways[numpaths];
                    for (int joinleft = 0; joinleft <= 1; ++joinleft) {
                        for (int joinright = 0; joinright <= 1; ++joinright) {
                            int prevnumpaths = numpaths - 1 + joinleft + joinright;
                            if (prevnumpaths >= 0 && prevnumpaths <= k + 1) {
                                long cur = ways[prevnumpaths];
                            /*if (joinleft > 0) {
                                cur = cur * prevnumpaths % MODULO;
                                --prevnumpaths;
                            }
                            if (joinright > 0) {
                                cur = cur * prevnumpaths % MODULO;
                                --prevnumpaths;
                            }
                            if (joinleft > 0 && joinright > 0) {
                                cur = cur * inv2 % MODULO;
                            }*/
                                sum = (sum + cur * numpaths) % MODULO;
                            }
                        }
                    }
                    res[size][numpaths] = sum % MODULO;
                }
            }
            out.println(res[k][1]);
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