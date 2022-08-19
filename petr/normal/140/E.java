import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        long m = in.nextLong();
        long p = in.nextLong();
        long[] primes = new long[100];
        int numPrimes = 0;
        long tmp = p;
        for (int i = 2; i * i <= tmp; ++i) {
            if (tmp % i == 0) {
                primes[numPrimes++] = i;
                while (tmp % i == 0) tmp /= i; 
            }
        }
        if (tmp > 1) {
            primes[numPrimes++] = tmp;
        }
        int[] l = new int[n + 1];
        int maxL = 0;
        for (int i = 0; i < n; ++i) {
            l[i + 1] = in.nextInt();
            maxL = Math.max(maxL, l[i + 1]);
        }
        long[] comb = new long[maxL + 1];
        int[] pow = new int[numPrimes];
        long prod = 1;
        comb[0] = 1;
        for (int i = 1; i <= maxL; ++i) {
            long mulBy = m - i + 1;
            if (mulBy <= 0) {
                comb[i] = 0;
                continue;
            }
            for (int j = 0; j < numPrimes; ++j)
                while (mulBy % primes[j] == 0) {
                    mulBy /= primes[j];
                    ++pow[j];
                }
            long divBy = i;
            for (int j = 0; j < numPrimes; ++j) {
                while (divBy % primes[j] == 0) {
                    divBy /= primes[j];
                    --pow[j];
                }
            }
            prod = prod * mulBy % p;
            prod = prod * BigInteger.valueOf(divBy).modInverse(BigInteger.valueOf(p)).longValue() % p;
            long val = prod;
            for (int j = 0; j < numPrimes; ++j) {
                val = val * pow(primes[j], pow[j], p) % p;
            }
            comb[i] = val;
        }
        ++n;
        long[] ways = new long[maxL + 1];
        long[] nways = new long[maxL + 1];
        int[][] lineWays = new int[maxL + 1][maxL + 1];
        lineWays[1][1] = 1;
        for (int lineLen = 2; lineLen <= maxL; ++lineLen) {
            for (int numColors = 2; numColors <= lineLen; ++numColors) {
                lineWays[lineLen][numColors] = (int) ((lineWays[lineLen - 1][numColors] * (long) (numColors - 1) + lineWays[lineLen - 1][numColors - 1] * (long) numColors) % p);
            }
        }
        ways[0] = 1;
        for (int i = 1; i < n; ++i) {
            int curL = l[i];
            int prevL = l[i - 1];
            Arrays.fill(nways, 0, curL + 1, 0);
            int[] clWays = lineWays[curL];
            long sum = 0;
            for (int j = 0; j <= prevL; ++j) {
                sum += comb[j] * ways[j];
                sum %= p;
            }
            for (int j = 0; j <= curL; ++j) {
                if (j <= prevL) {
                    nways[j] = ((sum + p - ways[j]) * clWays[j]) % p;
                } else {
                    nways[j] = sum * clWays[j] % p;
                }
            }
            long[] tmpA = ways;
            ways = nways;
            nways = tmpA;
        }
        long total = 0;
        for (int i = 0; i <= l[n - 1]; ++i) {
            total = (total + ways[i] * comb[i]) % p;
        }
        out.println(total);
	}

    private long pow(long a, int k, long p) {
        if (k == 0) {
            return 1;
        }
        if (k % 2 == 0) {
            return pow(a * a % p, k / 2, p);
        }
        return a * pow(a, k - 1, p) % p;
    }
}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

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

    public long nextLong() {
        return Long.parseLong(next());
    }

    }