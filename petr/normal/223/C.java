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
    static final int MODULO = (int) (1e9 + 7);

	public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
        }
        int[] m = new int[n];
        Arrays.fill(m, 1);
        m = pow(m, k);
        a = mul(a, m);
        for (int i = 0; i < n; ++i) {
            if (i > 0) out.print(" ");
            out.print(a[i]);
        }
        out.println();
	}

    private int[] pow(int[] a, int k) {
        if (k == 0) {
            int[] res = new int[a.length];
            res[0] = 1;
            return res;
        } else if (k % 2 == 0) {
            return pow(mul(a, a), k / 2);
        } else {
            return mul(a, pow(a, k - 1));
        }
    }

    private int[] mul(int[] a, int[] b) {
        int[] c = new int[a.length];
        for (int i = 0; i < a.length; ++i) {
            long r = 0;
            for (int j = 0; j <= i; ++j) {
                r += a[j] * (long) b[i - j];
                if (r > 6e18)
                    r %= MODULO;
            }
            c[i] = (int) (r % MODULO);
        }
        return c;
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