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
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
        }
        int[] next = new int[n];
        for (int i = 0; i < n - 1; ++i) next[i] = i + 1;
        next[n - 1] = -1;
        int time = 0;
        int[] toKill1 = new int[n];
        int[] toKill2 = new int[n];
        int nToKill1 = 0;
        for (int i = 0; next[i] >= 0; i = next[i]) {
            if (a[i] > a[next[i]]) {
                toKill1[nToKill1++] = i;
            }
        }
        while (nToKill1 > 0) {
            ++time;
            int nToKill2 = 0;
            int pos = 0;
            while (pos < nToKill1) {
                int start = toKill1[pos];
                int last = next[start];
                ++pos;
                while (pos < nToKill1 && toKill1[pos] == last) {
                    last = next[last];
                    ++pos;
                }
                next[start] = next[last];
                if (next[start] >= 0 && a[start] > a[next[start]]) {
                    toKill2[nToKill2++] = start;
                }
            }
            int[] tmp = toKill1;
            toKill1 = toKill2;
            toKill2 = tmp;
            nToKill1 = nToKill2;
        }
        out.println(time);
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