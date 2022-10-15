import java.io.Reader;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.List;
import java.io.BufferedReader;
import java.io.OutputStream;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    static List<Integer>[] edges;
    static int[] size;
    static int[] dpMax;
    static int[] dpMin;

    void dfs(int v, int p, int level) {
        size[v] = 0;
        for (int i = 0; i < edges[v].size(); i++) {
            int to = edges[v].get(i);
            if (to == p) continue;
            dfs(to, v, level ^ 1);
            size[v] += size[to];
        }
        if (size[v] == 0) {
            ++size[v];
            return;
        }
        if (level == 0) {
            int mx = Integer.MAX_VALUE;
            int mn = 0;
            for (int i = 0; i < edges[v].size(); i++) {
                int to = edges[v].get(i);
                if (to == p) continue;
                mx = Math.min(mx, size[to] - dpMax[to]);
                mn += size[to] - dpMin[to] - 1;
            }
            dpMax[v] = size[v] - mx;
            dpMin[v] = size[v] - mn - 1;
        } else {
            int mx = 0;
            int mn = Integer.MAX_VALUE;
            for (int i = 0; i < edges[v].size(); i++) {
                int to = edges[v].get(i);
                if (to == p) continue;
                mx += dpMax[to];
                mn = Math.min(mn, dpMin[to]);
            }
            dpMax[v] = mx;
            dpMin[v] = mn;
        }
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        edges = new List[n];
        for (int i = 0; i < n; i++) edges[i] = new ArrayList<>();
        for (int i = 0; i + 1 < n; i++) {
            int v = in.nextInt() - 1;
            int u = in.nextInt() - 1;
            edges[v].add(u);
            edges[u].add(v);
        }
        dpMax = new int[n];
        dpMin = new int[n];
        size = new int[n];
        dfs(0, -1, 0);
        out.println((dpMax[0] + 1) + " " + (dpMin[0] + 1));
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


}