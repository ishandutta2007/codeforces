import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
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
 * @author Niyaz Nigmatullin
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        List<String> heroes = new ArrayList<String>(Arrays.asList("Anka", "Chapay", "Cleo", "Troll", "Dracul", "Snowy", "Hexadecimal"));
        int m = in.nextInt();
        int n = heroes.size();
        boolean[][] like = new boolean[n][n];
        for (int i = 0; i < m; i++) {
            int x = heroes.indexOf(in.next());
            in.next();
            int y = heroes.indexOf(in.next());
            like[x][y] = true;
        }
        int a = in.nextInt();
        int b = in.nextInt();
        int c = in.nextInt();
        int bestDifference = Integer.MAX_VALUE;
        int bestCount = -1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j + i <= n; j++) {
                for (int k = 1; k + j + i <= n; k++) {
                    int max = Math.max(a / i, Math.max(b / j, c / k));
                    int min = Math.min(a / i, Math.min(b / j, c / k));
                    if (bestDifference < max - min) {
                        continue;
                    }
                    for (int mask1 = 0; mask1 < 1 << n; mask1++) {
                        if (Integer.bitCount(mask1) != i) {
                            continue;
                        }
                        int like1 = getLike(like, mask1);
                        int leftMask = ((1 << n) - 1) ^ mask1;
                        for (int mask2 = leftMask; mask2 > 0; mask2 = (mask2 - 1 & leftMask)) {
                            if (Integer.bitCount(mask2) != j) {
                                continue;
                            }
                            int mask3 = ((1 << n) - 1) ^ mask1 ^ mask2;
                            if (Integer.bitCount(mask3) != k) {
                                continue;
                            }
                            int allLike = like1 + getLike(like, mask2) + getLike(like, mask3);
                            if (bestDifference > max - min || bestDifference == max - min && bestCount < allLike) {
                                bestCount = allLike;
                                bestDifference = max - min;
                            }
                        }
                    }
                }
            }
        }
        out.println(bestDifference + " " + bestCount);
    }

    static int getLike(boolean[][] a, int mask) {
        int ret = 0;
        for (int i = 0; i < a.length; i++) {
            if (((mask >> i) & 1) == 0) {
                continue;
            }
            for (int j = 0; j < a.length; j++) {
                if (((mask >> j) & 1) == 0) {
                    continue;
                }
                ret += a[i][j] ? 1 : 0;
            }
        }
        return ret;
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

    public String next() {
        StringBuilder sb = new StringBuilder();
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        while (!isWhiteSpace(c)) {
            sb.appendCodePoint(c);
            c = read();
        }
        return sb.toString();
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