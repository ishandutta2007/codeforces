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
        String s = in.next();
        int[] count = new int[26];
        for (int i = 0; i < s.length(); ++i) {
            ++count[s.charAt(i) - 'a'];
        }
        int n = in.nextInt();
        int left = 0;
        int right = s.length() + 1;
        while (right - left > 1) {
            int middle = (left + right) / 2;
            int spent = 0;
            for (int i = 0; i < 26; ++i) {
                spent += (count[i] + middle - 1) / middle;
            }
            if (spent <= n) {
                right = middle;
            } else {
                left = middle;
            }
        }
        if (right > s.length()) {
            out.println(-1);
        } else {
            out.println(right);
            int spent = 0;
            for (int i = 0; i < 26; ++i) {
                int cur = (count[i] + right - 1) / right;
                for (int j = 0; j < cur; ++j) {
                    out.print((char) ('a' + i));
                    ++spent;
                }
            }
            while (spent < n) {
                ++spent;
                out.print('a');
            }
            out.println();
        }
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