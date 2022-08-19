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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {

    public static final int INF = (int) 1e9;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        String[] s = new String[n];
        for (int i = 0; i < n; ++i) s[i] = in.next();
        int[][] a = new int[n][m];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                a[i][j] = in.nextInt();
            }
        int[] best = new int[1 << n];
        Arrays.fill(best, INF);
        best[0] = 0;
        for (int col = 0; col < m; ++col) {
            int[] mask = new int[26];
            int[] total = new int[26];
            int[] max = new int[26];
            for (int i = 0; i < n; ++i) {
                int x = s[i].charAt(col) - 'a';
                mask[x] |= 1 << i;
                total[x] += a[i][col];
                max[x] = Math.max(max[x], a[i][col]);
                int cost = a[i][col];
                int cmask = 1 << i;
                for (int old = best.length - 1; old >= 0; --old) if (best[old] < INF) {
                    best[old | cmask] = Math.min(best[old | cmask], best[old] + cost);
                }
            }
            for (int t = 0; t < 26; ++t) if (mask[t] != 0) {
                int cost = total[t] - max[t];
                int cmask = mask[t];
                for (int old = best.length - 1; old >= 0; --old) if (best[old] < INF) {
                    best[old | cmask] = Math.min(best[old | cmask], best[old] + cost);
                }
            }
        }
        out.println(best[best.length - 1]);
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