import java.io.Reader;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Niyaz Nigmatullin
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[][] a = new int[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(a[i], Integer.MAX_VALUE);
            a[i][i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int from = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            int len = in.nextInt();
            a[to][from] = a[from][to] = len;
        }
        int[][] b = a.clone();
        for (int i = 0; i < n; i++) b[i] = b[i].clone();
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                int[] ai = a[i];
                for (int j = 0; j < n; j++) {
                    int val1 = ai[k];
                    int val2 = a[k][j];
                    if (val1 != Integer.MAX_VALUE && val2 != Integer.MAX_VALUE) {
                        ai[j] = Math.min(ai[j], val1 + val2);
                    }
                }
            }
        }
        int[][] ans = new int[n][n];
        for (int start = 0; start < n; start++) {
            int[] aStart = a[start];
            for (int mid = 0; mid < n; mid++) {
                int[] aMid = a[mid];
                if (aStart[mid] == Integer.MAX_VALUE || mid == start) continue;
                int countEdges = 0;
                for (int pre = 0; pre < n; pre++) {
                    if (aStart[pre] == Integer.MAX_VALUE || b[pre][mid] == Integer.MAX_VALUE || pre == mid) continue;
                    if (aStart[pre] + b[pre][mid] != aStart[mid]) continue;
                    ++countEdges;
                }
                for (int where = start + 1; where < n; where++) {
                    if (aStart[where] == Integer.MAX_VALUE || aMid[where] == Integer.MAX_VALUE) continue;
                    if (aStart[where] == aStart[mid] + aMid[where]) {
                        ans[start][where] += countEdges;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) out.print(ans[i][j] + " ");
        }
        out.println();
    }
}

class FastScanner extends BufferedReader {

    public FastScanner(InputStream is) {
        super(new InputStreamReader(is));
    }

    public int read() {
        try {
            int ret = super.read();
//            if (isEOF && ret < 0) {
//                throw new InputMismatchException();
//            }
//            isEOF = ret == -1;
            return ret;
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }

    static boolean isWhiteSpace(int c) {
        return c >= 0 && c <= 32;
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
        while (c >= 0 && !isWhiteSpace(c)) {
            if (c < '0' || c > '9') {
                throw new NumberFormatException("digit expected " + (char) c
                        + " found");
            }
            ret = ret * 10 + c - '0';
            c = read();
        }
        return ret * sgn;
    }

    public String readLine() {
        try {
            return super.readLine();
        } catch (IOException e) {
            return null;
        }
    }

}

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }


}