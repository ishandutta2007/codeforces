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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    static final long MODULO = (long) (1e9 + 7);

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        String p = in.next();
        int[] l = new int[p.length() + 1];
        for (int i = 2; i < l.length; ++i) {
            int j = l[i - 1];
            while (true) {
                if (p.charAt(j) == p.charAt(i - 1)) {
                    ++j;
                    break;
                }
                if (j == 0) break;
                j = l[j];
            }
            l[i] = j;
        }
        boolean[] nice = new boolean[l.length];
        int tmp = p.length();
        while (true) {
            nice[tmp] = true;
            if (tmp == 0) break;
            tmp = l[tmp];
        }
        int prev = -p.length();
        long res = 1;
        for (int i = 0; i < m; ++i) {
            int cur = in.nextInt() - 1;
            if (prev + p.length() <= cur) {
                for (int j = prev + p.length(); j < cur; ++j) {
                    res = res * 26 % MODULO;
                }
            } else {
                if (!nice[prev + p.length() - cur]) {
                    res = 0;
                }
            }
            prev = cur;
        }
        for (int j = prev + p.length(); j < n; ++j) {
            res = res * 26 % MODULO;
        }
        out.println(res);
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