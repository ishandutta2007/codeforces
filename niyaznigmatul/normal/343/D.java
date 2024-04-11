import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
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

    static int[][] edges;
    static int[] enter;
    static int[] exit;
    static int time;

    static void dfs(int v, int p) {
        enter[v] = time++;
        for (int i : edges[v]) {
            if (i == p) continue;
            dfs(i, v);
        }
        exit[v] = time;
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int[] from = new int[n - 1];
        int[] to = new int[n - 1];
        for (int i = 0; i < n - 1; i++) {
            from[i] = in.nextInt() - 1;
            to[i] = in.nextInt() - 1;
        }
        edges = GraphUtils.getEdgesUndirectedUnweighted(n, from, to);
        time = 0;
        enter = new int[n];
        exit = new int[n];
        dfs(0, -1);
        MaxSegmentTree tree = new MaxSegmentTree(n);
        MyMultiSegmentTree tree2 = new MyMultiSegmentTree(n);
        for (int i = 0; i < n; i++) {
            tree2.set(0, n, -2);
        }
        for (int i = 0; i < n; i++) {
            tree.set(i, -1);
        }
        int m = in.nextInt();
        for (int i = 0; i < m; i++) {
            int type = in.nextInt();
            int v = in.nextInt() - 1;
            if (type == 1) {
                tree2.set(enter[v], exit[v], i);
            } else if (type == 2) {
                tree.set(enter[v], i);
            } else {
                int max1 = tree.getMax(enter[v], exit[v]);
                int max2 = tree2.getMax(enter[v], enter[v] + 1);
                if (max1 > max2) {
                    out.println(0);
                } else {
                    out.println(1);
                }
            }
        }
    }

    static class MyMultiSegmentTree {
        private int[] max;
        private int[] set;
        private boolean[] toSet;
        final int n;

        public MyMultiSegmentTree(int n) {
            this.n = Integer.highestOneBit(n) << 1;
            max = new int[this.n << 1];
            set = new int[this.n << 1];
            toSet = new boolean[this.n << 1];
        }

        private void set(int node, int x) {
            set[node] = x;
            toSet[node] = true;
        }

        private void relax(int node) {
            if (!toSet[node]) {
                return;
            }
            max[node] = getMax(node);
                set((node << 1) | 1, set[node]);
                set((node << 1) + 2, set[node]);
                toSet[node] = false;
        }

        private int getMax(int node) {
            return toSet[node] ? set[node] : max[node];
        }

        private void set(int node, int l, int r, int left, int right, int x) {
            if (right <= l || r <= left) {
                return;
            }
            if (left <= l && r <= right) {
                set(node, x);
                return;
            }
            relax(node);
            int m = (l + r) >> 1;
            set((node << 1) | 1, l, m, left, right, x);
            set((node << 1) + 2, m, r, left, right, x);
            max[node] = Math.max(getMax((node << 1) | 1),
                    getMax((node << 1) + 2));
        }

        private int getMax(int node, int l, int r, int left, int right) {
            if (right <= l || r <= left) {
                return Integer.MIN_VALUE;
            }
            if (left <= l && r <= right) {
                return getMax(node);
            }
            relax(node);
            int m = (l + r) >> 1;
            return Math.max(getMax((node << 1) | 1, l, m, left, right),
                    getMax((node << 1) + 2, m, r, left, right));
        }

        public void set(int l, int r, int x) {
            if (l >= r) {
                return;
            }
            set(0, 0, n, l, r, x);
        }

        public int getMax(int l, int r) {
            if (l >= r) {
                return Integer.MAX_VALUE;
            }
            return getMax(0, 0, n, l, r);
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

class GraphUtils {
    public static int[][] getEdgesUndirectedUnweighted(int n, int[] v, int[] u) {
        int[][] edges = new int[n][];
        int[] deg = getDegreeUndirected(n, v, u);
        for (int i = 0; i < n; i++) {
            edges[i] = new int[deg[i]];
        }
        int m = v.length;
        Arrays.fill(deg, 0);
        for (int i = 0; i < m; i++) {
            edges[v[i]][deg[v[i]]++] = u[i];
            edges[u[i]][deg[u[i]]++] = v[i];
        }
        return edges;
    }

    public static int[] getDegreeUndirected(int n, int[] v, int[] u) {
        int[] deg = new int[n];
        for (int i : v) {
            deg[i]++;
        }
        for (int i : u) {
            deg[i]++;
        }
        return deg;
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