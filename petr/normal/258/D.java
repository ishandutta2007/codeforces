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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] p = new int[n];
        for (int i = 0; i < n; ++i) p[i] = in.nextInt() - 1;
        int[] a = new int[m];
        int[] b = new int[m];
        for (int i = 0; i < m; ++i) {
            a[i] = in.nextInt() - 1;
            b[i] = in.nextInt() - 1;
        }
        double[][] prThisOrder = new double[n][n];
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                prThisOrder[i][j] = 1.0;
        double[] sa = new double[n];
        double[] sb = new double[n];
        for (int i = m - 1; i >= 0; --i) {
            int ca = a[i];
            int cb = b[i];
            System.arraycopy(prThisOrder[ca], 0, sa, 0, n);
            System.arraycopy(prThisOrder[cb], 0, sb, 0, n);
            prThisOrder[ca][cb] = prThisOrder[cb][ca] = 0.5;
            for (int other = 0; other < n; ++other) {
                if (other == ca || other == cb) continue;
                prThisOrder[ca][other] = 0.5 * (sa[other] + sb[other]);
                prThisOrder[other][ca] = 1.0 - prThisOrder[ca][other];
                prThisOrder[cb][other] = 0.5 * (sa[other] + sb[other]);
                prThisOrder[other][cb] = 1.0 - prThisOrder[cb][other];
            }
        }
        double res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j)
                if (p[i] < p[j]) {
                    res += prThisOrder[j][i];
                } else {
                    res += prThisOrder[i][j];
                }
        }
        out.printf("%.9f\n", res);
	}
}

class InputReader {
    BufferedReader reader;
    StringTokenizer tokenizer;

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