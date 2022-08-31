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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int rows = in.nextInt();
        int cols = in.nextInt();
        String[] map = new String[rows];
        for (int i = 0; i < rows; ++i)
            map[i] = in.next();
        int[] qr = new int[rows * cols];
        int[] qc = new int[rows * cols];
        int[][] d = new int[rows][cols];
        for (int[] x : d) Arrays.fill(x, -1);
        int qt = 0;
        int qh = 0;
        for (int r = 0; r < rows; ++r)
            for (int c = 0; c < cols; ++c)
                if (map[r].charAt(c) == 'E') {
                    qr[qh] = r;
                    qc[qh] = c;
                    d[r][c] = 0;
                    ++qh;
                }
        while (qt < qh) {
            int r = qr[qt];
            int c = qc[qt];
            ++qt;
            for (int dr = -1; dr <= 1; ++dr)
                for (int dc = -1; dc <= 1; ++dc)
                    if (Math.abs(dr) + Math.abs(dc) == 1) {
                        int nr = r + dr;
                        int nc = c + dc;
                        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && map[nr].charAt(nc) != 'T' && d[nr][nc] < 0) {
                            d[nr][nc] = d[r][c] + 1;
                            qr[qh] = nr;
                            qc[qh] = nc;
                            ++qh;
                        }
                    }
        }
        int md = 0;
        for (int r = 0; r < rows; ++r)
            for (int c = 0; c < cols; ++c)
                if (map[r].charAt(c) == 'S') {
                    md = d[r][c];
                }
        int res = 0;
        for (int r = 0; r < rows; ++r)
            for (int c = 0; c < cols; ++c)
                if (map[r].charAt(c) >= '0' && map[r].charAt(c) <= '9' && d[r][c] >= 0 && d[r][c] <= md)
                    res += map[r].charAt(c) - '0';
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