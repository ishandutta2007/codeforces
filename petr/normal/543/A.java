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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int b = in.nextInt();
        int mod = in.nextInt();
        int[][] ways = new int[m + 1][b + 1];
        ways[0][0] = 1 % mod;
        for (int ii = 0; ii < n; ++ii) {
            int a = in.nextInt();
            for (int i = 0; i < m; ++i) {
                for (int oe = 0; oe <= b - a; ++oe) if (ways[i][oe] != 0) {
                    ways[i + 1][oe + a] += ways[i][oe];
                    if (ways[i + 1][oe + a] >= mod) ways[i + 1][oe + a] -= mod;
                }
            }
        }
        int res = 0;
        for (int i = 0; i <= b; ++i) res = (res + ways[m][i]) % mod;
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