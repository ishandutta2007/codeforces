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
		TaskD1 solver = new TaskD1();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD1 {

    static class Edge {
        int from;
        int to;
        int type;

        Edge(int from, int to, int type) {
            this.from = from;
            this.to = to;
            this.type = type;
        }
    }

    static List<Edge>[] edges;

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int c = in.nextInt();
        edges = new List[n];
        for (int i = 0; i < n; i++) {
            edges[i] = new ArrayList<>();
        }
        int[] deg = new int[n];
        for (int i = 0; i < c; i++) {
            int from = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            int type = in.next().equals("LEFT") ? 1 : 2;
            if (to <= from) {
                out.println("IMPOSSIBLE");
                return;
            }
            edges[from].add(new Edge(from, to, type));
            deg[to]++;
        }
        int[] q = new int[n];
        int head = 0;
        int tail = 0;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 0) {
                q[tail++] = i;
            }
        }
        while (head < tail) {
            int v = q[head++];
            for (int i = 0; i < edges[v].size(); i++) {
                Edge e = edges[v].get(i);
                deg[e.to]--;
                if (deg[e.to] == 0) {
                    q[tail++] = e.to;
                }
            }
        }
        if (head != n) {
            out.println("IMPOSSIBLE");
            return;
        }
        int[] max1 = new int[n];
//        int[] dMin = new int[n];
        int[] dMax = new int[n];
//        Arrays.fill(min2, Integer.MAX_VALUE);
//        Arrays.fill(dMin, Integer.MAX_VALUE);
        Arrays.fill(max1, Integer.MIN_VALUE);
        Arrays.fill(dMax, Integer.MIN_VALUE);
        MaxSegmentTree tree = new MaxSegmentTree(n);
        for (int i = 0; i < n; i++) {
            tree.set(i, i);
        }
        for (int v = n - 1; v >= 0; v--) {
            dMax[v] = v;
            max1[v] = v;
            int minimal = Integer.MAX_VALUE;
            for (int i = 0; i < edges[v].size(); i++) {
                Edge e = edges[v].get(i);
                dMax[v] = Math.max(dMax[v], dMax[e.to]);
                if (e.type == 1) {
                    max1[v] = Math.max(max1[v], dMax[e.to]);
                } else {
                    minimal = Math.min(minimal, e.to);
                }
            }
            max1[v] = tree.getMax(v, max1[v] + 1);
            tree.set(v, tree.getMax(v, dMax[v] + 1));
            if (max1[v] >= minimal) {
                out.println("IMPOSSIBLE");
                return;
            }
        }
        ans = new int[n];
        cn = 0;
        go(0, n - 1, max1);
        out.printArray(ans);
    }

    static int[] ans;
    static int cn;

    static void go(int v, int last, int[] max1) {
        if (v + 1 <= max1[v]) go(v + 1, max1[v], max1);
        ans[cn++] = v + 1;
        if (max1[v] <= last - 1) go(max1[v] + 1, last, max1);
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

class MaxSegmentTree {
    int[] max;
    int[] maxId;
    int n;

    public MaxSegmentTree(int n) {
        this.n = Integer.highestOneBit(n) << 1;
        max = new int[this.n * 2];
        maxId = new int[this.n * 2];
        Arrays.fill(max, Integer.MIN_VALUE);
        for (int i = 0; i < n; i++) {
            maxId[i + n] = i;
        }
        for (int i = 0; i < n; i++) {
            set(i, Integer.MIN_VALUE);
        }
    }

    public void set(int x, int y) {
        x += n;
        max[x] = y;
        while (x > 1) {
            x >>= 1;
            int left = max[x << 1];
            int right = max[(x << 1) | 1];
            if (left >= right) {
                max[x] = left;
                maxId[x] = maxId[x << 1];
            } else {
                max[x] = right;
                maxId[x] = maxId[(x << 1) | 1];
            }
        }
    }

    public int getMax(int left, int right) {
        --right;
        left += n;
        right += n;
        int ret = Integer.MIN_VALUE;
        while (left <= right) {
            if ((left & 1) == 1) {
                ret = Math.max(ret, max[left]);
                left++;
            }
            if ((right & 1) == 0) {
                ret = Math.max(ret, max[right]);
                right--;
            }
            left >>= 1;
            right >>= 1;
        }
        return ret;
    }

}