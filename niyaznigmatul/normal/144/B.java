import java.io.IOException;
import java.io.InputStreamReader;
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
        int x0 = in.nextInt();
        int y0 = in.nextInt();
        int w = in.nextInt();
        int h = in.nextInt();
        if (x0 > w) {
            int t = x0;
            x0 = w;
            w = t;
        }
        if (y0 > h) {
            int t = y0;
            y0 = h;
            h = t;
        }
        w -= x0;
        h -= y0;
        int n = in.nextInt();
        int[] x = new int[n];
        int[] y = new int[n];
        int[] r = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = in.nextInt() - x0;
            y[i] = in.nextInt() - y0;
            r[i] = in.nextInt();
        }
        int ans = 0;
        for (int curY = 0; curY <= h; curY++) {
            for (int curX = 0; curX <= w; curX++) {
                if (curX != 0 && curX != w && curY != 0 && curY != h) {
                    continue;
                }
                boolean ok = false;
                for (int b = 0; b < n; b++) {
                    int dx = curX - x[b];
                    int dy = curY - y[b];
                    if (dx * dx + dy * dy <= r[b] * r[b]) {
                        ok = true;
                        break;
                    }
                }
                if (!ok) {
                    ans++;
                }
            }
        }
        out.println(ans);
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