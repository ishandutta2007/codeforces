import java.util.Map;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.HashMap;
import java.util.Set;
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
            String name = in.next();
            if (map.containsKey(name)) {
                map.put(name, Math.max(in.nextInt(), map.get(name)));
            } else {
                map.put(name, in.nextInt());
            }
        }
        Map.Entry<String, Integer>[] en = map.entrySet().toArray(new Map.Entry[map.size()]);
        out.println(en.length);
        for (int i = 0; i < en.length; i++) {
            int countMore = 0;
            for (int j = 0; j < en.length; j++) {
                if (en[j].getValue() > en[i].getValue()) {
                    countMore++;
                }
            }
            out.println(en[i].getKey() + " " + getAns(countMore, en.length));
        }
    }

    static String getAns(int a, int b) {
        int c = b - a;
        if (c * 100 >= b * 99) {
            return "pro";
        } else if (c * 100 >= b * 90 && a * 100 > b) {
            return "hardcore";
        } else if (c * 100 >= b * 80 && a * 10 > b) {
            return "average";
        } else if (c * 100 >= b * 50 && a * 5 > b) {
            return "random";
        } else {
            return "noob";
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