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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        long min;
        int[] minDigits;
        int[] maxDigits;
        long max;
        long res;
        long[][] comb;
        int[] cnt;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            comb = new long[20][20];
            comb[0][0] = 1;
            for (int i = 1; i < comb.length; ++i) {
                comb[i][0] = 1;
                for (int j = 1; j < comb.length; ++j) {
                    comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
                }
            }
            min = in.nextLong() - 1;
            max = in.nextLong() + 1;
            minDigits = makeDigits(min);
            maxDigits = makeDigits(max);
            int[] cnt = new int[10];
            this.cnt = new int[10];
            res = 0;
            int[] p = new int[10];
            generate(18, 1, cnt);
            out.println(res);
        }

        private int[] makeDigits(long min) {
            int[] res = new int[19];
            for (int i = 0; i < res.length; ++i) {
                res[res.length - 1 - i] = (int) (min % 10);
                min /= 10;
            }
            return res;
        }

        private void generate(int max, int at, int[] cnt) {
            if (at >= 10) {
            /*long n1 = count(cnt, min, minDigits);
            long n2 = count(cnt, max, maxDigits);
            if (n1 < n2) {
                ++res;
            }*/
                if (isAny(cnt)) {
                    ++res;
                }
                return;
            }
            for (int x = 0; x <= max; ++x) {
                cnt[at] = x;
                generate(max - x, at + 1, cnt);
            }
        }

        private boolean isAny(int[] origCnt) {
            System.arraycopy(origCnt, 0, cnt, 0, 10);
            cnt[0] = maxDigits.length;
            for (int x : origCnt) cnt[0] -= x;
            int[] p = new int[10];
            for (int i = 0; i < p.length; ++i) p[i] = i - 1;
            boolean alreadyGreater = false;
            for (int pos = 0; pos < maxDigits.length; ++pos) {
                int cur = maxDigits[pos];
                int got = p[cur];
                while (got >= 0 && cnt[got] == 0) {
                    got = p[got];
                }
                int tmp = cur;
                while (tmp != got) {
                    int z = p[tmp];
                    p[tmp] = got;
                    tmp = z;
                }
                if (got >= 0 && got < cur) {
                    if (alreadyGreater || got > minDigits[pos]) {
                        return true;
                    }
                    if (got == minDigits[pos]) {
                        --cnt[got];
                        int at = pos + 1;
                        int coming;
                        outer:
                        for (coming = 9; coming >= 0; --coming) {
                            for (int i = cnt[coming]; i > 0; --i) {
                                if (minDigits[at] < coming) {
                                    return true;
                                }
                                if (minDigits[at] > coming) break outer;
                                ++at;
                            }
                        }
                        if (coming < 0) {
                            if (at != minDigits.length)
                                throw new RuntimeException();
                        }
                        ++cnt[got];
                    }
                }
                --cnt[cur];
                if (cnt[cur] < 0) return false;
                if (cur > minDigits[pos]) alreadyGreater = true;
            }
            return false;
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}