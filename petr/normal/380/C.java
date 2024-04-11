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
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        String s = in.nextLine();
        int n = s.length();
        int[] balance = new int[n + 1];
        balance[0] = 0;
        for (int i = 0; i < n; ++i) {
            balance[i + 1] = balance[i] + (s.charAt(i) == '(' ? 1 : -1);
        }
        int[] minTree = new int[4 * balance.length + 10];
        initMinTree(0, 0, balance.length - 1, balance, minTree);
        int m = in.nextInt();
        for (int qi = 0; qi < m; ++qi) {
            int l = in.nextInt() - 1;
            int r = in.nextInt();
            int minBalance = getMin(minTree, 0, 0, balance.length - 1, l, r);
            int leftBalance = balance[l];
            int rightBalance = balance[r];
            int skipOpens = leftBalance - minBalance;
            int skipCloses = rightBalance - leftBalance + skipOpens;
            out.println(r - l - skipOpens - skipCloses);
        }
    }

    private int getMin(int[] minTree, int root, int rl, int rr, int l, int r) {
        if (l > r) return Integer.MAX_VALUE;
        if (l == rl && r == rr) return minTree[root];
        int rm = (rl + rr) / 2;
        return Math.min(
                getMin(minTree, root * 2 + 1, rl, rm, l, Math.min(rm, r)),
                getMin(minTree, root * 2 + 2, rm + 1, rr, Math.max(rm + 1, l), r)
            );
    }

    private void initMinTree(int root, int rl, int rr, int[] balance, int[] minTree) {
        if (rl == rr) {
            minTree[root] = balance[rl];
            return;
        }
        int rm = (rl + rr) / 2;
        initMinTree(root * 2 + 1, rl, rm, balance, minTree);
        initMinTree(root * 2 + 2, rm + 1, rr, balance, minTree);
        minTree[root] = Math.min(minTree[root * 2 + 1], minTree[root * 2 + 2]);
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

    public String nextLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    }