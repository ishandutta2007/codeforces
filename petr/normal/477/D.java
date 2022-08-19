import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    static final int INF = (int) 1e9;
    static final int MODULO = (int) (1e9 + 7);

    int[][] numEqual;
    int n;
    String x;

    int compare(int p1, int p2, int len) {
        if (numEqual[p1][p2] >= len) return 0;
        int diff = numEqual[p1][p2];
        return x.charAt(p1 + diff) - x.charAt(p2 + diff);
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        x = in.next();
        n = x.length();
        numEqual = new int[n + 1][n + 1];
        for (int p1 = n - 1; p1 >= 0; --p1) {
            for (int p2 = p1; p2 >= 0; --p2) {
                if (x.charAt(p1) == x.charAt(p2)) {
                    numEqual[p1][p2] = 1 + numEqual[p1 + 1][p2 + 1];
                }
                numEqual[p2][p1] = numEqual[p1][p2];
            }
        }
        int[][] ways = new int[n + 1][n + 1];
        int[][] minOutputs = new int[n + 1][n + 1];
        Arrays.fill(ways[0], 1);
        Arrays.fill(minOutputs[0], 0);
        int[] minAnsOutputs = new int[n + 1];
        Arrays.fill(minAnsOutputs, INF);
        for (int len = 1; len <= n; ++len) {
            Arrays.fill(minOutputs[len], INF);
            for (int lastAtMost = 1; lastAtMost <= len; ++lastAtMost) {
                ways[len][lastAtMost] = ways[len][lastAtMost - 1];
                minOutputs[len][lastAtMost] = minOutputs[len][lastAtMost - 1];
                if (x.charAt(len - lastAtMost) == '1') {
                    int prevAtMost = lastAtMost;
                    prevAtMost = Math.min(prevAtMost, len - lastAtMost);
                    if (prevAtMost == lastAtMost && compare(len - 2 * lastAtMost, len - lastAtMost, lastAtMost) > 0) {
                        --prevAtMost;
                    }
                    int pways = ways[len - lastAtMost][prevAtMost];
                    if (pways != 0) {
                        int nways = ways[len][lastAtMost] + pways;
                        if (nways >= MODULO) nways -= MODULO;
                        ways[len][lastAtMost] = nways;
                    }
                    if (len == n) {
                        minAnsOutputs[lastAtMost] = 1 + minOutputs[len - lastAtMost][prevAtMost];
                    } else {
                        minOutputs[len][lastAtMost] = Math.min(minOutputs[len][lastAtMost], 1 + minOutputs[len - lastAtMost][prevAtMost]);
                    }
                }
            }
        }
        out.println(ways[n][n]);
        BigInteger res = null;
        for (int lastlen = 1; lastlen <= n; ++lastlen) {
            if (res != null && res.bitLength() < lastlen - 1) {
                break;
            }
            if (minAnsOutputs[lastlen] >= INF) continue;
            BigInteger cur = new BigInteger(x.substring(n - lastlen), 2).add(BigInteger.valueOf(minAnsOutputs[lastlen]));
            if (res == null || cur.compareTo(res) < 0) {
                res = cur;
            }
        }
        out.println(res.mod(BigInteger.valueOf(MODULO)));
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