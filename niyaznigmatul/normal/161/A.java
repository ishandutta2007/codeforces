import java.util.List;
import java.util.NavigableSet;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.Set;
import java.util.Comparator;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.util.TreeSet;
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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {

    static class Vest implements Comparable<Vest> {
        int x;
        int id;

        Vest(int x, int id) {
            this.x = x;
            this.id = id;
        }


        public int compareTo(Vest o) {
            if (x != o.x) {
                return x < o.x ? -1 : 1;
            }
            return id - o.id;
        }
    }

    static class Man {
        int left;
        int right;
        int id;

        Man(int left, int right, int id) {
            this.left = left;
            this.right = right;
            this.id = id;
        }
    }

	public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int x = in.nextInt();
        int y = in.nextInt();
        Man[] a = new Man[n];
        for (int i = 0; i < n; i++) {
            int c = in.nextInt();
            a[i] = new Man(c - x, c + y, i);
        }
        NavigableSet<Vest> set = new TreeSet<Vest>();
        for (int i = 0; i < m; i++) {
            int c = in.nextInt();
            set.add(new Vest(c, i));
        }
        Arrays.sort(a, new Comparator<Man>() {
            public int compare(Man o1, Man o2) {
                return o1.left < o2.left ? -1 : o1.left > o2.left ? 1 : 0;
            }
        });
        List<String> answer = new ArrayList<String>();
        Vest tmp = new Vest(0, -1);
        for (Man e : a) {
            tmp.x = e.left;
            Vest cur = set.ceiling(tmp);
            if (cur == null || cur.x > e.right) {
                continue;
            }
            set.remove(cur);
            answer.add(e.id + 1 + " " + (cur.id + 1));
        }
        out.println(answer.size());
        for (String e : answer) {
            out.println(e);
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