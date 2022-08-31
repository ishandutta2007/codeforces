import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int height = in.nextInt();
            int width = in.nextInt();
            int[] xRow = new int[height];
            int[] xCol = new int[width];
            for (int iter = 0; iter < 2; ++iter) {
                for (int r = 0; r < height; ++r) {
                    for (int c = 0; c < width; ++c) {
                        int a = in.nextInt();
                        xRow[r] ^= a;
                        xCol[c] ^= a;
                    }
                }
            }
            for (int x : xRow) {
                if (x != 0) {
                    out.println("No");
                    return;
                }
            }
            for (int x : xCol) {
                if (x != 0) {
                    out.println("No");
                    return;
                }
            }
            out.println("Yes");
        }

    }

    static class InputReader {
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
}