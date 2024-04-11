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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    boolean[][] alive;
    int r;
    int[][][][] grundyCache;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        r = in.nextInt();
        int n = in.nextInt();
        alive = new boolean[2][r + 2];
        for (boolean[] x : alive) {
            Arrays.fill(x, true);
            x[0] = false;
            x[r + 1] = false;
        }
        grundyCache = new int[2][2][r + 2][r + 2];
        for (int[][][] x : grundyCache) for (int[][] y : x) for (int[] z : y) Arrays.fill(z, -1);
        for (int i = 0; i < n; ++i) {
            int kr = in.nextInt();
            int kc = in.nextInt() - 1;
            alive[kc][kr] = false;
            for (int rr = kr - 1; rr <= kr + 1; ++rr)
                alive[1 - kc][rr] = false;
        }
        int gg = getGrundy(0, 0, 0, r + 1);
        if (gg == 0) {
            out.println("LOSE");
        } else {
            out.println("WIN");
        }
    }

    private int getGrundy(int extraTop, int extraBottom, int top, int bottom) {
        if (top > bottom) {
            return 0;
        }
        int cached = grundyCache[extraTop][extraBottom][top][bottom];
        if (cached >= 0) return cached;
        boolean[] seen = new boolean[300];
        for (int r = top; r <= bottom; ++r)
            for (int c = 0; c < 2; ++c) {
                if (!alive[c][r]) continue;
                if (r == top && c == extraTop) continue;
                if (r == bottom && c == extraBottom) continue;
                seen[getGrundy(extraTop, 1 - c, top, r - 1) ^ getGrundy(1 - c, extraBottom, r + 1, bottom)] = true;
            }
        for (int i = 0; i < seen.length; ++i) if (!seen[i]) {
            cached = i;
            break;
        }
        grundyCache[extraTop][extraBottom][top][bottom] = cached;
        return cached;
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