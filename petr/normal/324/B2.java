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
		Shaving solver = new Shaving();
		solver.solve(1, in, out);
		out.close();
	}
}

class Shaving {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) a[i] = in.nextInt() - 1;
        int[] inv = new int[n];
        for (int i = 0; i < n; ++i) inv[a[i]] = i;
        int[] starts = new int[n];
        for (int i = 1; i < n; ++i)
            if (inv[i] < inv[i - 1]) {
                update(starts, i, 1);
            }
        int q = in.nextInt();
        for (int qi = 0; qi < q; ++qi) {
            int kind = in.nextInt();
            int x = in.nextInt() - 1;
            int y = in.nextInt() - 1;
            if (kind == 1) {
                out.println(1 + get(starts, y) - get(starts, x));
            } else {
                int u = a[x];
                int v = a[y];
                int[] cands = new int[4];
                int ncands = 0;
                if (u > 0) ncands = add(cands, ncands, u);
                if (u + 1 < n) ncands = add(cands, ncands, u + 1);
                if (v > 0) ncands = add(cands, ncands, v);
                if (v + 1 < n) ncands = add(cands, ncands, v + 1);
                for (int i = 0; i < ncands; ++i) {
                    if (inv[cands[i]] < inv[cands[i] - 1])
                        update(starts, cands[i], -1);
                }
                a[x] = v;
                a[y] = u;
                inv[a[x]] = x;
                inv[a[y]] = y;
                for (int i = 0; i < ncands; ++i) {
                    if (inv[cands[i]] < inv[cands[i] - 1])
                        update(starts, cands[i], 1);
                }
            }
        }
    }

    private int add(int[] cands, int ncands, int v) {
        for (int i = 0; i < ncands; ++i) if (cands[i] == v) return ncands;
        cands[ncands] = v;
        return ncands + 1;
    }

    private int get(int[] starts, int at) {
        int res = 0;
        while (at >= 0) {
            res += starts[at];
            at = (at & (at + 1)) - 1;
        }
        return res;
    }

    private void update(int[] starts, int at, int by) {
        while (at < starts.length) {
            starts[at] += by;
            at |= (at + 1);
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