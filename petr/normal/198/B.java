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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        String left = in.next();
        String right = in.next();
        String[] sides = new String[]{left, right};
        int[] when = new int[2 * n];
        Arrays.fill(when, -1);
        when[0] = 0;
        int[] queue = new int[2 * n + 10];
        int qt = 0;
        int qh = 1;
        queue[0] = 0;
        while (qt < qh) {
            int cur = queue[qt++];
            int cside = cur & 1;
            int cpos = cur >> 1;
            int nwhen = when[cur] + 1;
            {
                int nside = cside;
                int npos = cpos + 1;
                if (npos >= n) {
                    out.println("YES");
                    return;
                }
                if (npos >= nwhen) {
                    int nat = (npos << 1) + nside;
                    if (when[nat] < 0 && sides[nside].charAt(npos) == '-') {
                        when[nat] = nwhen;
                        queue[qh++] = nat;
                    }
                }
            }
            {
                int nside = cside;
                int npos = cpos - 1;
                if (npos >= n) {
                    out.println("YES");
                    return;
                }
                if (npos >= nwhen) {
                    int nat = (npos << 1) + nside;
                    if (when[nat] < 0 && sides[nside].charAt(npos) == '-') {
                        when[nat] = nwhen;
                        queue[qh++] = nat;
                    }
                }
            }
            {
                int nside = 1 - cside;
                int npos = cpos + k;
                if (npos >= n) {
                    out.println("YES");
                    return;
                }
                if (npos >= nwhen) {
                    int nat = (npos << 1) + nside;
                    if (when[nat] < 0 && sides[nside].charAt(npos) == '-') {
                        when[nat] = nwhen;
                        queue[qh++] = nat;
                    }
                }
            }
        }
        out.println("NO");
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

    public int nextInt() {
        return Integer.parseInt(next());
    }

    }