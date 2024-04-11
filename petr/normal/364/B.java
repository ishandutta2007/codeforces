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
        int d = in.nextInt();
        int[] c = new int[n];
        for (int i = 0; i < n; ++i) c[i] = in.nextInt();
        int total = 0;
        for (int x : c) total += x;
        boolean[] canSum = new boolean[total + 1];
        canSum[0] = true;
        for (int x : c)
            for (int i = total - x; i >= 0; --i)
                if (canSum[i])
                    canSum[i + x] = true;
        int max = 0;
        int days = 0;
        while (true) {
            int nmax = max;
            for (int i = max + 1; i <= total && i <= max + d; ++i)
                if (canSum[i])
                    nmax = i;
            if (nmax == max) break;
            max = nmax;
            ++days;
        }
        out.println(max + " " + days);
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