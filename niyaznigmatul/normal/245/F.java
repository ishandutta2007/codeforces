import java.io.InputStreamReader;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.util.ArrayDeque;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.Writer;
import java.util.Queue;
import java.util.Collection;
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
		TaskF solver = new TaskF();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskF {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        in.nextLine();
        Queue<Long> q = new ArrayDeque<Long>();
        final int DAY = 3600 * 24;
        final int[] MONTHS = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        while (true) {
            String s = in.nextLine();
            if (s == null) {
                break;
            }
            String dateString = s.substring(0, 19);
            s = s.substring(5, 19);
            int month = s.charAt(0) * 10 + s.charAt(1) - 11 * '0';
            int day = s.charAt(3) * 10 + s.charAt(4) - 11 * '0';
            long z = 0;
            for (int i = 0; i + 1 < month; i++) {
                z += MONTHS[i] * DAY;
            }
            z += (day - 1) * DAY;
            int hour = s.charAt(6) * 10 + s.charAt(7) - 11 * '0';
            int min = s.charAt(9) * 10 + s.charAt(10) - 11 * '0';
            int sec = s.charAt(12) * 10 + s.charAt(13) - 11 * '0';
            z += hour * 3600 + min * 60 + sec;
            while (!q.isEmpty() && q.peek() + n <= z) {
                q.poll();
            }
            q.add(z);
            if (q.size() >= m) {
                out.println(dateString);
                return;
            }
        }
        out.println(-1);
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

    public String nextLine() {
        try {
            return readLine();
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