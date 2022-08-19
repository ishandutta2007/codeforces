import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
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
        int n = in.nextInt();
        int[] digits = new int[n];
        for (int i = 0; i < n; ++i) {
            digits[i] = in.nextInt();
        }
        StringBuilder b = new StringBuilder();
        List<String> res = new ArrayList<String>();
        rec(digits, b, 6, res, 0);
        out.println(res.size());
        for (String x : res) out.println(x);
    }

    private void rec(int[] digits, StringBuilder b, int togo, List<String> res, int usedMask) {
        int len = b.length();
        if (len > 0 && usedMask == (1 << digits.length) - 1) {
            for (int i = len - 1; i >= 0; --i) {
                b.append(b.charAt(i));
            }
            verify(b, res);
            b.deleteCharAt(len);
            verify(b, res);
            while (b.length() > len) b.deleteCharAt(b.length() - 1);
        }
        if (togo == 0) return;
        for (int i = 0; i < digits.length; ++i) {
            int x = digits[i];
            b.append(x);
            rec(digits, b, togo - 1, res, usedMask | (1 << i));
            b.deleteCharAt(len);
        }
    }

    private void verify(StringBuilder b, List<String> res) {
        int[][] can = new int[5][b.length() + 1];
        can[0][0] = 1;
        for (int octet = 0; octet < 4; ++octet) {
            int[] old = can[octet];
            int[] nxt = can[octet + 1];
            for (int pos = 0; pos < b.length(); ++pos)
                if (old[pos] > 0) {
                    int val = 0;
                    for (int size = 1; size <= 3 && pos + size <= b.length(); ++size) {
                        val = val * 10 + b.charAt(pos + size - 1) - '0';
                        if (val < 256) {
                            nxt[pos + size] |= 1 << size;
                        }
                        if (val == 0) break;
                    }
                }
        }
        rebuild(can, 4, b.length(), b, new StringBuilder(), res);
    }

    private void rebuild(int[][] can, int octet, int at, StringBuilder b, StringBuilder c, List<String> res) {
        if (can[octet][at] == 0) return;
        if (octet == 0) {
            c.reverse();
            res.add(c.toString());
            c.reverse();
            return;
        }
        int len = c.length();
        if (c.length() > 0) c.append('.');
        for (int size = 1; size <= 3 && size <= at; ++size) {
            c.append(b.charAt(at - size));
            if ((can[octet][at] & (1 << size)) != 0) {
                rebuild(can, octet - 1, at - size, b, c, res);
            }
        }
        while (c.length() > len) c.deleteCharAt(c.length() - 1);
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