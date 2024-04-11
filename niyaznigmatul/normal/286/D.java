import java.util.Map;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.TreeMap;
import java.util.Comparator;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.util.NavigableMap;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.Writer;
import java.util.SortedMap;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        Event[] events = new Event[2 * m];
        for (int i = 0; i < m; i++) {
            int l = in.nextInt();
            int r = in.nextInt();
            int t = in.nextInt();
            events[2 * i] = new Event(l, true, t);
            events[2 * i + 1] = new Event(r, false, t);
        }
        NavigableMap<Integer, Integer> map = new TreeMap<>();
        Arrays.sort(events, new Comparator<Event>() {
            @Override
            public int compare(Event o1, Event o2) {
                return o1.x - o2.x;
            }
        });
        int[] q = in.readIntArray(n);
        int last = 0;
        FenwickRev f1 = new FenwickRev(n);
        FenwickRev f2 = new FenwickRev(n);
        for (Event e : events) {
            if (!map.isEmpty() && last < e.x) {
                int time = map.firstKey();
                int left = last;
                int right = e.x;
                int firstQ;
                int lastQ;
                {
                    int l = -1;
                    int r = n;
                    while (l < r - 1) {
                        int mid = l + r >> 1;
                        if (q[mid] >= time - right) {
                            r = mid;
                        } else {
                            l = mid;
                        }
                    }
                    firstQ = r;
                }
                {
                    int l = -1;
                    int r = n;
                    while (l < r - 1) {
                        int mid = l + r >> 1;
                        if (q[mid] > time - left) {
                            r = mid;
                        } else {
                            l = mid;
                        }
                    }
                    lastQ = r;
                }
                f1.add(firstQ, lastQ, 1);
                f2.add(firstQ, lastQ, -(time - right));
                f2.add(lastQ, n, right - left);
            }
            if (e.start) {
                add(map, e.time);
            } else {
                remove(map, e.time);
            }
            last = e.x;
        }
        for (int i = 0; i < n; i++) {
            int ans = f1.getElement(i) * q[i] + f2.getElement(i);
            out.println(ans);
        }
    }

    static void add(Map<Integer, Integer> map, int x) {
        Integer z = map.get(x);
        if (z == null) {
            z = 0;
        }
        map.put(x, z + 1);
    }

    static void remove(Map<Integer, Integer> map, int x) {
        Integer z = map.get(x);
        if (z == 1) {
            map.remove(x);
        } else {
            map.put(x, z - 1);
        }
    }

    static class Event {
        int x;
        boolean start;
        int time;

        Event(int x, boolean start, int time) {
            this.x = x;
            this.start = start;
            this.time = time;
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

    public int[] readIntArray(int n) {
        int[] ret = new int[n];
        for (int i = 0; i < n; i++) {
            ret[i] = nextInt();
        }
        return ret;
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

class FenwickRev {
    int[] a;

    public FenwickRev(int n) {
        a = new int[n];
    }

    public void add(int x, int y) {
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
            a[i] += y;
        }
    }

    public int getElement(int x) {
        int ret = 0;
        for (int i = x; i < a.length; i |= i + 1) {
            ret += a[i];
        }
        return ret;
    }

    public void add(int left, int right, int y) {
        add(left - 1, -y);
        add(right - 1, y);
    }

}