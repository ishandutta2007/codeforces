import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    static final int MODULO = (int) (1e9 + 7);

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        if (n > m) {
            out.println(0);
            return;
        }
        int x = in.nextInt();
        --x;
        int[] ways = new int[(n + 1) * (n + 1)];
        int[] nways = new int[(n + 1) * (n + 1)];
        ways[0] = 1;
        for (int pos = 0; pos < m; ++pos) {
            {
                if (pos == x) Arrays.fill(nways, 0); else {
                    System.arraycopy(ways, 0, nways, 0, ways.length);
                }
                for (int oldbalance = 0; oldbalance < n; ++oldbalance)
                    for (int oldcomplete = 0; oldbalance + oldcomplete <= n; ++oldcomplete) {
                        int old = ways[oldbalance * (n + 1) + oldcomplete];
                        if (old != 0) {
                            int newbalance = oldbalance + 1;
                            int newcomplete = oldcomplete;
                            int newindex = newbalance * (n + 1) + newcomplete;
                            nways[newindex] += old;
                            if (nways[newindex] >= MODULO) {
                                nways[newindex] -= MODULO;
                            }
                        }
                    }
                int[] tmp = ways;
                ways = nways;
                nways = tmp;
            }
            {
                System.arraycopy(ways, 0, nways, 0, ways.length);
                for (int oldbalance = 1; oldbalance <= n; ++oldbalance)
                    for (int oldcomplete = 0; oldbalance + oldcomplete <= n; ++oldcomplete) {
                        int old = ways[oldbalance * (n + 1) + oldcomplete];
                        if (old != 0) {
                            int newbalance = oldbalance - 1;
                            int newcomplete = oldcomplete + 1;
                            int newindex = newbalance * (n + 1) + newcomplete;
                            nways[newindex] += old;
                            if (nways[newindex] >= MODULO) {
                                nways[newindex] -= MODULO;
                            }
                        }
                    }
                int[] tmp = ways;
                ways = nways;
                nways = tmp;
            }
        }
        long res = ways[n];
        for (int i = 0; i < n; ++i)
            res = res * (i + 1) % MODULO;
        out.println(res);
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    }