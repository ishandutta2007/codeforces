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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[] x = new int[n];
        int[] y = new int[n];
        for (int i = 0; i < n; ++i) {
            x[i] = in.nextInt();
            y[i] = in.nextInt();
        }
        int maxy = Integer.MIN_VALUE;
        for (int i = 0; i < n; ++i) if (y[i] > maxy) maxy = y[i];
        int root = -1;
        for (int i = 0; i < n; ++i) if (y[i] == maxy) {
            if (root < 0) root = i; else {
                out.println(-1);
                return;
            }
        }
        int[][] cap = new int[2 * n + 2][2 * n + 2];
        double[][] cost = new double[2 * n + 2][2 * n + 2];
        int s = 2 * n;
        int t = 2 * n + 1;
        for (int i = 0; i < n; ++i) {
            cap[s][i] = 2;
        }
        for (int i = 0; i < n; ++i) if (i != root) {
            cap[i + n][t] = 1;
        }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (y[i] > y[j]) {
                    cap[i][j + n] = 1;
                    double dx = x[i] - x[j];
                    double dy = y[i] - y[j];
                    cost[i][j + n] = Math.sqrt(dx * dx + dy * dy);
                    cost[j + n][i] = -cost[i][j + n];
                }
        FlowRes res = minCostMaxFlow(2 * n + 2, s, t, cap, cost);
        if (res.flow == n - 1) {
            out.printf("%.10f\n", res.cost);
        } else {
            out.println(-1);
        }
    }

    static class FlowRes {
        int flow;
        double cost;
    }

    static final double INF = 1e100;

    private FlowRes minCostMaxFlow(int n, int s, int t, int[][] cap, double[][] cost) {
        double[] pri = new double[n];
        FlowRes res = new FlowRes();
        while (true) {
            double[] dist = new double[n];
            int[] prev = new int[n];
            Arrays.fill(prev, -1);
            Arrays.fill(dist, INF);
            dist[s] = 0;
            boolean[] mark = new boolean[n];
            double mxd = 0;
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
                    double edge = pri[bi] - pri[i] + cost[bi][i];
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