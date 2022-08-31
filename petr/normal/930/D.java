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
        static final int MAX_COORD = (int) 1e5 + 10;
        static final int INF = (int) 1e9;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] max = new int[4 * MAX_COORD];
            int[] min = new int[4 * MAX_COORD];
            Arrays.fill(max, -INF);
            Arrays.fill(min, INF);
            for (int i = 0; i < n; ++i) {
                int x = in.nextInt();
                int y = in.nextInt();
                max[x + y + 2 * MAX_COORD] = Math.max(max[x + y + 2 * MAX_COORD], x - y);
                min[x + y + 2 * MAX_COORD] = Math.min(min[x + y + 2 * MAX_COORD], x - y);
            }
            long res = 0;
            int[] pmax = new int[4 * MAX_COORD];
            int[] pmin = new int[4 * MAX_COORD];
            int[] smax = new int[4 * MAX_COORD];
            int[] smin = new int[4 * MAX_COORD];
            for (int i = 0; i < max.length; ++i) {
                pmax[i] = max[i];
                if (i >= 2) pmax[i] = Math.max(pmax[i], pmax[i - 2]);
                pmin[i] = min[i];
                if (i >= 2) pmin[i] = Math.min(pmin[i], pmin[i - 2]);
            }
            for (int i = max.length - 1; i >= 0; --i) {
                smax[i] = max[i];
                if (i + 2 < max.length) smax[i] = Math.max(smax[i], smax[i + 2]);
                smin[i] = min[i];
                if (i + 2 < max.length) smin[i] = Math.min(smin[i], smin[i + 2]);
            }
            for (int i = 2; i < max.length; ++i) {
                int left = Math.max(pmin[i - 2], smin[i]);
                int right = Math.min(pmax[i - 2], smax[i]);
                if (left < right) {
                    res += right - left;
                }
            }
            out.println(res >> 1);
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