import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Set;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.StringTokenizer;
import java.util.HashSet;
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
        int[] p = MathUtils.getFactoringSieve(n + 1);
        int[] hasForPrime = new int[n + 1];
        Set<Integer> set = new HashSet<Integer>();
        all:
        for (int i = 0; i < m; i++) {
            String op = in.next();
            int x = in.nextInt();
            if (op.equals("+")) {
                if (set.contains(x)) {
                    out.println("Already on");
                    continue;
                }
                for (int z = x; z > 1; z /= p[z]) {
                    if (hasForPrime[p[z]] > 0) {
                        out.println("Conflict with " + hasForPrime[p[z]]);
                        continue all;
                    }
                }
                for (int z = x; z > 1; z /= p[z]) {
                    hasForPrime[p[z]] = x;
                }
                set.add(x);
                out.println("Success");
            } else {
                if (!set.contains(x)) {
                    out.println("Already off");
                    continue;
                }
                for (int z = x; z > 1; z /= p[z]) {
                    hasForPrime[p[z]] = 0;
                }
                set.remove(x);
                out.println("Success");
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

    //    public String next() {
//        if (!hasNext()) {
//            return null;
//        }
//        return st.nextToken();
//    }

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

class MathUtils {


    public static int[] getFactoringSieve(int n) {
        int[] p = new int[n];
        for (int i = 2; i < n; i++) {
            if (p[i] > 0) {
                continue;
            }
            for (int j = i; j < n; j += i) {
                p[j] = i;
            }
        }
        return p;

    }
}