import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
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
    static class Vertex {
        List<Vertex> adj = new ArrayList<Vertex>(1);
        List<Vertex> reqPair = new ArrayList<Vertex>();
        int left;
        int right;
        int res;
    }

    Vertex[] seq;
    int seqPtr;
    int[] sums;
    int[] countNonZero;
    int n;

	public void solve(int testNumber, InputReader in, PrintWriter out) {
        n = in.nextInt();
        int m = in.nextInt();
        Vertex[] v = new Vertex[n];
        for (int i = 0; i < n; ++i)
            v[i] = new Vertex();
        for (int i = 0; i < n - 1; ++i) {
            Vertex a = v[in.nextInt() - 1];
            Vertex b = v[in.nextInt() - 1];
            a.adj.add(b);
            b.adj.add(a);
        }
        seq = new Vertex[n];
        seqPtr = 0;
        buildSeq(v[0], null);
        if (seqPtr != n) throw new RuntimeException();
        for (int i = 0; i < m; ++i) {
            Vertex a = v[in.nextInt() - 1];
            Vertex b = v[in.nextInt() - 1];
            a.reqPair.add(b);
            b.reqPair.add(a);
        }
        sums = new int[4 * n + 10];
        countNonZero = new int[4 * n + 10];
        walk(v[0], null);
        for (int i = 0; i < n; ++i) {
            if (i > 0) out.print(" ");
            out.print(Math.max(0, v[i].res - 1));
        }
        out.println();
	}

    private void walk(Vertex root, Vertex parent) {
        if (root.reqPair.size() > 0) {
            change(0, 0, n - 1, root.left, root.right, 1);
            for (Vertex other : root.reqPair)
                change(0, 0, n - 1, other.left, other.right, 1);
        }
        root.res = countNonZero[0];
        for (Vertex v : root.adj)
            if (v != parent)
                walk(v, root);
        if (root.reqPair.size() > 0) {
            change(0, 0, n - 1, root.left, root.right, -1);
            for (Vertex other : root.reqPair)
                change(0, 0, n - 1, other.left, other.right, -1);
        }
    }

    private void change(int root, int rl, int rr, int left, int right, int by) {
        if (left > right) return;
        if (rl == left && rr == right) {
            sums[root] += by;
            if (sums[root] > 0)
                countNonZero[root] = rr - rl + 1;
            else {
                if (rl == rr)
                    countNonZero[root] = 0;
                else
                    countNonZero[root] = countNonZero[root * 2 + 1] + countNonZero[root * 2 + 2];
            }
            return;
        }
        int rm = (rl + rr) / 2;
        change(root * 2 + 1, rl, rm, left, Math.min(rm, right), by);
        change(root * 2 + 2, rm + 1, rr, Math.max(left, rm + 1), right, by);
        if (sums[root] == 0) {
            countNonZero[root] = countNonZero[root * 2 + 1] + countNonZero[root * 2 + 2];
        }
    }

    private void buildSeq(Vertex root, Vertex parent) {
        root.left = seqPtr;
        seq[seqPtr++] = root;
        for (Vertex v : root.adj)
            if (v != parent)
                buildSeq(v, root);
        root.right = seqPtr - 1;
    }
}

class InputReader {
    BufferedReader reader;
    StringTokenizer tokenizer;

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