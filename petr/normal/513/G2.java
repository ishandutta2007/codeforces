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
		TaskG1 solver = new TaskG1();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskG1 {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        int[] p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = in.nextInt() - 1;
        }
        double[][] pr = new double[n][];
        double[][] npr = new double[n][];
        for (int i = 0; i < n; ++i) {
            pr[i] = new double[i];
            npr[i] = new double[i];
            for (int j = 0; j < i; ++j) {
                pr[i][j] = p[j] > p[i] ? 1.0 : 0.0;
            }
        }
        for (int step = 0; step < k; ++step) {
            for (double[] tmp : npr) Arrays.fill(tmp, 0.0);
            for (int l = 0; l < n; ++l) {
                for (int r = l; r < n; ++r) {
                    for (int a = 0; a < n; ++a) {
                        int da;
                        if (l <= a && r >= a) da = r + l - a; else da = a;
                        for (int b = 0; b < a; ++b) {
                            int db;
                            if (l <= b && r >= b) db = r + l - b; else db = b;
                            if (da > db) {
                                npr[da][db] += pr[a][b];
                            } else {
                                npr[db][da] += 1.0 - pr[a][b];
                            }
                        }
                    }
                }
            }
            for (int a = 0; a < n; ++a)
                for (int b = 0; b < a; ++b)
                    pr[a][b] = npr[a][b] / (n * (n + 1) / 2);
        }
        double res = 0.0;
        for (int a = 0; a < n; ++a)
            for (int b = 0; b < a; ++b)
                res += pr[a][b];
        out.println(res);
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