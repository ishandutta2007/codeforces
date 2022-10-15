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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {

    static int[] a;
    static int[] id;

    static int[][] answer;
    static int cn;
    static boolean[] was;
    static int[] curid;

    static boolean go(int x, int n) {
        if (x == n) {
            answer[cn++] = curid.clone();
            return cn >= 3;
        }
        int first = -1;
        for (int it = 0; it < n; it++) {
            int i = id[it];
            if (was[i]) continue;
            if (first < 0) first = a[i];
            else if (first != a[i]) break;
            curid[x] = i;
            was[i] = true;
            if (go(x + 1, n)) {
                return true;
            }
            was[i] = false;
        }
        return false;
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        a = in.readIntArray(n);
        id = new int[n];
        for (int i = 0; i < n; i++) id[i] = i;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[id[i]] > a[id[j]]) {
                    int t = id[i];
                    id[i] = id[j];
                    id[j] = t;
                }
            }
        }
        curid = new int[n];
        was = new boolean[n];
        answer = new int[3][];
        cn = 0;
        go(0, n);
        if (cn < 3) {
            out.println("NO");
        } else {
            out.println("YES");
            for (int[] e : answer) {
                for (int j = 0; j < n; j++) {
                    if (j > 0) out.print(' ');
                    out.print(e[j] + 1);
                }
                out.println();
            }
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

    public int[] readIntArray(int n) {
        int[] ret = new int[n];
        for (int i = 0; i < n; i++) {
            ret[i] = nextInt();
        }
        return ret;
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