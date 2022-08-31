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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            String[] data = new String[n];
            for (int i = 0; i < n; ++i) {
                data[i] = in.next();
            }
            int[] srcs = new int[m];
            for (int i = 0; i < n; ++i) {
                int bit = 1 << i;
                String cur = data[i];
                for (int j = 0; j < m; ++j) {
                    if (cur.charAt(j) == '1')
                        srcs[j] |= bit;
                }
            }
            int half = n / 2;
            int[][] ways = new int[half + 1][1 << n];
            for (int i = 0; i < m; ++i) {
                ++ways[0][srcs[i]];
                ++ways[0][srcs[i] ^ ((1 << n) - 1)];
            }
            for (int i = 0; i < n; ++i) {
                int bit = 1 << i;
                for (int step = half; step >= 1; --step) {
                    int[] src = ways[step - 1];
                    int[] dst = ways[step];
                    for (int old = 0; old < src.length; ++old)
                        if (src[old] != 0) {
                            dst[old ^ bit] += src[old];
                        }
                }
            }
        /*int[][] waysTo = new int[n + 1][half + 1];
        for (int dest = 0; dest <= n; ++dest) {
            int[][] innerWays = new int[half + 1][n + 1];
            innerWays[0][dest] = 1;
            for (int step = 1; step <= half; ++step) {
                int[] src = innerWays[step - 1];
                int[] dst = innerWays[step];
                for (int old = 0; old < src.length; ++old) {
                    if (src[old] != 0) {
                        if (old > 0) {
                            dst[old - 1] += src[old] * old;
                        }
                        if (old + 1 <= n) {
                            dst[old + 1] += src[old] * (n - old);
                        }
                    }
                }
            }
            for (int step = 0; step <= half; ++step) {
                waysTo[dest][step] = innerWays[step][0];
            }
        }
        for (int step = 1; step <= half; ++step) {
            for (int realStep = step - 2; realStep >= 0; realStep -= 2) {
                int[] big = ways[step];
                int[] small = ways[realStep];
                int inner = waysTo[realStep][step];
                for (int i = 0; i < big.length; ++i) {
                    big[i] -= small[i] * inner;
                }
            }
        }*/
            int[] ans = new int[1 << n];
            for (int step = 0; step <= half; ++step) {
                int[] arr = ways[step];
                int shift = (step * 2 == n) ? 1 : 0;
                for (int i = 0; i < ans.length; ++i) {
                    ans[i] += (arr[i] >> shift) * step;
                }
            }
            int res = Integer.MAX_VALUE;
            for (int x : ans)
                res = Math.min(res, x);
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