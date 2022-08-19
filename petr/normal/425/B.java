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
        int k = in.nextInt();
        int[][] a = new int[height][width];
        for (int r = 0; r < height; ++r)
            for (int c = 0; c < width; ++c) {
                a[r][c] = in.nextInt();
            }
        if (height < width) {
            int[][] b = new int[width][height];
            for (int r = 0; r < height; ++r)
                for (int c = 0; c < width; ++c)
                    b[c][r] = a[r][c];
            a = b;
            int tmp = height;
            height = width;
            width = tmp;
        }
        int res = k + 1;
        if (height <= k) {
            int[] rows = new int[height];
            for (int r = 0; r < height; ++r)
                for (int c = 0; c < width; ++c)
                    rows[r] |= a[r][c] << c;
            for (int mask = 0; mask < (1 << width); ++mask) {
                int cur = 0;
                for (int r = 0; r < height; ++r) {
                    int z = mask ^ rows[r];
                    int need = Integer.bitCount(z);
                    need = Math.min(need, width - need);
                    cur += need;
                }
                res = Math.min(res, cur);
            }
        } else {
            int[] got = new int[height];
            for (int fixed = 0; fixed < height; ++fixed) {
                for (int other = fixed + 1; other < height; ++other) {
                    int cur = 0;
                    for (int c = 0; c < width; ++c) {
                        if (a[fixed][c] != a[other][c]) {
                            ++cur;
                        }
                    }
                    cur = Math.min(cur, width - cur);
                    got[fixed] += cur;
                    got[other] += cur;
                }
            }
            for (int x : got) res = Math.min(res, x);
        }
        if (res > k) res = -1;
        out.println(res);
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream), 32768);
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