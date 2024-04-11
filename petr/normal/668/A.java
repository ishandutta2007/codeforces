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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int height = in.nextInt();
            int width = in.nextInt();
            int queries = in.nextInt();
            int[] t = new int[queries];
            int[] r = new int[queries];
            int[] c = new int[queries];
            int[] x = new int[queries];
            for (int qi = 0; qi < queries; ++qi) {
                t[qi] = in.nextInt();
                switch (t[qi]) {
                    case 1:
                        r[qi] = in.nextInt() - 1;
                        break;

                    case 2:
                        c[qi] = in.nextInt() - 1;
                        break;

                    case 3:
                        r[qi] = in.nextInt() - 1;
                        c[qi] = in.nextInt() - 1;
                        x[qi] = in.nextInt();
                        break;
                }
            }

            int[][] res = new int[height][width];
            for (int qi = 0; qi < queries; ++qi)
                if (t[qi] == 3) {
                    int cr = r[qi];
                    int cc = c[qi];
                    for (int j = qi; j >= 0; --j) {
                        if (t[j] == 1 && r[j] == cr) {
                            cc = (cc + 1) % width;
                        }
                        if (t[j] == 2 && c[j] == cc) {
                            cr = (cr + 1) % height;
                        }

                    }
                    res[cr][cc] = x[qi];
                }

            for (int cr = 0; cr < height; ++cr) {
                for (int cc = 0; cc < width; ++cc) {
                    int xx = res[cr][cc];
                    if (cc > 0) out.print(" ");
                    out.print(xx);
                }
                out.println();
            }
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