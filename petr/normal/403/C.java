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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        boolean[][] edge = new boolean[n][n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                edge[i][j] = in.nextInt() > 0;
            }
        {
            int qt = 0;
            int qh = 1;
            boolean[] mark = new boolean[n];
            int[] queue = new int[n];
            mark[0] = true;
            queue[0] = 0;
            while (qt < qh) {
                int cur = queue[qt++];
                for (int next = 0; next < n; ++next) if (!mark[next] && edge[cur][next]) {
                    mark[next] = true;
                    queue[qh++] = next;
                }
            }
            if (qh < n) {
                out.println("NO");
                return;
            }
        }
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j) {
                boolean tmp = edge[i][j];
                edge[i][j] = edge[j][i];
                edge[j][i] = tmp;
            }
        {
            int qt = 0;
            int qh = 1;
            boolean[] mark = new boolean[n];
            int[] queue = new int[n];
            mark[0] = true;
            queue[0] = 0;
            while (qt < qh) {
                int cur = queue[qt++];
                for (int next = 0; next < n; ++next) if (!mark[next] && edge[cur][next]) {
                    mark[next] = true;
                    queue[qh++] = next;
                }
            }
            if (qh < n) {
                out.println("NO");
                return;
            }
        }
        out.println("YES");
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