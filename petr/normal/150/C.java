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
	public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        long c = in.nextLong();
        long[] x = new long[n];
        for (int i = 0; i < n; ++i) x[i] = in.nextLong();
        long[] p = new long[n - 1];
        for (int i = 0; i < n - 1; ++i)
            p[i] = in.nextLong();
        long[] gain = new long[n - 1];
        for (int i = 0; i < n - 1; ++i) {
            gain[i] = -(50 * (x[i + 1] - x[i]) - c * p[i]);
        }
        long[] partialSums = new long[n];
        for (int i = 0; i < n - 1; ++i)
            partialSums[i + 1] = partialSums[i] + gain[i];
        int[] nextLarger = new int[n];
        int[] stack = new int[n];
        int sp = 0;
        for (int i = n - 1; i >= 0; --i) {
            stack[sp++] = i;
            while (sp >= 2 && partialSums[stack[sp - 1]] >= partialSums[stack[sp - 2]]) {
                stack[sp - 2] = stack[sp - 1];
                --sp;
            }
            if (sp == 1)
                nextLarger[i] = n;
            else
                nextLarger[i] = stack[sp - 2];
        }
        long[] min = new long[4 * n + 10];
        long[] delta = new long[4 * n + 10];
        for (int i = 0; i < n; ++i) {
            update(min, delta, 0, 0, n - 1, i, i, partialSums[i]);
        }
        int at = 0;
        while (at < n) {
            update(min, delta, 0, 0, n - 1, at, nextLarger[at] - 1, -partialSums[at]);
            at = nextLarger[at];
        }
        long[] req = new long[m];
        for (int i = 0; i < m; ++i) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            req[i] = a * (long) n + b;
        }
        Arrays.sort(req);
        int cura = 0;
        double res = 0.0;
        for (int i = 0; i < m; ++i) {
            int a = (int) (req[i] / n);
            int b = (int) (req[i] % n);
            if (a < cura) throw new RuntimeException();
            while (cura < a) {
                int upto = nextLarger[cura];
                at = cura + 1;
                while (at < upto) {
                    update(min, delta, 0, 0, n - 1, at, nextLarger[at] - 1, partialSums[cura] - partialSums[at]);
                    at = nextLarger[at];
                }
                if (at != upto) throw new RuntimeException();
                ++cura;
            }
            long best = getMin(min, delta, 0, 0, n - 1, a, b);
            /*long best2 = 0;
            int b2l = -1;
            int b2r = -1;
            for (int l = a; l <= b; ++l)
                for (int r = l; r <= b; ++r) {
                    if (partialSums[r] - partialSums[l] < best2) {
                        best2 = Math.min(best2, partialSums[r] - partialSums[l]);
                        b2l = l;
                        b2r = r;
                    }
                }
            if (best != best2) throw new RuntimeException();
            System.out.println((a + 1) + " " + (b + 1) + " " + (b2l + 1) + " " + (b2r + 1));*/
            //res += partialSums[b] - partialSums[a] - best;
            res += -best;
        }
        out.println(res / 100.0);
	}

    private long getMin(long[] min, long[] delta, int root, int rl, int rr, int left, int right) {
        if (left > right) return Long.MAX_VALUE / 2;
        if (rl == left && rr == right) {
            return min[root];
        } else {
            int rm = (rl + rr) / 2;
            return Math.min(getMin(min, delta, root * 2 + 1, rl, rm, left, Math.min(right, rm)),
                getMin(min, delta, root * 2 + 2, rm + 1, rr, Math.max(left, rm + 1), right)) + delta[root];
        }
    }

    private void update(long[] min, long[] delta, int root, int rl, int rr, int left, int right, long by) {
        if (left > right) return;
        if (rl == left && rr == right) {
            delta[root] += by;
            min[root] += by;
        } else {
            int rm = (rl + rr) / 2;
            update(min, delta, root * 2 + 1, rl, rm, left, Math.min(right, rm), by);
            update(min, delta, root * 2 + 2, rm + 1, rr, Math.max(left, rm + 1), right, by);
            min[root] = delta[root] + Math.min(min[root * 2 + 1], min[root * 2 + 2]);
        }
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

    public long nextLong() {
        return Long.parseLong(next());
    }

    }