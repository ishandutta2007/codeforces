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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        char[][] c = in.readCharacterFieldTokens(n, n);
        boolean[] row = new boolean[n];
        boolean[] col = new boolean[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (c[i][j] == '.') {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        boolean rowOk = true;
        for (int i = 0; i < n; i++) {
            if (!row[i]) {
                rowOk = false;
                break;
            }
        }
        if (rowOk) {
            for (int i = 0; i < n; i++) {
                int id = -1;
                for (int j = 0; j < n; j++) {
                    if (c[i][j] == '.') {
                        id = j;
                        break;
                    }
                }
                out.println((i + 1) + " " + (id + 1));
            }
            return;
        }
        boolean colOk = true;
        for (int i = 0; i < n; i++) {
            if (!col[i]) {
                colOk = false;
                break;
            }
        }
        if (colOk) {
            for (int i = 0; i < n; i++) {
                int id = -1;
                for (int j = 0; j < n; j++) {
                    if (c[j][i] == '.') {
                        id = j;
                        break;
                    }
                }
                out.println((id + 1) + " " + (i + 1));
            }
            return;
        }
        out.println(-1);
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

    public char[][] readCharacterFieldTokens(int n, int m) {
        char[][] ret = new char[n][];
        for (int i = 0; i < n; i++) {
            ret[i] = next().toCharArray();
            if (ret[i].length != m) {
                throw new AssertionError("length expected " + m + ", found " + ret[i].length);
            }
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


}