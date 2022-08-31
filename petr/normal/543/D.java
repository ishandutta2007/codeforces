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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    static final int MODULO = (int) (1e9 + 7);

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[] p = new int[n];
        p[0] = -1;
        for (int i = 1; i < n; ++i) {
            p[i] = in.nextInt() - 1;
        }
        int[] prod = new int[n];
        int[] modpow = new int[n];
        Arrays.fill(prod, 1);
        for (int i = n - 1; i > 0; --i) {
            int j = p[i];
            if (modpow[i] == 0 && prod[i] + 1 == MODULO) {
                ++modpow[j];
            } else {
                prod[j] = (int) (prod[j] * (long) ((modpow[i] == 0 ? prod[i] : 0) + 1) % MODULO);
            }
        }
        if (modpow[0] == 0) {
            out.print(prod[0]);
        } else {
            out.print(0);
        }
        for (int i = 1; i < n; ++i) {
            int j = p[i];
            int pr = prod[j];
            int prpow = modpow[j];
            if (modpow[i] == 0 && prod[i] + 1 == MODULO) {
                --prpow;
            } else {
                pr = (int) (pr * (long) inv((modpow[i] == 0 ? prod[i] : 0) + 1) % MODULO);
            }
            if (prpow > 0) {
                pr = 0;
            }
            if (pr + 1 == MODULO) {
                ++modpow[i];
            } else {
                prod[i] = (int) (prod[i] * (long) (pr + 1) % MODULO);
            }
            out.print(' ');
            if (modpow[i] == 0) {
                out.print(prod[i]);
            } else {
                out.print(0);
            }
        }
        out.println();
    }

    private int inv(int x) {
        if (x == 1) return 1;
        return pow(x, MODULO - 2);
    }

    private int pow(int x, int k) {
        if (k == 0) return 1;
        if (k % 2 == 0) return pow((int) (x * (long) x % MODULO), k / 2);
        return (int) (x * (long) pow(x, k - 1) % MODULO);
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