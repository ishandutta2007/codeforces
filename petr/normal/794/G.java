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
        TaskG solver = new TaskG();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskG {
        static final long MODULO = (long) (1e9 + 7);

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String c = in.next();
            String d = in.next();
            int n = in.nextInt();
            long res = 0;
            long waysEqual = 0;
            if (c.length() == d.length()) {
                waysEqual = 1;
                for (int i = 0; i < c.length(); ++i) {
                    char ac = c.charAt(i);
                    char ad = d.charAt(i);
                    if (ac == '?') {
                        if (ad == '?') {
                            waysEqual = waysEqual * 2 % MODULO;
                        }
                    } else if (ad == '?') {

                    } else {
                        if (ac != ad) {
                            waysEqual = 0;
                            break;
                        }
                    }
                }
                long total = 1;
                for (int i = 0; i < n; ++i) {
                    total = total * 2 % MODULO;
                }
                total = ((total * 2 - 2) % MODULO + MODULO) % MODULO;
                res = (res + total * total % MODULO * waysEqual) % MODULO;
            }

            long[] nonperiodic = new long[n + 1];
            nonperiodic[0] = 1;
            for (int i = 1; i <= n; ++i) nonperiodic[i] = 2 * nonperiodic[i - 1] % MODULO;
            long[] uptoValid = new long[n + 1];
            for (int i = 1; i <= n; ++i) {
                uptoValid[i] = uptoValid[i - 1] + nonperiodic[i];
                uptoValid[i] %= MODULO;
            }
            for (int i = 1; i <= n; ++i) {
                for (int j = 2 * i; j <= n; j += i) {
                    nonperiodic[j] -= nonperiodic[i];
                    if (nonperiodic[j] < 0) nonperiodic[j] += MODULO;
                }
            }

            long anyValid = 0;
            for (int i = 1; i <= n; ++i) {
                long maxTimes = n / i;
                anyValid = (anyValid + nonperiodic[i] * maxTimes % MODULO * maxTimes) % MODULO;
            }

            int na = 0;
            int nb = 0;
            int qPlus = 0;
            int qMinus = 0;
            for (int i = 0; i < c.length(); ++i) {
                char ac = c.charAt(i);
                if (ac == 'A') ++na;
                else if (ac == 'B') ++nb;
                else ++qPlus;
            }
            for (int i = 0; i < d.length(); ++i) {
                char ad = d.charAt(i);
                if (ad == 'A') --na;
                else if (ad == 'B') --nb;
                else ++qMinus;
            }
            na -= qMinus;
            qPlus += qMinus;
            qMinus = 0;
            long[] invs = new long[qPlus + 1];
            if (qPlus > 0)
                invs[1] = 1;
            for (int i = 2; i <= qPlus; ++i) {
                invs[i] = (MODULO - invs[((int) (MODULO % i))] * (MODULO / i) % MODULO) % MODULO;
                if (invs[i] * i % MODULO != 1) throw new RuntimeException();
            }
            long comb = 1;
            for (int nPlus = 0; nPlus <= qPlus; ++nPlus) {
                if (nPlus > 0) {
                    comb = comb * (qPlus - nPlus + 1) % MODULO * invs[nPlus] % MODULO;
                }
                int deltaMul = na + nPlus;
                int bMul = c.length() - d.length();
                if (deltaMul == 0 && bMul == 0) {
                    res = ((res + (comb - waysEqual) * anyValid) % MODULO + MODULO) % MODULO;
                } else {
                    int g = gcd(Math.abs(deltaMul), Math.abs(bMul));
                    deltaMul /= g;
                    bMul /= g;
                    if (deltaMul != 0) {
                        if (deltaMul < 0) {
                            deltaMul = -deltaMul;
                            bMul = -bMul;
                        }
                        int lb = deltaMul;
                        int la = lb - bMul;
                        if (la > 0) {
                            res = (res + comb * uptoValid[n / Math.max(la, lb)]) % MODULO;
                        }
                    }
                }
            }

            out.println(res);
        }

        private int gcd(int a, int b) {
            while (b > 0) {
                int t = a % b;
                a = b;
                b = t;
            }
            return a;
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