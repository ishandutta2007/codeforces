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
        TaskG solver = new TaskG();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskG {
        static final long MODULO = (long) (1e9 + 7);

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String x = in.next();
            int[][] comb = new int[x.length() + 2][x.length() + 2];
            comb[0][0] = 1;
            for (int i = 1; i < comb.length; ++i) {
                comb[i][0] = 1;
                for (int j = 1; j < comb.length; ++j) {
                    comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % (int) MODULO;
                }
            }
            int[][] pow = new int[11][x.length() + 2];
            for (int i = 0; i < pow.length; ++i) {
                pow[i][0] = 1;
                for (int j = 1; j < pow[i].length; ++j) {
                    pow[i][j] = (int) (i * (long) pow[i][j - 1] % MODULO);
                }
            }
            int[] oneSum = new int[x.length() + 2];
            for (int i = 1; i < oneSum.length; ++i) {
                oneSum[i] = (int) ((10 * (long) oneSum[i - 1] + 1) % MODULO);
            }

            int[][] s1 = new int[10][x.length() + 1];
            int[][] s2 = new int[10][x.length() + 1];
            for (int what = 1; what <= 9; ++what) {
                for (int max = 0; max <= x.length(); ++max) {
                    long sum1 = 0;
                    long sum2 = 0;
                    for (int equalExtra = 0; equalExtra <= max; ++equalExtra) {
                        long cways = 1;
                        cways *= comb[max][equalExtra];
                        cways %= MODULO;
                        cways *= pow[what][max - equalExtra];
                        cways %= MODULO;
                        sum1 += cways * oneSum[equalExtra];
                        sum1 %= MODULO;
                        sum2 += cways;
                        sum2 %= MODULO;
                    }
                    s1[what][max] = (int) sum1;
                    s2[what][max] = (int) sum2;
                }
            }

            int[] sofar = new int[10];
            long res = 0;
            for (int firstLess = 0; firstLess < x.length(); ++firstLess) {
                int min = 0;
                int max = x.charAt(firstLess) - '0';
                if (firstLess < x.length() - 1) --max;
                for (int dig = min; dig <= max; ++dig) {
                    ++sofar[dig];
                    int totalSofar = firstLess + 1;
                    int sofarBigger = 0;
                    for (int what = 9; what >= 1; --what) {
                        int sofarThisOrLess = totalSofar - sofarBigger;
                        int sofarThis = sofar[what];
                        int sofarLess = sofarThisOrLess - sofarThis;
                        for (int bigger = sofarBigger; bigger + sofarThisOrLess <= x.length(); ++bigger) {
                            long ways = comb[x.length() - totalSofar][bigger - sofarBigger];
                            ways *= pow[9 - what][bigger - sofarBigger];
                            ways %= MODULO;
                            long sum1 = s1[what][x.length() - bigger - sofarThisOrLess];
                            long sum2 = s2[what][x.length() - bigger - sofarThisOrLess];
                            long sum = (sum1 * (long) pow[10][sofarThis] + sum2 * oneSum[sofarThis]) % MODULO;
                            sum *= pow[10][bigger];
                            sum %= MODULO;
                            res = (res + sum * ways % MODULO * what) % MODULO;
                        }
                        sofarBigger += sofarThis;
                    }
                    --sofar[dig];
                }
                ++sofar[x.charAt(firstLess) - '0'];
            }
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

    }
}