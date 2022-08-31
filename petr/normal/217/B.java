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
        int r = in.nextInt();
        int minErrors = (int) 1e9;
        int minQ = -1;
        for (int q = 1; q <= r; ++q) {
            int a = r;
            int b = q;
            int errors = -1;
            int steps = 0;
            while (b > 0) {
                int whole = a / b;
                int t = a - whole * b;
                a = b;
                b = t;
                errors += whole - 1;
                steps += whole;
            }
            if (a != 1) continue;
            if (steps == n) {
                if (errors < minErrors) {
                    minErrors = errors;
                    minQ = q;
                }
            }
        }
        if (minErrors < 0) minErrors = 0;
        if (minQ < 0) {
            out.println("IMPOSSIBLE");
        } else {
            out.println(minErrors);
            int a = r;
            int b = minQ;
            boolean[] seq = new boolean[n];
            boolean flag = false;
            int pos = n - 1;
            while (b > 0) {
                int whole = a / b;
                int t = a - whole * b;
                a = b;
                b = t;
                for (int i = 0; i < whole; ++i) {
                    seq[pos--] = flag;
                }
                flag ^= true;
            }
            seq[0] ^= true;
            for (int i = 0; i < n; ++i)
                if (seq[i] == seq[0]) out.print("T"); else out.print("B");
            out.println();
        }
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