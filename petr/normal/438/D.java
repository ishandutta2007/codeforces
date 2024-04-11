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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    static class MagicTree {
        long[] sum;
        int[] max;
        int[] data;

        public MagicTree(int[] data) {
            this.data = data;
            int n = data.length;
            sum = new long[4 * n + 10];
            max = new int[4 * n + 10];
            initTree(0, 0, n - 1);
        }

        private void initTree(int root, int rl, int rr) {
            if (rl == rr) {
                sum[root] = max[root] = data[rl];
            } else {
                int rm = (rl + rr) >> 1;
                initTree(root * 2 + 1, rl, rm);
                initTree(root * 2 + 2, rm + 1, rr);
                sum[root] = sum[root * 2 + 1] + sum[root * 2 + 2];
                max[root] = Math.max(max[root * 2 + 1], max[root * 2 + 2]);
            }
        }

        public long getSum(int l, int r) {
            return internalGetSum(0, 0, data.length - 1, l, r);
        }

        private long internalGetSum(int root, int rl, int rr, int l, int r) {
            if (l > r) return 0;
            if (rl == l && rr == r) return sum[root];
            int rm = (rl + rr) / 2;
            return internalGetSum(root * 2 + 1, rl, rm, l, Math.min(rm, r)) + internalGetSum(root * 2 + 2, rm + 1, rr, Math.max(rm + 1, l), r);
        }

        public void applyMod(int l, int r, int x) {
            internalApplyMod(0, 0, data.length - 1, l, r, x);
        }

        private void internalApplyMod(int root, int rl, int rr, int l, int r, int x) {
            if (l > r) return;
            if (max[root] < x) return;
            if (rl == rr) {
                data[rl] %= x;
                sum[root] = max[root] = data[rl];
                return;
            }
            int rm = (rl + rr) / 2;
            internalApplyMod(root * 2 + 1, rl, rm, l, Math.min(rm, r), x);
            internalApplyMod(root * 2 + 2, rm + 1, rr, Math.max(rm + 1, l), r, x);
            sum[root] = sum[root * 2 + 1] + sum[root * 2 + 2];
            max[root] = Math.max(max[root * 2 + 1], max[root * 2 + 2]);
        }

        public void setValue(int k, int x) {
            internalSetValue(0, 0, data.length - 1, k, x);
        }

        private void internalSetValue(int root, int rl, int rr, int k, int x) {
            if (rl == rr) {
                data[rl] = x;
                sum[root] = max[root] = data[rl];
                return;
            }
            int rm = (rl + rr) / 2;
            if (k <= rm)
                internalSetValue(root * 2 + 1, rl, rm, k, x);
            else
                internalSetValue(root * 2 + 2, rm + 1, rr, k, x);
            sum[root] = sum[root * 2 + 1] + sum[root * 2 + 2];
            max[root] = Math.max(max[root * 2 + 1], max[root * 2 + 2]);
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();

        int[] data = new int[n];
        for (int i = 0; i < n; ++i) {
            data[i] = in.nextInt();
        }
        MagicTree t = new MagicTree(data);
        for (int i = 0; i < m; ++i) {
            int c = in.nextInt();
            if (c == 1) {
                int l = in.nextInt() - 1;
                int r = in.nextInt() - 1;
                out.println(t.getSum(l, r));
            } else if (c == 2) {
                int l = in.nextInt() - 1;
                int r = in.nextInt() - 1;
                int x = in.nextInt();
                t.applyMod(l, r, x);
            } else if (c == 3) {
                int k = in.nextInt() - 1;
                int x = in.nextInt();
                t.setValue(k, x);
            }
        }
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