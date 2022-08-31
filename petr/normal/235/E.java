import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.HashMap;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
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
    static final long MODULO = 1L << 30;

    int[] prime;

	public void solve(int testNumber, InputReader in, PrintWriter out) {
        int a = in.nextInt();
        int b = in.nextInt();
        int c = in.nextInt();
        boolean[] isPrime = new boolean[Math.max(a, Math.max(b, c)) + 1];
        Arrays.fill(isPrime, true);
        isPrime[0] = false;
        isPrime[1] = false;
        int cnt = 0;
        for (int i = 2; i < isPrime.length; ++i)
            if (isPrime[i]) {
                ++cnt;
                for (int j = 2 * i; j < isPrime.length; j += i)
                    isPrime[j] = false;
            }
        prime = new int[cnt];
        cnt = 0;
        for (int i = 2; i < isPrime.length; ++i)
            if (isPrime[i]) prime[cnt++] = i;
        out.println(doit(a, b, c, 0));
	}

    HashMap<Long, Integer> cache = new HashMap<Long, Integer>();

    private long doit(int a, int b, int c, int lastPrime) {
        if (a == 1 && b == 1 && c == 1) {
            return 1;
        }
        if (lastPrime >= prime.length)
            return 1;
        if (a > b) {
            int t = a;
            a = b;
            b = t;
        }
        if (b > c) {
            int t = c;
            c = b;
            b = t;
        }
        if (a > b) {
            int t = a;
            a = b;
            b = t;
        }
        int p = prime[lastPrime];
        if (c < p)
            return 1;
        if (c < p * p) {
            int ma = lastPrime - 1;
            int mb = lastPrime - 1;
            int mc = lastPrime - 1;
            while (ma + 1 < prime.length && prime[ma + 1] <= a)
                ++ma;
            while (mb + 1 < prime.length && prime[mb + 1] <= b)
                ++mb;
            while (mc + 1 < prime.length && prime[mc + 1] <= c)
                ++mc;
            long simpleRes = countSimple(ma - lastPrime + 1, mb - lastPrime + 1, mc - lastPrime + 1) % MODULO;
            return simpleRes;
        }
        long zz = ((a * 31371L + b) * 31371 + c) * 31371 + lastPrime;
        Integer cached = cache.get(zz);
        if (cached != null) return cached;
        long res = 0;
        for (int pra = 1, ca = 0; pra <= a; pra *= p, ++ca)
            for (int prb = 1, cb = 0; prb <= b; prb *= p, ++cb)
                for (int prc = 1, cc = 0; prc <= c; prc *= p, ++cc) {
                    int na = a / pra;
                    int nb = b / prb;
                    int nc = c / prc;
                    long mul = (ca + cb + cc + 1);
                    res = (res + mul * doit(na, nb, nc, lastPrime + 1)) % MODULO;
                }
        cache.put(zz, (int) res);
        return res;
    }

    private long countSimple(long na, long nb, long nc) {
        long res = 8 * na * (nb - 1) * (nc - 2);
        res += 4 * na;
        res += 6 * na * (nc - 1);
        res += 6 * na * (nb - 1);
        res += 6 * na * (nb - 1);
        res += countTwo(na, nb);
        res += countTwo(na, nc);
        res += countTwo(nb, nc);
        res += 1 + 2 * na + 2 * nb + 2 * nc;
        return res;
    }

    private long countTwo(long na, long nb) {
        long res = 3 * na;
        res += 4 * na * (nb - 1);
        return res;
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

    }