import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.math.BigInteger;
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
		TaskA2 solver = new TaskA2();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA2 {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        String s = in.next();
        int[] cnt = new int[10];
        int p9 = 0;
        int p10 = 0;
        boolean haveFirstLetter = false;
        for (int i = 0; i < s.length(); ++i) {
            char ch = s.charAt(i);
            if (ch == '?') {
                if (i == 0) ++p9; else ++p10;
            } else if (ch >= 'A' && ch <= 'J') {
                ++cnt[ch - 'A'];
                if (i == 0) haveFirstLetter = true;
            }
        }
        int numLetters = 0;
        for (int i = 0; i < 10; ++i) if (cnt[i] > 0) ++numLetters;
        BigInteger res = BigInteger.ONE;
        res = res.multiply(BigInteger.valueOf(9).pow(p9));
        for (int i = 0; i < numLetters; ++i) {
            int by = 10 - i;
            if (haveFirstLetter && i == 0) --by;
            res = res.multiply(BigInteger.valueOf(by));
        }
        out.print(res);
        for (int i = 0; i < p10; ++i) out.print('0');
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

    }