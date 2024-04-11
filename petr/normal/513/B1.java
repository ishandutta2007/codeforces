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
		TaskB1 solver = new TaskB1();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB1 {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        long m = in.nextLong();
        --m;
        int[] res = new int[n];
        int left = 0;
        int right = n - 1;
        for (int i = 0; i < n - 1; ++i) {
            if (m < (1 << (n - 2 - i))) {
                res[left++] = i + 1;
            } else {
                m -= 1 << (n - 2 - i);
                res[right--] = i + 1;
            }
        }
        res[left] = n;
        for (int i = 0; i < n; ++i) {
            if (i > 0) out.print(" ");
            out.print(res[i]);
        }
        out.println();
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

    public long nextLong() {
        return Long.parseLong(next());
    }

}