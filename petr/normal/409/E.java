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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        double x = in.nextDouble();
        for (int a = 1; a <= 10; ++a)
            for (int b = 1; b <= 10; ++b) {
                double s1 = a / 2.0;
                double s2 = b;
                double s3 = Math.sqrt(s1 * s1 + s2 * s2);
                double y = s1 * s2 / s3;
                if (Math.abs(x - y) < 0.6e-6) {
                    out.println(a + " " + b);
                    return;
                }
            }
        throw new RuntimeException();
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

    public double nextDouble() {
        return Double.parseDouble(next());
    }
}