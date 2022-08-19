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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int height = in.nextInt();
        int width = in.nextInt();
        int max = 0;
        int[][] a = new int[height][width];
        for (int row = 0; row < height; ++row)
            for (int col = 0; col < width; ++col) {
                a[row][col] = in.nextInt();
                max = Math.max(max, a[row][col] + 1);
            }
        int[][] leftSame = new int[height][width];
        int[][] rightSame = new int[height][width];
        for (int[] x : leftSame) Arrays.fill(x, -1);
        for (int[] x : rightSame) Arrays.fill(x, width);
        int[] last = new int[max];
        int[] lastgen = new int[max];
        int gen = 0;
        int res = 0;
        for (int top = height - 1; top >= 0; --top) {
            int[] atleast = new int[width];
            Arrays.fill(atleast, 0);
            for (int bottom = top; bottom < height; ++bottom) {
                ++gen;
                for (int col = 0; col < width; ++col) {
                    if (bottom > top) {
                        int val = a[top][col];
                        last[val] = col;
                        lastgen[val] = gen;
                    }
                    {
                        int val = a[bottom][col];
                        if (lastgen[val] == gen) {
                            leftSame[bottom][col] = Math.max(leftSame[bottom][col], last[val]);
                        }
                    }
                    if (bottom == top) {
                        int val = a[top][col];
                        last[val] = col;
                        lastgen[val] = gen;
                    }
                }
                ++gen;
                for (int col = width - 1; col >= 0; --col) {
                    if (bottom > top) {
                        int val = a[top][col];
                        last[val] = col;
                        lastgen[val] = gen;
                    }
                    {
                        int val = a[bottom][col];
                        if (lastgen[val] == gen) {
                            rightSame[bottom][col] = Math.min(rightSame[bottom][col], last[val]);
                        }
                    }
                    if (bottom == top) {
                        int val = a[top][col];
                        last[val] = col;
                        lastgen[val] = gen;
                    }
                }
                int curAtLeast = 0;
                for (int col = 0; col < width; ++col) {
                    int left = leftSame[bottom][col];
                    int right = rightSame[bottom][col];
                    if (left >= 0) atleast[col] = Math.max(atleast[col], left + 1);
                    if (right < width) atleast[right] = Math.max(atleast[right], col + 1);
                    curAtLeast = Math.max(curAtLeast, atleast[col]);
                    res = Math.max(res, (bottom - top + 1) * (col - curAtLeast + 1));
                }
            }
        }
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