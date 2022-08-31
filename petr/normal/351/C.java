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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    static final int BUBEN = 50;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
        }
        for (int i = 0; i < n; ++i) {
            b[i] = in.nextInt();
        }
        int[][] matr = new int[BUBEN][BUBEN];
        for (int[] x : matr)
            Arrays.fill(x, Integer.MAX_VALUE);
        for (int i = 0; i < BUBEN; ++i) matr[i][i] = 0;
        for (int j = 0; j < n; ++j) {
            int[][] cm = new int[BUBEN][BUBEN];
            for (int[] x : cm)
                Arrays.fill(x, Integer.MAX_VALUE);
            for (int i = 0; i + 1 < BUBEN; ++i) {
                cm[i + 1][i] = b[j];
                cm[i][i + 1] = a[j];
            }
            matr = mul(matr, cm);
        }
        matr = pow(matr, m);
        out.println(matr[0][0]);
    }

    private int[][] pow(int[][] a, int k) {
        if (k == 0) {
            int[][] matr = new int[BUBEN][BUBEN];
            for (int[] x : matr)
                Arrays.fill(x, Integer.MAX_VALUE);
            for (int i = 0; i < BUBEN; ++i) matr[i][i] = 0;
            return matr;
        }
        if (k % 2 == 0)
            return pow(mul(a, a), k / 2);
        return mul(a, pow(a, k - 1));
    }

    private int[][] mul(int[][] a, int[][] b) {
        int[][] c = new int[BUBEN][BUBEN];
        for (int i = 0; i < BUBEN; ++i)
            for (int j = 0; j < BUBEN; ++j) {
                int mx = Integer.MAX_VALUE;
                for (int k = 0; k < BUBEN; ++k)
                    if (a[i][k] < Integer.MAX_VALUE && b[k][j] < Integer.MAX_VALUE) {
                        mx = Math.min(mx, a[i][k] + b[k][j]);
                    }
                c[i][j] = mx;
            }
        return c;
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