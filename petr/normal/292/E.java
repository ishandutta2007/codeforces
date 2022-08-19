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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    static final int UNCHANGED = (int) 1e9;
    static final int MIXED = (int) 1e9 + 1;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
        }
        for (int i = 0; i < n; ++i) {
            b[i] = in.nextInt();
        }
        int[] tree = new int[4 * n + 10];
        initTree(tree, 0, 0, n - 1);
        for (int i = 0; i < m; ++i) {
            int kind = in.nextInt();
            if (kind == 1) {
                int srcPos = in.nextInt() - 1;
                int dstPos = in.nextInt() - 1;
                int len = in.nextInt();
                updateTree(tree, 0, 0, n - 1, dstPos, dstPos + len - 1, srcPos - dstPos);
            } else {
                int pos = in.nextInt() - 1;
                int what = getFromTree(tree, 0, 0, n - 1, pos);
                if (what == UNCHANGED)
                    out.println(b[pos]);
                else
                    out.println(a[pos + what]);
            }
        }
    }

    private int getFromTree(int[] tree, int root, int rl, int rr, int pos) {
        if (tree[root] != MIXED) return tree[root];
        int rm = (rl + rr) / 2;
        if (pos > rm)
            return getFromTree(tree, root * 2 + 2, rm + 1, rr, pos);
        else
            return getFromTree(tree, root * 2 + 1, rl, rm, pos);
    }

    private void updateTree(int[] tree, int root, int rl, int rr, int left, int right, int value) {
        if (left > right) return;
        if (rl == left && rr == right) {
            tree[root] = value;
            return;
        }
        if (tree[root] != MIXED) {
            tree[root * 2 + 1] = tree[root];
            tree[root * 2 + 2] = tree[root];
            tree[root] = MIXED;
        }
        int rm = (rl + rr) / 2;
        updateTree(tree, root * 2 + 1, rl, rm, left, Math.min(right, rm), value);
        updateTree(tree, root * 2 + 2, rm + 1, rr, Math.max(rm + 1, left), right, value);
    }

    private void initTree(int[] tree, int root, int rl, int rr) {
        if (rl == rr) {
            tree[root] = UNCHANGED;
        } else {
            int rm = (rl + rr) / 2;
            initTree(tree, root * 2 + 1, rl, rm);
            initTree(tree, root * 2 + 2, rm + 1, rr);
            tree[root] = MIXED;
        }
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