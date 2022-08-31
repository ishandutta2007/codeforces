import java.util.Arrays;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.StringTokenizer;

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
		TaskE1 solver = new TaskE1();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE1 {
    static final int INF = (int) 2e9;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        int[] data = new int[n];
        for (int i = 0; i < n; ++i) {
            data[i] = in.nextInt();
        }
        int[][] max = new int[2][k + 1];
        int[][][] umax = new int[2][2][k + 1];
        for (int[] b : max) Arrays.fill(b, -INF);
        for (int[][] a : umax) for (int[] b : a) Arrays.fill(b, -INF);
        max[0][0] = 0;
        for (int right = 1; right <= n; ++right) {
            for (int mode = 0; mode < 2; ++mode) {
                for (int u = 1; u <= k; ++u) {
                    for (int pmode = 0; pmode < 2; ++pmode) {
                        int mult = (u == 1 ? 0 : 2 * pmode - 1);
                        mult += (u == k ? 0 : 1 - 2 * mode);
                        umax[mode][pmode][u] = Math.max(umax[mode][pmode][u], max[pmode][u - 1]) + mult * data[right - 1];
                    }
                }
            }
            for (int mode = 0; mode < 2; ++mode) {
                for (int u = 0; u <= k; ++u) {
                    max[mode][u] = Math.max(max[mode][u], Math.max(umax[mode][0][u], umax[mode][1][u]));
                }
            }
        }
        int res = -INF;
        for (int mode = 0; mode < 2; ++mode)
            res = Math.max(res, max[mode][k]);
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