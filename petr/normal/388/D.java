import java.io.InputStreamReader;
import java.io.IOException;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    static final int MODULO = (int) (1e9 + 7);

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int k = in.nextInt();
        int[][] ways = new int[32][2];
        ways[0][0] = 1;
        int[] p2 = new int[10000];
        p2[0] = 1;
        for (int i = 1; i < p2.length; ++i) p2[i] = 2 * p2[i - 1] % MODULO;
        int res = 1;
        for (int bit = 30; bit >= 0; --bit) {
            int[][] nways = new int[32][2];
            if ((k & (1 << bit)) != 0) {
                for (int cnt = 0; cnt < 32; ++cnt) {
                    if (ways[cnt][0] != 0) {
                        nways[cnt + 1][0] = (nways[cnt + 1][0] + ways[cnt][0]) % MODULO;
                        res = (int) ((res + ways[cnt][0] * (long) p2[cnt * bit] % MODULO * ((k & ((1 << bit) - 1)) + 1) % MODULO) % MODULO);
                        if (cnt > 0) {
                            nways[cnt][0] = (int) ((nways[cnt][0] + ways[cnt][0] * (long) p2[cnt - 1] % MODULO) % MODULO);
                            nways[cnt][1] = (int) ((nways[cnt][1] + ways[cnt][0] * (long) p2[cnt - 1] % MODULO) % MODULO);
                        } else {
                            nways[cnt][1] = (nways[cnt][1] + ways[cnt][0]) % MODULO;
                        }
                    }
                }
            } else {
                for (int cnt = 0; cnt < 32; ++cnt) {
                    if (ways[cnt][0] != 0) {
                        if (cnt > 0) {
                            nways[cnt][0] = (int) ((nways[cnt][0] + ways[cnt][0] * (long) p2[cnt - 1] % MODULO) % MODULO);
                        } else {
                            nways[cnt][0] = (nways[cnt][0] + ways[cnt][0]) % MODULO;
                        }
                    }
                }
            }

            for (int cnt = 0; cnt < 32; ++cnt) if (ways[cnt][1] != 0) {
                nways[cnt][1] = (int) ((nways[cnt][1] + ways[cnt][1] * (long) p2[cnt] % MODULO) % MODULO);
                nways[cnt + 1][1] = (nways[cnt + 1][1] + ways[cnt][1]) % MODULO;
                res = (int) ((res + ways[cnt][1] * (long) p2[(cnt + 1) * bit] % MODULO) % MODULO);
            }
            ways = nways;
        }
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