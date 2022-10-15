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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        FenwickKth[] set = new FenwickKth[17];
        for (int i = 0; i < set.length; i++) set[i] = new FenwickKth(n + 2);
        for (FenwickKth e : set) {
            for (int i = 0; i <= n + 1; i++) e.add(i, 1);
        }
        long ans = 0;
        for (int i = 0; i < n; i++) {
            int x = in.nextInt();
            for (int bit = 0; bit < set.length; bit++) {
                if (((x >> bit) & 1) == 1) {
                    set[bit].add(i + 1, -1);
                    ans += get(set[bit], i) << bit;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            int x = in.nextInt() - 1;
            int y = in.nextInt();
            for (int bit = 0; bit < set.length; bit++) {
                if ((set[bit].getSum(x + 1, x + 2) == 1) != (((y >> bit) & 1) == 0)) {
                    if (((y >> bit) & 1) == 1) {
                        set[bit].add(x + 1, -1);
                        ans += get(set[bit], x) << bit;
                    } else {
                        ans -= get(set[bit], x) << bit;
                        set[bit].add(x + 1, 1);
                    }
                }
            }
            out.println(ans);
        }
    }

    static long get(FenwickKth set, Integer i) {
        i++;
        int sum = set.getSum(i);
        int prev = set.getKth(sum);
        int next = set.getKth(sum + 1);
        return (long) (i - prev) * (next - i);
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

class FenwickKth {
    int[] a;

    public FenwickKth(int n) {
        a = new int[Integer.highestOneBit(n) << 1];
    }

    public void add(int x, int y) {
        for (int i = x; i < a.length; i |= i + 1) {
            a[i] += y;
        }
    }

    public int getSum(int x) {
        if (x >= a.length) x = a.length - 1;
        int ret = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
            ret += a[i];
        }
        return ret;
    }

    public int getSum(int l, int r) {
        return getSum(r - 1) - getSum(l - 1);
    }

    public int getKth(int k) {
        int l = 0;
        int r = a.length;
        while (l < r - 1) {
            int mid = l + r >> 1;
            if (a[mid - 1] >= k) {
                r = mid;
            } else {
                k -= a[mid - 1];
                l = mid;
            }
        }
        return l;
    }

}