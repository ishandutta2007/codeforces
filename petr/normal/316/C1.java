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
		TaskC1 solver = new TaskC1();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC1 {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[][] a = new int[n][m];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                a[i][j] = in.nextInt();
        int nv = n * m + 2;
        int s = nv - 2;
        int t = nv - 1;
        int[][] cap = new int[nv][nv];
        int[][] cost = new int[nv][nv];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                if ((i + j) % 2 == 0) {
                    cap[s][i * m + j] = 1;
                    for (int di = -1; di <= 1; ++di)
                        for (int dj = -1; dj <= 1; ++dj)
                            if (Math.abs(di) + Math.abs(dj) == 1) {
                                int ni = i + di;
                                int nj = j + dj;
                                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                                    cap[i * m + j][ni * m + nj] = 1;
                                    cost[i * m + j][ni * m + nj] = (a[i][j] == a[ni][nj] ? 0 : 1);
                                    cost[ni * m + nj][i * m + j] = -cost[i * m + j][ni * m + nj];
                                }
                            }
                } else {
                    cap[i * m + j][t] = 1;
                }
            }
        FlowRes fr = minCostMaxFlow(nv, s, t, cap, cost);
        if (fr.flow != n * m / 2) throw new RuntimeException();
        out.println(fr.cost);
    }
    static class FlowRes {
        int flow;
        int cost;
    }

    static final int INF = (int) 1e9;

    private FlowRes minCostMaxFlow(int n, int s, int t, int[][] cap, int[][] cost) {
        int[] pri = new int[n];
        FlowRes res = new FlowRes();
        while (true) {
            int[] dist = new int[n];
            int[] prev = new int[n];
            Arrays.fill(prev, -1);
            Arrays.fill(dist, INF);
            dist[s] = 0;
            boolean[] mark = new boolean[n];
            int mxd = 0;
            while (true) {
                int bi = -1;
                for (int i = 0; i < n; ++i) if (dist[i] < INF / 2 && !mark[i]) {
                    if (bi < 0 || dist[i] < dist[bi])
                        bi = i;
                }
                if (bi < 0) break;
                mark[bi] = true;
                mxd = dist[bi];
                for (int i = 0; i < n; ++i) if (!mark[i] && cap[bi][i] > 0) {
                    int edge = pri[bi] - pri[i] + cost[bi][i];
                    if (dist[i] > dist[bi] + edge) {
                        dist[i] = dist[bi] + edge;
                        prev[i] = bi;
                    }
                }
            }
            if (!mark[t]) break;
            ++res.flow;
            res.cost += dist[t] - pri[s] + pri[t];
            int at = t;
            while (at != s) {
                int pat = prev[at];
                --cap[pat][at];
                ++cap[at][pat];
                at = pat;
            }
            for (int i = 0; i < n; ++i) {
                if (dist[i] > INF / 2) pri[i] += mxd; else pri[i] += dist[i];
            }
        }
        return res;
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