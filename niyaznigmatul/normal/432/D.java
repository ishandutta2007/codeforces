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
        char[] c = in.next().toCharArray();
        int[] p = new int[c.length];
        int k = -1;
        p[0] = -1;
        int[] f = new int[c.length];
        for (int i = 1; i < c.length; i++) {
            while (k > -1 && c[k + 1] != c[i]) k = p[k];
            if (c[k + 1] == c[i]) ++k;
            if (k >= 0) f[k]++;
            p[i] = k;
        }
        int[] len = new int[c.length];
        int[] count = new int[c.length];
        int ac = 0;
        f[c.length - 1]++;
        for (int i = c.length - 1; i >= 0; i--) {
            if (p[i] >= 0) {
                f[p[i]] += f[i];
            }
        }
        len[ac] = c.length;
        count[ac++] = f[c.length - 1];
        while (k > -1) {
            len[ac] = k + 1;
            count[ac++] = f[k];
            k = p[k];
        }
        out.println(ac);
        for (int i = ac - 1; i >= 0; i--) {
            out.println(len[i] + " " + count[i]);
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