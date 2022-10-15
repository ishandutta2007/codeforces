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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int a = in.nextInt();
        int b = in.nextInt();
        int k = in.nextInt();
        for (long i = 2; i * i <= k; i++) {
            if (k % i == 0) {
                out.println(0);
                return;
            }
        }
        out.println(get(b, k) - get(a - 1, k));
    }

    static int get(int n, int k) {
        if (n < k) {
            return 0;
        }
        if ((long) k * k > n) {
            return 1;
        }
        int[] primes = MathUtils.genPrimes(k);
        int m = n / k;
        int z = primes.length;
        if (z <= 20) {
            int answer = 0;
            for (int mask = 0; mask < 1 << z; mask++) {
                long mul = 1;
                for (int i = 0; i < z; i++) {
                    if (((mask >> i) & 1) == 0) {
                        continue;
                    }
                    mul *= primes[i];
                }
                int got = (int) (m / mul);
                if ((Integer.bitCount(mask) & 1) == 0) {
                    answer += got;
                } else {
                    answer -= got;
                }
            }
            return answer;
        } else {
            boolean[] good = new boolean[m + 1];
            for (int i : primes) {
                for (int j = i; j <= m; j += i) {
                    good[j] = true;
                }
            }
            int answer = 0;
            for (int i = 1; i <= m; i++) {
                if (!good[i]) {
                    ++answer;
                }
            }
            return answer;
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