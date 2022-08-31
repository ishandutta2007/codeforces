import java.util.Arrays;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Random;
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
		TaskG solver = new TaskG();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskG {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt() + i;
        }
        Random random = new Random(5437534531L + System.currentTimeMillis());
        for (int i = 0; i < n; ++i) {
            int j = i + random.nextInt(n - i);
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
        Arrays.sort(a);
        for (int i = 0; i < n; ++i) {
            a[i] -= i;
            if (a[i] < 0) {
                out.println(":(");
                return;
            }
        }
        for (int i = 0; i + 1 < n; ++i) {
            if (a[i] > a[i + 1]) {
                out.println(":(");
                return;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i > 0) out.print(" ");
            out.print(a[i]);
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