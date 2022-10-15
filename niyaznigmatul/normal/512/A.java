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
        String[] s = new String[n];
        for (int i = 0; i < n; i++) s[i] = in.next();
        int[][] a = new int[26][26];
        for (int i = 0; i + 1 < n; i++) {
            int x = 0;
            while (x < s[i].length() && x < s[i + 1].length() && s[i].charAt(x) == s[i + 1].charAt(x)) ++x;
            if (x >= s[i + 1].length()) {
                out.println("Impossible");
                return;
            }
            if (x >= s[i].length()) continue;
            a[s[i].charAt(x) - 'a'][s[i + 1].charAt(x) - 'a'] = 1;
        }
        int[] deg = new int[26];
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                deg[j] += a[i][j];
            }
        }
        int[] q = new int[26];
        int head = 0;
        int tail = 0;
        for (int i = 0; i < 26; i++) {
            if (deg[i] == 0) {
                q[tail++] = i;
            }
        }
        while (head < tail) {
            int v = q[head++];
            for (int i = 0; i < 26; i++) {
                if (a[v][i] == 1) {
                    deg[i]--;
                    if (deg[i] == 0) {
                        q[tail++] = i;
                    }
                }
            }
        }
        if (head != 26) {
            out.println("Impossible");
        } else {
            for (int i = 0; i < 26; i++) {
                out.print((char) ('a' + q[i]));
            }
            out.println();
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