import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.Writer;
import java.util.Collections;
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

    static List<Move> make(int[] from, int[] to) {
        int n = from.length + 3;
        List<Move> ret = new ArrayList<>();
        for (int currentToMake = 2; currentToMake + 1 < n; ) {
            int last = currentToMake - 1;
            int next = n - 1;
            for (int j = 0; j < from.length; j++) {
                if (from[j] == 0 || to[j] == 0) {
                    int v = from[j] ^ to[j];
                    if (v >= currentToMake) {
                        next = Math.min(next, v);
                    }
                }
            }
            if (next == currentToMake) {
                ++currentToMake;
                continue;
            }
            int[] f = new int[n];
            f[(last + 1) % n] |= 1;
            f[(last + n - 1) % n] |= 1;
            f[(next + 1) % n] |= 2;
            f[(next + n - 1) % n] |= 2;
            for (int j = 0; j < from.length; j++) {
                if (from[j] == last) f[to[j]] |= 1;
                if (from[j] == next) f[to[j]] |= 2;
                if (to[j] == last) f[from[j]] |= 1;
                if (to[j] == next) f[from[j]] |= 2;
            }
            int fourth = 0;
            for (int j = 1; j < n; j++) if (f[j] == 3) fourth = j;
            if (fourth == 0) throw new AssertionError();
            boolean found = false;
            for (int j = 0; j < from.length; j++) {
                if (from[j] > to[j]) {
                    int t = from[j];
                    from[j] = to[j];
                    to[j] = t;
                }
                if (from[j] == last && to[j] == next) {
                    ret.add(new Move(new Diagonal(from[j], to[j]), new Diagonal(0, fourth)));
                    from[j] = 0;
                    to[j] = fourth;
                    found = true;
                    break;
                }
            }
            if (!found) throw new AssertionError();
        }
        return ret;
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int[] from1 = new int[n - 3];
        int[] to1 = new int[n - 3];
        for (int i = 0; i < n - 3; i++) {
            from1[i] = in.nextInt() - 1;
            to1[i] = in.nextInt() - 1;
        }
        int[] from2 = new int[n - 3];
        int[] to2 = new int[n - 3];
        for (int i = 0; i < n - 3; i++) {
            from2[i] = in.nextInt() - 1;
            to2[i] = in.nextInt() - 1;
        }
        List<Move> first = make(from1, to1);
        List<Move> second = make(from2, to2);
        out.println(first.size() + second.size());
        for (Move e : first) {
            out.println(e.a.from + 1 + " " + (e.a.to + 1));
        }
        Collections.reverse(second);
        for (Move e : second) {
            out.println(e.b.from + 1 + " " + (e.b.to + 1));
        }
    }

    static class Move {
        Diagonal a;
        Diagonal b;

        Move(Diagonal a, Diagonal b) {
            this.a = a;
            this.b = b;
        }
    }

    static class Diagonal {
        int from;
        int to;

        Diagonal(int from, int to) {
            this.from = from;
            this.to = to;
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