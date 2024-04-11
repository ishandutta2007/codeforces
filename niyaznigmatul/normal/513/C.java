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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int[] left = new int[n];
        int[] right = new int[n];
        for (int i = 0; i < n; i++) {
            left[i] = in.nextInt();
            right[i] = in.nextInt();
        }
        double ans = 0;
        for (int pay = 1; pay <= 10000; pay++) {
            for (int wins = 0; wins < n; wins++) {
                if (right[wins] <= pay) continue;
                boolean bad = false;
                double prob = 1.;
                double probLess = 1.;
                for (int second = 0; second < n; second++) {
                    if (second == wins) continue;
                    if (left[second] > pay) {
                        bad = true;
                        break;
                    }
                    prob *= (Math.min(pay, right[second]) - left[second] + 1);
                    probLess *= Math.min(pay - 1, right[second]) - left[second] + 1;
                }
                if (bad) continue;
                prob -= probLess;
                prob *= right[wins] - Math.max(pay + 1, left[wins]) + 1;
                ans += prob * pay;
            }
            for (int winMask = 1; winMask < 1 << n; winMask++) {
                if (Integer.bitCount(winMask) < 2) continue;
                double prob = 1.;
                boolean bad = false;
                for (int i = 0; i < n; i++) {
                    if (left[i] > pay) {
                        bad = true;
                        break;
                    }
                    if (((winMask >> i) & 1) == 0) {
                        prob *= Math.min(pay - 1, right[i]) - left[i] + 1;
                    } else {
                        if (pay < left[i] || pay > right[i]) {
                            bad = true;
                            break;
                        }
                    }
                }
                if (bad) continue;
                ans += prob * pay;
            }
        }
        for (int i = 0; i < n; i++) ans /= right[i] - left[i] + 1;
        out.println(ans);
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