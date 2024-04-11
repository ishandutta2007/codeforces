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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
        long a = in.nextLong();
        long b = in.nextLong();
        int k = in.nextInt();
        int lcm = 1;
        for (int i = 2; i <= k; ++i) {
            lcm = lcm * i / gcd(lcm, i);
        }
        int[] jump = new int[k + lcm];
        for (int i = 1; i < jump.length; ++i) {
            int mx = 1;
            long num = b + i;
            for (int j = 2; j <= k; ++j) {
                int cur = (int) (num % j);
                if (num - cur >= b && cur > mx) {
                    mx = cur;
                }
            }
            jump[i] = mx;
        }
        a -= b;
        long res = 0;
        if (a >= jump.length) {
            long[] seenAt = new long[jump.length];
            long[] seenA = new long[jump.length];
            Arrays.fill(seenA, -1);
            Arrays.fill(seenAt, -1);
            while (a >= jump.length) {
                int cur = (int) ((a - k) % lcm + k);
                if (seenA[cur] >= 0) {
                    long deltaA = seenA[cur] - a;
                    long deltaRes = res - seenAt[cur];
                    long whole = (a - jump.length) / deltaA;
                    a -= whole * deltaA;
                    res += whole * deltaRes;
                }
                seenA[cur] = a;
                seenAt[cur] = res;
                a -= jump[cur];
                ++res;
            }
        }
        while (a > 0) {
            ++res;
            a -= jump[((int) a)];
        }
        out.println(res);
	}

    private int gcd(int a, int b) {
        while (b > 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
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

    public long nextLong() {
        return Long.parseLong(next());
    }
}