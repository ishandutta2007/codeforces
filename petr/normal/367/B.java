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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int p = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) a[i] = in.nextInt();
        int[] b = new int[m];
        for (int i = 0; i < m; ++i) b[i] = in.nextInt();
        int[] all = new int[n + m];
        System.arraycopy(a, 0, all, 0, n);
        System.arraycopy(b, 0, all, n, m);
        Arrays.sort(all);
        int cnt = 0;
        for (int i = 0; i < all.length; ++i) {
            if (i == 0 || all[i] != all[i - 1]) {
                all[cnt++] = all[i];
            }
        }
        all = Arrays.copyOf(all, cnt);
        for (int i = 0; i < n; ++i) a[i] = Arrays.binarySearch(all, a[i]);
        for (int i = 0; i < m; ++i) b[i] = Arrays.binarySearch(all, b[i]);
        int[] balance = new int[cnt];
        for (int i = 0; i < m; ++i) ++balance[b[i]];
        int numnonzero = 0;
        for (int x : balance) if (x != 0) ++numnonzero;
        int[] res = new int[n];
        int rescnt = 0;
        for (int start = 0; start < Math.min(n, p); ++start) {
            int at;
            int first = -1;
            int count = 0;
            for (at = start; at < n; at += p) {
                if (balance[a[at]] == 0) ++numnonzero;
                --balance[a[at]];
                if (balance[a[at]] == 0) --numnonzero;
                ++count;
                if (count == 1)
                    first = at;
                if (count > m) {
                    if (balance[a[first]] == 0) ++numnonzero;
                    ++balance[a[first]];
                    if (balance[a[first]] == 0) --numnonzero;
                    first += p;
                    --count;
                }
                if (count == m && numnonzero == 0) {
                    res[rescnt++] = at + 1 - (m - 1) * p;
                }
            }
            for (; first < n; first += p) {
                if (balance[a[first]] == 0) ++numnonzero;
                ++balance[a[first]];
                if (balance[a[first]] == 0) --numnonzero;
            }
        }
        res = Arrays.copyOf(res, rescnt);
        Arrays.sort(res);
        out.println(res.length);
        for (int i = 0; i < res.length; ++i) {
            if (i > 0) out.print(" ");
            out.print(res[i]);
        }
        out.println();
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