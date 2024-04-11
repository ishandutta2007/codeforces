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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[] c = new int[n];
        boolean[][] preReq = new boolean[n][n];
        int[] deg = new int[n];
        for (int i = 0; i < n; ++i)
            c[i] = in.nextInt() - 1;
        for (int i = 0; i < n; ++i) {
            int k = in.nextInt();
            deg[i] = k;
            for (int j = 0; j < k; ++j)
                preReq[in.nextInt() - 1][i] = true;
        }
        int res = Integer.MAX_VALUE;
        for (int start = 0; start < 3; ++start) {
            int[] rem = deg.clone();
            int[][] q = new int[3][n];
            int[] qt = new int[3];
            int[] qh = new int[3];
            for (int i = 0; i < n; ++i) {
                if (rem[i] == 0) {
                    q[c[i]][qh[c[i]]++] = i;
                }
            }
            int cur = start;
            int elapsed = 0;
            int done = 0;
            while (done < n) {
                if (qt[cur] < qh[cur]) {
                    int doing = q[cur][qt[cur]++];
                    ++done;
                    ++elapsed;
                    for (int i = 0; i < n; ++i)
                        if (preReq[doing][i]) {
                            --rem[i];
                            if (rem[i] == 0) {
                                q[c[i]][qh[c[i]]++] = i;
                            }
                        }
                } else {
                    ++elapsed;
                    cur = (cur + 1) % 3;
                }
            }
            res = Math.min(res, elapsed);
        }
        out.println(res);
	}
}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

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