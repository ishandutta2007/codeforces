import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {

    static long ansMin;
    static long ansMax;

	public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        ansMax = Long.MIN_VALUE;
        ansMin = Long.MAX_VALUE;
        List<Integer> divs = new ArrayList<Integer>();
        for (long ca = 1; ca * ca <= n; ca++) {
            if (n % ca != 0) {
                continue;
            }
            divs.add((int) ca);
            if (ca * ca != n) {
                divs.add(n / (int) ca);
            }
        }
        for (long a : divs) {
            for (long b : divs) {
                if (n % (a * b) != 0) {
                    continue;
                }
                long c = n / a / b;
                long volume = (a + 1) * (b + 2) * (c + 2);
                ansMin = Math.min(ansMin, volume);
                ansMax = Math.max(ansMax, volume);
            }
        }
        out.println((ansMin - n) + " " + (ansMax - n));
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