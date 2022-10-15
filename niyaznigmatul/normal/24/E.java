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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int[] x = new int[n];
        int[] v = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = in.nextInt();
            v[i] = in.nextInt();
        }
        int[] stack = new int[n];
        int[] timeNum = new int[n];
        int[] timeDen = new int[n];
        int cnt = 0;
        double answer = Double.POSITIVE_INFINITY;
        for (int i = 0; i < n; i++) {
            if (v[i] > 0) {
                int l = -1;
                int r = cnt;
                while (l < r - 1) {
                    int mid = l + r >> 1;
                    int cur = stack[mid];
                    int num;
                    int den;
                    if (v[i] >= v[cur]) {
                        num = 1;
                        den = 0;
                    } else {
                        num = x[i] - x[cur];
                        den = v[cur] - v[i];
                    }
                    if (den == 0 || (long) num * timeDen[mid] >= (long) den * timeNum[mid]) {
                        r = mid;
                    } else {
                        l = mid;
                    }
                }
                stack[l + 1] = i;
                cnt = l + 2;
                if (l < 0) {
                    timeNum[l + 1] = 1;
                    timeDen[l + 1] = 0;
                } else {
                    timeNum[l + 1] = x[i] - x[stack[l]];
                    timeDen[l + 1] = v[stack[l]] - v[i];
                }
            } else {
                int l = -1;
                int r = cnt;
                while (l < r - 1) {
                    int mid = l + r >> 1;
                    int cur = stack[mid];
                    int num;
                    int den;
                    num = x[i] - x[cur];
                    den = v[cur] - v[i];
                    if ((long) num * timeDen[mid] >= (long) den * timeNum[mid]) {
                        r = mid;
                    } else {
                        l = mid;
                    }
                }
                if (l >= 0) {
                    answer = Math.min(answer, 1. * (x[i] - x[stack[l]]) / (v[stack[l]] - v[i]));
                }
            }
        }
        out.println(Double.isInfinite(answer) ? -1 : answer);
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