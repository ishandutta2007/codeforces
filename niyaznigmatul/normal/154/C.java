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
import java.math.BigInteger;
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
		TaskCC solver = new TaskCC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskCC {
    static final Random rand = new Random(1231113L);

    static final int PRIME = BigInteger.probablePrime(20, rand).intValue();

    static long hash(int[] a) {
        long ret = 1;
        for (int i = 0; i < a.length; i++) {
            ret = ret * PRIME + a[i];
        }
        return ret;
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] deg = new int[n];
        int[] a = new int[m];
        int[] b = new int[m];
        for (int i = 0; i < m; i++) {
            a[i] = in.nextInt() - 1;
            b[i] = in.nextInt() - 1;
            deg[a[i]]++;
            deg[b[i]]++;
        }
        long ans = 0;
        int[][] edges = new int[n][];
        {
            int[] curDeg = new int[n];
            for (int i = 0; i < n; i++) {
                edges[i] = new int[deg[i]];
            }
            for (int i = 0; i < m; i++) {
                edges[a[i]][curDeg[a[i]]++] = b[i];
                edges[b[i]][curDeg[b[i]]++] = a[i];
            }
            ans += count(edges);
        }
        {
            int[] curDeg = new int[n];
            for (int i = 0; i < n; i++) {
                edges[i] = new int[deg[i] + 1];
            }
            for (int i = 0; i < m; i++) {
                edges[a[i]][curDeg[a[i]]++] = b[i];
                edges[b[i]][curDeg[b[i]]++] = a[i];
            }
            for (int i = 0; i < n; i++) {
                edges[i][curDeg[i]++] = i;
            }
            ans += count(edges);
        }
        out.println(ans);
    }

    static long count(int[][] a) {
        long[] h = new long[a.length];
        long ret = 0;
        int count = 0;
        for (int[] e : a) {
            Arrays.sort(e);
            long p = hash(e);
            h[count++] = p;
        }
        Arrays.sort(h);
        for (int i = 0; i < a.length; ) {
            int j = i;
            while (j < a.length && h[i] == h[j]) {
                j++;
            }
            long z = j - i;
            ret += z * (z - 1) >> 1;
            i = j;
        }
        return ret;
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