import java.util.Arrays;
import java.util.ArrayList;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.List;
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
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) a[i] = in.nextInt();
        boolean[] prime = new boolean[(int) 2e4 + 1];
        Arrays.fill(prime, 2, prime.length, true);
        for (int i = 2; i < prime.length; ++i) if (prime[i]) {
            for (int j = i * i; j < prime.length; j += i) prime[j] = false;
        }
        int[][] c = new int[n + 2][n + 2];
        int s = n;
        int t = n + 1;
        for (int i = 0; i < n; ++i) {
            if (a[i] % 2 == 0) {
                c[s][i] = 2;
            } else {
                c[i][t] = 2;
            }
            for (int j = 0; j < n; ++j) if (prime[a[i] + a[j]]) {
                if (a[i] % 2 == 0) c[i][j] = 1; else c[j][i] = 1;
            }
        }
        int[][] f = new int[n + 2][n + 2];
        if (flow(n + 2, c, f, s, t) != n) {
            out.println("Impossible");
        } else {
            List<List<Integer>> cycles = new ArrayList<>();
            boolean[] mark = new boolean[n];
            for (int i = 0; i < n; ++i) if (!mark[i]) {
                List<Integer> cycle = new ArrayList<>();
                int cur = i;
                outer: while (true) {
                    mark[cur] = true;
                    cycle.add(cur + 1);
                    for (int j = 0; j < n; ++j) if (f[cur][j] != 0 && !mark[j]) {
                        cur = j;
                        continue outer;
                    }
                    break;
                }
                cycles.add(cycle);
            }
            out.println(cycles.size());
            for (List<Integer> cycle : cycles) {
                out.print(cycle.size());
                for (int x : cycle) out.print(" " + x);
                out.println();
            }
        }
    }

    private int flow(int n, int[][] c, int[][] f, int s, int t) {
        boolean[] mark = new boolean[n];
        int res = 0;
        while (dfs(s, t, c, f, mark)) {
            ++res;
            Arrays.fill(mark, false);
        }
        return res;
    }

    private boolean dfs(int at, int t, int[][] c, int[][] f, boolean[] mark) {
        if (at == t) return true;
        if (mark[at]) return false;
        mark[at] = true;
        for (int i = 0; i < c.length; ++i) if (f[at][i] < c[at][i] && dfs(i, t, c, f, mark)) {
            ++f[at][i];
            --f[i][at];
            return true;
        }
        return false;
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