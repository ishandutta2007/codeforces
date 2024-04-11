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
    static final int INF = (int) 1e9;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        String s = in.next();
        String p = in.next();
        int plen = p.length();
        int[] len = new int[s.length()];
        Arrays.fill(len, INF);
        for (int i = 0; i + p.length() <= s.length(); ++i) {
            int l = 0;
            for (int j = 0; j < p.length(); ++j) {
                while (i + l < s.length() && s.charAt(i + l) != p.charAt(j)) ++l;
                if (i + l >= s.length()) {
                    l = INF;
                    break;
                }
                ++l;
            }
            len[i] = l;
        }
        int[][] best = new int[s.length() + 1][s.length() + 1];
        for (int[] x : best) Arrays.fill(x, INF);
        best[s.length()][0] = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            for (int j = 0; j <= s.length(); ++j) {
                best[i][j] = best[i + 1][j];
                if (j > 0 && len[i] < INF)
                    best[i][j] = Math.min(best[i][j], best[i + len[i]][j - 1] + len[i] - plen);
            }
        }
        int[] res = new int[s.length() + 1];
        for (int take = 1; take <= s.length(); ++take) {
            int minDelete = best[0][take];
            int maxDelete = s.length() - take * plen;
            for (int x = minDelete; x <= maxDelete; ++x)
                res[x] = take;
        }
        for (int i = 0; i < res.length; ++i) {
            if (i > 0) out.print(' ');
            out.print(res[i]);
        }
        out.println();
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

}