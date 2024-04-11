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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int height = in.nextInt();
        int width = in.nextInt();
        int k = in.nextInt();
        int p = in.nextInt();
        int[] rowSums = new int[height];
        int[] colSums = new int[width];
        for (int row = 0; row < height; ++row)
            for (int col = 0; col < width; ++col) {
                int a = in.nextInt();
                rowSums[row] += a;
                colSums[col] += a;
            }
        long[] bestRow = getBest(rowSums, k, p * width);
        long[] bestCol = getBest(colSums, k, p * height);
        partialize(bestRow);
        partialize(bestCol);
        long res = Long.MIN_VALUE;
        for (int nrow = 0; nrow <= k; ++nrow) {
            res = Math.max(res, bestRow[nrow] + bestCol[k - nrow] - nrow * (long) (k - nrow) * p);
        }
        out.println(res);
    }

    private void partialize(long[] a) {
        for (int i = 1; i < a.length; ++i) {
            a[i] += a[i - 1];
        }
    }

    private long[] getBest(int[] sums, int k, int p) {
        long[] res = new long[k + 1];
        int max = 0;
        for (int x : sums) max = Math.max(max, x);
        int[] times = new int[max + 1];
        for (int x : sums) ++times[x];
        int ptr = 0;
        if (ptr >= k) return res;
        while (true) {
            while (max >= p && times[max] == 0) --max;
            if (max < p) break;
            res[++ptr] = max;
            if (ptr >= k) return res;
            --times[max];
            ++times[max - p];
        }
        int startPtr = ptr;
        for (int val = max; val >= 0; --val) {
            for (int i = times[val] - 1; i >= 0; --i) {
                res[++ptr] = val;
                if (ptr >= k) return res;
            }
        }
        int period = ptr - startPtr;
        while (true) {
            ++ptr;
            res[ptr] = res[ptr - period] - p;
            if (ptr >= k) return res;
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