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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    static final int MODULO = (int) 1e9 + 7;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[] invs = new int[n + 1];
        invs[1] = 1;
        for (int i = 2; i <= n; ++i) {
            invs[i] = (int) ((MODULO - (MODULO / i) * (long) invs[MODULO % i] % MODULO) % MODULO);
        }
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) a[i] = in.nextInt();
        int[] at = new int[n + 1];
        Arrays.fill(at, -1);
        for (int i = 0; i < n; ++i) if (a[i] > 0) at[a[i]] = i;
        int first = -1;
        for (int i = 1; i <= n; ++i) if (at[i] >= 0) {
            first = i;
            break;
        }
        if (first < 0) {
            int res = 1;
            for (int i = 0; i < n - 1; ++i) {
                res += res;
                if (res >= MODULO) res -= MODULO;
            }
            out.println(res);
            return;
        }
        int left = 0;
        int right = n - 1;
        int toFill = 0;
        long res = 1;
        for (int what = n; what > first; --what) if (at[what] >= 0) {
            int fillRight;
            int fillLeft;
            if (at[first] < at[what]) {
                fillRight = right - at[what];
                fillLeft = toFill - fillRight;
            } else {
                fillLeft = at[what] - left;
                fillRight = toFill - fillLeft;
            }
            if (fillLeft < 0 || fillRight < 0) {
                out.println(0);
                return;
            }
            for (int i = 0; i < fillRight; ++i) {
                if (a[right] > 0) {
                    out.println(0);
                    return;
                }
                --right;
            }
            for (int i = 0; i < fillLeft; ++i) {
                if (a[left] > 0) {
                    out.println(0);
                    return;
                }
                ++left;
            }
            for (int i = 0; i < fillLeft; ++i) {
                res = res * (fillLeft + fillRight - i) % MODULO;
                res = res * invs[i + 1] % MODULO;
            }
            if (at[first] < at[what]) {
                --right;
            } else {
                ++left;
            }
            toFill = 0;
        } else {
            ++toFill;
        }
        {
            long firstWays = 0;
            if (at[first] - left >= first - 1) {
                long pow = 1;
                for (int i = 0; i < first - 2; ++i) {
                    pow = pow * 2 % MODULO;
                }
                int fillLeft = (at[first] - left) - (first - 1);
                int fillRight = right - at[first];
                for (int i = 0; i < fillLeft; ++i) {
                    pow = pow * (fillLeft + fillRight - i) % MODULO;
                    pow = pow * invs[i + 1] % MODULO;
                }
                firstWays = (firstWays + pow) % MODULO;
            }
            if (right - at[first] >= first - 1 && first > 1) {
                long pow = 1;
                for (int i = 0; i < first - 2; ++i) {
                    pow = pow * 2 % MODULO;
                }
                int fillLeft = at[first] - left;
                int fillRight = right - at[first] - (first - 1);
                for (int i = 0; i < fillLeft; ++i) {
                    pow = pow * (fillLeft + fillRight - i) % MODULO;
                    pow = pow * invs[i + 1] % MODULO;
                }
                firstWays = (firstWays + pow) % MODULO;
            }
            res = res * firstWays % MODULO;
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