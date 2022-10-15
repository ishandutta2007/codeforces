import java.io.BufferedReader;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.io.Writer;
import java.util.Collection;
import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.ArrayDeque;
import java.io.Reader;
import java.util.Queue;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {

    static final int SHIFT = 400;
    static final int[][] PRECALC;
    static int[] DX = {-1, 0, 1, 0};
    static int[] DY = {0, 1, 0, -1};
    static {
        int all = SHIFT * 2 + 1;
        PRECALC = new int[all][all];
        int x = SHIFT;
        int y = SHIFT;
        int cur = 0;
        int dir = 0;
        int cur2 = 0;
        while (x >= 0 && y >= 0 && x < all && y < all) {
            int step = (cur >> 1) + 1;
            while (x >= 0 && y >= 0 && x < all && y < all && step > 0) {
                PRECALC[x][y] = cur2++;
                x += DX[dir];
                y += DY[dir];
                --step;
            }
            dir = dir + 1 & 3;
            ++cur;
        }
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        final int m = in.nextInt();
        int[][] a = in.readInt2DArray(n, m);
        int[][] b = in.readInt2DArray(n, m);
        int[] z = new int[n * m * 2 + 1];
        {
            int cur = 0;
            z[cur++] = 0;
            for (int[][] d : new int[][][]{a, b}) {
                for (int[] e : d) {
                    for (int f : e) {
                        if (f >= 0) {
                            z[cur++] = f;
                        }
                    }
                }
            }
            z = Arrays.copyOf(z, cur);
            z = ArrayUtils.sortAndUnique(z);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    a[i][j] = Arrays.binarySearch(z, a[i][j]);
                    if (b[i][j] >= 0) {
                        b[i][j] = Arrays.binarySearch(z, b[i][j]);
                    }
                }
            }
        }
        int x0 = in.nextInt() - 1;
        int y0 = in.nextInt() - 1;
        int cntColors = z.length;
        List<Integer>[] cells = new List[cntColors];
        List<Integer>[] elements = new List[cntColors];
        for (int i = 0; i < cntColors; i++) {
            cells[i] = new ArrayList<Integer>();
            elements[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cells[a[i][j]].add(i * m + j);
                if (x0 == i && y0 == j) {
                    continue;
                }
                if (b[i][j] >= 0) {
                    elements[a[i][j]].add(i * m + j);
                }
            }
        }
        DSU dsu = new DSU(n * m);
        for (int i = 0; i < cntColors; i++) {
            if (cells[i].isEmpty()) {
                continue;
            }
            int first = cells[i].get(0);
            for (int j : cells[i]) {
                dsu.union(first, j);
            }
            dsu.setColor(first, i);
        }
        Queue<Integer> q = new ArrayDeque<Integer>();
        q.add(x0 * m + y0);
        long answer = 0;
        while (!q.isEmpty()) {
            int v = q.poll();
            final int curX = v / m;
            final int curY = v % m;
//            int curColor = a[curX][curY];
            int curColor = dsu.color[dsu.get(v)];
            int nextColor = b[curX][curY];
            if (curColor == 0 || curColor == nextColor || cells[curColor].isEmpty()) {
                continue;
            }
            answer += cells[curColor].size();
            Collections.sort(elements[curColor], new Comparator<Integer>() {
                public int compare(Integer o1, Integer o2) {
                    return getID(o1) - getID(o2);
                }

                private int getID(int v) {
                    int x = v / m;
                    int y = v - x * m;
                    x -= curX;
                    y -= curY;
                    return PRECALC[x + SHIFT][y + SHIFT];
                }
            });
            for (int e : elements[curColor]) {
                q.add(e);
            }
            elements[curColor].clear();
            if (!cells[nextColor].isEmpty()) {
                dsu.union(v, cells[nextColor].get(0));
            }
            if (cells[nextColor].size() < cells[curColor].size()) {
                List<Integer> t = cells[nextColor];
                cells[nextColor] = cells[curColor];
                cells[curColor] = t;
            }
            while (!cells[curColor].isEmpty()) {
                Integer d = cells[curColor].remove(cells[curColor].size() - 1);
                int x = d / m;
                int y = d - x * m;
                a[x][y] = nextColor;
                cells[nextColor].add(d);
            }
            dsu.setColor(v, nextColor);
        }
        out.println(answer);
    }

    static class DSU {
        int[] p;
        int[] color;

        DSU(int n) {
            p = new int[n];
            for (int i = 0; i < n; i++) {
                p[i] = i;
            }
            color = new int[n];
        }

        void setColor(int v, int c) {
            v = get(v);
            color[v] = c;
        }

        int get(int v) {
            return v == p[v] ? v : (p[v] = get(p[v]));
        }

        void union(int v, int u) {
            v = get(v);
            u = get(u);
            p[v] = u;
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

    public int[][] readInt2DArray(int n, int m) {
        int[][] ret = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ret[i][j] = nextInt();
            }
        }
        return ret;
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

class ArrayUtils {


    static final long seed = System.nanoTime();

    static final Random rand = new Random(seed);

    static public int[] sortAndUnique(int[] a) {
        int[] ret = a.clone();
        sort(ret);
        if (ret.length == 0) {
            return ret;
        }
        int last = ret[0];
        int j = 1;
        for (int i = 1; i < ret.length; i++) {
            if (last != ret[i]) {
                ret[j++] = ret[i];
            }
            last = ret[i];
        }
        return Arrays.copyOf(ret, j);
    }

    public static void sort(int[] a) {
        shuffle(a);
        Arrays.sort(a);
    }

    public static void shuffle(int[] a) {
        for (int i = 0; i < a.length; i++) {
            int j = rand.nextInt(i + 1);
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }


    }