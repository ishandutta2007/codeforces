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
    static final long INF = (long) 1e18;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int q = in.nextInt();
        int[] v = new int[n];
        for (int i = 0; i < n; ++i) {
            v[i] = in.nextInt();
        }
        int[] c = new int[n];
        for (int i = 0; i < n; ++i) {
            c[i] = in.nextInt();
        }
        long[] best = new long[n + 1];
        for (int qi = 0; qi < q; ++qi) {
            long a = in.nextLong();
            long b = in.nextLong();
            Arrays.fill(best, -INF);
            best[0] = 0;
            int mx = 0;
            int mx1 = -1;
            for (int i = 0; i < n; ++i) {
                long we = -INF;
                if (mx != -1 && mx != c[i]) {
                    we = Math.max(we, best[mx] + b * v[i]);
                } else if (mx1 != c[i] && mx1 != -1) {
                    we = Math.max(we, best[mx1] + b * v[i]);
                }
                we = Math.max(we, best[c[i]] + a * v[i]);
                if (we > best[c[i]]) {
                    best[c[i]] = we;
                    if (c[i] != mx) {
                        if (c[i] != mx1) {
                            if (mx == -1 || best[c[i]] > best[mx]) {
                                mx1 = mx;
                                mx = c[i];
                            } else if (mx1 == -1 || best[c[i]] > best[mx1]) {
                                mx1 = c[i];
                            }
                        } else {
                            if (best[c[i]] > best[mx]) {
                                mx1 = mx;
                                mx = c[i];
                            }
                        }
                    }
                }
            }
            out.println(best[mx]);
        }
    }
}

class InputReader {
    BufferedReader reader;
    StringTokenizer tokenizer;

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