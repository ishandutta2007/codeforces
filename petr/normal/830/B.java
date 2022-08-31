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
            int n = in.nextInt();
            int[] a = new int[n];
            int maxa = 0;
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
                maxa = Math.max(maxa, a[i]);
            }
            int[] first = new int[maxa + 1];
            Arrays.fill(first, -1);
            int[] next = new int[n];
            for (int i = n - 1; i >= 0; --i) {
                next[i] = first[a[i]];
                first[a[i]] = i;
            }
            int remains = n;
            int pos = 0;
            int[] cur = new int[n + 1];
            long res = n;
            for (int val = 0; val <= maxa; ++val)
                if (first[val] >= 0) {
                    int count = 0;
                    int at = first[val];
                    while (at >= 0) {
                        cur[count++] = at;
                        at = next[at];
                    }
                    int before = 0;
                    while (before < count && cur[before] < pos) ++before;
                    if (before == 0) {
                        remains -= count;
                        pos = cur[count - 1];
                    } else {
                        remains -= count - before;
                        res += remains;
                        remains -= before;
                        pos = cur[before - 1];
                    }
                }
            if (remains != 0) throw new RuntimeException();
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