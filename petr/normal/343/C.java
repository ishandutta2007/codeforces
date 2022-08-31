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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        long[] h = new long[n];
        for (int i = 0; i < n; ++i) h[i] = in.nextLong();
        long[] p = new long[m];
        for (int i = 0; i < m; ++i) p[i] = in.nextLong();
        long left = -1;
        long right = (long) 3e10;
        while (right - left > 1) {
            long middle = (left + right) / 2;
            if (enough(middle, h, p)) {
                right = middle;
            } else {
                left = middle;
            }
        }
        out.println(right);
    }

    private boolean enough(long time, long[] h, long[] p) {
        int at = 0;
        for (int i = 0; i < h.length; ++i) {
            if (at >= p.length) continue;
            long start = p[at];
            if (Math.abs(h[i] - start) > time) continue;
            while (at < p.length && p[at] <= h[i]) ++at;
            while (at < p.length && Math.abs(p[at] - start) + Math.min(Math.abs(p[at] - h[i]), Math.abs(start - h[i])) <= time) ++at;
        }
        return at >= p.length;
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

    public long nextLong() {
        return Long.parseLong(next());
    }

    }