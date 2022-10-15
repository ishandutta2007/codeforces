import java.io.Reader;
import java.util.InputMismatchException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;

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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = in.nextInt();
        int[] next = new int[n + 1];
        next[n] = n;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] == -1) next[i] = next[i + 1]; else next[i] = i;
        }
        int ans = 0;
        for (int cur = 0; cur < n; ) {
            int next1 = next[cur];
            if (next1 >= n) {
                ++ans;
                break;
            }
            int next2 = next[next1 + 1];
            if (next2 >= n) {
                ++ans;
                break;
            }
            long dif = a[next2] - a[next1];
            if (dif % (next2 - next1) != 0) {
                cur = next2;
                ++ans;
                continue;
            }
            dif /= next2 - next1;
            long val = a[next1] - dif * (next1 - cur);
            if (val <= 0) {
                cur = next2;
                ++ans;
                continue;
            }
            while (cur < n && val > 0) {
                if (a[cur] >= 0 && a[cur] != val) {
                    break;
                }
                val += dif;
                ++cur;
            }
            ++ans;
        }
        out.println(ans);
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

}

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }


}