import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.io.Reader;
import java.io.Writer;
import java.util.Collections;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {

    static long[] ds;
    static int[][] cs;
    static long[] ans = new long[100000];
    static int cn;

    static boolean go(int x, long k, int who) {
        if (who == 0 || x == k) {
            ans[cn++] = ds[who];
            return cn >= ans.length;
        }
        for (int i = 0; i < cs[who].length; i++) {
            if (go(x + 1, k, cs[who][i])) {
                return true;
            }
        }
        return false;
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        long x = in.nextLong();
        long k = in.nextLong();
        List<Long> divs = new ArrayList<>();
        for (long i = 1; i * i <= x; i++) {
            if (x % i != 0) continue;
            divs.add(i);
            if (i * i != x) divs.add(x / i);
        }
        Collections.sort(divs);
        ds = ArrayUtils.toPrimitiveArrayLong(divs);
        cs = new int[ds.length][];
        for (int i = 0; i < ds.length; i++) {
            int cc = 1;
            for (int j = 0; j < i; j++) {
                if (ds[i] % ds[j] == 0) cc++;
            }
            cs[i] = new int[cc];
            cc = 0;
            for (int j = 0; j <= i; j++) {
                if (ds[i] % ds[j] == 0) {
                    cs[i][cc++] = j;
                }
            }
        }
        cn = 0;
        go(0, k, ds.length - 1);
        for (int i = 0; i < cn; i++) {
            if (i > 0) out.print(' ');
            out.print(ans[i]);
        }
        out.println();
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

    public String next() {
        StringBuilder sb = new StringBuilder();
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        if (c < 0) {
            return null;
        }
        while (c >= 0 && !isWhiteSpace(c)) {
            sb.appendCodePoint(c);
            c = read();
        }
        return sb.toString();
    }

    static boolean isWhiteSpace(int c) {
        return c >= 0 && c <= 32;
    }

    public long nextLong() {
        return Long.parseLong(next());
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

class ArrayUtils {


    static public long[] toPrimitiveArrayLong(List<Long> list) {
        long[] ret = new long[list.size()];
        for (int i = 0; i < ret.length; i++) {
            ret[i] = list.get(i);
        }
        return ret;
    }


}