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
        out.println((n + 1) + 3 * n);
        double[] x = new double[(n + 1) + 3 * n];
        double[] y = new double[(n + 1) + 3 * n];
        int pos = 0;
        double edgeLen = 5.0 / Math.sin(Math.PI / 10);
        for (int i = 0; i < n + 1; ++i) {
            out.printf("%.20f %.20f\n", (i * edgeLen), 0.0);
            x[pos] = i * edgeLen;
            y[pos] = 0;
            ++pos;
        }
        double dx1 = edgeLen * Math.cos(-Math.PI / 5);
        double dy1 = edgeLen * Math.sin(-Math.PI / 5);
        double dx2 = edgeLen - dx1;
        double dy2 = dy1;
        double dx3 = edgeLen / 2.0;
        double dy3 = edgeLen * Math.cos(Math.PI / 10) + dy1;
        for (int i = 0; i < n; ++i) {
            double sx = i * edgeLen;
            double sy = 0.0;
            out.printf("%.20f %.20f\n", (sx + dx1), (sy + dy1));
            x[pos] = sx + dx1;
            y[pos] = sy + dy1;
            ++pos;
            out.printf("%.20f %.20f\n", (sx + dx2), (sy + dy2));
            x[pos] = sx + dx2;
            y[pos] = sy + dy2;
            ++pos;
            out.printf("%.20f %.20f\n", (sx + dx3), (sy + dy3));
            x[pos] = sx + dx3;
            y[pos] = sy + dy3;
            ++pos;
        }
        for (int i = 0; i < n; ++i) {
            out.println((i + 1) + " " + (n + 1 + 3 * i + 3) + " " + (i + 2) + " " + (n + 1 + 3 * i + 1) + " " + (n + 1 + 3 * i + 2));
            //check(x, y, i + 1, (n + 1 + 3 * i + 3), (i + 2), (n + 1 + 3 * i + 1), (n + 1 + 3 * i + 2));
        }
        for (int i = 0; i < n; ++i) {
            if (i > 0) out.print(" ");
            out.print((i + 1) + " " + (n + 1 + 3 * i + 1) + " " + (n + 1 + 3 * i + 3) + " " + (n + 1 + 3 * i + 2));
        }
        for (int i = n; i >= 0; --i) {
            out.print(" " + (i + 1));
        }
        out.println();
	}

    }

class InputReader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

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