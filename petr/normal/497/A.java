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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        String[] data = new String[n];
        for (int i = 0; i < n; ++i) data[i] = in.next();
        boolean[] eq = new boolean[n - 1];
        Arrays.fill(eq, true);
        int res = 0;
        for (int j = 0; j < m; ++j) {
            boolean ok = true;
            for (int i = 0; i + 1 < n; ++i)
                if (eq[i] && data[i].charAt(j) > data[i + 1].charAt(j)) ok = false;
            if (!ok) {
                ++res;
                continue;
            }
            for (int i = 0; i + 1 < n; ++i)
                if (data[i].charAt(j) < data[i + 1].charAt(j)) eq[i] = false;
        }
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