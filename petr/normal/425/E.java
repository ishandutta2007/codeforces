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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    static final int MODULO = (int) 1e9 + 7;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        int[][] count = new int[n + 1][k + 1];
        int[] p2 = new int[n * n + 1];
        p2[0] = 1;
        for (int i = 1; i < p2.length; ++i) {
            p2[i] = 2 * p2[i - 1];
            if (p2[i] >= MODULO) p2[i] -= MODULO;
        }
        count[0][0] = 1;
        for (int pos = 1; pos <= n; ++pos) {
            for (int pk = 0; pk < k; ++pk) {
                long got = 0;
                for (int ppos = 0; ppos < pos; ++ppos) {
                    int old = count[ppos][pk];
                    if (old != 0) {
                        int ways = p2[(pos - ppos) * (ppos + 1)] - p2[(pos - ppos) * ppos];
                        if (ways < 0) ways += MODULO;
                        got += old * (long) ways;
                        if (got >= (long) 7e18) got %= MODULO;
                    }
                }
                count[pos][pk + 1] = (int) (got % MODULO);
            }
        }
        long res = 0;
        for (int pos = 0; pos <= n; ++pos) {
            int old = count[pos][k];
            if (old != 0) {
                int ways = p2[(n - pos) * pos];
                res = res + old * (long) ways;
                if (res >= (long) 7e18) res %= MODULO;
            }
        }
        out.println(res % MODULO);
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