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
        n = in.nextInt();
        int[] p = new int[n];
        for (int i = 0; i < n; ++i) p[i] = in.nextInt() - 1;
        adj = new boolean[n][n];
        for (int i = 0; i < n; ++i) {
            String s = in.next();
            for (int j = 0; j < n; ++j) {
                adj[i][j] = s.charAt(j) == '1';
            }
        }
        mark = new boolean[n];
        seq = new int[n];
        vals = new int[n];
        for (int i = 0; i < n; ++i) {
            if (mark[i]) continue;
            nseq = 0;
            dfs(i);
            Arrays.sort(seq, 0, nseq);
            for (int j = 0; j < nseq; ++j) vals[j] = p[seq[j]];
            Arrays.sort(vals, 0, nseq);
            for (int j = 0; j < nseq; ++j) p[seq[j]] = vals[j];
        }
        for (int i = 0; i < n; ++i) {
            if (i > 0) out.print(" ");
            out.print(p[i] + 1);
        }
        out.println();
    }

    private void dfs(int at) {
        if (mark[at]) return;
        mark[at] = true;
        seq[nseq++] = at;
        for (int i = 0; i < n; ++i) if (adj[at][i]) dfs(i);
    }

    int n;
    boolean[] mark;
    boolean[][] adj;
    int[] seq;
    int[] vals;
    int nseq;
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