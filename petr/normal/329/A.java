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
        int n = in.nextInt();
        String[] field = new String[n];
        for (int i = 0; i < n; ++i) {
            field[i] = in.next();
        }
        boolean haveBadRow = false;
        for (int row = 0; row < n; ++row) {
            boolean bad = true;
            for (int col = 0; col < n; ++col)
                if (field[row].charAt(col) == '.') bad = false;
            haveBadRow |= bad;
        }
        if (!haveBadRow) {
            for (int row = 0; row < n; ++row) {
                for (int col = 0; col < n; ++col)
                    if (field[row].charAt(col) == '.') {
                        out.println(row + 1 + " " + (col + 1));
                        break;
                    }
            }
            return;
        }
        boolean haveBadCol = false;
        for (int col = 0; col < n; ++col) {
            boolean bad = true;
            for (int row = 0; row < n; ++row)
                if (field[row].charAt(col) == '.') bad = false;
            haveBadCol |= bad;
        }
        if (!haveBadCol) {
            for (int col = 0; col < n; ++col) {
                for (int row = 0; row < n; ++row)
                    if (field[row].charAt(col) == '.') {
                        out.println(row + 1 + " " + (col + 1));
                        break;
                    }
            }
            return;
        }
        out.println(-1);
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