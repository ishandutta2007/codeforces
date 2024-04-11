import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
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
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {

    static class Event implements Comparable<Event> {
        int type;
        long x;
        int n;
        double prob;

        Event(int type, long x, int n) {
            this.type = type;
            this.x = x;
            this.n = n;
        }

        Event(int type, long x, int n, double prob) {
            this.type = type;
            this.x = x;
            this.n = n;
            this.prob = prob;
        }

        public int compareTo(Event o) {
            return Long.signum(x - o.x);
        }
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        Event[] events = new Event[4 * n + m];
        for (int i = 0; i < n; i++) {
            long x = in.nextInt() * 2L;
            long h = in.nextInt() * 2L;
            double p1 = in.nextInt() * .01;
            double p2 = in.nextInt() * .01;
            {
                long left = x - h - 1;
                long right = x - 1;
                events[4 * i] = new Event(0, left, 2 * i, 1 - p1);
                events[4 * i + 1] = new Event(1, right, 2 * i, 1 - p1);
            }
            {
                long left = x + 1;
                long right = x + h + 1;
                events[4 * i + 2] = new Event(0, left, 2 * i + 1, 1 - p2);
                events[4 * i + 3] = new Event(1, right, 2 * i + 1, 1 - p2);
            }
        }
        int[] cost = new int[m];
        for (int i = 0; i < m; i++) {
            long x = in.nextInt() * 2L;
            cost[i] = in.nextInt();
            events[4 * n + i] = new Event(2, x, i);
        }
        Arrays.sort(events);
        double ans = 0;
        SegmentTree tree = new SegmentTree(2 * n);
        for (Event e : events) {
            if (e.type == 0) {
                tree.set(e.n, e.prob);
            } else if (e.type == 1) {
                tree.set(e.n, 1.);
            } else {
                ans += tree.a[1] * cost[e.n];
            }
        }
        out.println(ans);
    }


    static class SegmentTree {
        double[] a;
        int n;

        SegmentTree(int n) {
            n = Integer.highestOneBit(n) << 1;
            a = new double[2 * n];
            Arrays.fill(a, 1.);
            this.n = n;
        }

        void set(int x, double y) {
            x += n;
            a[x] = y;
            while (x > 1) {
                x >>= 1;
                a[x] = a[x * 2] * a[x * 2 + 1];
            }
        }
    }
}

class FastScanner {
    BufferedReader br;
    StringTokenizer st;
    IOException happened;

    public FastScanner(InputStream is) {
        br = new BufferedReader(new InputStreamReader(is));
    }

    public String next() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                String line = br.readLine();
                st = new StringTokenizer(line);
            } catch (IOException e) {
                happened = e;
                return null;
            }
        }
        return st.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    }