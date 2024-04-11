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
 * @author Niyaz Nigmatullin
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
    static int cn;
    static int n;
    static int[] cur;
    static int[][] answer;

    static boolean go(int x, int d, int k) {
        if (x == d) {
            answer[cn++] = cur.clone();
            return cn >= n;
        }
        for (int i = 1; i <= k; i++) {
            cur[x] = i;
            if (go(x + 1, d, k)) return true;
        }
        return false;
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        n = in.nextInt();
        int k = in.nextInt();
        int d = in.nextInt();
        long cc = 1;
        for (int i = 0; i < d; i++) {
            cc *= k;
            if (cc >= n) break;
        }
        if (cc < n) {
            out.println("-1");
            return;
        }
        cn = 0;
        cur = new int[d];
        answer = new int[n][];
        go(0, d, k);
        for (int i = 0; i < d; i++) {
            for (int j = 0; j < n; j++) {
                if (j > 0) {
                    out.print(' ');
                }
                out.print(answer[j][i]);
            }
            out.println();
        }
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

    public FastPrinter(Writer out) {
        super(out);
    }


}