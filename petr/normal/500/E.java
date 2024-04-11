import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.StringTokenizer;

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
        int[] p = new int[n];
        int[] l = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = in.nextInt();
            l[i] = in.nextInt();
        }
        int[] range = new int[n];
        int[] tree = new int[4 * n + 10];
        for (int i = n - 1; i >= 0; --i) {
            int dest = p[i] + l[i];
            int left = i;
            int right = n;
            while (right - left > 1) {
                int middle = (left + right) / 2;
                if (p[middle] <= dest) left = middle; else right = middle;
            }
            int upto = treeGet(tree, 0, 0, n - 1, i + 1, left);
            upto = Math.max(upto, p[i] + l[i]);
            treePut(tree, 0, 0, n - 1, i, upto);
            range[i] = upto;
        }
        int logn = 0;
        while ((1 << logn) <= n) ++logn;
        int[][] jumpDest = new int[logn][n];
        int[][] jumpExtra = new int[logn][n];
        for (int i = 0; i < n; ++i) {
            int dest = range[i];
            int left = i;
            int right = n;
            while (right - left > 1) {
                int middle = (left + right) / 2;
                if (p[middle] <= dest) left = middle; else right = middle;
            }
            if (right == n) --right;
            jumpDest[0][i] = right;
            jumpExtra[0][i] = Math.max(0, p[jumpDest[0][i]] - dest);
        }
        for (int j = 1; j < logn; ++j) {
            for (int i = 0; i < n; ++i) {
                jumpDest[j][i] = jumpDest[j - 1][jumpDest[j - 1][i]];
                jumpExtra[j][i] = jumpExtra[j - 1][i] + jumpExtra[j - 1][jumpDest[j - 1][i]];
            }
        }
        int q = in.nextInt();
        for (int qi = 0; qi < q; ++qi) {
            int x = in.nextInt() - 1;
            int y = in.nextInt() - 1;
            int step = logn - 1;
            int res = 0;
            while (x < y) {
                int z = jumpDest[step][x];
                if (z <= y || step == 0) {
                    if (z <= y)
                        res += jumpExtra[step][x];
                    x = z;
                } else {
                    --step;
                }
            }
            out.println(res);
        }
    }

    private void treePut(int[] tree, int root, int rl, int rr, int at, int what) {
        if (rl == rr) {
            tree[root] = what;
            return;
        }
        int rm = (rl + rr) / 2;
        if (at <= rm) {
            treePut(tree, root * 2 + 1, rl, rm, at, what);
        } else {
            treePut(tree, root * 2 + 2, rm + 1, rr, at, what);
        }
        tree[root] = Math.max(tree[root * 2 + 1], tree[root * 2 + 2]);
    }

    private int treeGet(int[] tree, int root, int rl, int rr, int left, int right) {
        if (left > right) {
            return 0;
        }
        if (left == rl && right == rr) {
            return tree[root];
        }
        int rm = (rl + rr) / 2;
        return Math.max(treeGet(tree, root * 2 + 1, rl, rm, left, Math.min(rm, right)),
                treeGet(tree, root * 2 + 2, rm + 1, rr, Math.max(left, rm + 1), right));
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