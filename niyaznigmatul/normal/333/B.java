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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {

    static List<Integer>[] edges;

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        boolean[] ok = new boolean[(n - 2) * 4];
        Arrays.fill(ok, true);
        int m = in.nextInt();
        for (int i = 0; i < m; i++) {
            int x = in.nextInt() - 1;
            int y = in.nextInt() - 1;
            if (x > 0 && x < n - 1) {
                ok[x - 1] = false;
                ok[2 * (n - 2) + (n - 2) - x] = false;
            }
            if (y > 0 && y < n - 1) {
                ok[n - 2 + y - 1] = false;
                ok[3 * (n - 2) + (n - 2) - y] = false;
            }
        }
        edges = new List[4 * (n - 2)];
        for (int i = 0; i < edges.length; i++) {
            edges[i] = new ArrayList<>();
        }
        for (int x = 0; x < n - 2; x++) {
            for (int d = 0; d < 3; d++) {
                for (int j = d + 2; j <= 4; j++) {
                    edges[x + d * (n - 2)].add(j * (n - 2) - x - 1);
                    edges[j * (n - 2) - x - 1].add(x + d * (n - 2));
                }
            }
//            edges[x].add(3 * (n - 2) - x - 1);
//            edges[3 * (n - 2) - x - 1].add(x);
//            edges[x].add(4 * (n - 2) - x - 1);
//            edges[4 * (n - 2) - x - 1].add(x);
//            edges[x].add(2 * (n - 2) - x - 1);
//            edges[2 * (n - 2) - x - 1].add(x);
//            edges[(n - 2) + x].add(3 * (n - 2) - x - 1);
//            edges[3 * (n - 2) - x - 1].add(n - 2 + x);
//            edges[n - 2 + x].add(4 * (n - 2) - x - 1);
//            edges[4 * (n - 2) - x - 1].add(n - 2 + x);
//            edges[]
        }
        int[] q = new int[edges.length];
        boolean[] was = new boolean[edges.length];
        int[] vs = new int[edges.length];
        int ans = 0;
        for (int start = 0; start < edges.length; start++) {
            if (was[start]) continue;
            int head = 0;
            int tail = 0;
            q[tail++] = start;
            was[start] = true;
            int cn = 0;
            while (head < tail) {
                int v = q[head++];
                vs[cn++] = v;
                for (int i : edges[v]) {
                    if (was[i]) {
                        continue;
                    }
                    q[tail++] = i;
                    was[i] = true;
                }
            }
            Arrays.sort(vs, 0, cn);
            boolean[][] ms = new boolean[cn][cn];
            for (int i = 0; i < cn; i++) {
                for (int j : edges[vs[i]]) {
                    ms[i][Arrays.binarySearch(vs, 0, cn, j)] = true;
                }
            }
            int cur = Integer.MIN_VALUE;
            for (int mask = 0; mask < 1 << cn; mask++) {
                boolean isMaskOk = true;
                loop:
                for (int i = 0; i < cn; i++) {
                    if (((mask >> i) & 1) == 0) continue;
                    if (((mask >> i) & 1) == 1 && !ok[vs[i]]) {
                        isMaskOk = false;
                        break;
                    }
                    for (int j = i + 1; j < cn; j++) {
                        if (((mask >> j) & 1) == 1 && ms[i][j]) {
                            isMaskOk = false;
                            break loop;
                        }
                    }
                }
                if (isMaskOk) {
                    cur = Math.max(cur, Integer.bitCount(mask));
                }
            }
            ans += cur;
        }
        out.println(ans);
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