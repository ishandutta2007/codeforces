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
        int[] dr = new int[]{-1, 1, 0, 0};
        int[] dc = new int[]{0, 0, -1, 1};

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int height = in.nextInt();
            int width = in.nextInt();
            String[] field = new String[height];
            for (int row = 0; row < height; ++row) {
                field[row] = in.next();
            }
            int sr = -1;
            int sc = -1;
            for (int r = 0; r < height; ++r) {
                for (int c = 0; c < width; ++c) {
                    if (field[r].charAt(c) == 'S') {
                        sr = r;
                        sc = c;
                    }
                }
            }
            String cmds = in.next();
            boolean[] used = new boolean[4];
            int[] meaning = new int[4];
            out.println(rec(meaning, used, cmds, height, width, field, sr, sc, 0));
        }

        private int rec(int[] meaning, boolean[] used, String cmds, int height, int width, String[] field, int sr, int sc, int at) {
            if (at == 4) {
                if (valid(meaning, cmds, height, width, field, sr, sc)) return 1;
                else return 0;
            }
            int res = 0;
            for (int i = 0; i < 4; ++i)
                if (!used[i]) {
                    meaning[at] = i;
                    used[i] = true;
                    res += rec(meaning, used, cmds, height, width, field, sr, sc, at + 1);
                    used[i] = false;
                }
            return res;
        }

        private boolean valid(int[] meaning, String cmds, int height, int width, String[] field, int sr, int sc) {
            for (char ch : cmds.toCharArray()) {
                int what = meaning[ch - '0'];
                sr += dr[what];
                sc += dc[what];
                if (sr < 0 || sr >= height || sc < 0 || sc >= width || field[sr].charAt(sc) == '#') return false;
                if (field[sr].charAt(sc) == 'E') return true;
            }
            return false;
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