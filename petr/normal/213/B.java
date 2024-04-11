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
    static final int MODULO = (int) (1e9 + 7);

	public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[] a = new int[10];
        for (int i = 0; i < 10; ++i) {
            a[i] = in.nextInt();
        }
        int[][] comb = new int[n][n];
        comb[0][0] = 1;
        for (int i = 1; i < n; ++i) {
            comb[i][0] = 1;
            for (int j = 1; j < n; ++j) {
                comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MODULO;
            }
        }
        int res = 0;
        for (int firstDigit = 1; firstDigit < 10; ++firstDigit) {
            int[] minCount = a.clone();
            --minCount[firstDigit];
            if (minCount[firstDigit] < 0) minCount[firstDigit] = 0;
            int[] ways = new int[n];
            ways[0] = 1;
            for (int digit = 0; digit < 10; ++digit) {
                int[] nways = new int[n];
                for (int oldLen = 0; oldLen < n; ++oldLen) if (ways[oldLen] != 0) {
                    for (int curCount = minCount[digit]; curCount + oldLen < n; ++curCount) {
                        nways[oldLen + curCount] = (int) ((nways[oldLen + curCount] + ways[oldLen] * (long) comb[oldLen + curCount][curCount]) % MODULO);
                    }
                }
                ways = nways;
            }
            for (int x : ways) {
                res = (res + x) % MODULO;
            }
        }
        out.println(res);
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