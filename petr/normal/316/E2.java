import java.io.InputStreamReader;
import java.io.IOException;
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
		TaskE1 solver = new TaskE1();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE1 {
    static final int MODULO = (int) 1e9;

    static class Summator {
        int[] multipliers;
        int[] delta;
        int[] sum;
        int n;

        public Summator(int[] multipliers, int[] startingValues) {
            this.multipliers = multipliers;
            this.n = multipliers.length;
            if (startingValues.length != n) throw new RuntimeException();
            delta = new int[4 * n + 10];
            sum = new int[4 * n + 10];
            initTree(0, 0, n - 1, startingValues);
        }

        private void initTree(int root, int rl, int rr, int[] startingValues) {
            if (rl == rr) {
                delta[root] = startingValues[rl];
                sum[root] = (int) (multipliers[rl] * (long) startingValues[rl] % MODULO);
            } else {
                int rm = (rl + rr) / 2;
                initTree(root * 2 + 1, rl, rm, startingValues);
                initTree(root * 2 + 2, rm + 1, rr, startingValues);
                sum[root] = (sum[root * 2 + 1] + sum[root * 2 + 2]) % MODULO;
            }
        }

        public void updateValue(int x, int v) {
            internalUpdate(0, 0, n - 1, x, v);
        }

        private void internalUpdate(int root, int rl, int rr, int x, int v) {
            if (rl == rr) {
                if (rl != x) throw new RuntimeException();
                delta[root] = v;
                sum[root] = (int) (multipliers[rl] * (long) v % MODULO);
            } else {
                int rm = (rl + rr) / 2;
                if (x <= rm)
                    internalUpdate(root * 2 + 1, rl, rm, x, v);
                else
                    internalUpdate(root * 2 + 2, rm + 1, rr, x, v);
                sum[root] = (sum[root * 2 + 1] + sum[root * 2 + 2]) % MODULO;
            }
        }

        public int query(int l, int r) {
            return internalQuery(0, 0, n - 1, l, r);
        }

        private int internalQuery(int root, int rl, int rr, int left, int right) {
            if (left > right) return 0;
            if (rl == left && rr == right)
                return sum[root];
            int rm = (rl + rr) / 2;
            return (internalQuery(root * 2 + 1, rl, rm, left, Math.min(right, rm)) + internalQuery(root * 2 + 2, rm + 1, rr, Math.max(rm + 1, left), right)) % MODULO;
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) a[i] = in.nextInt();
        int[] f = new int[n + 1];
        f[0] = 0;
        f[1] = 1;
        for (int i = 2; i < n + 1; ++i) {
            f[i] = (f[i - 1] + f[i - 2]);
            if (f[i] >= MODULO) f[i] -= MODULO;
        }
        Summator s1 = new Summator(subArray(f, 0, n), a);
        Summator s2 = new Summator(subArray(f, 1, n), a);

        for (int i = 0; i < m; ++i) {
            int t = in.nextInt();
            switch (t) {
                case 1: {
                    int x = in.nextInt() - 1;
                    int v = in.nextInt();
                    s1.updateValue(x, v);
                    s2.updateValue(x, v);
                    break;
                }

                case 2: {
                    int l = in.nextInt() - 1;
                    int r = in.nextInt() - 1;
                    int a1 = s1.query(l, r);
                    int a2 = s2.query(l, r);
                    if (l == 0) out.println(a2); else {
                        long res = (a2 * (long) f[l - 1] - a1 * (long) f[l]) % MODULO;
                        if (l % 2 != 0) res = -res;
                        out.println((res + MODULO) % MODULO);
                    }
                    break;
                }

                case 3: {
                    int l = in.nextInt() - 1;
                    int r = in.nextInt() - 1;
                    int d = in.nextInt();
                    for (int j = l; j <= r; ++j) {
                        a[j] = (a[j] + d) % MODULO;
                    }
                    break;
                }
            }
        }
    }

    private int[] subArray(int[] f, int start, int len) {
        int[] res = new int[len];
        System.arraycopy(f, start, res, 0, len);
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

    }