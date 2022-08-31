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
    static final int MODULO = (int) (1e9 + 7);

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        long[] x = new long[n];
        long[] y = new long[n];
        for (int i = 0; i < n; ++i) {
            x[i] = in.nextInt() * 2;
            y[i] = in.nextInt() * 2;
        }
        boolean[][] niceEdge = new boolean[n][n];
        for (int i = 0; i < n; ++i) {
            niceEdge[i][(i + 1) % n] = niceEdge[(i + 1) % n][i] = true;
        }
        for (int i = 0; i < n; ++i) {
            outer: for (int j = i + 2; j < n; ++j) {
                if ((j + 1) % n == i) continue;
                long mx = (x[i] + x[j]) >> 1;
                long my = (y[i] + y[j]) >> 1;
                if (!inside(mx, my, n, x, y)) continue;
                long dx = x[j] - x[i];
                long dy = y[j] - y[i];
                for (int k = 0; k < n; ++k) if (k != i && k != j) {
                    long dx1 = x[k] - x[i];
                    long dy1 = y[k] - y[i];
                    long dx2 = x[k] - x[j];
                    long dy2 = y[k] - y[j];
                    if (dx1 * dy - dy1 * dx == 0 && dx1 * dx + dy1 * dy >= 0 && dx2 * dx + dy2 * dy <= 0)
                        continue outer;
                    long sk = signum(dx1 * dy - dy1 * dx);
                    int l = k + 1;
                    if (l >= n) l -= n;
                    if (l != i && l != j) {
                        long sl = signum((x[l] - x[i]) * dy - (y[l] - y[i]) * dx);
                        if (sk * sl == -1) {
                            long si = signum((x[i] - x[k]) * (y[l] - y[k]) - (y[i] - y[k]) * (x[l] - x[k]));
                            long sj = signum((x[j] - x[k]) * (y[l] - y[k]) - (y[j] - y[k]) * (x[l] - x[k]));
                            if (si * sj == -1) {
                                continue outer;
                            }
                        }
                    }
                }
                niceEdge[i][j] = niceEdge[j][i] = true;
            }
        }
        long[][] res = new long[n][n];
        for (int delta = 1; delta <= n - 1; ++delta) {
            for (int first = 0; first + delta < n; ++first) {
                int second = first + delta;
                if (delta == 1) {
                    res[first][second] = 1;
                    continue;
                }
                for (int middle = first + 1; middle < second; ++middle) {
                    if (niceEdge[first][middle] && niceEdge[middle][second]) {
                        res[first][second] = (res[first][second] + res[first][middle] * res[middle][second]) % MODULO;
                    }
                }
            }
        }
        out.println(res[0][n - 1]);
    }

    private long signum(long l) {
        if (l < 0) return -1;
        if (l > 0) return 1;
        return 0;
    }

    private boolean inside(long mx, long my, int n, long[] x, long[] y) {
        boolean res = false;
        for (int i = 0; i < n; ++i) {
            long x1 = x[i];
            long y1 = y[i];
            long x2 = x[(i + 1) % n];
            long y2 = y[(i + 1) % n];
            if (y1 > y2) {
                long t = x1;
                x1 = x2;
                x2 = t;
                t = y1;
                y1 = y2;
                y2 = t;
            }
            if (y1 >= my || y2 < my) continue;
            long z = (x1 * (y2 - y1) + (x2 - x1) * (my - y1)) - mx * (y2 - y1);
            if (z == 0) return true;
            if (z > 0) res ^= true;
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