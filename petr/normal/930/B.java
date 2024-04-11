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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String s = in.next();
            int n = s.length();
            int[] cands = new int[n];
            int[] am = new int[26];
            int res = 0;
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                int ncands = 0;
                for (int i = 0; i < n; ++i) if (s.charAt(i) == ch) cands[ncands++] = i;
                int best = 0;
                for (int j = 0; j < n; ++j) {
                    Arrays.fill(am, 0);
                    int got = 0;
                    for (int t = 0; t < ncands; ++t) {
                        int p = cands[t] + j;
                        if (p >= n) p -= n;
                        int c = s.charAt(p) - 'a';
                        ++am[c];
                        if (am[c] == 1) ++got;
                        else if (am[c] == 2) --got;
                    }
                    best = Math.max(best, got);
                }
                res += best;
            }
            out.println(res / (double) n);
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