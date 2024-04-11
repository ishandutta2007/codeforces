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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {

    static List<Integer>[] edges;
    static boolean[] type1, type2;

    static void dfs1(int v, int pv) {
        int children = 0;
        boolean allType1 = true;
        for (int i = 0; i < edges[v].size(); i++) {
            int to = edges[v].get(i);
            if (to == pv) continue;
            children++;
            dfs1(to, v);
            allType1 &= type1[to];
        }
        type1[v] = children <= 1 && allType1;
    }

    static void dfs2(int v, int pv) {
        if (type1[v]) return;
        int children = 0;
        boolean allType1 = true;
        for (int i = 0; i < edges[v].size(); i++) {
            int to = edges[v].get(i);
            if (to == pv) continue;
            children++;
            dfs2(to, v);
            allType1 &= type1[to];
        }
        if (children <= 2 && allType1) {
            type2[v] = true;
        }
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        edges = new List[n];
        for (int i = 0; i < n; i++) edges[i] = new ArrayList<>();
        for (int i = 0; i < n - 1; i++) {
            int v = in.nextInt() - 1;
            int u = in.nextInt() - 1;
            edges[v].add(u);
            edges[u].add(v);
        }
        int root1 = -1;
        for (int i = 0; i < n; i++)
            if (edges[i].size() >= 3) {
                root1 = i;
                break;
            }
        if (root1 < 0) {
            out.println("Yes");
            return;
        }
        type1 = new boolean[n];
        dfs1(root1, -1);
        int root2 = -1;
        for (int i = 0; i < n; i++) {
            if (type1[i]) continue;
            int countNotType1 = 0;
            for (int j : edges[i]) {
                if (!type1[j]) {
                    ++countNotType1;
                }
            }
            if (countNotType1 > 1) {
                root2 = i;
                break;
            }
        }
        if (root2 < 0) {
            out.println("Yes");
            return;
        }
        type2 = new boolean[n];
        dfs2(root2, -1);
        if (dfs3(root2, -1) < 0) {
            out.println("No");
        } else {
            out.println("Yes");
        }
    }

    static int dfs3(int v, int pv) {
        if (type1[v] || type2[v]) return 0;
        int all = 0;
        for (int i = 0; i < edges[v].size(); i++) {
            int to = edges[v].get(i);
            if (to == pv) continue;
            int got = dfs3(to, v);
            if (got < 0) return got;
            all += got;
        }
        if (all == 0) {
            all = 1;
        }
        if (pv >= 0 && all > 1) {
            return -1;
        }
        if (all > 2) return -1;
        return all;
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