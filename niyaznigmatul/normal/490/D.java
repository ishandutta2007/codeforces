import java.io.InputStreamReader;
import java.io.IOException;
import java.util.InputMismatchException;
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
        int a1 = in.nextInt();
        int b1 = in.nextInt();
        int a2 = in.nextInt();
        int b2 = in.nextInt();
        if ((long) free(a1) * free(b1) != (long) free(a2) * free(b2)) {
            out.println(-1);
            return;
        }
        int two1 = two(a1) + two(b1);
        int three1 = three(a1) + three(b1);
        int two2 = two(a2) + two(b2);
        int three2 = three(a2) + three(b2);
        int best = Integer.MAX_VALUE;
        int ansTwo = -1;
        int ansThree = -1;
        for (int two = 0; two <= two1 || two <= two2; two++) {
            for (int three = 0; three <= three1 && three <= three2; three++) {
                int cost = three1 + three2 - three * 2;
                int c1 = two1 + three1 - three;
                int c2 = two2 + three2 - three;
                if (c1 < two || c2 < two) continue;
                cost += c1 - two;
                cost += c2 - two;
                if (cost < best) {
                    best = cost;
                    ansTwo = two;
                    ansThree = three;
                }
            }
        }
        while (three1 > ansThree) {
            if (a1 % 3 == 0) {
                a1 /= 3;
                a1 *= 2;
                --three1;
                ++two1;
                continue;
            }
            if (b1 % 3 == 0) {
                b1 /= 3;
                b1 *= 2;
                --three1;
                ++two1;
                continue;
            }
            throw new AssertionError();
        }
        while (three2 > ansThree) {
            if (a2 % 3 == 0) {
                a2 /= 3;
                a2 *= 2;
                --three2;
                ++two2;
                continue;
            }
            if (b2 % 3 == 0) {
                b2 /= 3;
                b2 *= 2;
                --three2;
                ++two2;
                continue;
            }
            throw new AssertionError();
        }
        while (two1 > ansTwo) {
            if (a1 % 2 == 0) {
                a1 /= 2;
                --two1;
                continue;
            }
            if (b1 % 2 == 0) {
                b1 /= 2;
                --two1;
                continue;
            }
            throw new AssertionError();
        }
        while (two2 > ansTwo) {
            if (a2 % 2 == 0) {
                a2 /= 2;
                --two2;
                continue;
            }
            if (b2 % 2 == 0) {
                b2 /= 2;
                --two2;
                continue;
            }
            throw new AssertionError();
        }
        out.println(best);
        out.println(a1 + " " + b1);
        out.println(a2 + " " + b2);
    }


    static int free(int n) {
        while (n % 2 == 0) n /= 2;
        while (n % 3 == 0) n /= 3;
        return n;
    }

    static int countIt(int n, int a) {
        int count = 0;
        while (n % a == 0) {
            n /= a;
            ++count;
        }
        return count;
    }

    static int three(int n) {
        return countIt(n, 3);
    }

    static int two(int n) {
        return countIt(n, 2);
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