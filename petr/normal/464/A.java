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
        int p = in.nextInt();
        String s = in.next();
        for (int i = s.length() - 1; i >= 0; --i) {
            for (char ch = (char) (s.charAt(i) + 1); ch < 'a' + p; ++ch) {
                String first = firstGoodWithPrefix(s.substring(0, i) + ch, n, p);
                if (first != null) {
                    out.println(first);
                    return;
                }
            }
        }
        out.println("NO");
    }

    private String firstGoodWithPrefix(String prefix, int n, int p) {
        for (int i = 0; i < prefix.length(); ++i) {
            if (i >= 1 && prefix.charAt(i) == prefix.charAt(i - 1)) return null;
            if (i >= 2 && prefix.charAt(i) == prefix.charAt(i - 2)) return null;
        }
        if (prefix.length() == n) return prefix;
        if (p == 1) return null;
        if (p == 2) {
            if (n == 2) {
                if (prefix.charAt(0) == 'a') return "ab"; else return "ba";
            }
            return null;
        }
        StringBuilder res = new StringBuilder();
        res.append(prefix);
        for (int i = prefix.length(); i < n; ++i) {
            for (char ch = 'a'; ch <= 'c'; ++ch) {
                if (i >= 1 && ch == res.charAt(i - 1)) continue;
                if (i >= 2 && ch == res.charAt(i - 2)) continue;
                res.append(ch);
                break;
            }
        }
        return res.toString();
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