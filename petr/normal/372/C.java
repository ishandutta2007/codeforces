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
        int d = in.nextInt();
        int[] a = new int[m];
        int[] b = new int[m];
        int[] t = new int[m];
        for (int i = 0; i < m; ++i) {
            a[i] = in.nextInt() - 1;
            b[i] = in.nextInt();
            t[i] = in.nextInt();
        }
        int[] best = new int[n];
        int[] nbest = new int[n];
        int curT = 1;
        int[] stack = new int[n + 1];
        int tail;
        int head;
        for (int i = 0; i < m; ++i) {
            int elapsed = t[i] - curT;
            curT = t[i];
            int canWalk = (int) Math.min(n - 1, elapsed * (long) d);
            tail = 0;
            head = 0;
            for (int j = 0; j < canWalk; ++j) {
                while (head > tail && best[stack[head - 1]] <= best[j]) --head;
                stack[head++] = j;
            }
            for (int k = 0; k < n; ++k) {
                int j = k + canWalk;
                if (j < n) {
                    while (head > tail && best[stack[head - 1]] <= best[j]) --head;
                    stack[head++] = j;
                }
                while (stack[tail] < k - canWalk) ++tail;
                nbest[k] = best[stack[tail]];
            }
            int[] tmp = best;
            best = nbest;
            nbest = tmp;
            for (int j = 0; j < n; ++j)
                best[j] -= Math.abs(a[i] - j);
        }
        long res = Integer.MIN_VALUE;
        for (int x : best)
            res = Math.max(res, x);
        for (int x : b)
            res += x;
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