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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        Locale.setDefault(Locale.US);
        int n = in.nextInt();
        int k = in.nextInt();
        double[] pr = new double[n + 2];
        double[] gain = new double[n + 2];
        double[] prStay = new double[n + 2];
        double[] prPrev = new double[n + 2];
        double prSee = 1.0 / k;
        double prNotSee = (k - 1) / (double) k;
        for (int i = 1; i <= n; ++i) {
            gain[i] = i * (double) (i + 3) / 2 / (i + 1);
            prStay[i] = prNotSee + prSee * i / (double) (i + 1);
            prPrev[i] = prSee / i;
        }
        pr[1] = 1.0;
        int max = 1;
        double res = 0.0;
        for (int step = 0; step < n; ++step) {
            for (int i = max + 1; i >= 1; --i) {
                res = res + pr[i] * prSee * gain[i];
                pr[i] = pr[i] * prStay[i] + pr[i - 1] * prPrev[i];
            }
            ++max;
            if (pr[max] < 1e-10 / n) {
                pr[max - 1] += pr[max];
                --max;
            }
        }
        out.println(String.format("%.12f", res * k));
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