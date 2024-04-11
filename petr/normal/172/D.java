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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
        int a = in.nextInt();
        int n = in.nextInt();
        int[] rem = new int[n];
        for (int i = 0; i < n; ++i) {
            rem[i] = a + i;
        }
        for (int div = 2; div * div < a + n; ++div) {
            int sq = div * div;
            int first = (a - 1) / sq * sq + sq;
            for (int i = first; i < a + n; i += sq) {
                int j = i - a;
                while (rem[j] % sq == 0) {
                    rem[j] /= sq;
                }
            }
        }
        long res = 0;
        for (int x : rem) res += x;
        out.println(res);
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

    }