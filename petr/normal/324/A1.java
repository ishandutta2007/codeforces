import java.util.Map;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.HashMap;
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
		Trees solver = new Trees();
		solver.solve(1, in, out);
		out.close();
	}
}

class Trees {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
        }
        Map<Integer, Integer> first = new HashMap<Integer, Integer>();
        long[] positiveUpTo = new long[n + 1];
        long best = Long.MIN_VALUE;
        int bs = -1;
        int be = -1;
        for (int i = 0; i < n; ++i) {
            positiveUpTo[i + 1] = positiveUpTo[i];
            if (a[i] > 0) positiveUpTo[i + 1] += a[i];
            Integer start = first.get(a[i]);
            if (start != null) {
                int s = start;
                long cur = positiveUpTo[i] - positiveUpTo[s + 1] + 2 * a[i];
                if (cur > best) {
                    best = cur;
                    bs = s;
                    be = i;
                }
            } else {
                first.put(a[i], i);
            }
        }
        int[] toKill = new int[n];
        int kill = 0;
        for (int i = 0; i < n; ++i)
            if (i < bs || i > be || (i > bs && i < be && a[i] <= 0)) {
                toKill[kill++] = i;
            }
        out.println(best + " " + kill);
        for (int i = 0; i < kill; ++i) {
            if (i > 0) out.print(" ");
            out.print(toKill[i] + 1);
        }
        out.println();
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