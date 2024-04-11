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
    static final int INF = (int) 1e9;
    
	public void solve(int testNumber, InputReader in, PrintWriter out) {
        int height = in.nextInt();
        int width = in.nextInt();
        int[] dist = new int[height + width];
        char[][] data = new char[height][];
        for (int r = 0; r < height; ++r)
            data[r] = in.next().toCharArray();
        Arrays.fill(dist, INF);
        int[] q = new int[height + width];
        int qt = 0;
        int qh = 1;
        q[0] = height - 1;
        dist[height - 1] = 0;
        while (qt < qh) {
            int cur = q[qt++];
            if (cur < height) {
                for (int col = 0; col < width; ++col)
                    if (data[cur][col] == '#') {
                        if (dist[col + height] == INF) {
                            dist[col + height] = dist[cur] + 1;
                            q[qh++] = col + height;
                        }
                    }
            } else {
                int col = cur - height;
                for (int row = 0; row < height; ++row)
                    if (data[row][col] == '#') {
                        if (dist[row] == INF) {
                            dist[row] = dist[cur] + 1;
                            q[qh++] = row;
                        }
                    }
            }
        }
        int res = dist[0];
        if (res == INF) res = -1;
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