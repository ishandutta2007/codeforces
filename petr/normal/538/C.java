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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int days = in.nextInt();
        int m = in.nextInt();
        int[] d = new int[m];
        int[] h = new int[m];
        for (int i = 0; i < m; ++i) {
            d[i] = in.nextInt();
            h[i] = in.nextInt();
        }
        int res = Math.max((d[0] - 1) + h[0], (days - d[m - 1]) + h[m - 1]);
        for (int i = 0; i + 1 < m; ++i) {
            int delta = d[i + 1] - d[i];
            int dh = Math.abs(h[i + 1] - h[i]);
            int mx = Math.max(h[i + 1], h[i]);
            if (delta < dh) {
                out.println("IMPOSSIBLE");
                return;
            }
            delta -= dh;
            res = Math.max(res, mx + delta / 2);
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