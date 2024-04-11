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
        String s = in.next();
        String t = in.next();
        int[] left = new int[s.length() + 1];
        left[0] = 0;
        int cleft = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (cleft < t.length() && s.charAt(i) == t.charAt(cleft))
                ++cleft;
            left[i + 1] = cleft;
        }
        int[] right = new int[s.length() + 1];
        right[s.length()] = 0;
        int cright = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (cright < t.length() && s.charAt(i) == t.charAt(t.length() - 1 - cright)) {
                ++cright;
            }
            right[i] = cright;
        }
        int[] count = new int[t.length() + 1];
        boolean[] ok = new boolean[s.length()];
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            count[0] = 0;
            for (int i = 0; i < t.length(); ++i) {
                count[i + 1] = count[i];
                if (t.charAt(i) == ch)
                    ++count[i + 1];
            }
            for (int i = 0; i < s.length(); ++i) {
                if (s.charAt(i) == ch) {
                    int maxLeft = left[i];
                    int maxRight = right[i + 1];
                    int maxPos = Math.min(t.length() - 1, maxLeft);
                    int minPos = Math.max(0, t.length() - 1 - maxRight);
                    if (minPos <= maxPos) {
                        if (count[maxPos + 1] > count[minPos]) {
                            ok[i] = true;
                        }
                    }
                }
            }
        }
        for (boolean x : ok) {
            if (!x) {
                out.println("No");
                return;
            }
        }
        out.println("Yes");
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

    }