import java.util.Arrays;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.StringTokenizer;

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
        String[] field = new String[n];
        for (int i = 0; i < n; ++i) field[i] = in.next();
        char[][] attacks = new char[2 * n - 1][2 * n - 1];
        for (char[] x : attacks) Arrays.fill(x, 'x');
        attacks[n - 1][n - 1] = 'o';
        for (int r0 = 0; r0 < n; ++r0)
            for (int c0 = 0; c0 < n; ++c0)
                if (field[r0].charAt(c0) == 'o')
                    for (int r1 = 0; r1 < n; ++r1)
                        for (int c1 = 0; c1 < n; ++c1)
                            if (field[r1].charAt(c1) == '.') {
                                attacks[n - 1 + (r1 - r0)][n - 1 + (c1 - c0)] = '.';
                            }
        boolean ok = true;
        for (int r1 = 0; r1 < n; ++r1)
            for (int c1 = 0; c1 < n; ++c1)
                if (field[r1].charAt(c1) == 'x') {
                    boolean found = false;
                    for (int r0 = 0; r0 < n; ++r0)
                        for (int c0 = 0; c0 < n; ++c0)
                            if (field[r0].charAt(c0) == 'o') {
                                if (attacks[n - 1 + (r1 - r0)][n - 1 + (c1 - c0)] == 'x') {
                                    found = true;
                                }
                            }
                    if (!found) ok = false;
                }
        if (ok) {
            out.println("YES");
            for (char[] x : attacks) {
                out.println(new String(x));
            }
        } else {
            out.println("NO");
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