import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {

    static final int ALPHABET = 30;

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int left1 = in.nextInt();
        int right1 = in.nextInt();
        int left2 = in.nextInt();
        int right2 = in.nextInt();
        int ans = 0;
        for (int i = ALPHABET - 1; i >= 0; i--) {
            List<int[]> a = getLimits(left1, right1, i);
            List<int[]> b = getLimits(left2, right2, i);
            for (int[] first : a) {
                for (int[] second : b) {
                    int toLeft = Math.min(first[0], second[0]);
                    int toRight = Math.min(first[1], second[1]);
                    ans = Math.max(ans, toLeft + toRight + 1);
                }
            }
        }
        out.println(ans);
    }

    static List<int[]> getLimits(int left, int right, int letter) {
        int count = getCount(left, right, letter);
        List<int[]> ret = new ArrayList<int[]>();
        if (count == 0) {
            return ret;
        }
        if (count >= 3) {
            ret.add(new int[]{getMaxPart(letter), getMaxPart(letter)});
            return ret;
        }
        List<Integer> all = getAll(left, right, letter);
        for (int i : all) {
            ret.add(new int[]{Math.min(getMaxPart(letter), i - left), Math.min(getMaxPart(letter), right - i)});
        }
        return ret;
    }

    private static int getMaxPart(int letter) {
        return (1 << letter) - 1;
    }

    static int getCount(int left, int right, int letter) {
        int ret = 0;
        long add = 1L << letter + 1;
        for (long i = getFirst(left - 1, letter); i <= right; i += add) {
            ret++;
            if (ret >= 3) {
                return ret;
            }
        }
        return ret;
    }


    static List<Integer> getAll(int left, int right, int letter) {
        long add = 1L << letter + 1;
        List<Integer> ret = new ArrayList<Integer>();
        for (long i = getFirst(left - 1, letter); i <= right; i += add) {
            ret.add((int) i);
        }
        return ret;
    }

    static long getFirst(long x, int letter) {
        x &= ~((1L << letter) - 1);
        x += 1L << letter;
        if (((x >> letter) & 1) == 0) {
            x += 1L << letter;
        }
        return x;
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