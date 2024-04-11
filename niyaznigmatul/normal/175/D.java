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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int hp1 = in.nextInt();
        int dt1 = in.nextInt();
        int l1 = in.nextInt();
        int r1 = in.nextInt();
        int probability1 = in.nextInt();
        if (probability1 == 100) {
            out.println(0);
            return;
        }
        double prob1 = 1. - probability1 * .01;
        int hp2 = in.nextInt();
        int dt2 = in.nextInt();
        int l2 = in.nextInt();
        int r2 = in.nextInt();
        double prob2 = 1. - in.nextInt() * .01;
        double sum2 = 1.;
        double[] dp2 = new double[hp1 + 1];
        dp2[hp1] = 1.;
        double sum1 = 1.;
        double[] dp1 = new double[hp2 + 1];
        dp1[hp2] = 1.;
        int nextT1 = 0;
        int nextT2 = 0;
        double answer = 0;
        while (sum1 * sum2 >= 1e-8) {
            if (nextT1 <= nextT2) {
                double[] next = new double[hp2 + 1];
                for (int i = 1; i <= hp2; i++) {
                    next[i] = dp1[i] * (1 - prob1);
                    dp1[i] += dp1[i - 1];
                }
                for (int i = 1; i <= hp2 && i <= r1; i++) {
                    if (i < l1) {
                        next[0] += prob1 * (dp1[i] - dp1[i - 1]);
                    } else {
                        next[0] += prob1 * (dp1[i] - dp1[i - 1]) * (r1 - i + 1) / (r1 - l1 + 1);
                    }
                }
                for (int i = 1; i <= hp2; i++) {
                    int left = i + l1;
                    int right = Math.min(i + r1, hp2);
                    if (left <= right) {
                        next[i] += (dp1[right] - dp1[left - 1]) / (r1 - l1 + 1) * prob1;
                    }
                }
                answer += next[0] * sum2;
                next[0] = 0;
                sum1 = 0;
                for (double e : next) {
                    sum1 += e;
                }
                dp1 = next;
                nextT1 += dt1;
            } else {
                double[] next = new double[hp1 + 1];
                for (int i = 1; i <= hp1; i++) {
                    next[i] = dp2[i] * (1 - prob2);
                    dp2[i] += dp2[i - 1];
                }
                for (int i = 1; i <= hp1; i++) {
                    int left = i + l2;
                    int right = Math.min(i + r2, hp1);
                    if (left <= right) {
                        next[i] += (dp2[right] - dp2[left - 1]) / (r2 - l2 + 1) * prob2;
                    }
                }
                sum2 = 0;
                for (double e : next) {
                    sum2 += e;
                }
                dp2 = next;
                nextT2 += dt2;
            }
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