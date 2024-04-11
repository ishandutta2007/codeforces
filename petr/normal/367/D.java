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
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int d = in.nextInt();
        int[] color = new int[n];
        Arrays.fill(color, -1);
        for (int i = 0; i < m; ++i) {
            int s = in.nextInt();
            for (int j = 0; j < s; ++j) {
                color[in.nextInt() - 1] = i;
            }
        }
        int[] count = new int[m];
        int nonzeroset = 0;
        boolean[] bad = new boolean[1 << m];
        for (int i = 0; i < n; ++i) {
            if (count[color[i]] == 0) nonzeroset ^= (1 << color[i]);
            ++count[color[i]];
            if (i - d >= 0) {
                --count[color[i - d]];
                if (count[color[i - d]] == 0) nonzeroset ^= (1 << color[i - d]);
            }
            if (i >= d - 1) {
                bad[nonzeroset] = true;
            }
        }
        for (int i = 0; i < m; ++i)
            for (int set = 0; set < (1 << m); ++set)
                if ((set & (1 << i)) == 0 && bad[set])
                    bad[set ^ (1 << i)] = true;
        int res = 0;
        for (int set = 0; set < (1 << m); ++set) if (!bad[set])
            res = Math.max(res, Integer.bitCount(set));
        out.println(m - res);
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