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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int[] c = new int[n];
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            c[i] = in.nextInt();
            p[i] = in.nextInt();
        }
        boolean[] was = new boolean[n];
        int k = in.nextInt();
        int[] f = new int[k];
        for (int i = 0; i < k; i++) f[i] = in.nextInt();
        boolean[] used = new boolean[k];
        int[] ax = new int[n];
        int[] ay = new int[n];
        int ac = 0;
        int ans = 0;
        while (true) {
            int best = -1;
            for (int i = 0; i < n; i++) {
                if (was[i]) continue;
                if (best < 0 || p[i] > p[best]) best = i;
            }
            if (best < 0) break;
            was[best] = true;
            int best2 = -1;
            for (int i = 0; i < k; i++) {
                if (used[i] || f[i] < c[best]) continue;
                if (best2 < 0 || f[i] < f[best2]) best2 = i;
            }
            if (best2 < 0) continue;
            used[best2] = true;
            ans += p[best];
            ax[ac] = best;
            ay[ac++] = best2;
        }
        out.println(ac + " " + ans);
        for (int i = 0; i < ac; i++) {
            out.println((ax[i] + 1) + " " + (ay[i] + 1));
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

}

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }


}