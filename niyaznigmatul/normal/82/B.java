import java.util.List;
import java.util.Map;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.HashMap;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.Writer;
import java.util.Collections;
import java.util.Collection;
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
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        List<Integer>[] where = new List[201];
        for (int i = 0; i <= 200; i++) {
            where[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < n * (n - 1) / 2; i++) {
            int k = in.nextInt();
            for (int j = 0; j < k; j++) {
                int x = in.nextInt();
                where[x].add(i);
            }
        }
        for (List<Integer> e : where) {
            Collections.sort(e);
        }
        Map<List<Integer>, List<Integer>> map = new HashMap<List<Integer>, List<Integer>>();
        for (int i = 0; i <= 200; i++) {
            if (where[i].isEmpty()) {
                continue;
            }
            List<Integer> e = map.get(where[i]);
            if (e == null) {
                e = new ArrayList<Integer>();
            }
            e.add(i);
            map.put(where[i], e);
        }
        if (map.size() == 1) {
            for (List<Integer> z : map.values()) {
                out.print(z.size() - 1);
                Collections.sort(z);
                int first = -1;
                boolean firs = true;
                for (int i : z) {
                    if (firs) {
                        first = i;
                        firs = false;
                    } else {
                        out.print(" " + i);
                    }
                }
                out.println();
                out.println(1 + " " + first);
            }
            return;
        }
        for (List<Integer> z : map.values()) {
            out.print(z.size());
            Collections.sort(z);
            for (int i : z) {
                out.print(" " + i);
            }
            out.println();
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