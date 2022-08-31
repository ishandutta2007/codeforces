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
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int rows = in.nextInt();
        int cols = in.nextInt();
        int n = in.nextInt();
        int[] comp = new int[2 * rows * cols];
        int total = rows * cols;
        Arrays.fill(comp, -1);
        int[] a1 = new int[10];
        int[] a2 = new int[10];
        int res = 0;
        for (int step = 0; step < n; ++step) {
            int r = in.nextInt() - 1;
            int c = in.nextInt() - 1;
            comp[c * rows + r] = c * rows + r;
            comp[c * rows + r + total] = c * rows + r + total;
            int na1 = 0;
            int na2 = 0;
            for (int dr = -1; dr <= 1; ++dr)
                for (int dc = -1; dc <= 1; ++dc) {
                    int r1 = r + dr;
                    int c1 = c + dc;
                    if (c1 < 0) c1 += 2 * cols;
                    if (c1 >= 2 * cols) c1 -= 2 * cols;
                    if (r1 < 0 || r1 >= rows || c1 < 0 || c1 >= 2 * cols || comp[c1 * rows + r1] < 0) {
                    } else {
                        a1[na1++] = get(comp, c1 * rows + r1);
                    }
                    int r2 = r + dr;
                    int c2 = c + dc + cols;
                    if (c2 < 0) c2 += 2 * cols;
                    if (c2 >= 2 * cols) c2 -= 2 * cols;
                    if (r2 < 0 || r2 >= rows || c2 < 0 || c2 >= 2 * cols || comp[c2 * rows + r2] < 0) {
                    } else {
                        a2[na2++] = get(comp, c2 * rows + r2);
                    }
                }
            boolean ok = true;
            outer: for (int i = 0; i < na1; ++i)
                for (int j = 0; j < na2; ++j)
                    if (a1[i] == a2[j]) {
                        ok = false;
                        break outer;
                    }
            if (ok) {
                for (int i = 1; i < na1; ++i)
                    comp[a1[i]] = a1[0];
                for (int i = 1; i < na2; ++i)
                    comp[a2[i]] = a2[0];
                ++res;
            } else {
                comp[c * rows + r] = -1;
                comp[c * rows + r + total] = -1;
            }
        }
        out.println(res);
    }

    private int get(int[] comp, int at) {
        int root = at;
        while (comp[root] != root) root = comp[root];
        while (comp[at] != root) {
            int nat = comp[at];
            comp[at] = root;
            at = nat;
        }
        return root;
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