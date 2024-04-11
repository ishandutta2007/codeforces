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
        int n = in.nextInt();
        int m = in.nextInt();
        int[] x = new int[m];
        int[] y = new int[m];
        for (int i = 0; i < m; ++i) {
            x[i] = in.nextInt() - 1;
            y[i] = in.nextInt() - 1;
        }
        int[][] cprefix = new int[m + 1][n];
        int[][] csuffix = new int[m + 1][n];
        Arrays.fill(cprefix[0], -1);
        for (int i = 0; i < m; ++i) {
            System.arraycopy(cprefix[i], 0, cprefix[i + 1], 0, n);
            merge(cprefix[i + 1], x[i], y[i]);
        }
        Arrays.fill(csuffix[0], -1);
        for (int i = 0; i < m; ++i) {
            System.arraycopy(csuffix[i], 0, csuffix[i + 1], 0, n);
            merge(csuffix[i + 1], x[m - 1 - i], y[m - 1 - i]);
        }
        int k = in.nextInt();
        for (int i = 0; i < k; ++i) {
            int l = in.nextInt() - 1;
            int r = in.nextInt() - 1;
            out.println(solveit(n, cprefix[l], csuffix[m - 1 - r]));
        }
    }

    private int solveit(int n, int[] a1, int[] a2) {
        a1 = a1.clone();
        for (int i = 0; i < n; ++i) {
            if (a2[i] >= 0) merge(a1, i, a2[i]);
        }
        int res = 0;
        for (int x : a1) if (x < 0) ++res;
        return res;
    }

    private void merge(int[] comps, int a, int b) {
        a = get(comps, a);
        b = get(comps, b);
        if (a != b) comps[a] = b;
    }

    private int get(int[] comps, int x) {
        if (comps[x] < 0) return x;
        comps[x] = get(comps, comps[x]);
        return comps[x];
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