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
    static final int INF = (int) (1e9);
    
	public void solve(int testNumber, InputReader in, PrintWriter out) {
        int len = in.nextInt();
        int[] a = new int[len + 1];
        for (int i = 1; i <= len; ++i) a[i] = in.nextInt();
        String data = in.next();
        if (data.length() != len) throw new RuntimeException();
        int[][] bestErase = new int[len + 1][len + 1];
        int[][][] bestPalin = new int[len + 1][len + 1][len + 1];
        int[][][] bestAlmost = new int[len + 1][len + 1][len + 1];
        for (int[] x : bestErase) Arrays.fill(x, -INF);
        for (int[][] y : bestPalin) for (int[] x : y) Arrays.fill(x, -INF);
        for (int[][] y : bestAlmost) for (int[] x : y) Arrays.fill(x, -INF);
        for (int i = 0; i <= len; ++i)
            bestErase[i][0] = 0;
        for (int l = 1; l <= len; ++l) {
            if (l == 1) {
                for (int start = 0; start + l <= len; ++start)
                    bestPalin[start][l][1] = Math.max(bestPalin[start][l][1], 0);
            } else {
                for (int start = 0; start + l <= len; ++start)
                    if (data.charAt(start) == data.charAt(start + l - 1))
                        bestPalin[start][l][2] = Math.max(bestPalin[start][l][2], bestErase[start + 1][l - 2]);
            }
            for (int start = 0; start + l <= len; ++start) {
                for (int plen = 2; plen <= l; ++plen) {
                    for (int skip = 0; skip + plen <= l; ++skip)
                        bestAlmost[start][l][plen] = Math.max(bestAlmost[start][l][plen], bestPalin[start + 1 + skip][l - 1 - skip][plen - 1] + bestErase[start + 1][skip]);
                }
                if (data.charAt(start) == data.charAt(start + l - 1)) {
                    for (int plen = 3; plen <= l; ++plen) {
                        for (int skip = 0; skip + plen <= l; ++skip)
                            bestPalin[start][l][plen] = Math.max(bestPalin[start][l][plen], bestAlmost[start][l - 1 - skip][plen - 1] + bestErase[start + l - 1 - skip][skip]);
                    }
                }
            }
            for (int start = 0; start + l <= len; ++start) {
                for (int plen = 1; plen <= l; ++plen) if (a[plen] >= 0) {
                    bestErase[start][l] = Math.max(bestErase[start][l], bestPalin[start][l][plen] + a[plen]);
                }
                for (int first = 1; first < l; ++first)
                    bestErase[start][l] = Math.max(bestErase[start][l], bestErase[start][first] + bestErase[start + first][l - first]);
            }
        }
        int[] bestBy = new int[len + 1];
        for (int i = 1; i <= len; ++i) {
            bestBy[i] = bestBy[i - 1];
            for (int take = 1; take <= i; ++take) {
                bestBy[i] = Math.max(bestBy[i], bestBy[i - take] + bestErase[i - take][take]);
            }
        }
        out.println(bestBy[len]);
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