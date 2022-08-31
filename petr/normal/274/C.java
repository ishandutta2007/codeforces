import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.math.BigInteger;
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
        int[] x = new int[n];
        int[] y = new int[n];
        for (int i = 0; i < n; ++i) {
            x[i] = in.nextInt();
            y[i] = in.nextInt();
        }
        double res = -1.0;
        long[][] a = new long[n][n];
        long[][] b = new long[n][n];
        long[][] c = new long[n][n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                a[i][j] = 2 * (x[j] - x[i]);
                b[i][j] = 2 * (y[j] - y[i]);
                c[i][j] = x[i] * x[i] + y[i] * y[i] - x[j] * x[j] - y[j] * y[j];
            }
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    long x1 = x[i];
                    long y1 = y[i];
                    long x2 = x[j];
                    long y2 = y[j];
                    long x3 = x[k];
                    long y3 = y[k];
                    if ((x2 - x1) * (x3 - x1) + (y2 - y1) * (y3 - y1) <= 0) continue;
                    if ((x3 - x2) * (x1 - x2) + (y3 - y2) * (y1 - y2) <= 0) continue;
                    if ((x1 - x3) * (x2 - x3) + (y1 - y3) * (y2 - y3) <= 0) continue;
                    res = updateRes(n, x, y, res, a, b, c, i, j, k, x1, y1);
                }
                {
                    long d = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
                    long sx = x[i] + x[j];
                    long sy = y[i] + y[j];
                    long dx = x[j] - x[i];
                    long dy = y[j] - y[i];
                    boolean any = false;
                    int anyK = -1;
                    outer: for (int k = 0; k < n; ++k)
                        for (int t = k + 1; t < n; ++t) {
                            long nd = (x[k] - x[t]) * (x[k] - x[t]) + (y[k] - y[t]) * (y[k] - y[t]);
                            long nsx = x[k] + x[t];
                            long nsy = y[k] + y[t];
                            long ndx = x[t] - x[k];
                            long ndy = y[t] - y[k];
                            if (d == nd && sx == nsx && sy == nsy && dx * ndy - dy * ndx != 0) {
                                any = true;
                                anyK = k;
                                break outer;
                            }
                        }
                    if (any) res = updateRes(n, x, y, res, a, b, c, i, j, anyK, x[i], y[i]);
                }
            }
        out.printf("%.10f\n", res);
    }

    private double updateRes(int n, int[] x, int[] y, double res, long[][] a, long[][] b, long[][] c, int i, int j, int k, long x1, long y1) {
        long a1 = a[i][j];
        long a2 = a[j][k];
        long b1 = b[i][j];
        long b2 = b[j][k];
        long c1 = c[i][j];
        long c2 = c[j][k];
        long z = a1 * b2 - a2 * b1;
        if (z == 0) return res;
        long px = -(c1 * b2 - c2 * b1);
        long py = -(a1 * c2 - a2 * c1);
        BigInteger d = BigInteger.valueOf(px - z * x1).pow(2).add(BigInteger.valueOf(py - z * y1).pow(2));
        boolean ok = true;
        for (int t = 0; t < n; ++t) {
            BigInteger dd = BigInteger.valueOf(px - z * x[t]).pow(2).add(BigInteger.valueOf(py - z * y[t]).pow(2));
            if (dd.compareTo(d) < 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            res = Math.max(res, Math.sqrt(d.doubleValue()) / Math.abs(z));
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