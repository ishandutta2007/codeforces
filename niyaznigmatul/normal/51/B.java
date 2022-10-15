import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.io.Reader;
import java.io.Writer;
import java.util.StringTokenizer;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
	public void solve(int testNumber, FastScanner in, FastPrinter out) {
        StringBuilder sb = new StringBuilder();
        while (true) {
            String s = in.nextLine();
            if (s == null) {
                break;
            }
            sb.append(s);
        }
        StringTokenizer st = new StringTokenizer(sb.toString(), "<> \r\t");
        List<Integer> ans = new ArrayList<Integer>();
        List<Integer> cur = new ArrayList<Integer>();
        while (st.hasMoreTokens()) {
            String s = st.nextToken();
            if (s.endsWith("tr")) {
                continue;
            }
            if (s.equals("td")) {
                cur.set(cur.size() - 1, cur.get(cur.size() - 1) + 1);
            }
            if (s.endsWith("td")) {
                continue;
            }
            if (s.equals("table")) {
                cur.add(0);
            } else {
                ans.add(cur.remove(cur.size() - 1));
            }
        }
        Collections.sort(ans);
        out.printArray(ArrayUtils.toPrimitiveArrayInteger(ans));
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

    public String nextLine() {
        try {
            return readLine();
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