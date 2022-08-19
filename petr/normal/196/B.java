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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
        int height = in.nextInt();
        int width = in.nextInt();
        String[] field = new String[height];
        for (int i = 0; i < height; ++i)
            field[i] = in.next();
        boolean[][] seen = new boolean[height][width];
        int[][] dr = new int[height][width];
        int[][] dc = new int[height][width];
        int[] qr = new int[height * width + 10];
        int[] qc = new int[height * width + 10];
        int qt = 0;
        int qh = 0;
        for (int r = 0; r < height; ++r)
            for (int c = 0; c < width; ++c)
                if (field[r].charAt(c) == 'S') {
                    qr[qh] = r;
                    qc[qh] = c;
                    dr[r][c] = 0;
                    dc[r][c] = 0;
                    seen[r][c] = true;
                    ++qh;
                }
        while (qt < qh) {
            int r = qr[qt];
            int c = qc[qt];
            ++qt;
            for (int sr = -1; sr <= 1; ++sr)
                for (int sc = -1; sc <= 1; ++sc) if ((sr == 0) ^ (sc == 0)) {
                    int nr = r + sr;
                    int nc = c + sc;
                    if (nr < 0) nr += height;
                    if (nr >= height) nr -= height;
                    if (nc < 0) nc += width;
                    if (nc >= width) nc -= width;
                    if (field[nr].charAt(nc) == '#') continue;
                    int ndr = dr[r][c] + sr;
                    int ndc = dc[r][c] + sc;
                    if (seen[nr][nc]) {
                        if (dr[nr][nc] != ndr || dc[nr][nc] != ndc) {
                            out.println("Yes");
                            return;
                        }
                    } else {
                        qr[qh] = nr;
                        qc[qh] = nc;
                        seen[nr][nc] = true;
                        dr[nr][nc] = ndr;
                        dc[nr][nc] = ndc;
                        ++qh;
                    }
                }
        }
        out.println("No");
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