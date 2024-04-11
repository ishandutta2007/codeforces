import java.io.InputStreamReader;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {

    static Random rand = new Random(348734L);

    static class Node {
        Node l, r;
        int cnt;
        long sum1;
        long sum2;
        long sum;
        int x;

        Node(int x) {
            l = r = null;
            cnt = 1;
            this.x = x;
            sum1 = sum2 = 0;
            sum = x;
        }
    }

    static Node[] split(Node v, int x) {
        if (v == null) {
            return new Node[2];
        }
        Node[] ret;
        if (v.x > x) {
            ret = split(v.l, x);
            v.l = ret[1];
            ret[1] = v;
        } else {
            ret = split(v.r, x);
            v.r = ret[0];
            ret[0] = v;
        }
        update(v);
        return ret;
    }

    static Node merge(Node a, Node b) {
        if (a == null) {
            return b;
        }
        if (b == null) {
            return a;
        }
        int sizeA = a.cnt;
        int sizeB = b.cnt;
        Node ret;
        if (rand.nextInt(sizeA + sizeB) < sizeA) {
            a.r = merge(a.r, b);
            ret = a;
        } else {
            b.l = merge(a, b.l);
            ret = b;
        }
        update(ret);
        return ret;
    }

    static int getCnt(Node v) {
        return v == null ? 0 : v.cnt;
    }

    static long getSum(Node v) {
        return v == null ? 0 : v.sum;
    }

    static long getSum1(Node v) {
        return v == null ? 0 : v.sum1;
    }

    static long getSum2(Node v) {
        return v == null ? 0 : v.sum2;
    }

    static void update(Node v) {
        if (v == null) {
            return;
        }
        int cntLeft = getCnt(v.l);
        int cntRight = getCnt(v.r);
        v.cnt = 1 + cntLeft + cntRight;
        v.sum = v.x + getSum(v.l) + getSum(v.r);
        v.sum1 = getSum1(v.l) + getSum1(v.r) + (cntLeft + 1) * getSum(v.r) + (long) v.x * cntLeft;
        v.sum2 = getSum2(v.r) + getSum2(v.l) + (cntRight + 1) * getSum(v.l) + (long) v.x * cntRight;
    }

    static Node insert(Node v, int x) {
        Node[] t = split(v, x);
        return merge(merge(t[0], new Node(x)), t[1]);
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int[] x = new int[n];
        Node root = null;
        for (int i = 0; i < n; i++) {
            x[i] = in.nextInt();
            root = insert(root, x[i]);
        }
        int m = in.nextInt();
        for (int i = 0; i < m; i++) {
            int t = in.nextInt();
            if (t == 1) {
                int id = in.nextInt() - 1;
                Node[] t0 = split(root, x[id]);
                Node[] t1 = split(t0[0], x[id] - 1);
                x[id] += in.nextInt();
                root = merge(t1[0], t0[1]);
                root = insert(root, x[id]);
            } else {
                int left = in.nextInt();
                int right = in.nextInt();
                Node[] t0 = split(root, right);
                Node[] t1 = split(t0[0], left - 1);
                long ans1 = getSum1(t1[1]);
                long ans2 = getSum2(t1[1]);
                out.println(ans1 - ans2);
                root = merge(t1[0], merge(t1[1], t0[1]));
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

    }

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }

    public FastPrinter(Writer out) {
        super(out);
    }


}