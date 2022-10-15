import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.Writer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author niyaznigmatul 
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {

    static List<Integer>[] edges;
    static int[][] countDown;
    static long[] dp;
    static int k;

    static void dfs(int v, int parent) {
        List<Integer> edge = edges[v];
        for (int i1 = 0, edgeSize = edge.size(); i1 < edgeSize; i1++) {
            int i = edge.get(i1);
            if (i == parent) {
                continue;
            }
            dfs(i, v);
        }
        countDown[v] = new int[k + 1];
        List<Integer> edge1 = edges[v];
        for (int i1 = 0, edge1Size = edge1.size(); i1 < edge1Size; i1++) {
            int i = edge1.get(i1);
            if (i == parent) {
                continue;
            }
            int[] nextCountDown = countDown[v].clone();
            for (int j = 0; j + 1 <= k; j++) {
                int val = countDown[i][j];
                dp[v] += (long) val * countDown[v][k - j - 1];
                nextCountDown[j + 1] += val;
            }
            countDown[v] = nextCountDown;
        }
        dp[v] += countDown[v][k];
        countDown[v][0] = 1;
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        k = in.nextInt();
        edges = new List[n];
        for (int i = 0; i < n; i++) {
            edges[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < n - 1; i++) {
            int from = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            edges[from].add(to);
            edges[to].add(from);
        }
        countDown = new int[n][];
        dp = new long[n];
        dfs(0, -1);
        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += dp[i];
        }
        out.println(ans);
    }
}

class FastScanner extends BufferedReader {

    boolean isEOF;

    public FastScanner(InputStream is) {
        super(new InputStreamReader(is));
    }

    public int read() {
        try {
            int ret = super.read();
            if (isEOF && ret < 0) {
                throw new InputMismatchException();
            }
            isEOF = ret == -1;
            return ret;
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }

    static boolean isWhiteSpace(int c) {
        return c >= -1 && c <= 32;
    }

    public int nextInt() {
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int ret = 0;
        while (!isWhiteSpace(c)) {
            if (c < '0' || c > '9') {
                throw new NumberFormatException("digit expected " + (char) c
                        + " found");
            }
            ret = ret * 10 + c - '0';
            c = read();
        }
        return ret * sgn;
    }

    }

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }

    public FastPrinter(Writer out) {
        super(out);
    }


}