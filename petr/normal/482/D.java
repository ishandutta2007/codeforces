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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    static final long MODULO = (int) (1e9 + 7);

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[] p = new int[n];
        p[0] = -1;
        for (int i = 1; i < n; ++i) p[i] = in.nextInt() - 1;
        int[] firstChild = new int[n];
        int[] nextSibling = new int[n];
        Arrays.fill(firstChild, -1);
        for (int i = n - 1; i >= 1; --i) {
            nextSibling[i] = firstChild[p[i]];
            firstChild[p[i]] = i;
        }
        long[] waysOdd = new long[n];
        long[] waysEven = new long[n];
        for (int v = n - 1; v >= 0; --v) {
            waysOdd[v] = 1;
            waysEven[v] = 0;
            long waysOddAllOdd = 1;
            long waysOddAllEven = 1;
            long waysEvenAllOdd = 0;
            long waysEvenAllEven = 0;
            int child = firstChild[v];
            while (child >= 0) {
                long nodd = (waysOdd[v] * (1 + waysEven[child]) + waysEven[v] * waysOdd[child]) % MODULO;
                long neven = (waysEven[v] * (1 + waysEven[child]) + waysOdd[v] * waysOdd[child]) % MODULO;
                waysOdd[v] = nodd;
                waysEven[v] = neven;
                nodd = (waysOddAllOdd + waysEvenAllOdd * waysOdd[child]) % MODULO;
                neven = (waysEvenAllOdd + waysOddAllOdd * waysOdd[child]) % MODULO;
                waysOddAllOdd = nodd;
                waysEvenAllOdd = neven;
                nodd = (waysOddAllEven * (1 + waysEven[child])) % MODULO;
                neven = (waysEvenAllEven * (1 + waysEven[child])) % MODULO;
                waysOddAllEven = nodd;
                waysEvenAllEven = neven;
                child = nextSibling[child];
            }
            waysOdd[v] = (waysOdd[v] * 2 - waysOddAllEven + 2 * MODULO) % MODULO;
            waysEven[v] = (waysEven[v] * 2 - waysEvenAllOdd - waysEvenAllEven + 2 * MODULO) % MODULO;
        }
        out.println((waysOdd[0] + waysEven[0]) % MODULO);
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