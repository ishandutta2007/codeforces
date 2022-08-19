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
            int n = in.nextInt();
            int m = in.nextInt();
            int[] after = new int[n];
            boolean[] mark = new boolean[n];
            Arrays.fill(after, -1);
            for (int ii = 0; ii < m; ++ii) {
                int prev = in.nextInt() - 1;
                for (int i = 1; i < n; ++i) {
                    int cur = in.nextInt() - 1;
                    if (after[prev] == -1) {
                        after[prev] = cur;
                    } else if (after[prev] != cur) {
                        after[prev] = -2;
                    }
                    prev = cur;
                }
                after[prev] = -2;
            }
            for (int x : after) if (x >= 0) mark[x] = true;
            long res = n;
            for (int i = 0; i < n; ++i)
                if (!mark[i] && after[i] >= 0) {
                    int len = 0;
                    int j = i;
                    while (j >= 0) {
                        ++len;
                        j = after[j];
                    }
                    res += len * (long) (len - 1) / 2;
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