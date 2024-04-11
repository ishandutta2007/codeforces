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
        String s = in.next();
        int n = s.length();
        int[] count = new int[9 * n + 1];
        for (int start = 0; start < n; ++start) {
            int cur = 0;
            for (int end = start; end < n; ++end) {
                cur += s.charAt(end) - '0';
                ++count[cur];
            }
        }
        long res = 0;
        if (a == 0) {
            for (int rowSum = 0; rowSum < count.length; ++rowSum) {
                for (int colSum = 0; colSum < count.length; ++colSum) {
                    if (rowSum > 0 && colSum > 0) break;
                    res += count[rowSum] * (long) count[colSum];
                }
            }
        } else {
            for (int rowSum = 1; rowSum < count.length; ++rowSum)
                if (a % rowSum == 0 && a / rowSum < count.length)
                    res += count[rowSum] * (long) count[a / rowSum];
        }
        out.println(res);
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