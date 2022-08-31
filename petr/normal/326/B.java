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
        String s = in.next();
        int[] count = new int[26];
        for (int i = 0; i < s.length(); ++i) {
            ++count[s.charAt(i) - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (count[i] >= 100) {
                for (int j = 0; j < 100; ++j) {
                    out.print((char) ('a' + i));
                }
                out.println();
                return;
            }
        }
        int n = s.length();
        int[][] best = new int[n + 1][n + 1];
        boolean[][] via = new boolean[n + 1][n + 1];
        Arrays.fill(best[0], 0);
        for (int i = 1; i <= n; ++i)
            Arrays.fill(best[i], -1);
        for (int j = 0; j < n; ++j)
            best[1][j] = 1;
        for (int len = 2; len <= n; ++len) {
            for (int start = 0; start + len <= n; ++start) {
                if (s.charAt(start) == s.charAt(start + len - 1)) {
                    best[len][start] = 2 + best[len - 2][start + 1];
                } else {
                    if (best[len - 1][start] > best[len - 1][start + 1]) {
                        via[len][start] = false;
                        best[len][start] = best[len - 1][start];
                    } else {
                        via[len][start] = true;
                        best[len][start] = best[len - 1][start + 1];
                    }
                }
            }
        }
        int res = 0;
        int rlen = 0;
        int rstart = 0;
        for (int len = 1; len <= n; ++len)
            for (int start = 0; start + len <= n; ++start)
                if (best[len][start] > res) {
                    res = best[len][start];
                    rlen = len;
                    rstart = start;
                }
        int offset = 0;
        char[] rstr = new char[res];
        while (offset <= res - 1 - offset) {
            if (s.charAt(rstart) == s.charAt(rstart + rlen - 1)) {
                rstr[offset] = s.charAt(rstart);
                rstr[res - 1 - offset] = s.charAt(rstart);
                ++offset;
                rlen -= 2;
                ++rstart;
            } else if (via[rlen][rstart]) {
                --rlen;
                ++rstart;
            } else {
                --rlen;
            }
        }
        if (res > 100) {
            char[] nr = new char[100];
            for (int i = 0; i < 50; ++i) {
                nr[i] = rstr[i];
                nr[99 - i] = rstr[res - 1 - i];
            }
            rstr = nr;
        }
        out.println(new String(rstr));
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

    }