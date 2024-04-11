import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Comparator;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    static class Segment {
        int start;
        int end;
        int id;

        Segment(int start, int end, int id) {
            this.start = start;
            this.end = end;
            this.id = id;
        }
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        in.nextInt();
        int m = in.nextInt();
        Segment[] a = new Segment[m];
        for (int i = 0; i < m; i++) {
            int start = in.nextInt();
            int end = in.nextInt() + start - 1;
            a[i] = new Segment(start, end, i);
        }
        Arrays.sort(a, new Comparator<Segment>() {
            @Override
            public int compare(Segment o1, Segment o2) {
                if (o1.start != o2.start) return Integer.compare(o1.start, o2.start);
                return Integer.compare(o2.end, o1.end);
            }
        });
        int last = Integer.MIN_VALUE;
        boolean[] get = new boolean[m];
        Segment curMax = null;
        boolean first = true;
        for (Segment e : a) {
            if (first) {
                first = false;
                curMax = e;
                last = e.end;
                get[e.id] = true;
                continue;
            }
            if (e.start <= last + 1) {
                if (curMax.end < e.end) {
                    curMax = e;
                }
                continue;
            }
            last = curMax.end;
            get[curMax.id] = true;
            if (e.end > curMax.end) {
                curMax = e;
            }
        }
        if (curMax.end >= last) {
            get[curMax.id] = true;
        }
        int[] ans = new int[m];
        int ac = 0;
        for (int i = 0; i < m; i++) {
            if (!get[i]) {
                ans[ac++] = i + 1;
            }
        }
        out.println(ac);
        out.printArray(Arrays.copyOf(ans, ac));
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

    public void printArray(int[] a) {
        for (int i = 0; i < a.length; i++) {
            if (i > 0) {
                print(' ');
            }
            print(a[i]);
        }
        println();
    }


}