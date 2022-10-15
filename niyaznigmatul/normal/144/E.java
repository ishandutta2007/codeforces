import java.util.NavigableSet;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.Set;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.TreeSet;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {

    static class Segment implements Comparable<Segment>{
        int a;
        int b;
        int num;

        Segment(int a, int b, int num) {
            this.a = a;
            this.b = b;
            this.num = num;
        }

        public int compareTo(Segment o) {
            return b - o.b;
        }
    }

	public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        NavigableSet<Integer> set = new TreeSet<Integer>();
        for (int i = 0; i < n; i++) {
            set.add(i);
        }
        Segment[] a = new Segment[m];
        for (int i = 0; i < m; i++) {
            int r = in.nextInt() - 1;
            int c = in.nextInt() - 1;
            a[i] = new Segment(n - r - 1, c, i);
        }
        Arrays.sort(a);
        NavigableSet<Integer> answer = new TreeSet<Integer>();
        for (Segment e : a) {
            Integer next = set.ceiling(e.a);
            if (next == null || next > e.b) {
                continue;
            }
            answer.add(e.num);
            set.remove(next);
        }
        out.println(answer.size());
        for (int i : answer) {
            out.print(i + 1 + " ");
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

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }

    public FastPrinter(Writer out) {
        super(out);
    }


}