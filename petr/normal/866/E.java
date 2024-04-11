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
        long[] best;
        int[] ww;
        static final long INF = 1L << 60;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String s = in.next();
            int[] d = new int[s.length()];
            for (int i = 0; i < d.length; ++i) d[i] = decode(s.charAt(s.length() - 1 - i));
            long res = Long.MAX_VALUE;
            best = new long[1 << d.length];
            ww = new int[1 << d.length];
            for (int carryMask = 0; carryMask < (1 << (d.length - 1)); ++carryMask) {
                int[] delta = new int[d.length];
                int sum = 0;
                boolean ok = true;
                for (int i = 0; i < d.length; ++i) {
                    int diff = d[i];
                    if ((carryMask & (1 << i)) != 0) {
                        diff -= 16;
                    }
                    if (i > 0 && (carryMask & (1 << (i - 1))) != 0) {
                        ++diff;
                    }
                    delta[i] = diff;
                    sum += delta[i];
                    if (Math.abs(diff) >= 16) {
                        ok = false;
                    }
                }
                if (sum == 0 && ok) {
                    res = Math.min(res, solveOne(delta));
                }
            }
            if (res >= INF) {
                out.println("NO");
            } else {
                for (int i = 0; i < d.length; ++i) {
                    d[i] = (int) (res & 15);
                    res >>= 4;
                }
                for (int i = d.length - 1; i >= 0; --i) {
                    out.print(encode(d[i]));
                }
                out.println();
            }
        }

        private long solveOne(int[] delta) {
            best[0] = 0;
            ww[0] = 0;
            for (int mask = 1; mask < best.length; ++mask) {
                int b = Integer.lowestOneBit(mask);
                int w = ww[mask ^ b] - delta[Integer.numberOfTrailingZeros(b)];
                ww[mask] = w;
                long cbest = INF;
                if (w >= 0 && w < 16) {
                    for (int p = 0; p < delta.length; ++p)
                        if ((mask & (1 << p)) != 0) {
                            int nxt = w + delta[p];
                            if (nxt >= 0 && nxt < 16) {
                                cbest = Math.min(cbest, best[mask ^ (1 << p)] + (((long) w) << (4 * p)));
                            }
                        }
                }
                best[mask] = cbest;
            }
            return best[best.length - 1];
        }

        private char encode(int i) {
            if (i < 10) return (char) ('0' + i);
            return (char) ('a' + (i - 10));
        }

        private int decode(char c) {
            if (c >= '0' && c <= '9') return c - '0';
            return c - 'a' + 10;
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