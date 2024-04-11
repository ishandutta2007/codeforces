import java.util.Map;
import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Set;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.Writer;
import java.util.Collections;
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
        int m = in.nextInt();
        in.next();
        HashMap<Integer, Integer> z = new HashMap<>();
        for (int i = 0; i < n; i++) {
            add(z, in.nextInt(), 1);
        }
        for (int i = 0; i < m; i++) {
            add(z, in.nextInt(), -1);
        }
        List<Integer> a = new ArrayList<>();
        List<Integer> b = new ArrayList<>();
        for (int e : z.keySet()) {
            int d = z.get(e);
            if (d < 0) {
                d = -d;
                for (int i = 0; i < d; i++) {
                    b.add(e);
                }
            } else {
                for (int i = 0; i < d; i++) {
                    a.add(e);
                }
            }
        }
        Collections.sort(a);
        Collections.sort(b);
        if (a.size() > b.size()) {
            out.println("YES");
            return;
        }
        for (int i = a.size() - 1, j = b.size() - 1; i >= 0; i--, j--) {
            if (a.get(i) > b.get(j)) {
                out.println("YES");
                return;
            }
        }
        out.println("NO");
    }

    static void add(Map<Integer, Integer> z, int x, int d) {
        Integer e = z.get(x);
        if (e == null) {
            e = 0;
        }
        e += d;
        if (e == 0) {
            z.remove(x);
        } else {
            z.put(x, e);
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