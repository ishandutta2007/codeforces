import java.io.InputStreamReader;
import java.io.IOException;
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
        int[] deg = new int[n];
        for (int i = 0; i < m; i++) {
            int x = in.nextInt() - 1;
            int y = in.nextInt() - 1;
            deg[x]++;
            deg[y]++;
        }
        if (isCycle(deg)) {
            out.println("ring topology");
            return;
        }
        if (isStar(deg)) {
            out.println("star topology");
            return;
        }
        if (isBus(deg)) {
            out.println("bus topology");
            return;
        }
        out.println("unknown topology");
    }

    private boolean isBus(int[] deg) {
        int cnt = 0;
        for (int i = 0; i < deg.length; i++) {
            if (deg[i] == 1) {
                ++cnt;
                if (cnt > 2) {
                    return false;
                }
            } else if (deg[i] != 2) {
                return false;
            }
        }
        return cnt == 2;
    }

    private boolean isStar(int[] deg) {
        int best = -1;
        for (int i = 0; i < deg.length; i++) {
            if (best < 0 || deg[i] > deg[best]) {
                best = i;
            }
        }
        for (int i = 0; i < deg.length; i++) {
            if (i != best && deg[i] != 1) {
                return false;
            }
        }
        return deg[best] == deg.length - 1;
    }

    private boolean isCycle(int[] deg) {
        for (int i : deg) {
            if (i != 2) return false;
        }
        return true;
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