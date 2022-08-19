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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i)
            a[i] = in.nextInt();
        int[] b = new int[n];
        int[] c = new int[n];
        int res = (int) -1e9;
        for (int l = 0; l < n; ++l)
            for (int r = l; r < n; ++r) {
                int bcnt = 0;
                int ccnt = 0;
                for (int i = 0; i < n; ++i)
                    if (l <= i && i <= r)
                        b[bcnt++] = a[i];
                    else
                        c[ccnt++] = a[i];
                Arrays.sort(b, 0, bcnt);
                Arrays.sort(c, 0, ccnt);
                int sum = 0;
                for (int i = 0; i < bcnt; ++i) sum += b[i];
                res = Math.max(res, sum);
                for (int swaps = 0; swaps < k && swaps < bcnt && swaps < ccnt; ++swaps) {
                    sum -= b[swaps];
                    sum += c[ccnt - 1 - swaps];
                    res = Math.max(res, sum);
                }
            }
        out.println(res);
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