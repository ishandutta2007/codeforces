import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
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
        int k = in.nextInt();
        int[] q = new int[n];
        for (int i = 0; i < n; ++i) {
            q[i] = in.nextInt() - 1;
        }
        int[] s = new int[n];
        for (int i = 0; i < n; ++i) {
            s[i] = in.nextInt() - 1;
        }
        int[] invq = new int[n];
        for (int i = 0; i < n; ++i) {
            invq[q[i]] = i;
        }
        boolean[] hit = new boolean[2 * k + 1];
        int[] at = new int[n];
        for (int i = 0; i < n; ++i) {
            at[i] = i;
        }
        for (int i = 0; i < k; ++i) {
            at = mul(at, invq);
        }
        for (int i = 0; i < hit.length; ++i) {
            if (Arrays.equals(at, s))
                hit[i] = true;
            at = mul(at, q);
        }
        if (hit[k]) {
            if (k == 0)
                out.println("YES");
            else
                out.println("NO");
            return;
        }
        if (k == 0) {
            out.println("NO");
        }
        int down = 0;
        int up = 0;
        while (down <= k && !hit[k - down]) ++down;
        while (up <= k && !hit[k + up]) ++up;
        if (down == 1 && up == 1) {
            if (k == 1)
                out.println("YES");
            else
                out.println("NO");
            return;
        }
        if (down <= k && down % 2 == k % 2) {
            out.println("YES");
            return;
        }
        if (up <= k && up % 2 == k % 2) {
            out.println("YES");
            return;
        }
        out.println("NO");
    }

    private int[] mul(int[] a, int[] b) {
        int[] c = new int[a.length];
        for (int i = 0; i < a.length; ++i)
            c[i] = a[b[i]];
        return c;
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