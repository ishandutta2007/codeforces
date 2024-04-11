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
        int height = in.nextInt();
        int width = in.nextInt();
        int n = in.nextInt() + 1;
        int cost = in.nextInt();
        char[][] c = new char[n][];
        c[0] = new char[height * width];
        for (int i = 1; i < n; i++) {
            char[][] d = in.readCharacterFieldTokens(height, width);
            c[i] = new char[height * width];
            int cn = 0;
            for (int x = 0; x < height; x++) {
                for (int y = 0; y < width; y++) {
                    c[i][cn++] = d[x][y];
                }
            }
        }
        int all = height * width;
        int[] d = new int[n];
        int[] from = new int[n];
        boolean[] was = new boolean[n];
        Arrays.fill(d, Integer.MAX_VALUE);
        d[0] = 0;
        int[] ansX = new int[n - 1];
        int[] ansY = new int[n - 1];
        int count = 0;
        int allCost = 0;
        while (true) {
            int best = -1;
            for (int i = 0; i < n; i++) {
                if (was[i] || d[i] == Integer.MAX_VALUE) continue;
                if (best < 0 || d[best] > d[i]) {
                    best = i;
                }
            }
            if (best < 0) break;
            char[] c1 = c[best];
            was[best] = true;
            allCost += d[best];
            if (best > 0) {
                ansX[count] = best;
                ansY[count] = from[best];
                ++count;
            }
            for (int i = 0; i < n; i++) {
                if (was[i]) continue;
                char[] c2 = c[i];
                int curCost = 0;
                int bestCost = all;
                for (int j = 0; curCost < bestCost && j < all; j++) {
                    if (c1[j] != c2[j]) {
                        curCost += cost;
                    }
                }
                bestCost = Math.min(bestCost, curCost);
                if (d[i] > bestCost) {
                    d[i] = bestCost;
                    from[i] = best;
                }
            }
        }
        out.println(allCost);
        for (int i = 0; i + 1 < n; i++) {
            out.println(ansX[i] + " " + ansY[i]);
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

    public String next() {
        StringBuilder sb = new StringBuilder();
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        if (c < 0) {
            return null;
        }
        while (c >= 0 && !isWhiteSpace(c)) {
            sb.appendCodePoint(c);
            c = read();
        }
        return sb.toString();
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

    public char[][] readCharacterFieldTokens(int n, int m) {
        char[][] ret = new char[n][];
        for (int i = 0; i < n; i++) {
            ret[i] = next().toCharArray();
            if (ret[i].length != m) {
                throw new AssertionError("length expected " + m + ", found " + ret[i].length);
            }
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