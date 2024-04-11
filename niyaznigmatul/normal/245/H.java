import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.ArrayList;
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
		TaskH solver = new TaskH();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskH {
	public void solve(int testNumber, FastScanner in, FastPrinter out) {
        char[] c = in.next().toCharArray();
        int n = in.nextInt();
        Query[] q = new Query[n];
        List<Query>[] all = new List[c.length];
        for (int i = 0; i < c.length; i++) {
            all[i] = new ArrayList<Query>();
        }
        for (int i = 0; i < n; i++) {
            q[i] = new Query(in.nextInt() - 1, in.nextInt() - 1);
            all[q[i].right].add(q[i]);
        }
        boolean[][] isPalindrom = new boolean[c.length][c.length];
        for (int i = 0; i < c.length; i++) {
            int d = 0;
            while (i - d >= 0 && i + d < c.length && c[i - d] == c[i + d]) {
                isPalindrom[i - d][i + d] = true;
                ++d;
            }
        }
        for (int i = 0; i + 1 < c.length; i++) {
            int d = 0;
            while (i - d >= 0 && i + d + 1 < c.length && c[i - d] == c[i + d + 1]) {
                isPalindrom[i - d][i + d + 1] = true;
                ++d;
            }
        }
        int[] d = new int[c.length];
        for (int right = 0; right < c.length; right++) {
            int count = 0;
            for (int left = right; left >= 0; left--) {
                if (isPalindrom[left][right]) {
                    ++count;
                }
                d[left] += count;
            }
            for (Query e : all[right]) {
                e.answer = d[e.left];
            }
        }
        for (Query e : q) {
            out.println(e.answer);
        }
	}

    static class Query {
        int left;
        int right;
        long answer;

        Query(int left, int right) {
            this.left = left;
            this.right = right;
        }
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

    public String next() {
        StringBuilder sb = new StringBuilder();
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        while (!isWhiteSpace(c)) {
            sb.appendCodePoint(c);
            c = read();
        }
        return sb.toString();
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