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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    static final long MODULO = (long) (1e9 + 7);
    int[] count;
    int m;
    int superShift;

	public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        m = in.nextInt();
        int t = in.nextInt();
        int[] a = new int[t];
        for (int i = 0; i < t; ++i) a[i] = in.nextInt();
        count = new int[m / 2 + 1];
        for (int i = 0; i < t; ++i) ++count[Math.min(m - a[i] % m, a[i] % m)];
        if (m % 2 == 0)
            superShift = m / 2 - 1;
        else
            superShift = m / 2;
        out.println(rec(1, 1));
	}

    private long rec(int at, long bad) {
        if (at >= count.length)
            return 1;
        long res = rec(at + 1, bad);
        if ((bad & (1L << at)) == 0) {
            long newBad = bad;
            newBad |= bad << at;
            newBad &= (1L << count.length) - 1;
            newBad |= Long.reverse(bad >>> (count.length - at)) >>> (63 - superShift);
            newBad |= bad >>> at;
            newBad |= Long.reverse(bad & ((1L << at) - 1)) >>> (63 - at);
            res = (res + rec(at + 1, newBad) * count[at]) % MODULO;
        }
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