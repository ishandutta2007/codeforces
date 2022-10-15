import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.io.Reader;
import java.io.Writer;
import java.util.Collections;
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
        String s = in.next();
        boolean[] has = new boolean[11];
        for (int i = 0; i < s.length(); i++) {
            has[i + 1] = s.charAt(i) == '1';
        }
        int m = in.nextInt();
        int[][][] dp = new int[m + 1][11][11];
        for (int[][] d1 : dp) {
            for (int[] d2 : d1) {
                Arrays.fill(d2, -1);
            }
        }
        dp[0][0][0] = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j <= 10; j++) {
                for (int last = 0; last <= 10; last++) {
                    if (dp[i - 1][j][last] < 0) continue;
                    for (int k = 1; k <= 10; k++) {
                        if (!has[k]) continue;
                        if (k == last) continue;
                        int nj = k - j;
                        if (nj <= 0) continue;
                        dp[i][nj][k] = last;
                    }
                }
            }
        }
        int bi = -1;
        int bj = -1;
        for (int i = 1; i <= 10; i++)
            for (int j = 1; j <= 10; j++) {
                if (dp[m][i][j] >= 0) {
                    bi = i;
                    bj = j;
                    break;
                }
            }
        if (bi < 0) {
            out.println("NO");
            return;
        }
        out.println("YES");
        List<Integer> answer = new ArrayList<>();
        for (int i = m, j = bi, k = bj; i > 0; i--) {
            answer.add(k);
            int nk = dp[i][j][k];
            j = k - j;
            k = nk;
        }
        Collections.reverse(answer);
        out.printArray(ArrayUtils.toPrimitiveArrayInteger(answer));
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

    }

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }

    public FastPrinter(Writer out) {
        super(out);
    }

    public void printArray(int[] a) {
        for (int i = 0; i < a.length; i++) {
            if (i > 0) {
                print(' ');
            }
            print(a[i]);
        }
        println();
    }


}

class ArrayUtils {


    static public int[] toPrimitiveArrayInteger(List<Integer> list) {
        int[] ret = new int[list.size()];
        for (int i = 0; i < ret.length; i++) {
            ret[i] = list.get(i);
        }
        return ret;
    }


    }