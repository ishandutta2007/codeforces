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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int k = in.nextInt();
            int n = 1 << k;
            double[][] p = new double[n][n];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    p[i][j] = in.nextInt() / 100.0;
                }
            }
            double[][] s = new double[k + 1][n];
            double[][] pr = new double[k + 1][n];
            Arrays.fill(pr[0], 1.0);
            for (int stage = 0; stage < k; ++stage) {
                int block = 1 << stage;
                for (int win = 0; win < n; ++win) {
                    int left = win & ~(block - 1);
                    int right = left + block;
                    int gleft = win & ~(2 * block - 1);
                    int gright = gleft + 2 * block;
                    for (int o = gleft; o < gright; ++o) {
                        if (o < left || o >= right) {
                            pr[stage + 1][win] += pr[stage][win] * pr[stage][o] * p[win][o];
                        }
                    }
                    for (int o = gleft; o < gright; ++o) {
                        if (o < left || o >= right) {
                            s[stage + 1][win] = Math.max(s[stage + 1][win], s[stage][win] + s[stage][o] + block * pr[stage + 1][win]);
                        }
                    }
                }
            }
            double res = 0;
            for (double x : s[k]) {
                res = Math.max(res, x);
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

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}