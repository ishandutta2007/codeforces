import java.io.Reader;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.List;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.util.Collections;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;

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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {

    static List<Integer>[] edges;
    static List<Integer>[] revEdges;
    static List<Integer> topSort;
    static boolean[] was;
    static int[] color;

    static void dfs(int v) {
        was[v] = true;
        for (int i = 0; i < edges[v].size(); i++) {
            int to = edges[v].get(i);
            if (!was[to]) dfs(to);
        }
        topSort.add(v);
    }

    static void dfs2(int v, int c) {
        color[v] = c;
        for (int i = 0; i < revEdges[v].size(); i++) {
            int to = revEdges[v].get(i);
            if (color[to] < 0) dfs2(to, c);
        }
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int[] v = in.readIntArray(n);
        edges = new List[n];
        revEdges = new List[n];
        for (int i = 0; i < n; i++) {
            edges[i] = new ArrayList<>();
            revEdges[i] = new ArrayList<>();
        }
        int m = in.nextInt();
        for (int i = 0; i < m; i++) {
            int from = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            edges[from].add(to);
            revEdges[to].add(from);
        }
        was = new boolean[n];
        topSort = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (!was[i]) dfs(i);
        }
        Collections.reverse(topSort);
        color = new int[n];
        int c = 0;
        Arrays.fill(color, -1);
        for (int i : topSort) {
            if (color[i] < 0) dfs2(i, c++);
        }
        int[] minimum = new int[c];
        Arrays.fill(minimum, Integer.MAX_VALUE);
        int[] count = new int[c];
        for (int i = 0; i < n; i++) {
            int where = color[i];
            if (minimum[where] > v[i]) {
                minimum[where] = v[i];
                count[where] = 1;
            } else if (minimum[where] == v[i]) {
                ++count[where];
            }
        }
        int ans = 1;
        long sum = 0;
        for (int i = 0; i < c; i++) {
            sum += minimum[i];
            ans = (int) ((long) ans * count[i] % 1000000007);
        }
        out.println(sum + " " + ans);
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

    public int[] readIntArray(int n) {
        int[] ret = new int[n];
        for (int i = 0; i < n; i++) {
            ret[i] = nextInt();
        }
        return ret;
    }

}

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }


}