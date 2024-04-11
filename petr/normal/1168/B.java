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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        int MAX_DELTA = 12;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String s = in.next();
            int[] r = new int[s.length()];
            for (int i = 0; i < s.length(); ++i) {
                r[i] = s.length();
                for (int j = 1; j <= MAX_DELTA && i + 2 * j < s.length(); ++j) {
                    if (s.charAt(i) == s.charAt(i + j) && s.charAt(i) == s.charAt(i + 2 * j)) {
                        r[i] = i + 2 * j;
                        break;
                    }
                }
            }
            int sofar = s.length();
            long res = 0;
            for (int i = s.length() - 1; i >= 0; --i) {
                sofar = Math.min(sofar, r[i]);
                res += s.length() - sofar;
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