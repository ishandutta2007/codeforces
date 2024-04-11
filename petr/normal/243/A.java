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
		NewFunction solver = new NewFunction();
		solver.solve(1, in, out);
		out.close();
	}
}

class NewFunction {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) a[i] = in.nextInt();
        int[][] nextBit = new int[20][n];
        for (int i = 0; i < 20; ++i)
            for (int j = 0; j < n; ++j) {
                if (j == 0) nextBit[i][j] = -1; else nextBit[i][j] = nextBit[i][j - 1];
                if ((a[j] & (1 << i)) != 0)
                    nextBit[i][j] = j;
            }
        boolean[] seen = new boolean[1 << 20];
        for (int last = 0; last < n; ++last) {
            int at = last;
            int val = a[at];
            while (true) {
                seen[val] = true;
                if (at == 0) break;
                int closest = -1;
                for (int i = 0; i < 20; ++i)
                    if ((val & (1 << i)) == 0)
                        closest = Math.max(closest, nextBit[i][at - 1]);
                if (closest < 0) break;
                at = closest;
                val |= a[at];
            }
        }
        int cnt = 0;
        for (boolean x : seen) if (x) ++cnt;
        out.println(cnt);
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