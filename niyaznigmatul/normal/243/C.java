import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
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

    static class Segment {
        int type;
        int x;
        int left;
        int right;

        Segment(int type, int x, int left, int right) {
            this.type = type;
            this.x = x;
            this.left = left;
            this.right = right;
        }
    }

    static final int[] DX = {1, 0, -1, 0};
    static final int[] DY = {0, 1, 0, -1};

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        List<Segment> all = new ArrayList<Segment>();
        int curX = 0;
        int curY = 0;
        int[] x = new int[n + 1];
        int[] y = new int[n + 1];
        all.add(new Segment(0, 0, 0, 0));
        for (int i = 1; i <= n; i++) {
            int dir = "RULD".indexOf(in.next());
            int count = in.nextInt();
            curX += DX[dir] * count;
            curY += DY[dir] * count;
            x[i] = curX;
            y[i] = curY;
        }
        int[] ux = x.clone();
        int[] uy = y.clone();
        x = ArrayUtils.sortAndUnique(x);
        y = ArrayUtils.sortAndUnique(y);
        int[] mapX = new int[x.length];
        int[] mapY = new int[y.length];
        int[] sizeX = getSize(x, mapX);
        int[] sizeY = getSize(y, mapY);
        boolean[][] a = new boolean[sizeX.length][sizeY.length];
        curX = 0;
        curY = 0;
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            int x1 = mapX[Arrays.binarySearch(x, ux[i])];
            int y1 = mapY[Arrays.binarySearch(y, uy[i])];
            int x2 = mapX[Arrays.binarySearch(x, ux[j])];
            int y2 = mapY[Arrays.binarySearch(y, uy[j])];
            if (x1 > x2) {
                int t = x1;
                x1 = x2;
                x2 = t;
            }
            if (y1 > y2) {
                int t = y1;
                y1 = y2;
                y2 = t;
            }
            while (x1 != x2 || y1 != y2) {
                a[x1][y1] = true;
                if (x1 != x2) {
                    ++x1;
                }
                if (y1 != y2) {
                    ++y1;
                }
            }
            a[x1][y1] = true;
        }
        int[] q = new int[sizeX.length * sizeY.length];
        boolean[][] was = new boolean[sizeX.length][sizeY.length];
        int head = 0;
        int tail = 0;
        n = sizeX.length;
        int m = sizeY.length;
        for (int i = 0; i < sizeX.length; i++) {
            if (!was[i][0]) {
                q[tail++] = i * m;
                was[i][0] = true;
            }
            if (!was[i][m - 1]) {
                was[i][m - 1] = true;
                q[tail++] = i * m + (m - 1);
            }
        }
        for (int i = 0; i < sizeY.length; i++) {
            if (!was[0][i]) {
                q[tail++] = i;
                was[0][i] = true;
            }
            if (!was[n - 1][i]) {
                q[tail++] = (n - 1) * m + i;
                was[n - 1][i] = true;
            }
        }
        while (head < tail) {
            int vx = q[head] / m;
            int vy = q[head] % m;
            ++head;
            for (int dir = 0; dir < 4; dir++) {
                int nx = vx + DX[dir];
                int ny = vy + DY[dir];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || a[nx][ny] || was[nx][ny]) {
                    continue;
                }
                was[nx][ny] = true;
                q[tail++] = nx * m + ny;
            }
        }
        long answer = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!was[i][j]) {
                    answer += (long) sizeX[i] * sizeY[j];
                }
            }
        }
        out.println(answer);
    }

    static int[] getSize(int[] x, int[] mapX) {
        int count = 0;
        int n = x.length;
        for (int i = 0; i + 1 < n; i++) {
            if (x[i + 1] - x[i] - 1 > 0) {
                ++count;
            }
        }
        int[] size = new int[2 + count + n];
        int cur = 0;
        size[cur++] = 1;
        for (int i = 0; i < n; i++) {
            mapX[i] = cur;
            size[cur++] = 1;
            if (i + 1 < n && x[i + 1] - x[i] - 1 > 0) {
                size[cur++] = x[i + 1] - x[i] - 1;
            }
        }
        size[cur++] = 1;
        if (cur != size.length) {
            throw new AssertionError();
        }
        return size;
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
        while (!isWhiteSpace(c)) {
            sb.appendCodePoint(c);
            c = read();
        }
        return sb.toString();
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

class ArrayUtils {

    static Random rand;

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

    static public void sort(int[] a) {
        if (rand == null) {
            rand = new Random(System.nanoTime());
        }
        for (int i = 1; i < a.length; i++) {
            int j = rand.nextInt(i + 1);
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
        Arrays.sort(a);
    }
}