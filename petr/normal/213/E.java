import java.io.InputStreamReader;
import java.io.IOException;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    long MOD1;
    long MOD2;
    long K1;
    long K2;
    int[] K1pow;
    int[] K2pow;

    class Fenwick {
        int[] invSum1;
        int[] invSum2;
        int[] counts;
        int size;

        public Fenwick(int size, boolean needInvs) {
            this.size = size;
            counts = new int[size];
            if (needInvs) {
                invSum1 = new int[size];
                invSum2 = new int[size];
            }
        }

        void add(int pos, int what) {
            adjustCounts(size - 1 - pos, 1);
            if (invSum1 != null) {
                adjustInvs(invSum1, pos, K1pow[what], (int) MOD1);
                adjustInvs(invSum2, pos, K2pow[what], (int) MOD2);
            }
        }

        void remove(int pos, int what) {
            adjustCounts(size - 1 - pos, -1);
            if (invSum1 != null) {
                adjustInvs(invSum1, pos, (int) (MOD1 - K1pow[what]), (int) MOD1);
                adjustInvs(invSum2, pos, (int) (MOD2 - K2pow[what]), (int) MOD2);
            }
        }

        int getNumLarger(int pos) {
            pos = size - 1 - pos;
            int res = 0;
            while (pos >= 0) {
                res += counts[pos];
                pos = (pos & (pos + 1)) - 1;
            }
            return res;
        }

        void getInvSums(int pos, long[] resHolder) {
            resHolder[0] = getInvSumsInternal(pos, invSum1, (int) MOD1);
            resHolder[1] = getInvSumsInternal(pos, invSum2, (int) MOD2);
        }

        private long getInvSumsInternal(int pos, int[] invSum, int mod) {
            long res = 0;
            while (pos >= 0) {
                res += invSum[pos];
                if (res >= mod) res -= mod;
                pos = (pos & (pos + 1)) - 1;
            }
            return res;
        }

        private void adjustInvs(int[] invSum, int at, int by, int mod) {
            if (by >= mod) by -= mod;
            while (at < size) {
                invSum[at] += by;
                if (invSum[at] >= mod) invSum[at] -= mod;
                at |= (at + 1);
            }
        }

        private void adjustCounts(int at, int by) {
            while (at < size) {
                counts[at] += by;
                at |= (at + 1);
            }
        }
    }

	public void solve(int testNumber, InputReader in, PrintWriter out) {
        Random random = new Random(543175431531L + System.nanoTime());
        MOD1 = ((int) 5e8 + random.nextInt((int) 5e8));
        while (!isPrime(MOD1)) ++MOD1;
        K1 = random.nextInt((int) MOD1 - 3) + 2;
        MOD2 = ((int) 5e8 + random.nextInt((int) 5e8));
        while (!isPrime(MOD2)) ++MOD2;
        K2 = random.nextInt((int) MOD2 - 3) + 2;
        int _n = in.nextInt();
        int _m = in.nextInt();
        int[] a = new int[_n];
        for (int i = 0; i < _n; ++i) a[i] = in.nextInt() - 1;
        int[] b = new int[_m];
        for (int i = 0; i < _m; ++i) b[i] = in.nextInt() - 1;
        K1pow = new int[_m + 1];
        K2pow = new int[_m + 1];
        K1pow[0] = 1;
        K2pow[0] = 1;
        for (int i = 1; i <= _m; ++i) {
            K1pow[i] = (int) (K1 * K1pow[i - 1] % MOD1);
            K2pow[i] = (int) (K2 * K2pow[i - 1] % MOD2);
        }
        int[] aWhere = new int[a.length];
        for (int i = 0; i < a.length; ++i) aWhere[a[i]] = i;
        long[] needHash = new long[2];
        Fenwick g = new Fenwick(a.length, false);
        for (int i = 0; i < a.length; ++i) {
            long numExtra = g.getNumLarger(aWhere[i]);
            g.add(aWhere[i], i);
            needHash[0] = (needHash[0] + numExtra * K1pow[i]) % MOD1;
            needHash[1] = (needHash[1] + numExtra * K2pow[i]) % MOD2;
        }
        int[] bWhere = new int[b.length];
        for (int i = 0; i < b.length; ++i) bWhere[b[i]] = i;
        Fenwick f = new Fenwick(b.length, true);
        long[] curHash = new long[2];
        long[] resHolder = new long[2];
        int res = 0;
        for (int i = 0; i < b.length; ++i) {
            if (i >= a.length) {
                int ii = i - a.length;
                f.remove(bWhere[ii], ii);
                f.getInvSums(bWhere[ii], resHolder);
                curHash[0] = (curHash[0] + MOD1 - resHolder[0]) % MOD1;
                curHash[1] = (curHash[1] + MOD2 - resHolder[1]) % MOD2;
            }
            long numExtra = f.getNumLarger(bWhere[i]);
            curHash[0] = (curHash[0] + numExtra * K1pow[i]) % MOD1;
            curHash[1] = (curHash[1] + numExtra * K2pow[i]) % MOD2;
            f.add(bWhere[i], i);
            if (i + 1 >= a.length) {
                int delta = i + 1 - a.length;
                if (curHash[0] == needHash[0] * K1pow[delta] % MOD1 && curHash[1] == needHash[1] * K2pow[delta] % MOD2) {
                    ++res;
                }
            }
        }
        out.println(res);
    }

    private boolean isPrime(long x) {
        for (long i = 2; i * i <= x; ++i) if (x % i == 0) return false;
        return true;
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