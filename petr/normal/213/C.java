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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    static final int INF = (int) (1e9);

	public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[][] a = new int[n][n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                a[i][j] = in.nextInt();
        int[][] best = new int[n][n];
        int[][] best1 = new int[n][n];
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            Arrays.fill(best[i], -INF);
        }
        for (int i = 0; i < n; ++i) {
            sum += a[0][i];
            for (int j = 0; j <= i; ++j) {
                best[j][i] = sum;
            }
        }
        for (int row = 1; row < n; ++row) {
            for (int[] x : best1) Arrays.fill(x, -INF);
            for (int bottom = 0; bottom < n; ++bottom) {
                if (bottom > 0) {
                    for (int top = bottom - 1; top < n; ++top) {
                        int oldBest = best[bottom - 1][top];
                        int ntop = Math.max(top, bottom);
                        best[bottom][ntop] = Math.max(best[bottom][ntop], oldBest + a[row][bottom - 1]);
                    }
                }
                best1[bottom][bottom] = Math.max(best1[bottom][bottom], best[bottom][bottom] + a[row][bottom]);
                for (int top = bottom + 1; top < n; ++top) {
                    best1[bottom][top] = Math.max(best1[bottom][top], best1[bottom][top - 1] + a[row][top]);
                    best1[bottom][top] = Math.max(best1[bottom][top], best[bottom][top] + a[row][bottom] + a[row][top]);
                }
            }
            int[][] tmp = best;
            best = best1;
            best1 = tmp;
        }
        out.println(best[n - 1][n - 1]);
    }
}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

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