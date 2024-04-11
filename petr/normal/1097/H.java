import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        TaskH solver = new TaskH();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskH {
        long[] lens;
        Description[] cache;
        int m;
        int[] b;
        int[] gen;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int d = in.nextInt();
            m = in.nextInt();
            gen = new int[d];
            for (int i = 0; i < d; ++i) gen[i] = in.nextInt();
            int blen = in.nextInt();
            b = new int[blen];
            for (int i = 0; i < blen; ++i) {
                b[i] = in.nextInt();
            }
            long left = in.nextLong();
            long right = in.nextLong();
            lens = new long[100];
            long len = 1;
            int layer = 0;
            lens[layer] = len;
            while (true) {
                ++layer;
                if (len < (right + d - 1) / d) {
                    len *= d;
                    lens[layer] = len;
                } else {
                    lens[layer] = right + 1;
                    break;
                }
            }
            cache = new Description[layer + 1];
            Description d1 = describe(layer, right);
            Description d2 = describe(layer, left + b.length - 2);
            long res = d1.matchesInside[0] - d2.matchesInside[0];
            out.println(res);
        }

        private Description describe(int layer, long upto) {
            if (upto > lens[layer]) throw new RuntimeException();
            if (upto == lens[layer]) {
                if (cache[layer] != null) return cache[layer];
            }
            Description res = null;
            if (upto <= 0) {
                res = new Description(upto);
                return res;
            }
            if (layer == 0) {
                res = new Description(upto);
                for (int shift = 0; shift < m; ++shift) {
                    if (b.length > 1 && b[0] >= shift) {
                        res.matchesPrefix[shift] = BigInteger.ONE;
                    } else {
                        res.matchesPrefix[shift] = BigInteger.ZERO;
                    }
                    if (b.length > 1 && b[b.length - 1] >= shift) {
                        res.matchesSuffix[shift] = BigInteger.ONE.shiftLeft(b.length - 1);
                    } else {
                        res.matchesSuffix[shift] = BigInteger.ZERO;
                    }
                    if (b.length == 1 && b[0] >= shift) {
                        ++res.matchesInside[shift];
                    }
                    byte[] bits = new byte[(b.length + 7) >> 3];
                    for (int i = 0; i < b.length; ++i) {
                        if (b[i] >= shift) {
                            bits[bits.length - 1 - (i >> 3)] |= (1 << (i & 7));
                        }
                    }
                    res.coveredIfStartsFrom[shift] = new BigInteger(1, bits);
                }
            } else {
                long togo = upto;
                for (int i = 0; i < gen.length && togo > 0; ++i) {
                    long by = Math.min(togo, lens[layer - 1]);
                    Description d = describe(layer - 1, by);
                    res = combine(res, d, gen[i]);
                    togo -= by;
                }
            }
            if (res == null) throw new RuntimeException();
            if (upto == lens[layer]) {
                cache[layer] = res;
            }
            return res;
        }

        private Description combine(Description a, Description b, int delta) {
            if (a == null) {
                if (delta != 0) throw new RuntimeException();
                return b;
            }
            Description res = new Description(a.len + b.len);
            for (int shift = 0; shift < m; ++shift) {
                int ashift = shift;
                int bshift = (shift + delta) % m;
                res.matchesInside[shift] = a.matchesInside[ashift] + b.matchesInside[bshift];
                res.matchesInside[shift] += a.matchesPrefix[ashift].and(b.matchesSuffix[bshift].shiftRight(1)).bitCount();
                res.matchesPrefix[shift] = b.matchesPrefix[bshift];
                if (b.len < this.b.length) {
                    res.matchesPrefix[shift] = res.matchesPrefix[shift].or(a.matchesPrefix[ashift].and(b.coveredIfStartsFrom[bshift].shiftRight(1)).shiftLeft((int) b.len));
                }
                res.matchesSuffix[shift] = a.matchesSuffix[ashift];
                if (a.len < this.b.length) {
                    res.matchesSuffix[shift] = res.matchesSuffix[shift].or(b.matchesSuffix[bshift].shiftRight((int) a.len).and(a.coveredIfStartsFrom[ashift]));
                }
                if (a.len < this.b.length) {
                    res.coveredIfStartsFrom[shift] = a.coveredIfStartsFrom[ashift].and(b.coveredIfStartsFrom[bshift].shiftRight((int) a.len));
                } else {
                    res.coveredIfStartsFrom[shift] = BigInteger.ZERO;
                }
            }
            return res;
        }

        class Description {
            long len;
            long[] matchesInside = new long[m];
            BigInteger[] matchesPrefix = new BigInteger[m];
            BigInteger[] matchesSuffix = new BigInteger[m];
            BigInteger[] coveredIfStartsFrom = new BigInteger[m];

            public Description(long len) {
                this.len = len;
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}