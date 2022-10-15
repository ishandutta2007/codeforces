import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
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
 * @author niyaznigmatul 
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
        int h = in.nextInt();
        int n = in.nextInt();
        Query[] q = new Query[n];
        for (int i = 0; i < n; i++) {
            int type = in.next().equals("add") ? 0 : 1;
            if (type == 0) {
                q[i] = new Query(type, in.nextInt(), in.nextInt());
            } else {
                q[i] = new Query(type, 0, 0);
            }
        }
        int[] allVertices = new int[(h + 1) * n * 2];
        int cnt = 0;
        for (Query e : q) {
            if (e.type == 0) {
                for (int i = e.v; i > 0; i >>= 1) {
                    allVertices[cnt++] = i;
                }
            }
        }
        allVertices = Arrays.copyOf(allVertices, cnt);
        allVertices = ArrayUtils.sortAndUnique(allVertices);
        cnt = allVertices.length;
        int[] d = new int[cnt];
        for (Query e : q) {
            if (e.type == 1) {
                int maximal = Integer.MIN_VALUE;
                long all = 0;
                for (int i = 1, level = 0, j = 1 << h; level < h + 1; level++, j >>= 1) {
                    int f = get(i, allVertices, d);
                    int f1 = f - get(i * 2 + 1, allVertices, d);
                    int f2 = f - get(i * 2, allVertices, d);
                    if (f1 <= maximal && f2 <= maximal) {
                        all += (long) maximal * j;
                        break;
                    } else if (f1 > f2) {
                        maximal = Math.max(maximal, f2);
                        all += (long) f1 * (j >> 1);
                        i = i * 2;
                    } else if (f1 < f2) {
                        maximal = Math.max(maximal, f1);
                        all += (long) f2 * (j >> 1);
                        i = i * 2 + 1;
                    } else {
                        all += (long) f1 * j;
                        break;
                    }
                }
                out.println(1. * all / (1 << h));
            } else {
                for (int i = e.v; i > 0; i >>= 1) {
                    d[Arrays.binarySearch(allVertices, i)] += e.add;
                }
            }
        }
	}

    static int get(int i, int[] allVertices, int[] d) {
        int j = Arrays.binarySearch(allVertices, i);
        return j < 0 ? 0 : d[j];
    }

    static class Query {
        int type;
        int v;
        int add;

        Query(int type, int v, int add) {
            this.type = type;
            this.v = v;
            this.add = add;
        }
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

    public String next() {
        StringBuilder sb = new StringBuilder();
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        while (!isWhiteSpace(c)) {
            sb.appendCodePoint(c);
            c = read();
        }
        return sb.toString();
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
            }
            last = ret[i];
        }
        return Arrays.copyOf(ret, j);
    }

    public static void sort(int[] a) {
        Random rand = new Random(System.nanoTime());
        for (int i = 0; i < a.length; i++) {
            int j = rand.nextInt(i + 1);
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
        Arrays.sort(a);
    }


    }