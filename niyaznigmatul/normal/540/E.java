import java.util.HashMap;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.io.Writer;
import java.util.List;
import java.util.Map;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.Reader;
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
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int[] all = new int[2 * n];
        int[] from = new int[n];
        int[] to = new int[n];
        for (int i = 0; i < n; i++) {
            from[i] = in.nextInt();
            to[i] = in.nextInt();
            all[2 * i] = from[i];
            all[2 * i + 1] = to[i];
        }
        Map<Integer, Integer> z = new HashMap<>();
        all = ArrayUtils.sortAndUnique(all);
        List<Segment> d = new ArrayList<>();
        for (int i = 0; i < all.length; i++) {
            if (i > 0 && all[i] > all[i - 1] + 1) {
                d.add(new Segment(all[i - 1] + 1, all[i] - (all[i - 1] + 1), d.size()));
            }
            d.add(new Segment(all[i], 1, d.size()));
            z.put(all[i], d.size() - 1);
        }
        for (int i = 0; i < n; i++) {
            Segment t = d.get(z.get(from[i]));
            d.set(z.get(from[i]), d.get(z.get(to[i])));
            d.set(z.get(to[i]), t);
        }
        Fenwick f = new Fenwick(d.size());
        long ans = 0;
        for (int i = d.size() - 1; i >= 0; i--) {
            ans += (long) d.get(i).weight * f.getSum(d.get(i).id);
            f.add(d.get(i).id, d.get(i).weight);
        }
        out.println(ans);
    }

    static class Segment {
        int x;
        int weight;
        int id;

        Segment(int x, int weight, int id) {
            this.x = x;
            this.weight = weight;
            this.id = id;
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

    public FastPrinter(Writer out) {
        super(out);
    }


}

class ArrayUtils {


    static final long seed = System.nanoTime();

    static final Random rand = new Random(seed);

    static public int[] sortAndUnique(int[] a) {
        int[] ret = a.clone();
        sort(ret);
        if (ret.length == 0) {
            return ret;
        }
        int last = ret[0];
        int j = 1;
        for (int i = 1; i < ret.length; i++) {
            if (last != ret[i]) {
                ret[j++] = ret[i];
                last = ret[i];
            }
        }
        return Arrays.copyOf(ret, j);
    }

    public static void sort(int[] a) {
        shuffle(a);
        Arrays.sort(a);
    }

    public static void shuffle(int[] a) {
        for (int i = 0; i < a.length; i++) {
            int j = rand.nextInt(i + 1);
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }


    }

class Fenwick {
    int[] a;

    public Fenwick(int n) {
        a = new int[n];
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

    }