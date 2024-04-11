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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int x = in.nextInt();
        int[] t = new int[n];
        int[] h = new int[n];
        int[] m = new int[n];
        for (int i = 0; i < n; ++i) {
            t[i] = in.nextInt();
            h[i] = in.nextInt();
            m[i] = in.nextInt();
        }
        int[] mark = new int[n];
        int res = 0;
        for (int stage = 1; stage <= 2; ++stage) {
            int got = 0;
            int curMax = x;
            int nextType = stage - 1;
            while (true) {
                int bi = -1;
                for (int i = 0; i < n; ++i) if (mark[i] < stage && t[i] == nextType && h[i] <= curMax && (bi < 0 || m[i] > m[bi])) bi = i;
                if (bi < 0) break;
                mark[bi] = stage;
                curMax += m[bi];
                ++got;
                nextType = 1 - nextType;
            }
            res = Math.max(res, got);
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