import java.util.Map;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.HashMap;
import java.util.Set;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.Writer;
import java.util.HashSet;
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
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt() - 1;
            b[i] = in.nextInt() - 1;
            if (b[i] < 0) --b[i];
        }
//        System.out.println(Arrays.toString(a));
//        System.out.println(Arrays.toString(b));
        Set<Integer> f = new HashSet<>();
        Map<Integer, Integer> g = new HashMap<>();
        for (int i = 0; i < n; i++) {
            if (f.contains(a[i])) f.remove(a[i]);
            else f.add(a[i]);
            if (f.contains(b[i])) f.remove(b[i]);
            else f.add(b[i]);
            g.put(a[i], b[i]);
        }
        int first = g.get(-1);
        int[] ans = new int[n];
        int cur;
        cur = 1;
        f.remove(-1);
        while (first >= 0) {
            ans[cur] = first + 1;
            if (f.contains(first)) break;
            cur += 2;
            first = g.get(first);
        }
        int prev = -1;
        for (int i = 0; i < n; i++) if (f.contains(a[i])) {
            prev = a[i];
            first = b[i];
        }
        f.remove(prev);
        ans[0] = prev + 1;
        cur = 2;
        while (first >= 0) {
            ans[cur] = first + 1;
            if (f.contains(first)) break;
            cur += 2;
            first = g.get(first);
        }
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