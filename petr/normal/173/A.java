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
        String a = in.next();
        String b = in.next();
        int prod = a.length() * b.length();
        int na = 0;
        int nb = 0;
        for (int rem = 0; rem < prod && rem < n; ++rem) {
            int cnt = (n - 1 - rem) / prod + 1;
            char c1 = a.charAt(rem % a.length());
            char c2 = b.charAt(rem % b.length());
            int p1 = "RSP".indexOf(c1);
            int p2 = "RSP".indexOf(c2);
            if ((p1 + 1) % 3 == p2)
                nb += cnt;
            else if ((p1 + 2) % 3 == p2)
                na += cnt;
        }
        out.println(na + " " + nb);
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