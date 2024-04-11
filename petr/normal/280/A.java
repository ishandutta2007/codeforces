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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        double w = in.nextInt();
        double h = in.nextInt();
        if (w < h) {
            double t = w;
            w = h;
            h = t;
        }
        int alphaInt = in.nextInt();
        double res;
        if (alphaInt == 0 || alphaInt == 180) {
            res = h * w;
        } else if (alphaInt == 90) {
            res = h * h;
        } else {
            if (alphaInt > 90) alphaInt = 180 - alphaInt;
            double alpha = alphaInt / 180.0 * Math.PI;
            double diag = Math.sqrt(h * h + w * w);
            double a = Math.cos(alpha);
            double b = Math.sin(alpha);
            double c = w / 2 * a + h / 2 * b - w / 2;
            double r1 = c / a;
            double r2 = c / b;
            c = w / 2 * b + h / 2 * a - h / 2;
            double r3 = c / a;
            double r4 = c / b;
            if (r1 < 0 || r2 < 0 || r3 < 0 || r4 < 0) {
                res = h * h / Math.sin(alpha);
            } else {
                res = h * w - r1 * r2 - r3 * r4;
            }
        }
        out.printf("%.10f\n", res);
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