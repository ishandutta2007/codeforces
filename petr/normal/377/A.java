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
    int togo;
    int height;
    int width;
    boolean[][] wall;
    boolean[][] take;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        height = in.nextInt();
        width = in.nextInt();
        int k = in.nextInt();
        int s = 0;
        int sr = -1;
        int sc = -1;
        wall = new boolean[height][width];
        for (int row = 0; row < height; ++row) {
            String st = in.next();
            for (int col = 0; col < width; ++col) {
                if (st.charAt(col) == '#')
                    wall[row][col] = true;
                else {
                    ++s;
                    sr = row;
                    sc = col;
                }
            }
        }
        togo = s - k;
        take = new boolean[height][width];
        dfs(sr, sc);
        for (int row = 0; row < height; ++row) {
            for (int col = 0; col < width; ++col) {
                if (take[row][col]) out.print("."); else if (wall[row][col]) out.print("#"); else out.print("X");
            }
            out.println();
        }
    }

    private void dfs(int r, int c) {
        take[r][c] = true;
        --togo;
        if (togo == 0) return;
        for (int dr = -1; dr <= 1; ++dr)
            for (int dc = -1; dc <= 1; ++dc) if (Math.abs(dr) + Math.abs(dc) == 1) {
                int nr = r + dr;
                int nc = c + dc;
                if (nr >= 0 && nr < height && nc >= 0 && nc < width && !wall[nr][nc] && !take[nr][nc]) {
                    dfs(nr, nc);
                    if (togo == 0) return;
                }
            }
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