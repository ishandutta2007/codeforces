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
		TaskF solver = new TaskF();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskF {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[] p = new int[n];
        for (int i = 0; i < n; ++i) p[i] = in.nextInt() - 1;
        if (check(p)) {
            out.println("YES");
        } else {
            out.println("NO");
        }
    }

    private boolean check(int[] p) {
        int n = p.length;
        if (p[0] % 2 != 0) {
            for (int i = 0; i < n - 1 - i; ++i) {
                int t = p[i];
                p[i] = p[n - 1 - i];
                p[n - 1 - i] = t;
            }
        }
        int[] where = new int[n];
        for (int i = 0; i < n; ++i) where[p[i]] = i;
        int stableSide = n / 2 - 6;
        if (stableSide * 2 <= (n + 1) / 2) {
            for (int i = 0; i < p.length; ++i)
                for (int j = i + 1; j < p.length; ++j) {
                    int need = 2 * p[j] - p[i];
                    if (need >= 0 && need < n && where[need] > j) {
                        return true;
                    }
                }
            return false;
        } else {
            for (int i = 0; i < stableSide; ++i)
                if (p[i] % 2 != 0) {
                    return true;
                }
            for (int i = 0; i < stableSide; ++i)
                if (p[n - 1 - i] % 2 == 0) {
                    return true;
                }
            for (int a = stableSide; a <= n - 1 - stableSide; ++a)
                for (int b = a + 1; b <= n - 1 - stableSide; ++b) if (((p[a] + p[b]) & 1) != 0) {
                    int need = 2 * p[b] - p[a];
                    if (need >= 0 && need < n && where[need] > b) {
                        return true;
                    }
                    need = 2 * p[a] - p[b];
                    if (need >= 0 && need < n && where[need] < a) {
                        return true;
                    }
                }
            int[] pEven = new int[(n + 1) / 2];
            int[] pOdd = new int[n / 2];
            int ptrEven = 0;
            int ptrOdd = 0;
            for (int i = 0; i < n; ++i) {
                if ((p[i] & 1) == 0)
                    pEven[ptrEven++] = p[i] >> 1;
                else
                    pOdd[ptrOdd++] = p[i] >> 1;
            }
            return check(pEven) || check(pOdd);
        }
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