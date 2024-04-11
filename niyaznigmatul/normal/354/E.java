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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    final int MAXCARRY = 6;
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int t = in.nextInt();
        for (int curTest = 0; curTest < t; curTest++) {
            long n = in.nextLong();
            String s = n + "";
            int[] d = new int[s.length()];
            for (int i = 0; i < d.length; i++) {
                d[i] = s.charAt(i) - '0';
            }
            boolean[][] dp = new boolean[d.length + 1][MAXCARRY];
            dp[d.length][0] = true;
            for (int i = d.length - 1; i >= 0; i--) {
                for (int carry2 = 0; carry2 < MAXCARRY; carry2++) {
                    if (!dp[i + 1][carry2]) {
                        continue;
                    }
                    for (int carry = 0; carry < MAXCARRY; carry++) {
                        int needSum = carry * 10 + d[i] - carry2;
                        for (int seven = 0; seven * 7 <= needSum && seven <= 6; seven++) {
                            int left = needSum - seven * 7;
                            if (left % 4 != 0 || left / 4 + seven > 6) {
                                continue;
                            }
                            dp[i][carry] = true;
                            break;
                        }
                    }
                }
            }
            if (!dp[0][0]) {
                out.println(-1);
                continue;
            }
            long[] answer = new long[6];
            all: for (int i = 0, carry = 0; i < d.length; i++) {
                for (int carry2 = 0; carry2 < MAXCARRY; carry2++) {
                    if (!dp[i + 1][carry2]) continue;
                    int needSum = carry * 10 + d[i] - carry2;
                    for (int seven = 0; seven * 7 <= needSum && seven <= 6; seven++) {
                        int left = needSum - seven * 7;
                        if (left % 4 != 0 || left / 4 + seven > 6) {
                            continue;
                        }
                        int four = left / 4;
                        carry = carry2;
                        for (int j = 0; j < seven; j++) {
                            answer[j] = answer[j] * 10 + 7;
                        }
                        for (int j = 0; j < four; j++) {
                            answer[j + seven] = answer[j + seven] * 10 + 4;
                        }
                        for (int j = 0; j < 6 - seven - four; j++) {
                            answer[j + seven + four] *= 10;
                        }
                        continue all;
                    }
                }
                throw new AssertionError();
            }
            out.printArray(answer);
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

    public long nextLong() {
        return Long.parseLong(next());
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

    public void printArray(long[] a) {
        for (int i = 0; i < a.length; i++) {
            if (i > 0) {
                print(' ');
            }
            print(a[i]);
        }
        println();
    }


}