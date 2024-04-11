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
        int height = in.nextInt();
        int width = in.nextInt();
        int k = in.nextInt();
        int w = in.nextInt();
        String[] levels = new String[k];
        for (int i = 0; i < k; ++i) {
            StringBuilder b = new StringBuilder();
            for (int row = 0; row < height; ++row) b.append(in.next());
            levels[i] = b.toString();
        }
        int[][] dist = new int[k + 1][k + 1];
        int size = height * width;
        for (int i = 0; i < k; ++i) {
            dist[i][k] = dist[k][i] = size;
            for (int j = 0; j < i; ++j) {
                int diff = 0;
                String li = levels[i];
                String lj = levels[j];
                for (int t = 0; t < size; ++t) if (li.charAt(t) != lj.charAt(t)) ++diff;
                dist[i][j] = dist[j][i] = diff * w;
            }
        }
        boolean[] mark = new boolean[k + 1];
        int[] best = new int[k + 1];
        Arrays.fill(best, Integer.MAX_VALUE);
        best[k] = 0;
        int[] prev = new int[k + 1];
        Arrays.fill(prev, -1);
        int[] seq = new int[k + 1];
        int total = 0;
        boolean first = true;
        for (int i = 0; i < k + 1; ++i) {
            int bj = -1;
            for (int j = 0; j < k + 1; ++j) if (!mark[j] && (bj < 0 || best[j] < best[bj])) bj = j;
            total += best[bj];
            seq[i] = bj;
            mark[bj] = true;
            for (int j = 0; j < k + 1; ++j) if (!mark[j] && dist[bj][j] < best[j]) {
                best[j] = dist[bj][j];
                prev[j] = bj;
            }
        }
        out.println(total);
        for (int i = 1; i < k + 1; ++i) {
            out.print(seq[i] + 1);
            out.print(" ");
            if (prev[seq[i]] == k) {
                out.print(0);
            } else {
                out.print(prev[seq[i]] + 1);
            }
            out.println();
        }
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