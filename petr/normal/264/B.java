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
        for (int i = 0; i < n; ++i) a[i] = in.nextInt();
        int maxA = 3;
        for (int x : a) maxA = Math.max(maxA, x + 1);
        int[] di = new int[maxA];
        for (int i = 2; i < maxA; ++i) {
            if (di[i] == 0) {
                di[i] = i;
                if (i * (long) i < maxA) {
                    for (int j = i * i; j < maxA; j += i)
                        if (di[j] == 0) di[j] = i;
                }
            }
        }
        int[] best = new int[maxA];
        int res = 0;
        for (int x : a) {
            int cb = 0;
            int tmp = x;
            while (tmp > 1) {
                cb = Math.max(cb, best[di[tmp]]);
                tmp /= di[tmp];
            }
            ++cb;
            res = Math.max(res, cb);
            tmp = x;
            while (tmp > 1) {
                best[di[tmp]] = Math.max(cb, best[di[tmp]]);
                tmp /= di[tmp];
            }
        }
        out.println(res);
    }
}

class InputReader {
    BufferedReader reader;
    StringTokenizer tokenizer;

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