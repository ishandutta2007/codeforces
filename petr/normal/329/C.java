import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    int[][] adj;
    int[] nadj;
    int[] seq;
    int[] deg;
    long finish;
    int checkEach;
    boolean timeOver;
    PrintWriter out;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        this.out = out;
        long start = System.currentTimeMillis();
        int nodes = in.nextInt();
        int edges = in.nextInt();
        adj = new int[nodes][2];
        for (int[] x : adj) Arrays.fill(x, -1);
        nadj = new int[nodes];
        for (int i = 0; i < edges; ++i) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            adj[a][nadj[a]++] = b;
            adj[b][nadj[b]++] = a;
        }
        Random random = new Random(5346543531L + System.currentTimeMillis());
        seq = new int[nodes];
        deg = new int[nodes];
        for (int attempt = 0; attempt < 10; ++attempt) {
            finish = start + (attempt + 1) * 200;
            checkEach = 1000000;
            timeOver = false;
            for (int i = 0; i < nodes; ++i) {
                seq[i] = i;
            }
            for (int i = 0; i < nodes; ++i) {
                int j = i + random.nextInt(nodes - i);
                int tmp = seq[i];
                seq[i] = seq[j];
                seq[j] = tmp;
            }
            Arrays.fill(deg, 0);
            if (rec(0, edges)) return;
        }
        out.println(-1);
    }

    private boolean rec(int at, int edges) {
        if (edges == 0) {
            return true;
        }
        if (at >= seq.length) return false;
        --checkEach;
        if (checkEach < 0) {
            if (System.currentTimeMillis() > finish) timeOver = true;
            checkEach = 1000000;
        }
        if (timeOver) return false;
        int v = seq[at];
        if (deg[v] == 0 && edges >= 2) {
            for (int dest = at + 1; dest < seq.length; ++dest) {
                int vv = seq[dest];
                if (adj[v][0] == vv || adj[v][1] == vv || deg[vv] >= 2) continue;
                ++deg[v];
                ++deg[vv];
                for (int d2 = dest + 1; d2 < seq.length; ++d2) {
                    int vvv = seq[d2];
                    if (adj[v][0] == vvv || adj[v][1] == vvv || deg[vvv] >= 2) continue;
                    ++deg[v];
                    ++deg[vvv];
                    if (rec(at + 1, edges - 2)) {
                        out.println((v + 1) + " " + (vv + 1));
                        out.println((v + 1) + " " + (vvv + 1));
                        return true;
                    }
                    if (timeOver) return false;
                    --deg[v];
                    --deg[vvv];
                }
                if (timeOver) return false;
                --deg[v];
                --deg[vv];
            }
        }
        if (deg[v] < 2) {
            for (int dest = at + 1; dest < seq.length; ++dest) {
                int vv = seq[dest];
                if (adj[v][0] == vv || adj[v][1] == vv || deg[vv] >= 2) continue;
                ++deg[v];
                ++deg[vv];
                if (rec(at + 1, edges - 1)) {
                    out.println((v + 1) + " " + (vv + 1));
                    return true;
                }
                if (timeOver) return false;
                --deg[v];
                --deg[vv];
            }
        }
        return rec(at + 1, edges);
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