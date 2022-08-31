import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
        long mod1;
        long mod2;
        long mul1;
        long mul2;
        int[] pow1;
        int[] pow2;
        int[][] e;
        byte[] mark;
        int left;
        int right;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            Random random = new Random(5714354351L + System.currentTimeMillis());
            mod1 = random.nextInt((int) 5e8) + (int) 1e9;
            mod2 = random.nextInt((int) 5e8) + (int) 1e9;
            while (!isPrime((int) mod1)) ++mod1;
            while (!isPrime((int) mod2)) ++mod2;
            mul1 = random.nextInt((int) (mod1 - 3)) + 2;
            mul2 = random.nextInt((int) (mod2 - 3)) + 2;
            int n = in.nextInt();
            String[] s = new String[n];
            int maxlen = 0;
            for (int i = 0; i < n; ++i) {
                s[i] = in.next();
                maxlen = Math.max(maxlen, s[i].length());
            }
            pow1 = buildPowers(mul1, mod1, maxlen);
            pow2 = buildPowers(mul2, mod2, maxlen);
            int[][] pHash1 = new int[n][];
            int[][] pHash2 = new int[n][];
            for (int i = 0; i < n; ++i) {
                pHash1[i] = buildPHash(s[i], mul1, mod1);
                pHash2[i] = buildPHash(s[i], mul2, mod2);
            }
            int m = 1;
            int[] offset = new int[n];
            for (int i = 0; i < n; ++i) {
                offset[i] = m;
                m += s[i].length() - 1;
            }
            int[][] e = new int[m][n];
            for (int[] ee : e) Arrays.fill(ee, -1);
            for (int i = 0; i < n; ++i) {
                for (int pos = 0; pos < s[i].length(); ++pos) {
                    int start = pos == 0 ? 0 : offset[i] + pos - 1;
                    for (int other = 0; other < n; ++other) {
                        int common = findCommon(pHash1[i], pHash2[i], pHash1[other], pHash2[other], pos);
                        boolean iEnds = common == s[i].length() - pos;
                        boolean otherEnds = common == s[other].length();
                        if (iEnds && otherEnds) {
                            if (pos > 0) {
                                e[start][other] = 0;
                            }
                        } else if (iEnds) {
                            if (pos > 0) {
                                e[start][other] = offset[other] + (common - 1);
                            }
                        } else if (otherEnds) {
                            e[start][other] = offset[i] + (pos + common - 1);
                        }
                    }
                }
            }

            int right = 0;
            int res = 0;
            byte[] mark = new byte[m];
            for (int left = 0; left < n; ++left) {
                if (right < left) right = left;
                while (right < n && isGood(e, left, right, n, m, offset, s, mark)) ++right;
                res += right - left;
            }
            out.println(res);
        }

        private boolean isGood(int[][] e, int left, int right, int n, int m, int[] offset, String[] s, byte[] mark) {
            this.e = e;
            this.mark = mark;
            this.left = left;
            this.right = right;
            Arrays.fill(mark, (byte) 0);
            for (int i = 0; i < n; ++i)
                if (i < left || i > right) {
                    for (int pos = 1; pos < s[i].length(); ++pos) {
                        int a = offset[i] + pos - 1;
                        mark[a] = 2;
                    }
                }
            for (int i = left; i <= right; ++i) {
                for (int pos = 1; pos < s[i].length(); ++pos) {
                    int a = offset[i] + pos - 1;
                    if (mark[a] == 0) {
                        if (dfs(a)) return false;
                    }
                }
            }
            return true;
        }

        private boolean dfs(int a) {
            if (mark[a] == 1) return true;
            if (mark[a] == 2) return false;
            mark[a] = 1;
            for (int j = left; j <= right; ++j) {
                int v = e[a][j];
                if (v >= 0 && dfs(v)) {
                    return true;
                }
            }
            mark[a] = 2;
            return false;
        }

        private int[] buildPowers(long mul, long mod, int maxlen) {
            int[] res = new int[maxlen + 1];
            res[0] = 1;
            for (int i = 0; i < maxlen; ++i) {
                res[i + 1] = (int) (res[i] * mul % mod);
            }
            return res;
        }

        private int findCommon(int[] ph1, int[] ph2, int[] qh1, int[] qh2, int offset) {
            int left = 0;
            int right = Math.min(ph1.length - offset, qh1.length);
            while (right - left > 1) {
                int middle = (left + right) >> 1;
                long pv1 = (ph1[offset + middle] - ph1[offset] * (long) pow1[middle]) % mod1;
                if (pv1 < 0) pv1 += mod1;
                long qv1 = qh1[middle];
                if (pv1 == qv1) {
                    long pv2 = (ph2[offset + middle] - ph2[offset] * (long) pow2[middle]) % mod2;
                    if (pv2 < 0) pv2 += mod2;
                    long qv2 = qh2[middle];
                    if (pv2 == qv2) {
                        left = middle;
                    } else {
                        right = middle;
                    }
                } else {
                    right = middle;
                }
            }
            return left;
        }

        private boolean isPrime(int mod) {
            for (int i = 2; i * i <= mod; ++i) if (mod % i == 0) return false;
            return true;
        }

        private int[] buildPHash(String s, long mul, long mod) {
            int[] res = new int[s.length() + 1];
            res[0] = 0;
            for (int i = 0; i < s.length(); ++i) {
                res[i + 1] = (int) ((res[i] * mul + s.charAt(i)) % mod);
            }
            return res;
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