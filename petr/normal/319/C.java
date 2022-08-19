import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
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
    static final long INF = (long) 2e18;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n; ++i)
            a[i] = in.nextLong();
        long[] b = new long[n];
        for (int i = 0; i < n; ++i) {
            b[i] = in.nextLong();
        }
        long[] r = solve1(n, a, b);
        out.println(r[n - 1]);
    }


    private long[] solve1(int n, long[] a, long[] b) {
        long[] r = new long[n];
        Arrays.fill(r, INF);
        r[0] = 0;
        int[] stack = new int[n];
        int sp = 1;
        int st = 0;
        stack[0] = 0;
        for (int i = 1; i < n; ++i) {
            while (st + 1 < sp && r[stack[st]] + b[stack[st]] * a[i] >= r[stack[st + 1]] + b[stack[st + 1]] * a[i]) ++st;
            r[i] = r[stack[st]] + b[stack[st]] * a[i];
            if (r[i] > 1e18) throw new RuntimeException();
            while (true) {
                if (st < sp && r[stack[sp - 1]] + b[stack[sp - 1]] * a[i] >= r[i] + b[i] * a[i]) {
                    --sp;
                    continue;
                }
                if (st + 1 < sp) {
                    long p1 = r[i] - r[stack[sp - 1]];
                    long q1 = b[stack[sp - 1]] - b[i];
                    long p2 = r[stack[sp - 1]] - r[stack[sp - 2]];
                    long q2 = b[stack[sp - 2]] - b[stack[sp - 1]];
                    if (p1 * q2 - p2 * q1 <= 0) {
                        if (p1 * (double) q2 - p2 * (double) q1 <= 1e18) {
                            --sp;
                            continue;
                        }
                    } else {
                        if (p1 * (double) q2 - p2 * (double) q1 <= -1e18) {
                            --sp;
                            continue;
                        }
                    }
                }
                break;
            }
            stack[sp] = i;
            ++sp;
        }
        return r;
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