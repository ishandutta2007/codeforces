import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
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
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        long n = in.nextLong();
        if (n % 3 != 0) {
            out.println(0);
            return;
        }
        n /= 3;
        long[] divisors;
        {
            List<Long> d = new ArrayList<>();
            for (long i = 1; i * i <= n; i++) {
                if (n % i == 0) {
                    d.add(i);
                    if (i * i != n) d.add(n / i);
                }
            }
            divisors = new long[d.size()];
            for (int i = 0; i < divisors.length; i++) {
                divisors[i] = d.get(i);
            }
            Arrays.sort(divisors);
        }
        long ans = 0;
        for (long ac : divisors) {
            for (long ab : divisors) {
                if (ab > ac) {
                    break;
                }
                if ((n / ac) % ab != 0) {
                    continue;
                }
                long bc = n / ac / ab;
                if (bc < ac || bc < ab) {
                    break;
                }
                long twiceB = ab + bc - ac;
                if ((twiceB & 1) != 0) {
                    continue;
                }
                long b = twiceB >> 1;
                long a = ab - b;
                if (a <= 0) {
                    continue;
                }
                long c = bc - b;
                if (c <= 0 || c < b) {
                    continue;
                }
                if ((a + b) * (b + c) * (a + c) == n) {
                    if (a == b && b == c) {
                        ans++;
                    } else if (a == b || b == c) {
                        ans += 3;
                    } else {
                        ans += 6;
                    }
                }
            }
        }
        out.println(ans);
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