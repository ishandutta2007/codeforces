import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
	public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();
        DisjointSetUnion dsu = new DisjointSetUnion(n);
        for (int i = 0; i + k <= n; i++) {
            for (int j = i, t = j + k - 1; j < t; j++, t--) {
                dsu.union(j, t);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i == dsu.get(i)) {
                ans++;
            }
        }
        out.println(MathUtils.modPow(m, ans, MOD));
	}

    static final int MOD = 1000000007;
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

class DisjointSetUnion {
    int[] p;

    public DisjointSetUnion(int n) {
        p = new int[n];
        clear();
    }

    public void clear() {
        for (int i = 0; i < p.length; i++) {
            p[i] = i;
        }
    }

    public int get(int x) {
        return x != p[x] ? p[x] = get(p[x]) : x;
    }

    public boolean union(int a, int b) {
        a = get(a);
        b = get(b);
        p[a] = b;
        return a == b;
    }
}

class MathUtils {


    public static int modPow(int a, int b, int mod) {
        int ret = 1;
        a = (a % mod + mod) % mod;
        while (b > 0) {
            if ((b & 1) == 1) {
                ret = (int) ((long) ret * a % mod);
            }
            a = (int) ((long) a * a % mod);
            b >>= 1;
        }
        return ret;
    }

    }