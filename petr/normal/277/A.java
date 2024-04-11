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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        boolean[][] know = new boolean[n][m];
        boolean any = false;
        for (int i = 0; i < n; ++i) {
            int cnt = in.nextInt();
            for (int j = 0; j < cnt; ++j) {
                know[i][in.nextInt() - 1] = true;
                any = true;
            }
        }
        boolean[][] g = new boolean[n][n];
        for (int i = 0; i < n; ++i)
            g[i][i] = true;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < m; ++k) if (know[i][k] && know[j][k]) g[i][j] = true;
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    g[i][j] |= g[i][k] && g[k][j];
        boolean[] mark = new boolean[n];
        int res = any ? -1 : 0;
        for (int i = 0; i < n; ++i) if (!mark[i]) {
            for (int j = 0; j < n; ++j) if (g[i][j]) mark[j] = true;
            ++res;
        }
        out.println(res);
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