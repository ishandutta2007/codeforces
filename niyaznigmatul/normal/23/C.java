import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Comparator;
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
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = 2 * in.nextInt() - 1;
        Box[] a = new Box[n];
        long allOrange = 0;
        for (int i = 0; i < n; i++) {
            a[i] = new Box(in.nextInt(), in.nextInt(), i);
            allOrange += a[i].orange;
        }
        Arrays.sort(a, new Comparator<Box>() {
            public int compare(Box o1, Box o2) {
                return o1.apple - o2.apple;
            }
        });
        long countOrange = 0;
        for (int i = 0; i < n; i += 2) {
            countOrange += a[i].orange;
        }
        out.println("YES");
        if (countOrange * 2 >= allOrange) {
            for (int i = 0; i < n; i += 2) {
                out.print(a[i].id + 1 + " ");
            }
        } else {
            for (int i = 1; i < n; i += 2) {
                out.print(a[i].id + 1 + " ");
            }
            out.print(a[n - 1].id + 1 + " ");
        }
        out.println();
    }

    static class Box {
        int apple;
        int orange;
        int id;

        Box(int apple, int orange, int id) {
            this.apple = apple;
            this.orange = orange;
            this.id = id;
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