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

    static final double EPS = 1e-9;

	public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int length = in.nextInt();
        int v1 = in.nextInt();
        int v2 = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        double myLen = 1. * length / (v1 + v2) * v2;
        Event[] events = new Event[2 * n];
        int count = 0;
        for (int i = 0; i < n; i++) {
            {
                double x = a[i] - myLen;
                if (x < 0) {
                    x += 2 * length;
                    count++;
                }
                events[2 * i] = new Event(x, true);
            }
            events[1 + 2 * i] = new Event(a[i], false);
        }
        Arrays.sort(events);
        double last = 0;
        double[] answer = new double[n + 1];
        for (Event e : events) {
            answer[count] += (e.x - last);
            if (e.begin) {
                ++count;
            } else {
                --count;
            }
            last = e.x;
        }
        answer[count] += 2 * length - last;
        for (int i = 0; i <= n; i++) {
            answer[i] /= 2 * length;
        }
        for (double e : answer) {
            out.println(e);
        }
	}

    static class Event implements Comparable<Event> {
        double x;
        boolean begin;

        Event(double x, boolean begin) {
            this.x = x;
            this.begin = begin;
        }

        public int compareTo(Event o) {
            int c = compare(x, o.x);
            if (c != 0) {
                return c;
            }
            if (begin == o.begin) {
                return 0;
            }
            if (begin) {
                return -1;
            }
            return 1;
        }
    }

    static int compare(double a, double b) {
        return Math.abs(a - b) < EPS ? 0 : Double.compare(a, b);
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