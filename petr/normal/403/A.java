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
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int p = in.nextInt();
        boolean[][] niceEdge = new boolean[n][n];
        for (int i = 0; i < n; ++i) {
            int j = (i + 1) % n;
            if (niceEdge[i][j]) throw new RuntimeException();
            niceEdge[i][j] = niceEdge[j][i] = true;
            if (n % 2 != 0) {
                j = (i + 2) % n;
                if (niceEdge[i][j]) throw new RuntimeException();
                niceEdge[i][j] = niceEdge[j][i] = true;
            } else {
                if (i < n / 2) {
                    j = i + n / 2;
                    if (i == n / 2 - 1) --j;
                    if (i == n / 2 - 2) ++j;
                    if (niceEdge[i][j]) throw new RuntimeException();
                    niceEdge[i][j] = niceEdge[j][i] = true;
                } else {
                    j = i - n / 2 + 1;
                    if (i == n - 1) --j;
                    if (i == n - 2) j = 0;
                    if (niceEdge[i][j]) {
                        throw new RuntimeException();
                    }
                    niceEdge[i][j] = niceEdge[j][i] = true;
                }
            }
        }
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j) {
                if (niceEdge[i][j] || p > 0) {
                    out.println((i + 1) + " " + (j + 1));
                    if (!niceEdge[i][j]) --p;
                }
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