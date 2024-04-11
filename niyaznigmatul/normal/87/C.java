import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
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
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int[] g = new int[n + 1];
        int[] g2 = new int[n + 1];
        g[1] = 0;
        int[] v = new int[n + 1];
        int[] move = new int[n + 1];
        Arrays.fill(move, -1);
        for (int i = 2; i <= n; i++) {
            for (int z = 2; z * (z + 1) / 2 <= i; z++) {
                if ((z & 1) == 1) {
                    if (i % z == 0) {
                        int q = g2[i / z + z / 2] ^ g2[i / z - z / 2 - 1];
                        v[q] = i;
                        if (q == 0 && move[i] < 0) {
                            move[i] = z;
                        }
                    }
                } else {
                    if (i % z == z / 2) {
                        int q = g2[i / z + z / 2] ^ g2[i / z - z / 2];
                        v[q] = i;
                        if (q == 0 && move[i] < 0) {
                            move[i] = z;
                        }
                    }
                }
            }
            for (int k = 0; ; k++) {
                if (v[k] != i) {
                    g[i] = k;
                    break;
                }
            }
            g2[i] = g2[i - 1] ^ g[i];
        }
        if (g[n] == 0) {
            out.println(-1);
            return;
        }
        out.println(move[n]);
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