import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Set;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.HashSet;
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
		TaskD1 solver = new TaskD1();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD1 {
    static final int MODULO = (int) (1e9 + 7);

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int n1 = 0;
        int n2 = 0;
        for (int i = 0; i < n; ++i) {
            int a = in.nextInt();
            if (a == 1) ++n1; else if (a == 2) ++n2; else throw new RuntimeException();
        }
        int[] a = new int[Math.max(2, n1 + 1)];
        a[0] = 1;
        a[1] = 1;
        for (int i = 2; i <= n1; ++i) {
            a[i] = (int) ((a[i - 1] + (i - 1) * (long) a[i - 2]) % MODULO);
        }
        int res = a[n1];
        for (int i = 0; i < n2; ++i) {
            res = (int) (res * (long) (n1 + n2 - i) % MODULO);
        }
        out.println(res);
    }

    }

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

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