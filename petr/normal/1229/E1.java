import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.math.BigInteger;
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
        TaskE1 solver = new TaskE1();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE1 {
        static final int DENOM = 100;
        static final long MODULO = (long) 1e9 + 7;
        private static final long INVDENOM = BigInteger.valueOf(DENOM).modInverse(BigInteger.valueOf(MODULO)).longValue();
        int n;
        long[][] p;
        int[][] s;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            p = new long[n][n];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    p[i][j] = in.nextInt() * INVDENOM % MODULO;
                }
            }
            int[] match = new int[n];
            Arrays.fill(match, -1);
            s = new int[n][n];
            int[] stack = new int[n];
            int[] via = new int[n];
            int[] ptr = new int[n];
            long res = rec(match, stack, via, ptr, -1, 0);
            out.println(res);
        }

        private long rec(int[] match, int[] stack, int[] via, int[] ptr, int sp, int next) {
            for (int i = 0; i < sp; ++i)
                if (via[stack[i]] == -1) {
                    throw new RuntimeException();
                }
            if (sp == 0) return 0;
            if (sp == -1) {
                if (next >= n) {
                    return 1;
                }
                Arrays.fill(via, -1);
                Arrays.fill(ptr, 0);
                Arrays.fill(stack, -1);
                stack[0] = next;
                via[next] = -2;
                return rec(match, stack, via, ptr, 1, next);
            } else {
                int cur = stack[sp - 1];
                int dest = ptr[cur];
                if (dest < n && match[dest] < 0) {
                    if (s[cur][dest] == 0) {
                        s[cur][dest] = 1;
                        long res = p[cur][dest] * rec(match, stack, via, ptr, sp, next);
                        s[cur][dest] = 2;
                        res += (1 - p[cur][dest]) * rec(match, stack, via, ptr, sp, next);
                        res %= MODULO;
                        if (res < 0) res += MODULO;
                        s[cur][dest] = 0;
                        return res;
                    }
                    if (s[cur][dest] == 1) {
                        int[] nmatch = match.clone();
                        int[] nstack = new int[n];
                        int[] nvia = new int[n];
                        int[] nptr = new int[n];
                        for (int i = 1; i < sp; ++i) {
                            nmatch[via[stack[i]]] = stack[i - 1];
                        }
                        nmatch[dest] = cur;
                        return rec(nmatch, nstack, nvia, nptr, -1, next + 1);
                    }
                }
                int ndest = dest - n;
                if (ndest >= 0 && ndest < n && match[ndest] >= 0 && via[match[ndest]] == -1) {
                    if (s[cur][ndest] == 0) {
                        s[cur][ndest] = 1;
                        long res = p[cur][ndest] * rec(match, stack, via, ptr, sp, next);
                        s[cur][ndest] = 2;
                        res += (1 - p[cur][ndest]) * rec(match, stack, via, ptr, sp, next);
                        res %= MODULO;
                        if (res < 0) res += MODULO;
                        s[cur][ndest] = 0;
                        return res;
                    }
                    if (s[cur][ndest] == 1) {
                        int md = match[ndest];
                        via[md] = ndest;
                        stack[sp] = md;
                        long res = rec(match, stack, via, ptr, sp + 1, next);
                        stack[sp] = -1;
                        via[md] = -1;
                        return res;
                    }
                }
                if (dest >= 2 * n) {
                    long res = rec(match, stack, via, ptr, sp - 1, next);
                    stack[sp - 1] = cur;
                    return res;
                } else {
                    ptr[cur] = dest + 1;
                    long res = rec(match, stack, via, ptr, sp, next);
                    ptr[cur] = dest;
                    return res;
                }
            }
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