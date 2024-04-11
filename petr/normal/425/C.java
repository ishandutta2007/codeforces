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
    static final int MAX_NUM = (int) (1e5 + 1);
    static final int INF = (int) 1e9;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int s = in.nextInt();
        int e = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) a[i] = in.nextInt();
        int[] b = new int[m];
        for (int i = 0; i < m; ++i) b[i] = in.nextInt();
        int maxMoney = s / e + 1;
        int[] best = new int[maxMoney];
        Arrays.fill(best, INF);
        best[0] = 0;
        int[][] first = new int[maxMoney][MAX_NUM];
        for (int money = 0; money < maxMoney; ++money) Arrays.fill(first[money], INF);
        for (int i = m - 1; i >= 0; --i) first[0][b[i]] = i;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int oldMoney = maxMoney - 2; oldMoney >= 0; --oldMoney) {
                int nxt = first[oldMoney][a[i]];
                if (nxt + 1 < best[oldMoney + 1]) {
                    for (int j = Math.min(m - 1, best[oldMoney + 1] - 1); j >= nxt + 1; --j) {
                        first[oldMoney + 1][b[j]] = j;
                    }
                    best[oldMoney + 1] = nxt + 1;
                    if (e * (oldMoney + 1) + (i + 1) + (nxt + 1) <= s) {
                        res = Math.max(res, oldMoney + 1);
                    }
                }
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