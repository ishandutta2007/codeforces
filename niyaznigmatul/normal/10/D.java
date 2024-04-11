import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
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
		LICS solver = new LICS();
		solver.solve(1, in, out);
		out.close();
	}
}

class LICS {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int[] a = in.readIntArray(n);
        int m = in.nextInt();
        int[] b = in.readIntArray(m);
        int[] c = new int[n + m];
        for (int i = 0; i < n + m; i++) {
            c[i] = i < n ? a[i] : b[i - n];
        }
        c = ArrayUtils.sortAndUnique(c);
        for (int i = 0; i < n; i++) {
            a[i] = Arrays.binarySearch(c, a[i]);
        }
        for (int j = 0; j < m; j++) {
            b[j] = Arrays.binarySearch(c, b[j]);
        }
        int cnt = c.length;
        int[][] next1 = new int[n + 1][];
        int[][] next2 = new int[m + 1][];
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                next1[i] = next1[i - 1].clone();
            } else {
                next1[i] = new int[cnt];
                Arrays.fill(next1[i], -1);
            }
            next1[i][a[i]] = i;
        }
        for (int i = 0; i < m; i++) {
            if (i > 0) {
                next2[i] = next2[i - 1].clone();
            } else {
                next2[i] = new int[cnt];
                Arrays.fill(next2[i], -1);
            }
            next2[i][b[i]] = i;
        }
        int[][] dp = new int[n][m];
        int[][] prev = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i] != b[j]) {
                    continue;
                }
                int val = 1;
                int p = -1;
                for (int k1 = i - 1; k1 >= 0; k1--) {
                    if (a[k1] < a[i] && j > 0) {
                        int k2 = next2[j - 1][a[k1]];
                        if (k2 >= 0 && val < dp[k1][k2] + 1) {
                            val = dp[k1][k2] + 1;
                            p = k1 * m + k2;
                        }
                    }
                }
                for (int k2 = j - 1; k2 >= 0; k2--) {
                    if (b[k2] < b[j] && i > 0) {
                        int k1 = next1[i - 1][b[k2]];
                        if (k1 >= 0 && val < dp[k1][k2] + 1) {
                            val = dp[k1][k2] + 1;
                            p = k1 * m + k2;
                        }
                    }
                }
                dp[i][j] = val;
                prev[i][j] = p;
            }
        }
        int answer = 0;
        int ansI = -1;
        int ansJ = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (answer < dp[i][j]) {
                    answer = dp[i][j];
                    ansI = i;
                    ansJ = j;
                }
            }
        }
        int[] ans = new int[answer];
        out.println(answer);
        for (int i = ansI, j = ansJ; answer > 0;  ) {
            ans[--answer] = c[a[i]];
            int p = prev[i][j];
            i = p / m;
            j = p % m;
         }
        out.printArray(ans);
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

    static public int[] sortAndUnique(int[] a) {
        int[] ret = a.clone();
        sort(ret);
        if (ret.length == 0) {
            return ret;
        }
        int last = ret[0];
        int j = 1;
        for (int i = 1; i < ret.length; i++) {
            if (last != ret[i]) {
                ret[j++] = ret[i];
            }
            last = ret[i];
        }
        return Arrays.copyOf(ret, j);
    }

    public static void sort(int[] a) {
        Random rand = new Random(System.nanoTime());
        for (int i = 0; i < a.length; i++) {
            int j = rand.nextInt(i + 1);
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
        Arrays.sort(a);
    }


    }