import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Locale;
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
		Locale.setDefault(Locale.US);
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
        int k = in.nextInt();
        int[][] y = new int[n][k + 1];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= k; ++j) {
                y[i][j] = in.nextInt();
            }
        }
        double[] area = new double[n];
        for (int j = 0; j < k; ++j) {
            int[] left = new int[n];
            int[] right = new int[n];
            for (int i = 0; i < n; ++i) {
                left[i] = y[i][j];
                right[i] = y[i][j + 1];
            }
            updateArea(left, right, area);
        }
        for (double x : area) {
            out.println(String.format("%.20f", x));
        }
    }

    private void updateArea(int[] left, int[] right, double[] area) {
        int n = left.length;
        double[] x = new double[2 * n + 5];
        double[] y = new double[2 * n + 5];
        double[] nx = new double[2 * n + 5];
        double[] ny = new double[2 * n + 5];
        int cnt = 2;
        x[0] = 0;
        y[0] = 0;
        x[1] = 1;
        y[1] = 0;
        double ca = 0;
        for (int which = 0; which < n; ++which) {
            int l = left[which];
            int r = right[which];
            int ncnt = 0;
            int state = 0;
            for (int i = 0; i < cnt; ++i) {
                double cx = x[i];
                double cy = y[i];
                double wy = l + (r - l) * cx;
                if (wy < cy - 1e-10) {
                    if (state == 1) {
                        double min = x[i - 1];
                        double max = x[i];
                        while (max - min > 1e-15) {
                            double middle = (min + max) / 2;
                            double val = y[i - 1] + (y[i] - y[i - 1]) / (x[i] - x[i - 1]) * (middle - x[i - 1]);
                            double got = l + middle * (r - l);
                            if (got > val) {
                                min = middle;
                            } else {
                                max = middle;
                            }
                        }
                        nx[ncnt] = max;
                        ny[ncnt] = l + max * (r - l);
                        ++ncnt;
                        state = 2;
                    }
                    nx[ncnt] = cx;
                    ny[ncnt] = cy;
                    ++ncnt;
                } else if (state == 0) {
                    if (i == 0) {
                        nx[ncnt] = 0;
                        ny[ncnt] = l;
                        ++ncnt;
                    } else {
                        double min = x[i - 1];
                        double max = x[i];
                        while (max - min > 1e-15) {
                            double middle = (min + max) / 2;
                            double val = y[i - 1] + (y[i] - y[i - 1]) / (x[i] - x[i - 1]) * (middle - x[i - 1]);
                            double got = l + middle * (r - l);
                            if (got > val) {
                                max = middle;
                            } else {
                                min = middle;
                            }
                        }
                        nx[ncnt] = max;
                        ny[ncnt] = l + max * (r - l);
                        ++ncnt;
                    }
                    state = 1;
                }
            }
            if (state == 1) {
                nx[ncnt] = 1;
                ny[ncnt] = r;
                ++ncnt;
                state = 2;
            }
            double[] tmp = x;
            x = nx;
            nx = tmp;
            tmp = y;
            y = ny;
            ny = tmp;
            cnt = ncnt;
            double na = 0;
            for (int i = 0; i + 1 < cnt; ++i) {
                na += (x[i + 1] - x[i]) * (y[i] + y[i + 1]) / 2;
            }
            area[which] += na - ca;
            ca = na;
        }
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