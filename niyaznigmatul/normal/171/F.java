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
 * @author niyaznigmatul 
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskF solver = new TaskF();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskF {

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
//        char[] map = new char[26];
//        for (int i = 0; i < b.length(); i++) {
//            map[b.charAt(i) - 'a'] = a.charAt(i);
//        }
//        for (int i = 0; i < m.length(); i++) {
//            if (!Character.isLetter(m.charAt(i))) {
//                out.print(m.charAt(i));
//            } else if (map[m.charAt(i) - 'a'] == 0) {
//                out.print("?");
//            } else {
//                out.print(map[m.charAt(i) - 'a']);
//            }
//        }
        int n = in.nextInt();
        int[] primes = MathUtils.genPrimes(2000000);
        for (int i : primes) {
            int z = Integer.parseInt(new StringBuilder(i + "").reverse().toString());
            if (i == z) {
                continue;
            }
            if (Arrays.binarySearch(primes, z) >= 0) {
                if (--n == 0) {
                    out.println(i);
                    return;
                }
            }
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