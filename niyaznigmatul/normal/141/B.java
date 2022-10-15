import java.io.IOException;
import java.io.InputStreamReader;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
	public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int a = in.nextInt();
        int x = in.nextInt();
        int y = in.nextInt();
        if (y % a == 0) {
            out.println(-1);
            return;
        }
        int v = y / a;
        if (v == 0 || v % 2 == 1) {
            x *= 2;
            if (x > -a && x < a) {
                out.println(getFor(v) + 1);
            } else {
                out.println(-1);
            }
        } else {
            if (x == 0 || x <= -a || x >= a) {
                out.println(-1);
            } else if (x < 0) {
                out.println(getFor(v) + 1);
            } else {
                out.println(getFor(v) + 2);
            }
        }
	}

    static int getFor(int v) {
        int ret = 0;
        for (int i = 0; i < v; i++) {
            ret += (i == 0 || (i & 1) == 1) ? 1 : 2;
        }
        return ret;
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