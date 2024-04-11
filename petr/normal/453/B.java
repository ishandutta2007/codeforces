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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int[] primes = new int[0];
        for (int i = 2; i <= 60; ++i) {
            boolean ok = true;
            for (int j = 2; j < i; ++j) if (i % j == 0) ok = false;
            if (ok) {
                primes = Arrays.copyOf(primes, primes.length + 1);
                primes[primes.length - 1] = i;
            }
        }
        int maxMask = 1 << primes.length;
        int[] mask = new int[61];
        for (int i = 1; i < mask.length; ++i)
            for (int j = 0; j < primes.length; ++j)
                if (i % primes[j] == 0) mask[i] |= 1 << j;
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) a[i] = in.nextInt();
        int[] best = new int[maxMask];
        int[] nbest = new int[maxMask];
        int[][] via = new int[n][maxMask];
        for (int i = 0; i < n; ++i) {
            Arrays.fill(nbest, (int) 1e9);
            int cur = a[i];
            for (int nxt = 1; nxt <= 60; ++nxt) {
                int badMask = mask[nxt];
                for (int old = (maxMask - 1) & (~badMask);; old = (old - 1) & (~badMask)) {
                    int nmask = old | mask[nxt];
                    int got = best[old] + Math.abs(nxt - cur);
                    if (got < nbest[nmask]) {
                        nbest[nmask] = got;
                        via[i][nmask] = nxt;
                    }
                    if (old == 0) break;
                }
            }
            int[] tmp = best;
            best = nbest;
            nbest = tmp;
        }
        int[] res = new int[n];
        int cmask = maxMask - 1;
        for (int i = n - 1; i >= 0; --i) {
            res[i] = via[i][cmask];
            cmask &= ~mask[res[i]];
        }
        for (int i = 0; i < n; ++i) {
            if (i > 0) out.print(" ");
            out.print(res[i]);
        }
        out.println();
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream), 32768);
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