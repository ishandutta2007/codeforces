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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        static final long MODULO = (long) (1e9 + 7);

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int m = in.nextInt();
            int n = in.nextInt();
            String[] t = new String[n];
            for (int i = 0; i < n; ++i) {
                t[i] = in.next();
            }
            long[] code = new long[m];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    code[j] |= ((long) (t[i].charAt(j) - '0')) << i;
                }
            }
            Arrays.sort(code);
            int[][] comb = new int[code.length + 2][code.length + 2];
            comb[0][0] = 1;
            for (int i = 1; i < comb.length; ++i) {
                comb[i][0] = 1;
                for (int j = 1; j < comb.length; ++j) {
                    comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % (int) MODULO;
                }
            }
            long[] ways = new long[code.length + 1];
            ways[0] = 1;
            for (int i = 1; i < ways.length; ++i) {
                for (int j = 1; j <= i; ++j) {
                    ways[i] = (ways[i] + ways[i - j] * comb[i - 1][j - 1]) % MODULO;
                }
            }
            long res = 1;
            int block = 1;
            for (int i = 1; i < code.length; ++i) {
                if (code[i] == code[i - 1]) {
                    ++block;
                } else {
                    res = res * ways[block] % MODULO;
                    block = 1;
                }
            }
            res = res * ways[block] % MODULO;
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