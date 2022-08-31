import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    static final int BUBEN = 100;
    static final double BUBEN3 = 1e-9;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        double[] pr = new double[BUBEN + 1];
        pr[0] = 1.0;
        for (int i = 0; i < BUBEN; ++i) {
            for (int j = BUBEN; j >= 1; --j) {
                pr[j] += pr[j - 1] * 0.5;
                pr[j - 1] *= 0.5;
            }
        }
        int BUBEN2 = 0;
        double sum = 0;
        while (sum + pr[BUBEN2] < BUBEN3) {
            sum += pr[BUBEN2];
            ++BUBEN2;
        }
        int n = in.nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n; ++i) a[i] = in.nextLong();
        boolean[] ispr = new boolean[1000000];
        Arrays.fill(ispr, true);
        ispr[0] = ispr[1] = false;
        int cntpr = 0;
        for (int i = 2; i < ispr.length; ++i)
            if (ispr[i]) {
                ++cntpr;
                for (int j = i * 2; j < ispr.length; j += i)
                    ispr[j] = false;
            }
        long[] primes = new long[cntpr];
        cntpr = 0;
        for (int i = 2; i < ispr.length; ++i)
            if (ispr[i])
                primes[cntpr++] = i;
        long[] divisors = new long[50 * BUBEN];
        int pos = 0;
        Random random = new Random(547315431513L + System.currentTimeMillis());
        for (int i = 0; i < BUBEN; ++i) {
            long x = a[random.nextInt(n)];
            for (long p : primes) {
                if (x % p == 0) {
                    long pw = 0;
                    while (x % p == 0) {
                        ++pw;
                        x /= p;
                        divisors[pos++] = p * 100 + pw;
                    }
                }
            }
            if (x > 1) {
                divisors[pos++] = x * 100 + 1;
            }
        }
        Arrays.sort(divisors, 0, pos);
        divisors = Arrays.copyOf(divisors, pos);
        long[] nicedivisors = new long[divisors.length];
        int nicecnt = 0;
        for (int i = 0; i < pos;) {
            int j = i;
            while (j < pos && divisors[j] == divisors[i]) ++j;
            int cnt = j - i;
            long cur = divisors[i];
            if (cnt >= BUBEN2) {
                if (nicecnt > 0 && nicedivisors[nicecnt - 1] / 100 == cur / 100)
                    nicedivisors[nicecnt - 1] = cur;
                else
                    nicedivisors[nicecnt++] = cur;
            }
            i = j;
        }
        nicedivisors = Arrays.copyOf(nicedivisors, nicecnt);
        long[] arr = new long[n];
        pos = 0;
        for (long x : a) {
            long y = 1;
            for (long pair : nicedivisors) {
                long p = pair / 100;
                long maxpw = pair % 100;
                long pw = 0;
                while (x % p == 0 && pw < maxpw) {
                    x /= p;
                    y *= p;
                    ++pw;
                }
            }
            arr[pos++] = y;
        }
        if (pos != n) throw new RuntimeException();
        for (int i = 0; i < nicedivisors.length; ++i)
            nicedivisors[i] /= 100;
        Arrays.sort(arr);
        long[] narr = new long[n];
        long[] ncnt = new long[n];
        pos = 0;
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && arr[j] == arr[i]) ++j;
            narr[pos] = arr[i];
            ncnt[pos] = j - i;
            i = j;
            ++pos;
        }
        narr = Arrays.copyOf(narr, pos);
        ncnt = Arrays.copyOf(ncnt, pos);
        int half = (n + 1) / 2;
        long res = rec(narr, ncnt, nicedivisors, 0, 1, half);
        out.println(res);
    }

    private long rec(long[] narr, long[] ncnt, long[] nicedivisors, int at, long prod, int half) {
        long got = 0;
        for (int i = 0; i < narr.length; ++i)
            if (narr[i] % prod == 0) got += ncnt[i];
        if (got < half)
            return 0;
        long max = ((long) 1.1e12) / prod;
        long res  = prod;
        for (int next = at; next < nicedivisors.length && nicedivisors[next] <= max; ++next) {
            res = Math.max(res, rec(narr, ncnt, nicedivisors, next, prod * nicedivisors[next], half));
        }
        return res;
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

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