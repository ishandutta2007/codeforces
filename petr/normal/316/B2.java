import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
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
		TaskB1 solver = new TaskB1();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB1 {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int x = in.nextInt() - 1;
        int[] a = new int[n];
        int[] chainPos = new int[n];
        for (int i = 0; i < n; ++i) a[i] = in.nextInt() - 1;
        boolean[] tail = new boolean[n];
        Arrays.fill(tail, true);
        for (int i = 0; i < n; ++i) if (a[i] >= 0) tail[a[i]] = false;
        boolean[] possiblePos = new boolean[n + 1];
        possiblePos[0] = true;
        for (int i = 0; i < n; ++i) if (tail[i]) {
            boolean hasBeaver = false;
            int at = i;
            int len = 0;
            while (at >= 0) {
                if (at == x) hasBeaver = true;
                ++len;
                at = a[at];
            }
            if (!hasBeaver) {
                for (int j = n - len; j >= 0; --j)
                    if (possiblePos[j]) possiblePos[j + len] = true;
            }
        }
        int beaverOffset = 0;
        while (x >= 0) {
            ++beaverOffset;
            x = a[x];
        }
        for (int i = 0; i <= n; ++i) if (possiblePos[i]) {
            out.println(i + beaverOffset);
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