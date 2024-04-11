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
        int a = in.nextInt();
        int b = in.nextInt();
        for (int xa = 1; xa < a; ++xa) {
            int ya2 = a * a - xa * xa;
            int ya = (int) Math.round(Math.sqrt(ya2));
            if (ya * ya != ya2) continue;
            int xb = -ya * b;
            if (xb % a != 0) continue;
            xb /= a;
            int yb = xa * b;
            if (yb % a != 0) continue;
            yb /= a;
            if (xb == xa || yb == ya) continue;
            out.println("YES");
            out.println(0 + " " + 0);
            out.println(xa + " " + ya);
            out.println(xb + " " + yb);
            return;
        }
        out.println("NO");
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