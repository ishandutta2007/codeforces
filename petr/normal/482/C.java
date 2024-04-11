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
        String[] lines = new String[n];
        for (int i = 0; i < n; ++i) {
            lines[i] = in.next();
        }
        int len = lines[0].length();
        long[] ambiguous = new long[1 << len];
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j) {
                String a = lines[i];
                String b = lines[j];
                int eq = 0;
                for (int t = 0; t < len; ++t) if (a.charAt(t) == b.charAt(t)) eq |= 1 << t;
                ambiguous[eq] |= 1L << i;
                ambiguous[eq] |= 1L << j;
            }
        for (int i = (1 << len) - 1; i >= 0; --i) {
            for (int j = 0; j < len; ++j) {
                ambiguous[i & ~(1 << j)] |= ambiguous[i];
            }
        }
        double res = 0.0;
        for (int i = 0; i < (1 << len) - 1; ++i) {
            double numFinish = 0;
            int cnt = 0;
            for (int j = 0; j < len; ++j) if ((i & (1 << j)) == 0) {
                long delta = ~ambiguous[i | (1 << j)] & ambiguous[i];
                numFinish += Long.bitCount(delta);
            } else {
                ++cnt;
            }
            for (int t = 2; t <= cnt; ++t) numFinish *= t;
            for (int t = len; t >= len - cnt; --t) {
                numFinish /= t;
            }
            res += numFinish * (cnt + 1);
        }
        res /= n;
        Locale.setDefault(Locale.US);
        out.println(String.format("%.20f\n", res));
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