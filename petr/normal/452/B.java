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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        if (n < m) {
            int[] x = doit(n, m);
            for (int i = 0; i < 4; ++i) {
                out.println(x[i * 2] + " " + x[i * 2 + 1]);
            }
        } else {
            int[] x = doit(m, n);
            for (int i = 0; i < 4; ++i) {
                out.println(x[i * 2 + 1] + " " + x[i * 2]);
            }
        }
    }

    int[] doit(int n, int m) {
        double len1 = 0;
        double d = Math.sqrt(n * n + m * m);
        if (n >= 1 && m >= 1) {
            len1 = 2 * d + m;
        }
        double len2 = 0;
        if (n == 0 && m >= 3)
            len2 = 3 * m - 2;
        double len3 = 0;
        if (n > 0) {
            double d2 = Math.sqrt((n - 1) * (n - 1) + m * m);
            len3 = d + 2 * d2;
        }
        if (len1 >= len2 && len1 >= len3) {
            return new int[]{0, 0, n, m, n, 0, 0, m};
        } else if (len2 >= len3) {
            return new int[]{0, 1, 0, m, 0, 0, 0, m - 1};
        } else {
            return new int[]{1, 0, n, m, 0, 0, n - 1, m};
        }
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