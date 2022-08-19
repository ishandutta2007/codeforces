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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    static final int MODULO = (int) (1e9 + 7);

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int numTests = in.nextInt();
        int[] fact = new int[1001];
        fact[0] = 1;
        int[][] extras = new int[1001][1001];
        Arrays.fill(extras[0], 1);
        for (int k = 1; k <= 1000; ++k) {
            for (int left = 0; left <= 1000; ++left) {
                for (int times = 0; times * k <= left; ++times) {
                    extras[k][left] += extras[k - 1][left - times * k];
                    if (extras[k][left] >= MODULO) extras[k][left] -= MODULO;
                }
                if (left > 0) {
                    extras[k][left] += extras[k][left - 1];
                    if (extras[k][left] >= MODULO) extras[k][left] -= MODULO;
                }
            }
        }
        for (int i = 1; i < fact.length; ++i) fact[i] = (int) (i * (long) fact[i - 1] % MODULO);
        for (int testId = 0; testId < numTests; ++testId) {
            int n = in.nextInt();
            int k = in.nextInt();
            int forSure = k * (k + 1) / 2;
            if (forSure > n) {
                out.println(0);
                continue;
            }
            long res = fact[k];
            res = res * extras[k][n - forSure] % MODULO;
            out.println(res);
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