import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
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
 * @author niyaznigmatul 
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {

    static class Figure implements Comparable<Figure> {

        int count;
        int cost;

        Figure(int count, int cost) {
            this.count = count;
            this.cost = cost;
        }

        public int compareTo(Figure o) {
            return cost - o.cost;
        }
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        Figure[] f = new Figure[n];
        for (int i = 0; i < n; i++) {
            f[i] = new Figure(in.nextInt(), in.nextInt());
        }
        int t = in.nextInt();
        long[] p = new long[t];
        for (int i = 0; i < t; i++) {
            p[i] = in.nextLong();
        }
        Arrays.sort(f);
        long currentCount = 0;
        int currentMul = 0;
        long answer = 0;
        for (Figure e : f) {
            while (e.count > 0) {
                long left = currentMul == t ? Long.MAX_VALUE : p[currentMul] - currentCount;
                if (left <= 0) {
                    ++currentMul;
                    continue;
                }
                if (e.count >= left) {
                    answer += (long) e.cost * left * (currentMul + 1);
                    e.count -= left;
                    currentCount += left;
                    ++currentMul;
                } else {
                    answer += (long) e.cost * e.count * (currentMul + 1);
                    currentCount += e.count;
                    e.count = 0;
                }
            }
        }
        out.println(answer);
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

    public long nextLong() {
        return Long.parseLong(next());
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