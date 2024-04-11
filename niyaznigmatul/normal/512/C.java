import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        boolean[] isPrime = MathUtils.genPrimesBoolean(123456);
        int[][] has = new int[n][n];
        for (int two = 0; two < 2; two++) {
            KuhnMatchingGraph g = new KuhnMatchingGraph(n, n);
            for (int i = 0; i < n; i++) {
                if ((a[i] & 1) == 1) continue;
                for (int j = 0; j < n; j++) {
                    if ((a[j] & 1) == 0) continue;
                    if (has[i][j] > 0) continue;
                    if (isPrime[a[i] + a[j]]) {
                        g.addEdge(i, j);
                    }
                }
            }
            int f = g.getMaximalMatching();
            if (2 * f != n) {
                out.println("Impossible");
                return;
            }
            int[] p = g.getPaired2();
            for (int i = 0; i < n; i++) {
                if ((a[i] & 1) == 1) {
                    has[i][p[i]] = has[p[i]][i] = 1;
                }
            }
        }
        List<List<Integer>> answer = new ArrayList<>();
        boolean[] was = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (was[i]) continue;
            List<Integer> cur = new ArrayList<>();
            int prev = -1;
            int last = i;
            while (true) {
                was[last] = true;
                cur.add(last);
                int next = -1;
                for (int j = 0; j < n; j++) {
                    if (has[last][j] == 0) continue;
                    if (j == prev) continue;
                    next = j;
                    break;
                }
                prev = last;
                last = next;
                if (last == i) break;
            }
            answer.add(cur);
        }
        out.println(answer.size());
        for (List<Integer> e : answer) {
            out.print(e.size());
            for (int i : e) {
                out.print(" " + (i + 1));
            }
            out.println();
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

class MathUtils {


    public static boolean[] genPrimesBoolean(int n) {
        boolean[] isPrime = new boolean[n];
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i < n; i++) {
            if (!isPrime[i]) {
                continue;
            }
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
        return isPrime;
    }

}

class KuhnMatchingGraph {

    int n;
    int m;
    List<Integer>[] edges;
    int[] p1;
    int[] p2;
    int[] was;
    int VER;

    public KuhnMatchingGraph(int n, int m) {
        this.n = n;
        this.m = m;
        edges = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            edges[i] = new ArrayList<Integer>(2);
        }
    }

    public void addEdge(int from, int to) {
        edges[from].add(to);
    }

    public int[] getPaired2() {
        return p2;
    }

    public int getMaximalMatching() {
        p1 = new int[n];
        p2 = new int[m];
        was = new int[n];
        VER = 0;
        Arrays.fill(p1, -1);
        Arrays.fill(p2, -1);
        int answer = 0;
        for (int i = 0; i < n; i++) {
            for (int j : edges[i]) {
                if (p2[j] < 0) {
                    p2[j] = i;
                    p1[i] = j;
                    answer++;
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (p1[i] >= 0) {
                continue;
            }
            VER++;
            if (dfs(i)) {
                answer++;
            }
        }
        return answer;
    }

    boolean dfs(int v) {
        if (was[v] == VER) {
            return false;
        }
        was[v] = VER;
        for (int i = 0; i < edges[v].size(); i++) {
            int e = edges[v].get(i);
            if (p2[e] < 0 || dfs(p2[e])) {
                p2[e] = v;
                p1[v] = e;
                return true;
            }
        }
        return false;
    }
}