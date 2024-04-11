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
    int n;
    int m;
    int[] dest;
    int[] next;
    int[] first;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        n = in.nextInt();
        m = in.nextInt();
        dest = new int[2 * m];
        next = new int[2 * m];
        first = new int[n];
        Arrays.fill(first, -1);
        for (int i = 0; i < m; ++i) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            dest[i * 2] = b;
            next[i * 2] = first[a];
            first[a] = i * 2;
            dest[i * 2 + 1] = a;
            next[i * 2 + 1] = first[b];
            first[b] = i * 2 + 1;
        }
        int s1 = in.nextInt() - 1;
        int t1 = in.nextInt() - 1;
        int l1 = in.nextInt();
        int s2 = in.nextInt() - 1;
        int t2 = in.nextInt() - 1;
        int l2 = in.nextInt();
        int[][] d = new int[n][];
        for (int i = 0; i < n; ++i) d[i] = dist(i);
        int res = INF;
        if (d[s1][t1] <= l1 && d[s2][t2] <= l2) {
            res = Math.min(res, d[s1][t1] + d[s2][t2]);
        }
        for (int v1 = 0; v1 < n; ++v1) {
            for (int v2 = 0; v2 < n; ++v2) {
                if (d[s1][v1] + d[v1][v2] + d[v2][t1] <= l1 && d[s2][v1] + d[v1][v2] + d[v2][t2] <= l2) {
                    res = Math.min(res, d[s1][v1] + d[s2][v1] + d[v1][v2] + d[v2][t1] + d[v2][t2]);
                }
                if (d[s1][v1] + d[v1][v2] + d[v2][t1] <= l1 && d[s2][v2] + d[v1][v2] + d[v1][t2] <= l2) {
                    res = Math.min(res, d[s1][v1] + d[s2][v2] + d[v1][v2] + d[v2][t1] + d[v1][t2]);
                }
            }
        }
        if (res == INF) {
            out.println(-1);
        } else {
            out.println(m - res);
        }
    }

    static final int INF = (int) 1e9;

    private int[] dist(int from) {
        int[] res = new int[n];
        Arrays.fill(res, INF);
        res[from] = 0;
        int[] queue = new int[n];
        int qt = 0;
        int qh = 1;
        queue[0] = from;
        while (qt < qh) {
            int cur = queue[qt++];
            int e = first[cur];
            while (e >= 0) {
                int v = dest[e];
                if (res[v] == INF) {
                    res[v] = res[cur] + 1;
                    queue[qh++] = v;
                }
                e = next[e];
            }
        }
        return res;
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