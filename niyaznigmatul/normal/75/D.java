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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[][] b = new int[n][];
        for (int i = 0; i < n; i++) {
            b[i] = new int[in.nextInt()];
            for (int j = 0; j < b[i].length; j++) {
                b[i][j] = in.nextInt();
            }
        }
        int[] minimal = new int[n];
        long[] maximal = new long[n];
        long[] maxSum = new long[n];
        int[] sum = new int[n];
        for (int i = 0; i < n; i++) {
            int summ = 0;
            maxSum[i] = Long.MIN_VALUE;
            maximal[i] = Long.MIN_VALUE;
            for (int j : b[i]) {
                summ += j;
                maxSum[i] = Math.max(maxSum[i], summ - minimal[i]);
                minimal[i] = Math.min(minimal[i], summ);
                maximal[i] = Math.max(maximal[i], summ);
            }
            sum[i] = summ;
        }
        long curMin = 0;
        long current = 0;
        long answer = Long.MIN_VALUE;
        for (int iteration = 0; iteration < m; iteration++) {
            int i = in.nextInt() - 1;
            answer = Math.max(answer, maxSum[i]);
            answer = Math.max(answer, maximal[i] + current - curMin);
            curMin = Math.min(curMin, current + minimal[i]);
            current += sum[i];
        }
        out.println(answer);
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