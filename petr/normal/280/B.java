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
        int[] s = new int[n];
        for (int i = 0; i < n; ++i) {
            s[i] = in.nextInt();
        }
        int res = doit(n, s);
        int[] ss = new int[n];
        for (int i = 0; i < n; ++i) {
            ss[i] = s[n - 1 - i];
        }
        res = Math.max(res, doit(n, ss));
        out.println(res);
    }

    private int doit(int n, int[] s) {
        int[] stack = new int[n];
        int sp = 0;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            while (sp > 0 && stack[sp - 1] < s[i]) {
                --sp;
            }
            if (sp > 0) {
                res = Math.max(res, stack[sp - 1] ^ s[i]);
            }
            stack[sp++] = s[i];
        }
        return res;
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