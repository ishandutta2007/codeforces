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
		Holes solver = new Holes();
		solver.solve(1, in, out);
		out.close();
	}
}

class Holes {

    static final int BLOCK = 555;

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] power = new int[n];
        int[] count = new int[n];
        int[] to = new int[n];
        for (int i = 0; i < n; i++) {
            power[i] = in.nextInt();
        }
        int[] blockID = new int[n];
        for (int i = 0; i < n; i++) {
            blockID[i] = i / BLOCK;
        }
        for (int i = n - 1; i >= 0; i--) {
            updateIt(n, count, to, blockID, i, power);
        }
        for (int i = 0; i < m; i++) {
            int type = in.nextInt();
            if (type == 0) {
                int a = in.nextInt() - 1;
                int b = in.nextInt();
                power[a] = b;
                updateIt(n, count, to, blockID, a, power);
                for (int j = a - 1; j >= 0; j--) {
                    if (blockID[j] != blockID[a]) {
                        break;
                    }
                    updateIt(n, count, to, blockID, j, power);
                }
            } else {
                int a = in.nextInt() - 1;
                int answer = 0;
                int last = -1;
                for (int j = a; j < n; j = to[j] + power[to[j]]) {
                    answer += count[j];
                    last = to[j];
                }
                out.println((last + 1) + " " + answer);
            }
        }
    }

    private void updateIt(int n, int[] count, int[] to, int[] blockID, int i, int[] power) {
        int z = i + power[i];
        if (z >= n || blockID[z] != blockID[i]) {
            count[i] = 1;
            to[i] = i;
        } else {
            count[i] = count[z] + 1;
            to[i] = to[z];
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