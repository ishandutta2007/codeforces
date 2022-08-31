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
        int[] dst = new int[2 * (n - 1)];
        int[] first = new int[n];
        int[] next = new int[dst.length];
        Arrays.fill(first, -1);
        for (int i = 0; i < (n - 1); ++i) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            dst[i * 2] = b;
            next[i * 2] = first[a];
            first[a] = i * 2;
            dst[i * 2 + 1] = a;
            next[i * 2 + 1] = first[b];
            first[b] = i * 2 + 1;
        }
        int[] q = new int[n];
        int qh = 1;
        int qt = 0;
        int[] depth = new int[n];
        Arrays.fill(depth, -1);
        depth[0] = 0;
        while (qt < qh) {
            int cur = q[qt++];
            int edge = first[cur];
            while (edge >= 0) {
                int d = dst[edge];
                if (depth[d] < 0) {
                    depth[d] = depth[cur] + 1;
                    q[qh++] = d;
                }
                edge = next[edge];
            }
        }
        double res = 0.0;
        for (int i = 0; i < n; ++i) {
            res += 1.0 / (depth[i] + 1);
        }
        out.printf("%.10f\n", res);
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