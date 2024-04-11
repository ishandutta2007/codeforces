import java.io.InputStreamReader;
import java.io.IOException;
import java.util.InputMismatchException;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {

    static int[][] low;
    static int[][] high;
    static int[][] act;

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        low = new int[n][n];
        high = new int[n][n];
        act = new int[n][n];
        int minCut = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int v = in.nextInt() - 1;
                int u = in.nextInt() - 1;
                low[v][u] = in.nextInt();
                high[v][u] = in.nextInt();
                act[v][u] = in.nextInt();
                minCut += high[v][u];
            }
        }
        ansCost = Integer.MIN_VALUE;
        come = new int[n];
        for (int flow = 0; flow <= minCut; flow++) {
            come[0] = flow;
            go(0, 1, n, 0);
            if (ansCost != Integer.MIN_VALUE) {
                out.println(flow + " " + ansCost);
                return;
            }
        }
        out.println("-1 -1");
    }

    static int ansCost;

    static int[] come;

    static void go(int v, int u, int n, int curCost) {
        if (v == n - 1) {
            if (ansCost < curCost) {
                ansCost = curCost;
            }
            return;
        }
        if (u == n) {
            if (come[v] > 0) {
                return;
            }
            go(v + 1, v + 2, n, curCost);
            return;
        }
        for (int z = low[v][u]; z <= high[v][u]; z++) {
            if (z > come[v]) {
                break;
            }
            int cost = z == 0 ? 0 : act[v][u] + z * z;
            come[v] -= z;
            come[u] += z;
            go(v, u + 1, n, curCost + cost);
            come[v] += z;
            come[u] -= z;
        }
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