import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.StringTokenizer;

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
        int[][] data = new int[height][width];
        for (int r = 0; r < height; ++r) {
            String s = in.next();
            for (int c = 0; c < width; ++c) {
                if (s.charAt(c) == 'W') data[r][c] = 1; else data[r][c] = -1;
            }
        }
        int res = 0;
        for (int r = height - 1; r >= 0; --r)
            for (int c = width - 1; c >= 0; --c) 
                if (data[r][c] != 0) {
                    ++res;
                    int by = -data[r][c];
                    for (int rr = 0; rr <= r; ++rr)
                        for (int cc =0; cc <= c; ++cc)
                            data[rr][cc] += by;
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