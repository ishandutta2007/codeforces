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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        static final int MAX = (int) 1e6;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] countPositive = new int[MAX];
            int[] countNegative = new int[MAX];
            for (int i = 0; i < n; ++i) {
                String s = in.next();
                int min = 0;
                int cur = 0;
                for (int j = 0; j < s.length(); ++j) {
                    char ch = s.charAt(j);
                    if (ch == '(') {
                        ++cur;
                    } else {
                        --cur;
                        if (cur < min) min = cur;
                    }
                }
                if (cur >= 0) {
                    if (min == 0) ++countPositive[cur];
                } else {
                    if (min == cur) ++countNegative[-cur];
                }
            }
            int res = countPositive[0] / 2;
            for (int i = 1; i < countPositive.length; ++i) {
                res += Math.min(countPositive[i], countNegative[i]);
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