import java.io.Reader;
import java.util.InputMismatchException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;

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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int f = in.nextInt();
        char[] c = in.next().toCharArray();
        int[] p = new int[n];
        p[0] = -1;
        int k = -1;
        int K = 20;
        int[][] pp = new int[K][n];
        char[] ans = new char[n];
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                while (k > -1 && c[k + 1] != c[i]) {
                    k = p[k];
                }
                if (c[k + 1] == c[i]) ++k;
                p[i] = k;
            }
            pp[0][i] = p[i];
            for (int j = 1; j < K; j++) {
                int go = pp[j - 1][i];
                pp[j][i] = go >= 0 ? pp[j - 1][go] : -1;
            }
            int len = i + 1;
            int cur = p[i];
            for (int j = K - 1; cur >= 0 && j >= 0; j--) {
                int go = pp[j][cur];
                int period = (len - go - 1);
                int nf = len / period;
                if (nf >= f + 1) {
                    cur = go;
                }
            }
            boolean ok = false;
            for (int d = 0; d < 3; d++) {
                int period = len - cur - 1;
                if (len % period == 0 && len / period == f + 1 || len / period == f) {
                    ok = true;
                    break;
                }
                if (cur < 0) break;
                cur = p[cur];
            }
            ans[i] = ok ? '1' : '0';
//            int period = len - cur - 1;
//            System.out.println(i + " " + len + " " + period);
//            if (len % period == 0 && len / period == f + 1 || len / (len - cur - 1) == f) {
//                ans[i] = '1';
//                continue;
//            } else {
//                if (cur >= 0) {
//                    cur = p[cur];
//                    period = len - cur - 1;
//                    if (len / period == f) {
//                        ans[i] = '1';
//                        continue;
//                    }
//                }
//            }
//            ans[i] = '0';
        }
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


}