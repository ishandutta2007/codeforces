import java.util.Map;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.HashMap;
import java.util.Set;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
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
		TaskG solver = new TaskG();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskG {

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        Map<String, Integer> id = new HashMap<String, Integer>();
        int m = in.nextInt();
        int[] a = new int[m];
        int[] b = new int[m];
        for (int i = 0; i < m; i++) {
            a[i] = get(id, in.next());
            b[i] = get(id, in.next());
        }
        int n = id.size();
        short[][] mutual = new short[n][];
        for (int i = 0; i < n; i++) {
            mutual[i] = new short[i];
        }
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                int c = -1;
                int d = -1;
                if (a[i] == a[j]) {
                    c = b[i];
                    d = b[j];
                } else if (a[i] == b[j]) {
                    c = b[i];
                    d = a[j];
                } else if (b[i] == a[j]) {
                    c = a[i];
                    d = b[j];
                } else if (b[i] == b[j]) {
                    c = a[i];
                    d = a[j];
                }
                if (c >= 0) {
                    if (c < d) {
                        int t = c;
                        c = d;
                        d = t;
                    }
                    mutual[c][d]++;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            int c = a[i];
            int d = b[i];
            if (c < d) {
                int t = c;
                c = d;
                d = t;
            }
            mutual[c][d] = -1;
        }
        int[] deg = new int[n];
        for (int i = 0; i < m; i++) {
            deg[a[i]]++;
            deg[b[i]]++;
        }
        int[] answer = new int[n];
        int[] max = new int[n];
        for (int i = 0; i < n; i++) {
            int z = 0;
            int count = 0;
            for (int j = 0; j < i; j++) {
                int c = mutual[i][j];
                if (c > z) {
                    z = c;
                    count = 1;
                } else if (c == z) {
                    ++count;
                }
            }
            for (int j = i + 1; j < n; j++) {
                int c = mutual[j][i];
                if (c > z) {
                    z = c;
                    count = 1;
                } else if (c == z) {
                    ++count;
                }
            }
            answer[i] = count;
        }
        out.println(n);
        for (String e : id.keySet()) {
            out.println(e + " " + answer[id.get(e)]);
        }
    }

    static int get(Map<String, Integer> id, String s) {
        Integer z = id.get(s);
        if (z == null) {
            z = id.size();
        }
        id.put(s, z);
        return z;
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