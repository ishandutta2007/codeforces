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
        int[][] best;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int s = in.nextInt();
            int m = in.nextInt();
            int k = in.nextInt();
            int[] a = new int[n];
            int[] l = new int[s];
            int[] r = new int[s];
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
            }
            for (int i = 0; i < s; ++i) {
                l[i] = in.nextInt() - 1;
                r[i] = in.nextInt() - 1;
            }
            int[] minLeft = new int[n];
            Arrays.fill(minLeft, n);
            for (int i = 0; i < s; ++i) {
                minLeft[r[i]] = Math.min(minLeft[r[i]], l[i]);
            }
            for (int i = n - 1; i > 0; --i) {
                minLeft[i - 1] = Math.min(minLeft[i - 1], minLeft[i]);
            }
            int[] aSorted = a.clone();
            Arrays.sort(aSorted);
            boolean[] allowed = new boolean[n];
            int left = -1;
            int right = aSorted.length;
            best = new int[n + 1][m + 1];
            while (right - left > 1) {
                int middle = (left + right) / 2;
                for (int i = 0; i < n; ++i) allowed[i] = a[i] <= aSorted[middle];
                if (getMaxAllowed(allowed, minLeft, m) >= k) {
                    right = middle;
                } else {
                    left = middle;
                }
            }
            if (right >= aSorted.length)
                out.println(-1);
            else
                out.println(aSorted[right]);
        }

        private int getMaxAllowed(boolean[] allowed, int[] minLeft, int count) {
            int ptr = 0;
            int inside = 0;
            Arrays.fill(best[0], 0);
            for (int i = 0; i < allowed.length; ++i) {
                int[] dest = best[i + 1];
                System.arraycopy(best[i], 0, dest, 0, best[i].length);
                if (allowed[i]) ++inside;
                while (ptr < minLeft[i]) {
                    if (allowed[ptr]) --inside;
                    ++ptr;
                }
                if (ptr <= i) {
                    int[] src = best[ptr];
                    for (int old = 0; old < count; ++old) {
                        dest[old + 1] = Math.max(dest[old + 1], src[old] + inside);
                    }
                }
            }
            return best[allowed.length][count];
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