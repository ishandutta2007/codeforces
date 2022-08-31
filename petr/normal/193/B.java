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
    int[] b;
    int[] k;
    int[] p;
    int r;
    int n;
    
	public void solve(int testNumber, InputReader in, PrintWriter out) {
        n = in.nextInt();
        int u = in.nextInt();
        r = in.nextInt();
        int[] a = new int[n];
        b = new int[n];
        k = new int[n];
        p = new int[n];
        for (int i = 0; i < n; ++i)
            a[i] = in.nextInt();
        for (int i = 0; i < n; ++i)
            b[i] = in.nextInt();
        for (int i = 0; i < n; ++i)
            k[i] = in.nextInt();
        for (int i = 0; i < n; ++i)
            p[i] = in.nextInt() - 1;
        out.println(rec(a, u));
	}

    private long rec(int[] a, int u) {
        long res = Long.MIN_VALUE;
        if (u % 2 == 0) {
            long sum = 0;
            for (int i = 0; i < a.length; ++i)
                sum += a[i] * (long) k[i];
            res = Math.max(res, sum);
        } else {
            long sum = 0;
            for (int i = 0; i < a.length; ++i)
                sum += (a[i] ^ b[i]) * (long) k[i];
            res = Math.max(res, sum);
        }
        if (u == 0) return res;
        int[] z = new int[n];
        for (int i = 0; i < n; ++i) {
            z[i] = a[p[i]] + r;
        }
        res = Math.max(res, rec(z, u - 1));
        if (u <= 1) return res;
        for (int i = 0; i < n; ++i) {
            z[i] = (a[p[i]] ^ b[p[i]]) + r;
        }
        res = Math.max(res, rec(z, u - 2));
        return res;
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