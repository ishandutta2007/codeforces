import java.util.Map;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.HashMap;
import java.util.Comparator;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.Writer;
import java.util.StringTokenizer;
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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        Map<String, Integer> a = new HashMap<String, Integer>();
        String[] name = new String[n];
        for (int i = 0; i < n; i++) {
            String team = in.next();
            a.put(team, i);
            name[i] = team;
        }
        final int[] pnt = new int[n];
        final int[] scored = new int[n];
        final int[] dif = new int[n];
        for (int i = 0; i < n * (n - 1) / 2; i++) {
            StringTokenizer st = new StringTokenizer(in.next(), "-");
            int t1 = a.get(st.nextToken());
            int t2 = a.get(st.nextToken());
            st = new StringTokenizer(in.next(), ":");
            int p1 = Integer.parseInt(st.nextToken());
            int p2 = Integer.parseInt(st.nextToken());
            if (p1 > p2) {
                pnt[t1] += 3;
            } else if (p1 < p2) {
                pnt[t2] += 3;
            } else {
                ++pnt[t1];
                ++pnt[t2];
            }
            scored[t1] += p1;
            scored[t2] += p2;
            dif[t1] += p1 - p2;
            dif[t2] += p2 - p1;
        }
        Integer[] z = new Integer[n];
        for (int i = 0; i < n; i++) {
            z[i] = i;
        }
        Arrays.sort(z, new Comparator<Integer>() {
            public int compare(Integer o1, Integer o2) {
                if (pnt[o1] != pnt[o2]) {
                    return pnt[o2] - pnt[o1];
                }
                if (dif[o1] != dif[o2]) {
                    return dif[o2] - dif[o1];
                }
                return scored[o2] - scored[o1];
            }
        });
        String[] ans = new String[n / 2];
        for (int i = 0; i < n / 2; i++) {
            ans[i] = (name[z[i]]);
        }
        Arrays.sort(ans);
        for (String e : ans) {
            out.println(e);
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