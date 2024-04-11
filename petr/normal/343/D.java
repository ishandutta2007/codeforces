import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
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
    int[] first;
    int[] dest;
    int[] next;
    int[] left;
    int[] right;
    int[] parent;
    int ptr;
    boolean[] haveAny;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        first = new int[n];
        dest = new int[2 * (n - 1)];
        next = new int[2 * (n - 1)];
        Arrays.fill(first, -1);
        for (int i = 0; i < n - 1; ++i) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            dest[i * 2] = b;
            next[i * 2] = first[a];
            first[a] = i * 2;
            dest[i * 2 + 1] = a;
            next[i * 2 + 1] = first[b];
            first[b] = i * 2 + 1;
        }
        ptr = 0;
        left = new int[n];
        parent = new int[n];
        right = new int[n];
        dfs(0, -1);
        if (ptr != n) throw new RuntimeException();
        haveAny = new boolean[4 * n + 10];
        Arrays.fill(haveAny, true);
        int q = in.nextInt();
        for (int i = 0; i < q; ++i) {
            int c = in.nextInt();
            int v = in.nextInt() - 1;
            switch (c) {
                case 1:
                    if (testSegment(0, 0, n - 1, left[v], right[v] - 1)) {
                        if (parent[v] >= 0)
                            setPoint(0, 0, n - 1, left[parent[v]]);
                    }
                    clearSegment(0, 0, n - 1, left[v], right[v] - 1);
                    break;

                case 2:
                    setPoint(0, 0, n - 1, left[v]);
                    break;

                case 3:
                    if (testSegment(0, 0, n - 1, left[v], right[v] - 1)) {
                        out.println(0);
                    } else {
                        out.println(1);
                    }
                    break;

                default:
                    throw new RuntimeException();
            }
        }
    }

    private boolean testSegment(int root, int rl, int rr, int left, int right) {
        if (left > right) return false;
        if (!haveAny[root]) return false;
        if (rl == left && rr == right) {
            return true;
        }
        int rm = (rl + rr) / 2;
        return testSegment(root * 2 + 1, rl, rm, left, Math.min(right, rm)) ||
            testSegment(root * 2 + 2, rm + 1, rr, Math.max(left, rm + 1), right);
    }

    private void setPoint(int root, int rl, int rr, int pos) {
        if (rl == pos && rr == pos) {
            haveAny[root] = true;
            return;
        }
        if (!haveAny[root]) {
            haveAny[root * 2 + 1] = false;
            haveAny[root * 2 + 2] = false;
        }
        int rm = (rl + rr) / 2;
        if (pos <= rm)
            setPoint(root * 2 + 1, rl, rm, pos);
        else
            setPoint(root * 2 + 2, rm + 1, rr, pos);
        haveAny[root] = haveAny[root * 2 + 1] || haveAny[root * 2 + 2];
    }

    private void clearSegment(int root, int rl, int rr, int left, int right) {
        if (left > right) return;
        if (!haveAny[root]) return;
        if (left == rl && right == rr) {
            haveAny[root] = false;
            return;
        }
        int rm = (rl + rr) / 2;
        clearSegment(root * 2 + 1, rl, rm, left, Math.min(right, rm));
        clearSegment(root * 2 + 2, rm + 1, rr, Math.max(left, rm + 1), right);
        haveAny[root] = haveAny[root * 2 + 1] || haveAny[root * 2 + 2];
    }

    private void dfs(int root, int parent) {
        this.parent[root] = parent;
        left[root] = ptr;
        ++ptr;
        int cur = first[root];
        while (cur >= 0) {
            if (dest[cur] != parent)
                dfs(dest[cur], root);
            cur = next[cur];
        }
        right[root] = ptr;
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