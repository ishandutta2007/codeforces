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
        int n = in.nextInt();
        int m = in.nextInt();
        int q = in.nextInt();
        int[][] field = new int[n][m];
        for (int i = 0; i < n; ++i) {
            String s = in.next();
            for (int j = 0; j < m; ++j) {
                field[i][j] = s.charAt(j) - '0';
            }
        }
        int[][] sum = new int[n + 1][m + 1];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + field[i][j];
        int[][][][] ways = new int[n + 1][m + 1][n + 1][m + 1];
        for (int a = 0; a < n; ++a)
            for (int b = 0; b < m; ++b)
                for (int c = a; c < n; ++c)
                    for (int d = b; d < m; ++d)
                        if (sum[c + 1][d + 1] - sum[a][d + 1] - sum[c + 1][b] + sum[a][b] == 0) {
                            ++ways[a][b][c][d];
                        }
        for (int a = 0; a < n; ++a)
            for (int b = 0; b < m; ++b)
                for (int c = a; c < n; ++c)
                    for (int d = b; d + 1 < m; ++d)
                        ways[a][b][c][d + 1] += ways[a][b][c][d];
        for (int a = 0; a < n; ++a)
            for (int b = 0; b < m; ++b)
                for (int c = a; c + 1 < n; ++c)
                    for (int d = b; d < m; ++d)
                        ways[a][b][c + 1][d] += ways[a][b][c][d];
        for (int a = n - 1; a >= 1; --a)
            for (int b = 0; b < m; ++b)
                for (int c = a; c < n; ++c)
                    for (int d = b; d < m; ++d)
                        ways[a - 1][b][c][d] += ways[a][b][c][d];
        for (int a = n - 1; a >= 0; --a)
            for (int b = m - 1; b >= 1; --b)
                for (int c = a; c < n; ++c)
                    for (int d = b; d < m; ++d)
                        ways[a][b - 1][c][d] += ways[a][b][c][d];
        for (int i = 0; i < q; ++i) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            int c = in.nextInt() - 1;
            int d = in.nextInt() - 1;
            out.println(ways[a][b][c][d]);
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