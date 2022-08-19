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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
        int height = in.nextInt();
        int width = in.nextInt();
        int[][] a = new int[height][width];
        for (int row = 0; row < height; ++row)
            for (int col = 0; col < width; ++col) {
                a[row][col] = in.nextInt();
            }
        int[][] sumLeft = new int[height + 1][width + 1];
        int[][] sumUp = new int[height + 1][width + 1];
        for (int row = 0; row < height; ++row)
            for (int col = 0; col < width; ++col) {
                sumLeft[row + 1][col + 1] = a[row][col] + sumLeft[row + 1][col];
                sumUp[row + 1][col + 1] = a[row][col] + sumUp[row][col + 1];
            }
        int res = Integer.MIN_VALUE;
        for (int startRow = 0; startRow < height; ++startRow)
            for (int startCol = 0; startCol < width; ++startCol) {
                for (int dir = -1; dir <= 1; dir += 2) {
                    int dRow = 0;
                    int dCol = dir;
                    int row = startRow;
                    int col = startCol;
                    int sum = a[startRow][startCol];
                    for (int size = 3;; size += 2) {
                        if (size == 3 || dCol < 0) {
                            int sRow = row + dRow;
                            int sCol = col + dCol;
                            int eRow = row + 2 * dRow;
                            int eCol = col + 2 * dCol;
                            if (eRow < 0 || eRow >= height || eCol < 0 || eCol >= width) break;
                            sum += sumLeft[eRow + 1][Math.max(eCol, sCol) + 1] - sumLeft[eRow + 1][Math.min(eCol, sCol)];
                            row = eRow;
                            col = eCol;
                        }
                        {
                            int ndRow = -dCol;
                            int ndCol = dRow;
                            dRow = ndRow;
                            dCol = ndCol;
                        }
                        {
                            int sRow = row + dRow;
                            int sCol = col + dCol;
                            int eRow = row + (size - 1) * dRow;
                            int eCol = col + (size - 1) * dCol;
                            if (eRow < 0 || eRow >= height || eCol < 0 || eCol >= width) break;
                            sum += sumUp[Math.max(eRow, sRow) + 1][eCol + 1] - sumUp[Math.min(eRow, sRow)][eCol + 1];
                            row = eRow;
                            col = eCol;
                            int ndRow = -dCol;
                            int ndCol = dRow;
                            dRow = ndRow;
                            dCol = ndCol;
                        }
                        {
                            int sRow = row + dRow;
                            int sCol = col + dCol;
                            int eRow = row + (size + dCol) * dRow;
                            int eCol = col + (size + dCol) * dCol;
                            if (eRow < 0 || eRow >= height || eCol < 0 || eCol >= width) break;
                            sum += sumLeft[eRow + 1][Math.max(eCol, sCol) + 1] - sumLeft[eRow + 1][Math.min(eCol, sCol)];
                            row = eRow;
                            col = eCol;
                        }
                        if (dCol < 0) {
                            res = Math.max(res, sum);
                        }
                    }
                }
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