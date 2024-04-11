import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
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
public class MyFirstProgram {
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
    static final int MOD = 1000000007;

    static int add(int a, int b) {
        a += b;
        if (a >= MOD) a -= MOD;
        return a;
    }

    static int mul(int a, int b) {
        return (int) ((long) a * b % MOD);
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
    	int n = in.nextInt();
		int[][] d = new int[n + 1][n + 1];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
			d[i][j] = in.nextInt();			
		}
		long res1 = -2, res2 = -456;
		long[] d1 = new long[2 * n];
		long[] d2 = new long[2 * n];
 		long[][] tmp = new long[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == 0 || j == 0) {
					tmp[i][j] = d[i][j];
				} else {
					tmp[i][j] += tmp[i - 1][j - 1] + d[i][j];
				}
			}
		}
		for (int i = 0; i < n; i++) {
			d2[i] = tmp[i][n - 1];
		}
		for (int i = 0; i < n - 1; i++) {
			d2[n + i] = tmp[n - 1][n - i - 2];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				tmp[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == 0 || j == n - 1) {
					tmp[i][j] = d[i][j];
				} else {
					tmp[i][j] += tmp[i - 1][j + 1] + d[i][j];
				}
			}
		}
		for (int i = 0; i < n; i++) {
			d1[i] = tmp[i][0];
		}
		for (int i = 0; i < n - 1; i++) {
			d1[n + i] = tmp[n - 1][i + 1];
		}
		int x1 = -1;
		int x2 = -1;
		int y1 = -1;
		int y2 = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if ((i + j) % 2 == 0) {
					if (d1[i + j] + d2[i + n - j - 1] - d[i][j] > res1) {
						res1 = d1[i + j] + d2[i + n - j - 1] - d[i][j];
						x1 = i + 1;
						y1 = j + 1;
					}
				} else {
					if (d1[i + j] + d2[i + n - j - 1] - d[i][j] > res2) {
						res2 = d1[i + j] + d2[i + n - j - 1] - d[i][j];
						x2 = i + 1;
						y2 = j + 1;
					}
				}
			}
		}
		out.println(res1 + res2);
		out.println(x1+" "+y1+" "+x2+" "+y2);
		

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


}

class MathUtils {


    public static int modPow(int a, long b, int mod) {
        int ret = 1;
        a = (a % mod + mod) % mod;
        while (b > 0) {
            if ((b & 1) == 1) {
                ret = (int) ((long) ret * a % mod);
            }
            a = (int) ((long) a * a % mod);
            b >>= 1;
        }
        return ret;
    }
}