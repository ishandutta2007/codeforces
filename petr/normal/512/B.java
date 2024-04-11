import java.util.Arrays;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.StringTokenizer;

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
        int n = in.nextInt();
        int[] l = new int[n];
        for (int i = 0; i < n; ++i) l[i] = in.nextInt();
        int[] c = new int[n];
        for (int i = 0; i < n; ++i) c[i] = in.nextInt();
        int[] primes = new int[100];
        int res = Integer.MAX_VALUE;
        for (int start = 0; start < n; ++start) {
            int nprimes = 0;
            int tmp = l[start];
            for (int i = 2; i * i <= tmp; ++i) {
                if (tmp % i == 0) {
                    while (tmp % i == 0) tmp /= i;
                    primes[nprimes++] = i;
                }
            }
            if (tmp > 1) primes[nprimes++] = tmp;
            int[] best = new int[1 << nprimes];
            Arrays.fill(best, Integer.MAX_VALUE);
            best[0] = c[start];
            for (int i = start + 1; i < n; ++i) {
                int cur = 0;
                for (int j = 0; j < nprimes; ++j) if (l[i] % primes[j] != 0) cur |= 1 << j;
                int cc = c[i];
                for (int old = 0; old < best.length; ++old)
                    if (best[old] < Integer.MAX_VALUE) {
                        best[old | cur] = Math.min(best[old | cur], best[old] + cc);
                    }
            }
            res = Math.min(res, best[best.length - 1]);
        }
        if (res == Integer.MAX_VALUE) res = -1;
        out.println(res);
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