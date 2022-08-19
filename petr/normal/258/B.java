import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.math.BigInteger;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    static final long MODULO = (int) (1e9 + 7);

	public void solve(int testNumber, InputReader in, PrintWriter out) {
        long m = in.nextInt();
        long[] ways = new long[11];
        ++ways[countHappy(m)];
        ways[0] = (ways[0] + MODULO - 1) % MODULO;
        long[][] byLen = new long[11][11];
        byLen[0][0] = 1;
        for (int len = 1; len < 11; ++len) {
            for (int prevCnt = 0; prevCnt < 11; ++prevCnt)
                if (byLen[len - 1][prevCnt] > 0) {
                    byLen[len][prevCnt] = (byLen[len][prevCnt] + byLen[len - 1][prevCnt] * 8) % MODULO;
                    byLen[len][prevCnt + 1] = (byLen[len][prevCnt + 1] + byLen[len - 1][prevCnt] * 2) % MODULO;
                }
        }
        int rlen;
        long p10;
        for (p10 = 1, rlen = 0; p10 <= m; p10 *= 10, ++rlen) {
            int dig = (int) ((m / p10) % 10);
            for (int what = 0; what < dig; ++what) {
                int pref = countHappy(m / p10 / 10) + countHappy(what);
                for (int extra = 0; extra < 11; ++extra)
                    if (byLen[rlen][extra] > 0)
                        ways[pref + extra] = (ways[pref + extra] + byLen[rlen][extra]) % MODULO;
            }
        }
        long total = 0;
        for (int w = 0; w < 11; ++w) total += ways[w];
        if (total != m) throw new RuntimeException();
        long[][] sumWays = new long[7][11];
        sumWays[0][0] = 1;
        for (int what = 0; what < 11; ++what) {
            long prod = 1;
            long[][] nsWays = new long[7][11];
            for (int a = 0; a < 7; ++a) for (int b = 0; b < 11; ++b) nsWays[a][b] = sumWays[a][b];
            for (int times = 1; times < 7 && times * what < 11; ++times) {
                prod = prod * (ways[what] + 1 - times + MODULO) % MODULO;
                prod = prod * BigInteger.valueOf(times).modInverse(BigInteger.valueOf(MODULO)).longValue() % MODULO;
                for (int st = 10 - times * what; st >= 0; --st)
                    for (int cnt = 6 - times; cnt >= 0; --cnt) {
                        nsWays[cnt + times][st + times * what] = (nsWays[cnt + times][st + times * what] + sumWays[cnt][st] * prod) % MODULO;
                    }
            }
            sumWays = nsWays;
        }
        long sum = 0;
        long res = 0;
        for (int we = 1; we < 11; ++we) {
            sum = (sum + sumWays[6][we - 1]) % MODULO;
            res = (res + sum * ways[we]) % MODULO;
        }
        for (int i = 1; i < 7; ++i) res = (res * i) % MODULO;
        out.println(res);
	}

    private int countHappy(long m) {
        int res = 0;
        while (m > 0) {
            if (m % 10 == 4 || m % 10 == 7) ++res;
            m /= 10;
        }
        return res;
    }
}

class InputReader {
    BufferedReader reader;
    StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
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