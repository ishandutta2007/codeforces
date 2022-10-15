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
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        char[] c = in.next().toCharArray();
        int[] ans = new int[12];
        int ac = 0;
        for (int a = 1; a <= 12; a++) {
            if (12 % a != 0) continue;
            char[][] d = new char[a][12 / a];
            for (int i = 0, cur = 0; i < a; i++) {
                for (int j = 0; j < d[i].length; j++) {
                    d[i][j] = c[cur++];
                }
            }
            boolean found = false;
            for (int j = 0; j < 12 / a; j++) {
                boolean ok = true;
                for (int i = 0; i < a; i++) {
                    if (d[i][j] != 'X') {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    found = true;
                    break;
                }
            }
            if (found) ans[ac++] =a ;
        }
        out.print(ac);
        for (int i = 0; i < ac; i++) {
            out.print(" " + ans[i] + "x" + (12 / ans[i]));
        }
        out.println();
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


}