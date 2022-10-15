import java.util.NavigableSet;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.SortedSet;
import java.util.Set;
import java.util.Comparator;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.TreeSet;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {


    static int step;

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        final int n = in.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt() - 1;
        }
        for (int i = 0; i < n; i++) {
            b[i] = in.nextInt() - 1;
        }
//        System.out.println(Arrays.toString(stupid(a.clone(), b.clone())));
        int[] arev = new int[n];
        for (int i = 0; i < n; i++) {
            arev[a[i]] = i;
        }
        final int[] dist = new int[n];
        for (int i = 0; i < n; i++) {
            b[i] = arev[b[i]];
            a[b[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            dist[i] = i - a[i];
            if (dist[i] < 0) {
                dist[i] += n;
            }
        }
        NavigableSet<Integer> pq1 = new TreeSet<Integer>(new Comparator<Integer>() {
            public int compare(Integer o1, Integer o2) {
                int a = dist[o1];
                int b = dist[o2];
                return a == b ? o1 - o2 : a - b;
            }
        });
        NavigableSet<Integer> pq2 = new TreeSet<Integer>(new Comparator<Integer>() {
            public int compare(Integer o1, Integer o2) {
                int a = dist[o1];
                int b = dist[o2];
                return a == b ? o1 - o2 : a - b;
            }
        });
        step = 0;
        for (int i = 0; i < n; i++) {
            if (i - a[i] < 0) {
                pq2.add(i);
            } else {
                pq1.add(i);
            }
        }
        Integer[] id = new Integer[n];
        for (int i = 0; i < n; i++) {
            id[i] = i;
        }
        Arrays.sort(id, new Comparator<Integer>() {
            public int compare(Integer o1, Integer o2) {
                return dist[o1] - dist[o2];
            }
        });
//        System.out.println(Arrays.toString(id));
//        System.out.println(Arrays.toString(a));
//        System.out.println(Arrays.toString(b));
        int[] answer = new int[n];
//        System.out.println(pq1 + " " + pq2);
        int cur = 0;
        for (int i = n - 1; i >= 0; i--) {
            int curAns = Integer.MAX_VALUE;
            if (!pq1.isEmpty()) {
                int d = dist[pq1.first()] - step;
//                System.out.println(pq1.first() + " " + d);
                curAns = Math.min(curAns, d);
            }
            if (!pq2.isEmpty()) {
                int d = n - dist[pq2.last()] + step;
//                System.out.println(pq2.last() + " " + d);
                curAns = Math.min(curAns, d);
            }
            answer[(i + 1) % n] = curAns;
            while (cur < n && dist[id[cur]] == step) {
                pq1.remove(id[cur]);
                dist[id[cur]] += n;
                pq2.add(id[cur]);
                ++cur;
            }
            pq2.remove(b[i]);
            pq1.add(b[i]);
            ++step;
//            System.out.println(pq1 + " " + pq2);
        }
        for (int i : answer) {
            out.println(i);
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