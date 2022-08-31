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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();
        double[][] comb = new double[n + 1][n + 1];
        comb[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            comb[i][0] = 1;
            for (int j = 1; j <= n; ++j) {
                comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
            }
        }
        double[] prOne = new double[k + 1];
        prOne[0] = 1.0;
        for (int i = 1; i <= k; ++i) {
            prOne[i] = prOne[i - 1] * (k - i + 1) / (m - i + 1);
        }
        double res = 0;
        for (int sum = 2 * n; sum >= 0; --sum) {
            for (int nrow = 0; nrow <= n; ++nrow) {
                int ncol = sum - nrow;
                if (ncol < 0 || ncol > n) continue;
                int totalCells = nrow * n + ncol * n - nrow * ncol;
                if (totalCells > k) continue;
                res += comb[n][nrow] * comb[n][ncol] * prOne[totalCells];
            }
        }
        if (res > 1e99) res = 1e99;
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