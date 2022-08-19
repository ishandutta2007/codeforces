import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class HappyNumbers implements Runnable {
    private void solve() throws IOException {
        /*for (long l = 1; l <= 1000; ++l) {
            System.out.println(l);
            for (long a = 1; a <= 1000; ++a) {
                if (doit(a, l) != doit2(a, l))
                    throw new RuntimeException(a + " " + l);
            }
        }*/
        long a = nextLong();
        long l = nextLong();
        System.out.println(doit(a, l));
    }

    /*private long doit2(long a, long l) {
        for (long b = a + 1;; ++b) {
            boolean ok = true;
            for (int i = 0; i < l; ++i)
                if (countLucky(a + i) != countLucky(b + i)) {
                    ok = false;
                    break;
                }
            if (ok)
                return b;
        }
    }*/

    private long doit(long a, long l) {
        if (l >= 10) {
            long first = a;
            long last = a + l - 1;
            return doit(first / 10, last / 10 - first / 10 + 1) * 10 + first % 10;
        } else {
            int[] cnts = new int[(int) l];
            for (int i = 0; i < l; ++i)
                cnts[i] = countLucky(a + i);
            return doitFrom(cnts, a + 1);
        }
    }

    private long doitFrom(int[] cnts, long min) {
        if (cnts.length == 1) {
            return doitOne(cnts[0], min);
        } else if (cnts.length == 2 && min <= 1) {
            return doitTwoSimple(cnts[0], cnts[1], min);
        }
        long res = Long.MAX_VALUE;
        for (int lastDigit = 0; lastDigit < 10; ++lastDigit) {
            int max = lastDigit + cnts.length - 1;
            int[] ncnts = new int[max / 10 + 1];
            Arrays.fill(ncnts, -1);
            boolean ok = true;
            for (int i = 0; i < cnts.length; ++i) {
                int cur = lastDigit + i;
                int need = cnts[i];
                if (cur % 10 == 4 || cur % 10 == 7)
                    --need;
                if (need < 0) {
                    ok = false;
                    break;
                }
                if (ncnts[cur / 10] < 0 || ncnts[cur / 10] == need) {
                    ncnts[cur / 10] = need;
                } else {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;
            long newMin = min / 10 - 3;
            while (newMin * 10 + lastDigit < min)
                ++newMin;
            long tmp = doitFrom(ncnts, newMin) * 10 + lastDigit;
            res = Math.min(res, tmp);
        }
        return res;
    }

    private long doitTwoSimple(int cntFirst, int cntSecond, long min) {
        if (cntFirst == 0 && cntSecond == 0)
            return min;
        if (cntFirst == cntSecond) {
            long res = 0;
            for (int i = 0; i < cntFirst; ++i)
                res = res * 10 + 4;
            return res * 10;
        } else if (cntFirst == cntSecond + 1) {
            long res = 0;
            for (int i = 0; i < cntFirst; ++i)
                res = res * 10 + 4;
            return res;
        } else if (cntFirst + 1 == cntSecond) {
            long res = 0;
            for (int i = 0; i < cntSecond; ++i)
                res = res * 10 + 4;
            return res - 1;
        } else {
            return Long.MAX_VALUE;
        }
    }

    private long doitOne(int cnt, long min) {
        long p10 = 1;
        int pow = 0;
        while (p10 <= min) {
            p10 *= 10;
            ++pow;
        }
        p10 *= 100;
        pow += 2;
        while (pow < cnt + 2) {
            p10 *= 10;
            ++pow;
        }
        long res = 0;
        while (true) {
            for (int curDigit = 0; curDigit < 10; ++curDigit) {
                int curCnt = 0;
                if (curDigit == 4 || curDigit == 7) curCnt = 1;
                if (possible(res, p10, pow, cnt - curCnt, min)) {
                    cnt -= curCnt;
                    break;
                }
                res += p10;
                if (curDigit == 9)
                    throw new RuntimeException();
            }
            if (p10 == 1) break;
            p10 /= 10;
            --pow;
        }
        return res;
    }

    private boolean possible(long res, long p10, int pow, int needLucky, long min) {
        if (needLucky > pow || needLucky < 0)
            return false;
        long cur = 0;
        for (int i = 0; i < pow - needLucky; ++i)
            cur = cur * 10 + 9;
        for (int i = 0; i < needLucky; ++i)
            cur = cur * 10 + 7;
        return res + cur >= min;
    }

    private int countLucky(long x) {
        int res = 0;
        while (x > 0) {
            long dig = x % 10;
            x /= 10;
            if (dig == 4 || dig == 7) ++res;
        }
        return res;
    }

    public static void main(String[] args) {
        new HappyNumbers().run();
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            writer = new PrintWriter(System.out);
            solve();
            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}