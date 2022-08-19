import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Collections;
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
    static final long INF = (long) 2e18;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        long n = in.nextLong();
        List<Long> res = new ArrayList<Long>();
        for (int p2 = 0; (1L << p2) <= n + 1; ++p2) {
            long koef = (1L << p2) - 1;
            long a = 2;
            long b = 1 + 2 * koef;
            long c = koef;
            long left = -1;
            long right = n + 1;
            while (right - left > 1) {
                long middle = (left + right) / 2;
                long cur = mul((mul(a, middle) + b), middle) + c;
                if (cur == n) {
                    res.add((2 * middle + 1) << p2);
                    break;
                }
                if (cur > n) {
                    right = middle;
                } else {
                    left = middle;
                }
            }
        }
        if (res.size() == 0) res.add(-1L);
        Collections.sort(res);
        for (long x : res) out.println(x);
    }

    private long mul(long a, long b) {
        if (a == 0 || b == 0) return 0;
        if (INF / b < a) return INF; else return a * b;
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

    public long nextLong() {
        return Long.parseLong(next());
    }

    }