import java.util.Map;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
import java.util.HashMap;
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
        Map<String, Integer> map = new HashMap<String, Integer>();
        for (int i = 0; i < n; i++) {
            String s = in.next();
            String type = in.next();
            int cnta = 0;
            int cntb = 0;
            while (type.startsWith("&")) {
                cnta++;
                type = type.substring(1);
            }
            while (type.endsWith("*")) {
                cntb++;
                type = type.substring(0, type.length() - 1);
            }
            if (s.equals("typeof")) {
                Integer got = map.get(type);
                if (type.equals("void")) {
                    got = 0;
                }
                if (got == null || got < 0 || got + cntb - cnta < 0) {
                    out.println("errtype");
                } else {
                    out.print("void");
                    for (int j = 0; j < got + cntb - cnta; j++) {
                        out.print("*");
                    }
                    out.println();
                }
            } else {
                String newType = in.next();
                if (type.equals("errtype")) {
                    map.put(newType, -1);
                } else {
                    if (!type.equals("void") && !map.containsKey(type)) {
                        map.put(newType, -1);
                    } else {
                        int z = type.equals("void") ? 0 : map.get(type);
                        if (z < 0) {
                            map.put(newType, -1);
                        } else {
                            int got = Math.max(-1, z + cntb - cnta);
                            map.put(newType, got);
                        }
                    }
                }
            }
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