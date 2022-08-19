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
        int[] a = new int[n];
        int total = 0;
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
            total += a[i];
        }
        int p = in.nextInt();
        if (total <= p) {
            out.println(n);
            return;
        }
        double res = 0.0;
        for (int blocker = 0; blocker < n; ++blocker) {
            double[][] pr = new double[n][p + 1];
            pr[0][0] = 1.0;
            for (int i = 0; i < n; ++i) {
                if (i == blocker) continue;
                int cur = a[i];
                for (int oldCnt = n - 2; oldCnt >= 0; --oldCnt)
                    for (int oldSum = 0; oldSum + cur <= p; ++oldSum)
                        pr[oldCnt + 1][oldSum + cur] += pr[oldCnt][oldSum] / (n - oldCnt) * (oldCnt + 1);
            }
            for (int amt = 0; amt < n; ++amt)
                for (int size = Math.max(0, p - a[blocker] + 1); size <= p; ++size)
                    res += amt * pr[amt][size] / (n - amt);
        }
        out.printf("%.10f\n", res);
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