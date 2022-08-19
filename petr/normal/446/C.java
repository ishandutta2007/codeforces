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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    static final int MODULO = (int) (1e9 + 9);

    static class Tree {
        int[] data;

        public Tree(int size) {
            data = new int[size];
        }

        private void update(int at, int by) {
            while (at < data.length) {
                int s = data[at] + by;
                if (s >= MODULO) s -= MODULO;
                data[at] = s;
                at |= (at + 1);
            }
        }

        private int query(int at) {
            long add = 0;
            while (at >= 0) {
                add += data[at];
                at = (at & (at + 1)) - 1;
            }
            return (int) (add % MODULO);
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int numQueries = in.nextInt();
        Tree[] trees = new Tree[3];
        for (int i = 0; i < 3; ++i) trees[i] = new Tree(n);
        Tree tails = new Tree(n);
        int[] starter = new int[n];
        for (int i = 0; i < n; ++i) {
            starter[i] = in.nextInt() % MODULO;
        }
        int[] starterSums = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            int s = starterSums[i - 1] + starter[i - 1];
            if (s >= MODULO) s -= MODULO;
            starterSums[i] = s;
        }
        for (int queryI = 0; queryI < numQueries; ++queryI) {
            int kind = in.nextInt();
            int l = in.nextInt() - 1;
            int r = in.nextInt() - 1;
            if (kind == 1) {
                int[] extra = rev(new int[]{1, 1, 1}, l);
                for (int i = 0; i < 3; ++i) {
                    trees[i].update(l, extra[i]);
                    if (r + 1 < n) {
                        trees[i].update(r + 1, (MODULO - extra[i]) % MODULO);
                    }
                }
                if (r + 1 < n) {
                    tails.update(r + 1, fwd(new int[]{1, 1, 1}, r - l)[2]);
                }
            } else {
                long res = starterSums[r + 1] - starterSums[l] + MODULO;
                int[] extraL = new int[3];
                int[] extraR = new int[3];
                for (int i = 0; i < 3; ++i) {
                    extraR[i] = trees[i].query(r);
                    if (l > 0)
                        extraL[i] = trees[i].query(l - 1);
                }
                if (l > 0)
                    res += MODULO - fwd(extraL, l - 1)[2];
                res += fwd(extraR, r)[2];
                if (l > 0)
                    res += MODULO - tails.query(l - 1);
                res += tails.query(r);
                res %= MODULO;
                out.println(res);
            }
        }
    }

    static int[][] fwdM = new int[][]{
            new int[]{0, 1, 0},
            new int[]{1, 1, 0},
            new int[]{0, 1, 1}
    };

    static int[][] revM = new int[][]{
            new int[]{MODULO - 1, 1, 0},
            new int[]{1, 0, 0},
            new int[]{MODULO - 1, 0, 1}
    };

    static int[][][] fwdMPow = new int[20][][];
    static int[][][] revMPow = new int[20][][];
    static {
        fwdMPow[0] = fwdM;
        revMPow[0] = revM;
        for (int i = 1; i < fwdMPow.length; ++i) {
            fwdMPow[i] = mul(fwdMPow[i - 1], fwdMPow[i - 1]);
            revMPow[i] = mul(revMPow[i - 1], revMPow[i - 1]);
        }
    }

    private static int[][] mul(int[][] a, int[][] b) {
        int[][] c = new int[3][3];
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j) {
                long s = 0;
                for (int k = 0; k < 3; ++k) {
                    s += a[i][k] * (long) b[k][j];
                }
                c[i][j] = (int) (s % MODULO);
            }
        return c;
    }

    private static int[] mul(int[][] a, int[] b) {
        int[] c = new int[3];
        for (int i = 0; i < 3; ++i) {
            long s = 0;
            for (int k = 0; k < 3; ++k) {
                s += a[i][k] * (long) b[k];
            }
            c[i] = (int) (s % MODULO);
        }
        return c;
    }

    private int[] fwd(int[] v, int times) {
        for (int i = 0; i < fwdMPow.length; ++i)
            if ((times & (1 << i)) != 0)
                v = mul(fwdMPow[i], v);
        return v;
    }

    private int[] rev(int[] v, int times) {
        for (int i = 0; i < revMPow.length; ++i)
            if ((times & (1 << i)) != 0)
                v = mul(revMPow[i], v);
        return v;
    }
}

class InputReader {
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