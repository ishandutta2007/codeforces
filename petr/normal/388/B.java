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
        int k = in.nextInt();
        int n = 3 * 30 + 1 + 2 * 30 + 1;
        boolean[][] g = new boolean[n][n];
        int cur = 0;
        for (int i = 1; i <= 30; ++i) {
            int a = 2 * i;
            int b = 2 * i + 1;
            g[cur][a] = g[a][cur] = true;
            g[a][b] = g[b][a] = true;
            cur = b;
        }
        cur = 1;
        for (int i = 1; i <= 30; ++i) {
            int a = 59 + 3 * i;
            int b = 60 + 3 * i;
            int c = 61 + 3 * i;
            g[cur][a] = g[a][cur] = true;
            g[cur][b] = g[b][cur] = true;
            g[c][a] = g[a][c] = true;
            g[c][b] = g[b][c] = true;
            cur = c;
        }
        for (int bit = 0; bit <= 30; ++bit)
            if ((k & (1 << bit)) != 0) {
                int a;
                if (bit == 30) a = 0; else a = 61 - 2 * bit;
                int b;
                if (bit == 0) b = 1; else b = 61 + 3 * bit;
                g[a][b] = g[b][a] = true;
            }
        out.println(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) out.print(g[i][j] ? 'Y' : 'N');
            out.println();
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