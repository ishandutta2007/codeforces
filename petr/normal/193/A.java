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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
        int height = in.nextInt();
        int width = in.nextInt();
        String[] field = new String[height];
        for (int row = 0; row < height; ++row) field[row] = in.next();
        int cnt = 0;
        boolean[][] f = new boolean[height][width];
        for (int row = 0; row < height; ++row)
            for (int col = 0; col < width; ++col) {
                if (field[row].charAt(col) == '.') continue;
                ++cnt;
                f[row][col] = true;
            }
        if (cnt <= 2) {
            out.println(-1);
            return;
        }
        boolean[][] mark = new boolean[height][width];
        for (int row = 0; row < height; ++row)
            for (int col = 0; col < width; ++col) if (f[row][col]) {
                f[row][col] = false;
                if (!isConnected(f, mark, height, width)) {
                    out.println(1);
                    return;
                }
                f[row][col] = true;
            }
        out.println(2);
	}

    private boolean isConnected(boolean[][] f, boolean[][] mark, int height, int width) {
        for (boolean[] x : mark) Arrays.fill(x, false);
        int comp = 0;
        for (int row = 0; row < height; ++row)
            for (int col = 0; col < width; ++col)
                if (f[row][col] && !mark[row][col]) {
                    ++comp;
                    if (comp >= 2) return false;
                    dfs(f, mark, row, col, height, width);
                }
        return true;
    }

    private void dfs(boolean[][] f, boolean[][] mark, int row, int col, int height, int width) {
        if (row < 0 || row >= height || col < 0 || col >= width || !f[row][col] || mark[row][col]) return;
        mark[row][col] = true;
        dfs(f, mark, row + 1, col, height, width);
        dfs(f, mark, row - 1, col, height, width);
        dfs(f, mark, row, col + 1, height, width);
        dfs(f, mark, row, col - 1, height, width);
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