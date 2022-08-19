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
        static final int MODULO = (int) (1e9 + 7);

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            String s = in.next();
            int[] numEq = new int[n + 1];
            int[] nNumEq = new int[n + 1];
            int[][] ways = new int[n][];
            for (int i = n - 1; i >= 0; --i) {
                ways[i] = new int[n - i + 1];
                Arrays.fill(nNumEq, 0);
                for (int j = i + 1; j < n; ++j) {
                    if (s.charAt(j) == s.charAt(i)) {
                        nNumEq[j] = numEq[j + 1] + 1;
                    }
                }
                int[] tmp = numEq;
                numEq = nNumEq;
                nNumEq = tmp;
                if (s.charAt(i) != '0') {
                    for (int len = n - i; len >= 1; --len) {
                        if (len == n - i) {
                            ways[i][len] = 1;
                        } else {
                            ways[i][len] = ways[i][len + 1];
                        }
                        if (i + 2 * len <= n) {
                            int cnt = numEq[i + len];
                            boolean canSame = false;
                            if (cnt < len && s.charAt(i + cnt) < s.charAt(i + len + cnt)) {
                                canSame = true;
                            }
                            if (canSame) {
                                ways[i][len] += ways[i + len][len];
                            } else if (i + 2 * len + 1 <= n) {
                                ways[i][len] += ways[i + len][len + 1];
                            }
                            if (ways[i][len] >= MODULO) {
                                ways[i][len] -= MODULO;
                            }
                        }
                    }
                }
            }
            out.println(ways[0][1]);
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