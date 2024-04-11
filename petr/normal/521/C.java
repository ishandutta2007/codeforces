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
    static final long MODULO = (long) (1e9 + 7);

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        String s = in.next();
        long[] invs = new long[n + 1];
        invs[1] = 1;
        for (int i = 2; i <= n; ++i) {
            invs[i] = (MODULO - invs[((int) (MODULO % i))] * (MODULO / i) % MODULO) % MODULO;
            if (invs[i] * i % MODULO != 1) throw new RuntimeException();
        }
        long[] cbyk = new long[n + 1];
        long[] cbykm1 = new long[n + 1];
        cbyk[k] = 1;
        for (int i = k + 1; i <= n; ++i) {
            cbyk[i] = cbyk[i - 1] * i % MODULO * invs[i - k] % MODULO;
        }
        if (k > 0) {
            cbykm1[k - 1] = 1;
            for (int i = k; i <= n; ++i) {
                cbykm1[i] = cbykm1[i - 1] * i % MODULO * invs[i - k + 1] % MODULO;
            }
        }
        long koef = 0;
        long res = 0;
        long p10 = 1;
        for (int i = n - 1; i >= 0; --i) {
            int digit = s.charAt(i) - '0';
            res = (res + digit * (koef + p10 * cbyk[i] % MODULO)) % MODULO;
            if (i > 0) {
                koef = (koef + p10 * cbykm1[i - 1]) % MODULO;
                p10 = p10 * 10 % MODULO;
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