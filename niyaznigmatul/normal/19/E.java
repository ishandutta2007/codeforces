import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.io.Writer;
import java.util.Collection;
import java.util.HashSet;
import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.Set;
import java.io.Reader;
import java.util.Collections;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {

    static class Edge {
        int from;
        int to;
        int id;

        Edge(int from, int to, int id) {
            this.from = from;
            this.to = to;
            this.id = id;
        }
    }

    static List<Edge>[] edges;
    static int[] depth;
    static int[] count;
    static Edge[] last;
    static int countOdd;
    static Set<Integer> all;

    static void dfs(int v, int d, Edge p) {
        depth[v] = d;
        last[v] = p;
        for (Edge e : edges[v]) {
            int i = e.to;
            if (p != null && e.id == p.id) {
                continue;
            }
            if (depth[i] < 0) {
                dfs(i, d + 1, e);
            } else if (depth[i] < depth[v]) {
                Set<Integer> f = new HashSet<Integer>();
                f.add(e.id);
                for (int z = v; z != i; z = last[z].from) {
                    f.add(last[z].id);
                }
                if ((depth[v] - depth[i] & 1) == 0) {
                    countOdd++;
                    all.retainAll(f);
                } else {
                    all.removeAll(f);
                }
            }
        }
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        edges = new List[n];
        for (int i = 0; i < n; i++) {
            edges[i] = new ArrayList<Edge>();
        }
        for (int i = 0; i < m; i++) {
            int x = in.nextInt() - 1;
            int y = in.nextInt() - 1;
            edges[x].add(new Edge(x, y, i));
            edges[y].add(new Edge(y, x, i));
        }
        countOdd = 0;
        count = new int[n];
        depth = new int[n];
        last = new Edge[n];
        Arrays.fill(depth, -1);
        all = new HashSet<Integer>();
        for (int i = 0; i < m; i++) {
            all.add(i);
        }
        for (int i = 0; i < n; i++) {
            if (depth[i] < 0) {
                dfs(i, 0, null);
            }
        }
        if (countOdd == 0) {
            all = new HashSet<Integer>();
            for (int i = 0; i < m; i++) {
                all.add(i);
            }
        }
        List<Integer> answer = new ArrayList<Integer>(all);
        Collections.sort(answer);
        out.println(answer.size());
        int[] ans = ArrayUtils.toPrimitiveArrayInteger(answer);
        for (int i = 0; i < ans.length; i++) {
            ans[i]++;
        }
        out.printArray(ans);
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

class ArrayUtils {

    static public int[] toPrimitiveArrayInteger(List<Integer> list) {
        int[] ret = new int[list.size()];
        for (int i = 0; i < ret.length; i++) {
            ret[i] = list.get(i);
        }
        return ret;
    }


    }