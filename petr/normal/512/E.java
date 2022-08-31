import java.util.ArrayList;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.List;
import java.io.BufferedReader;
import java.util.Collection;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Collections;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[] a = new int[n - 3];
        int[] b = new int[n - 3];
        for (int i = 0; i < a.length; ++i) {
            a[i] = in.nextInt();
            b[i] = in.nextInt();
        }
        List<String> sol = canonicalize(n, a, b, false);
        for (int i = 0; i < a.length; ++i) {
            a[i] = in.nextInt();
            b[i] = in.nextInt();
        }
        List<String> sol2 = canonicalize(n, a, b, true);
        Collections.reverse(sol2);
        sol.addAll(sol2);
        out.println(sol.size());
        for (String x : sol) {
            out.println(x);
        }
    }

    private List<String> canonicalize(int n, int[] a, int[] b, boolean printSecond) {
        List<String> res = new ArrayList<>();
        boolean[] have = new boolean[n + 1];
        while (true) {
            have[2] = true;
            have[n] = true;
            for (int i = 0; i < a.length; ++i) if (a[i] == 1) have[b[i]] = true; else if (b[i] == 1) have[a[i]] = true;
            int missing;
            for (missing = 3; missing < n; ++missing) if (!have[missing]) break;
            if (missing >= n) break;
            int left = missing - 1;
            int right = missing + 1;
            while (!have[right]) ++right;
            int where;
            for (where = 0; where < a.length; ++where) if ((a[where] == left && b[where] == right) || (a[where] == right && b[where] == left)) {
                break;
            }
            if (where >= a.length) throw new RuntimeException();
            int other = right - 1;
            for (int i = 0; i < a.length; ++i) if ((a[i] == right && b[i] > left)) other = Math.min(other, b[i]); else if (b[i] == right && a[i] > left) other = Math.min(other, a[i]);
            if (printSecond) {
                res.add(1 + " " + other);
            } else {
                res.add(left + " " + right);
            }
            a[where] = 1;
            b[where] = other;
        }
        return res;
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