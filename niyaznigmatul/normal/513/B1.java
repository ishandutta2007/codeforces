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
		TaskB1 solver = new TaskB1();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB1 {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
        List<int[]> ret = new ArrayList<>();
        int best = Integer.MIN_VALUE;
        do {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                int min = Integer.MAX_VALUE;
                for (int j = i; j < n; j++) {
                    min = Math.min(min, p[j]);
                    sum += min;
                }
            }
            if (best < sum) {
                ret.clear();
                best = sum;
            }
            if (best == sum) ret.add(p.clone());
        } while (ArrayUtils.nextPermutation(p));
        int[] ans = ret.get(m - 1);
        for (int i = 0; i < n; i++) ++ans[i];
        out.printArray(ans);
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

    public FastPrinter(Writer out) {
        super(out);
    }

    public void printArray(int[] a) {
        for (int i = 0; i < a.length; i++) {
            if (i > 0) {
                print(' ');
            }
            print(a[i]);
        }
        println();
    }


}

class ArrayUtils {


    public static boolean nextPermutation(int[] a) {
        for (int i = a.length - 2; i >= 0; i--) {
            if (a[i] < a[i + 1]) {
                int cur = i + 1;
                for (int j = i + 2; j < a.length; j++) {
                    if (a[j] > a[i] && a[j] < a[cur]) {
                        cur = j;
                    }
                }
                {
                    int t = a[cur];
                    a[cur] = a[i];
                    a[i] = t;
                }
                for (int j = i + 1, k = a.length - 1; j < k; j++, k--) {
                    int t = a[j];
                    a[j] = a[k];
                    a[k] = t;
                }
                return true;
            }
        }
        return false;
    }


}