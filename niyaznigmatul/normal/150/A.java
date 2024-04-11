import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
	public void solve(int testNumber, FastScanner in, FastPrinter out) {
        long n = in.nextLong();
        List<Long> divs = new ArrayList<Long>();
        for (long i = 1; i * i <= n; i++) {
            if (n % i != 0) {
                continue;
            }
            divs.add(i);
            if (i * i != n) {
                divs.add(n / i);
            }
        }
        Collections.sort(divs);
        boolean[] win = new boolean[divs.size()];
        long[] move = new long[divs.size()];
        for (int i = 0; i < win.length; i++) {
            long curD = divs.get(i);
            boolean couldGetMove = false;
            for (int j = 1; j < i; j++) {
                long nextD = divs.get(j);
                if (curD % nextD == 0) {
                    if (!win[j]) {
                        move[i] = nextD;
                        win[i] = true;
                    }
                    couldGetMove = true;
                }
            }
            if (!couldGetMove) {
                win[i] = true;
            }
        }
        if (win[divs.size() - 1]) {
            out.println(1);
            out.println(move[divs.size() - 1]);
        } else {
            out.println(2);
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

    public long nextLong() {
        return Long.parseLong(next());
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