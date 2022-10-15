import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    static void swap(int i, int j, int[] a, int[] pos) {
        if (i == j) return;
        if (i > j) {
            int t = i;
            i = j;
            j = t;
        }
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
        pos[a[i]] = i;
        pos[a[j]] = j;
        ax[ac] = i;
        ay[ac++] = j;
    }

    static int ac;
    static int[] ax;
    static int[] ay;

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        ac = 0;
        int[] primes = MathUtils.genPrimes(123456);
        boolean[] isPrime = MathUtils.genPrimesBoolean(123456);
        int n = in.nextInt();
        int[] a = new int[n];
        int[] pos = new int[n];
        ax = new int[5 * n];
        ay = new int[5 * n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt() - 1;
            pos[a[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            int where = pos[i];
            int dif = where - i;
            if (dif == 0) {
                continue;
            }
            if (dif == 1) {
                swap(i, i + 1, a, pos);
                continue;
            }
            if ((dif & 1) == 1) {
                dif--;
                int found = findSwap(primes, isPrime, dif);
                int second = dif - (found - 1) + 1;
                swap(where, where - found + 1, a, pos);
                swap(i + 1 + second - 1, i + 1, a, pos);
                swap(i, i + 1, a, pos);
            } else {
                int found = findSwap(primes, isPrime, dif);
                int second = dif - (found - 1) + 1;
                swap(where, where - found + 1, a, pos);
                swap(i + second - 1, i, a, pos);
            }
        }
        for (int i = 0; i < n; i++) if (a[i] != i) throw new AssertionError();
        out.println(ac);
        for (int i = 0; i < ac; i++) {
            out.println((ax[i] + 1) + " " + (ay[i] + 1));
        }
    }

    private int findSwap(int[] primes, boolean[] isPrime, int dif) {
        int found = -1;
        for (int j : primes) {
            if (isPrime[dif - (j - 1) + 1]) {
                found = j;
                break;
            }
        }
        if (found < 0) throw new AssertionError();
        return found;
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

class MathUtils {


    public static int[] genPrimes(int n) {
        boolean[] isPrime = genPrimesBoolean(n);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (isPrime[i]) {
                count++;
            }
        }
        int[] primes = new int[count];
        for (int i = 0, j = 0; i < n; i++) {
            if (isPrime[i]) {
                primes[j++] = i;
            }
        }
        return primes;
    }

    public static boolean[] genPrimesBoolean(int n) {
        boolean[] isPrime = new boolean[n];
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i < n; i++) {
            if (!isPrime[i]) {
                continue;
            }
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
        return isPrime;
    }

}