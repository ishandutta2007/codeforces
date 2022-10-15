import java.io.InputStreamReader;
import java.io.IOException;
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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        long sum = 0;
        HashMap<Integer, Long> map = new HashMap<>();
        HashMap<Integer, Integer> last = new HashMap<>();
        long ans = Long.MIN_VALUE;
        int ansI = -1;
        int ansJ = -1;
        int[] a = in.readIntArray(n);
        for (int i = 0; i < n; i++) {
            int x = a[i];
            Long z = map.get(x);
            if (z != null) {
                long cur = sum + x + x - z;
                if (x >= 0) {
                    sum += x;
                }
                if (cur > ans) {
                    ans = cur;
                    ansI = last.get(x);
                    ansJ = i;
                }
            } else {
                if (x >= 0) {
                    sum += x;
                }
                map.put(x, sum);
                last.put(x, i);
            }
        }
        boolean[] cut = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (a[i] < 0) {
                cut[i] = true;
            }
        }
        cut[ansI] = false;
        cut[ansJ] = false;
        for (int i = 0; i < ansI; i++) cut[i] = true;
        for (int i = ansJ + 1; i < n; i++) cut[i] = true;
        int count = 0;
        for (int i = 0; i < n; i++) if (cut[i]) ++count;
        out.println(ans + " " + count);
        for (int i = 0; i < n; i++) {
            if (cut[i]) {
                out.print(i + 1 + " ");
            }
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

    public int[] readIntArray(int n) {
        int[] ret = new int[n];
        for (int i = 0; i < n; i++) {
            ret[i] = nextInt();
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