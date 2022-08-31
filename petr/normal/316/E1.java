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
		TaskE1 solver = new TaskE1();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE1 {
    static final int MODULO = (int) 1e9;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) a[i] = in.nextInt();
        int[] f = new int[Math.max(2, n)];
        f[0] = 1;
        f[1] = 1;
        for (int i = 2; i < n; ++i) {
            f[i] = (f[i - 1] + f[i - 2]);
            if (f[i] >= MODULO) f[i] -= MODULO;
        }
        for (int i = 0; i < m; ++i) {
            int t = in.nextInt();
            switch (t) {
                case 1: {
                    int x = in.nextInt() - 1;
                    int v = in.nextInt();
                    a[x] = v;
                    break;
                }

                case 2: {
                    int l = in.nextInt() - 1;
                    int r = in.nextInt() - 1;
                    long s = 0;
                    for (int j = l; j <= r; ++j)
                        s = (s + a[j] * (long) f[j - l]) % MODULO;
                    out.println(s % MODULO);
                    break;
                }

                case 3: {
                    int l = in.nextInt() - 1;
                    int r = in.nextInt() - 1;
                    int d = in.nextInt();
                    for (int j = l; j <= r; ++j) {
                        a[j] = (a[j] + d) % MODULO;
                    }
                    break;
                }
            }
        }
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