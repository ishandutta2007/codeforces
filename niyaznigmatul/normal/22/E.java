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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {

    static boolean[] was;
    static int[] a;
    static int[] colors;
    static int cntColors;
    static int[] forColor;

    static int dfs(int v) {
        if (was[v]) {
            if (colors[v] < 0) {
                forColor[cntColors] = v;
                colors[v] = cntColors++;
            }
            return colors[v];
        }
        was[v] = true;
        int got = dfs(a[v]);
        return colors[v] = got;
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt() - 1;
        }
        boolean[] comes = new boolean[n];
        for (int i = 0; i < n; i++) {
            comes[a[i]] = true;
        }
        was = new boolean[n];
        colors = new int[n];
        cntColors = 0;
        forColor = new int[n];
        Arrays.fill(colors, -1);
        for (int i = 0; i < n; i++) {
            if (was[i]) {
                continue;
            }
            dfs(i);
        }
        List<Integer> ans = new ArrayList<Integer>();
        boolean[] has = new boolean[cntColors];
        for (int i = 0; i < n; i++) {
            if (comes[i]) {
                continue;
            }
            ans.add(forColor[(colors[i] - 1 + cntColors) % cntColors] + 1);
            ans.add(i + 1);
            has[colors[i]] = true;
        }
        for (int i = 0; i < cntColors; i++) {
            if (!has[i]) {
                if (cntColors == 1) {
                    break;
                }
                ans.add(forColor[(i - 1 + cntColors) % cntColors] + 1);
                ans.add(forColor[i] + 1);
            }
        }
        out.println(ans.size() / 2);
        for (int i = 0; i < ans.size(); i += 2) {
            out.println(ans.get(i) + " " + ans.get(i + 1));
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

    }

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }

    public FastPrinter(Writer out) {
        super(out);
    }


}