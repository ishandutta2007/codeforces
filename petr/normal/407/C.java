import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.math.BigInteger;
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
    static final int MODULO = (int) (1e9 + 7);
    static final int MAX_POWER = 101;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
        }
        int[] inv = new int[MAX_POWER];
        inv[0] = 1;
        int fact = 1;
        for (int i = 1; i < MAX_POWER; ++i) {
            fact = (int) (fact * (long) i % MODULO);
            inv[i] = BigInteger.valueOf(fact).modInverse(BigInteger.valueOf(MODULO)).intValue();
        }
        int[][] comb = new int[MAX_POWER][MAX_POWER];
        comb[0][0] = 1;
        for (int i = 1; i < MAX_POWER; ++i) {
            comb[i][0] = 1;
            for (int j = 1; j < MAX_POWER; ++j) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MODULO;
            }
        }

        int[][] polyDelta = new int[n + 1][MAX_POWER];
        int[] tmp = new int[MAX_POWER];
        for (int i = 0; i < m; ++i) {
            int l = in.nextInt() - 1;
            int r = in.nextInt() - 1;
            int k = in.nextInt();

            long prod = inv[k];
            for (int j = 0; j <= k; ++j) {
                tmp[k - j] = (int) (comb[k][j] * prod % MODULO);
                prod = prod * (-l + k - j) % MODULO;
                if (prod < 0) prod += MODULO;
            }

            for (int j = 0; j <= k; ++j) {
                polyDelta[l][j] += tmp[j];
                if (polyDelta[l][j] >= MODULO)
                    polyDelta[l][j] -= MODULO;
            }
            for (int j = 0; j <= k; ++j) {
                polyDelta[r + 1][j] -= tmp[j];
                if (polyDelta[r + 1][j] < 0)
                    polyDelta[r + 1][j] += MODULO;
            }
        }

        Arrays.fill(tmp, 0);
        for (int i = 0; i < n; ++i) {
            long extra = 0;
            long prod = 1;
            for (int j = 0; j < MAX_POWER; ++j) {
                tmp[j] += polyDelta[i][j];
                if (tmp[j] >= MODULO)
                    tmp[j] -= MODULO;
                extra = (extra + prod * tmp[j]) % MODULO;
                prod = prod * (i - j) % MODULO;
                if (prod < 0) prod += MODULO;
            }
            if (i > 0) out.print(" ");
            extra = (extra + a[i]) % MODULO;
            out.print(extra);
        }
        out.println();
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