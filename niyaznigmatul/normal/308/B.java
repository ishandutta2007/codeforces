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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int r = in.nextInt();
        int c = in.nextInt();
        int[] a = new int[n];
        String[] str = new String[n];
        for (int i = 0; i < n; i++) {
            str[i] = in.next();
            a[i] = str[i].length() + 1;
        }
        ++c;
        int j = -1;
        int[] p = new int[n];
        int s = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > c) {
                p[i] = i;
                continue;
            }
            if (j < i) {
                j = i;
                s = a[i];
            }
            while (true) {
                if (j + 1 < n && s + a[j + 1] <= c) {
                    ++j;
                    s += a[j];
                } else {
                    break;
                }
            }
            s -= a[i];
            p[i] = j + 1;
        }
        int[] dp = p.clone();
        int[] np = new int[n];
        int[] ansp = new int[n];
        for (int i = 0; i < n; i++) ansp[i] = i;
        {
            int m = r;
            while (m > 0) {
                if ((m & 1) == 1) {
                    for (int i = 0; i < n; i++) {
                        np[i] = ansp[i] >= n ? ansp[i] : p[ansp[i]];
                    }
                    int[] t = np;
                    np = ansp;
                    ansp = t;
                }
                for (int i = 0; i < n; i++) {
                    np[i] = p[i] >= n ? p[i] : p[p[i]];
                }
                m >>= 1;
                int[] t = np;
                np = p;
                p = t;
            }
        }
        int best = 0;
        int start = 0;
        for (int i = 0; i < n; i++) {
            int cur = ansp[i] - i;
            if (cur > best) {
                best = cur;
                start = i;
            }
        }
        for (int i = start, cnt = r; cnt > 0 && i < n; --cnt) {
            int ne = dp[i];
            for (int k = i; k < ne; k++) {
                if (k > i) out.print(' ');
                out.print(str[k]);
            }
            out.println();
            i = ne;
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

    }

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }

    public FastPrinter(Writer out) {
        super(out);
    }


}