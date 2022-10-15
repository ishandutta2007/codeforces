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
		TaskG3 solver = new TaskG3();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskG3 {

    public int[] readToken(FastScanner in) {
        char[] c = in.next().toCharArray();
        int[] ret = new int[c.length];
        for (int i = 0; i < c.length; i++) {
            ret[i] = c[i] - 'a';
        }
        return ret;
    }

    static int[][] as;
    static int[] low;
    static int[] high;
    static SuffixAutomaton sa;
    static int[] terminal;
    static long[] dp1;
    static long[][] dp2;

    void dfs1(int v) {
        if (dp2[0][v] >= 0) return;
        for (int j = 0; j < dp2.length; j++) {
            dp2[j][v] = (terminal[v] >> j) & 1;
        }
        for (int i = 0; i < sa.link.length; i++) {
            int to = sa.link[i][v];
            if (to >= 0) {
                dfs1(to);
                for (int j = 0; j < dp2.length; j++) {
                    dp2[j][v] += dp2[j][to];
                }
            }
        }
    }

    void dfs2(int v) {
        if (dp1[v] >= 0) return;
        boolean ok = true;
        for (int i = 0; i < dp2.length;i++) {
            if (low[i] <= dp2[i][v] && dp2[i][v] <= high[i]) {

            } else {
                ok = false;
                break;
            }
        }
        if (v == 0) ok = false;
        if (ok) dp1[v] = 1; else dp1[v] = 0;
        for (int i = 0; i < sa.link.length; i++) {
            int to = sa.link[i][v];
            if (to >= 0) {
                dfs2(to);
                dp1[v] += dp1[to];
            }
        }
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int[] ss = readToken(in);
        int n = in.nextInt();
        as = new int[n + 1][];
        low = new int[n + 1];
        high = new int[n + 1];
        low[0] = 1;
        high[0] = Integer.MAX_VALUE / 3;
        as[0] = ss;
        for (int i = 1; i <= n; i++) {
            as[i] = readToken(in);
            low[i] = in.nextInt();
            high[i] = in.nextInt();
        }
        sa = new SuffixAutomaton(as, 26);
        terminal = new int[sa.free];
        for (int i = 0; i <= n; i++) {
            int v = 0;
            for (int j : as[i]) {
                v = sa.link[j][v];
            }
            while (v >= 0) {
                terminal[v] |= 1 << i;
                v = sa.sufLink[v];
            }
        }
        dp1 = new long[terminal.length];
        dp2 = new long[n + 1][terminal.length];
        Arrays.fill(dp1, -1);
        for (long[] e : dp2) {
            Arrays.fill(e, -1);
        }
        dfs1(0);
        dfs2(0);
        out.println(dp1[0]);
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

class SuffixAutomaton {
    public int[][] link;
    public int[] sufLink;
    public int[] length;
    public int free;

    public SuffixAutomaton(int[][] a, int alphabet) {
        int all = 1;
        for (int[] i : a) {
            all += i.length;
        }
        all = all * 2 + 1;
        link = new int[alphabet][all];
        sufLink = new int[all];
        length = new int[all];
        for (int[] d : link) {
            Arrays.fill(d, -1);
        }
        Arrays.fill(sufLink, -1);
        free = 0;
        int root = newNode(0);
        for (int[] d : a) {
            int v = root;
            for (int i : d) {
                v = append(v, i);
            }
        }
    }

    int newNode(int len) {
        length[free] = len;
        return free++;
    }

    int copyNode(int v, int len) {
        length[free] = len;
        for (int i = 0; i < link.length; i++) {
            link[i][free] = link[i][v];
        }
        sufLink[free] = sufLink[v];
        return free++;
    }

    int append(int v, int c) {
        if (link[c][v] >= 0) {
            int q = link[c][v];
            if (length[q] == length[v] + 1) {
                return q;
            }
            int copy = copyNode(q, length[v] + 1);
            while (v >= 0 && link[c][v] == q) {
                link[c][v] = copy;
                v = sufLink[v];
            }
            sufLink[q] = copy;
            return copy;
        }
        int u = newNode(length[v] + 1);
        while (v >= 0 && link[c][v] < 0) {
            link[c][v] = u;
            v = sufLink[v];
        }
        if (v < 0) {
            sufLink[u] = 0;
            return u;
        }
        int q = link[c][v];
        if (length[q] == length[v] + 1) {
            sufLink[u] = q;
            return u;
        }
        int copy = copyNode(q, length[v] + 1);
        while (v >= 0 && link[c][v] == q) {
            link[c][v] = copy;
            v = sufLink[v];
        }
        sufLink[q] = sufLink[u] = copy;
        return u;
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