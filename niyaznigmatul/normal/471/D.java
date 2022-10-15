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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] a = new int[n - 1];
        int last = in.nextInt();
        for (int i = 0; i + 1 < n; i++) {
            int x = in.nextInt();
            a[i] = x - last;
            last = x;
        }
        int[] b = new int[m - 1];
        last = in.nextInt();
        for (int i = 0; i + 1 < m; i++) {
            int x = in.nextInt();
            b[i] = x - last;
            last = x;
        }
        if (m == 1) {
            out.println(n);
            return;
        }
        --m;
        int k = -1;
        int[] p = new int[m];
        p[0] = -1;
        for (int i = 1; i < m; i++) {
            while (k > -1 && b[k + 1] != b[i]) k = p[k];
            if (b[k + 1] == b[i]) ++k;
            p[i] = k;
        }
        k = -1;
        int ans = 0;
        for (int i : a) {
            while (k > -1 && (k + 1 >= b.length || i != b[k + 1])) k = p[k];
            if (k + 1 < b.length && i == b[k + 1]) {
                ++k;
            }
            if (k == b.length - 1) ++ans;
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