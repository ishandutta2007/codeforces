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
		TaskF1 solver = new TaskF1();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskF1 {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int h = in.nextInt();
        int w = in.nextInt();
        boolean[][] board = new boolean[h][w];
        for (int r = 0; r < h; ++r)
            for (int c = 0; c < w; ++c)
                board[r][c] = in.nextInt() == 1;
        int[][] comp = new int[h][w];
        int ncomp = 0;
        for (int r = 0; r < h; ++r)
            for (int c = 0; c < w; ++c)
                if (board[r][c] && comp[r][c] == 0)
                    markComp(r, c, h, w, ++ncomp, board, comp);
        int[] rays = new int[ncomp];
        out.println(ncomp);
        int[][] psum = new int[h + 1][w + 1];
        for (int r = 0; r < h; ++r)
            for (int c = 0; c < w; ++c) {
                psum[r + 1][c + 1] = psum[r][c + 1] + psum[r + 1][c] - psum[r][c] + (board[r][c] ? 1 : 0);
            }
        boolean[][] sun = new boolean[h][w];
        for (int r = 0; r < h; ++r)
            for (int c = 0; c < w; ++c) if (board[r][c]) {
                int cnt = psum[Math.min(h, r + 3)][Math.min(w, c + 3)] - psum[Math.max(0, r - 3)][Math.min(w, c + 3)] - psum[Math.min(h, r + 3)][Math.max(0, c - 3)] + psum[Math.max(0, r - 3)][Math.max(0, c - 3)];
                if (cnt == 36) {
                    for (int dr = -5; dr <= 5; ++dr)
                        for (int dc = -5; dc <= 5; ++dc)
                        {
                            int nr = r + dr;
                            int nc = c + dc;
                            if (nr >= 0 && nr < h && nc >= 0 && nc < w && board[nr][nc])
                                sun[nr][nc] = true;
                        }
                }
            }
        for (int r = 0; r < h; ++r)
            for (int c = 0; c < w; ++c)
                if (sun[r][c]) board[r][c] = false;
        int[][] c2 = new int[h][w];
        for (int r = 0; r < h; ++r)
            for (int c = 0; c < w; ++c)
                if (board[r][c] && c2[r][c] == 0) {
                    markComp(r, c, h, w, 1, board, c2);
                    ++rays[comp[r][c] - 1];
                }
        Arrays.sort(rays);
        for (int i = 0; i < ncomp; ++i) {
            if (i > 0) out.print(" ");
            out.print(rays[i]);
        }
        out.println();
    }

    private void markComp(int r, int c, int h, int w, int cid, boolean[][] board, int[][] comp) {
        if (comp[r][c] != 0) {
            if (comp[r][c] != cid) throw new RuntimeException();
            return;
        }
        comp[r][c] = cid;
        for (int dr = -1; dr <= 1; ++dr)
            for (int dc = -1; dc <= 1; ++dc)
                if (Math.abs(dr) + Math.abs(dc) == 1) {
                    int nr = r + dr;
                    int nc = c + dc;
                    if (nr >= 0 && nr < h && nc >= 0 && nc < w && board[nr][nc])
                        markComp(nr, nc, h, w, cid, board, comp);
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