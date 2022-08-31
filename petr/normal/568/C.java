import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
            String vowels = in.next();
            int n = in.nextInt();
            int m = in.nextInt();
            boolean[][] edge = new boolean[2 * n][2 * n];
            for (int i = 0; i < 2 * n; ++i) edge[i][i] = true;
            for (int i = 0; i < m; ++i) {
                int p1 = in.nextInt() - 1;
                int t1 = "VC".indexOf(in.next().charAt(0));
                int p2 = in.nextInt() - 1;
                int t2 = "VC".indexOf(in.next().charAt(0));
                edge[p1 * 2 + t1][p2 * 2 + t2] = true;
                edge[p2 * 2 + (1 - t2)][p1 * 2 + (1 - t1)] = true;
            }
            if (vowels.indexOf('C') < 0) {
                for (int i = 0; i < n; ++i) edge[i * 2 + 1][i * 2] = true;
            }
            if (vowels.indexOf('V') < 0) {
                for (int i = 0; i < n; ++i) edge[i * 2][i * 2 + 1] = true;
            }
            for (int k = 0; k < edge.length; ++k)
                for (int i = 0; i < edge.length; ++i)
                    for (int j = 0; j < edge.length; ++j)
                        edge[i][j] |= (edge[i][k] & edge[k][j]);
            for (int i = 0; i < n; ++i)
                if (edge[2 * i][2 * i + 1] && edge[2 * i + 1][2 * i]) {
                    out.println(-1);
                    return;
                }
            int[] setToTrue = new int[2 * n];
            String s = in.next();
            String res = findSol(setToTrue, s, n, edge, 0, vowels);
            if (res == null) res = "-1";
            out.println(res);
        }

        String findSol(int[] setToTrue, String s, int n, boolean[][] edge, int i, String vowels) {
            if (i >= n) {
                return "";
            }
            boolean[] can = new boolean[2];
            for (int w = 0; w < 2; ++w) {
                can[w] = !edge[2 * i + w][2 * i + 1 - w] && setToTrue[2 * i + 1 - w] == 0;
                for (int j = 0; can[w] && j < n; ++j)
                    if (i != j) {
                        if (edge[2 * i + w][2 * j] && setToTrue[2 * j + 1] > 0) {
                            can[w] = false;
                        }
                        if (edge[2 * i + w][2 * j + 1] && setToTrue[2 * j] > 0) {
                            can[w] = false;
                        }
                    }
            }
            if (s != null) {
                int our = "VC".indexOf(vowels.charAt(s.charAt(i) - 'a'));
                if (can[our]) {
                    for (int j = 0; j < 2 * n; ++j) if (edge[i * 2 + our][j]) ++setToTrue[j];
                    String child = findSol(setToTrue, s, n, edge, i + 1, vowels);
                    for (int j = 0; j < 2 * n; ++j) if (edge[i * 2 + our][j]) --setToTrue[j];
                    if (child != null) return s.charAt(i) + child;
                }
            }
            int[] any = new int[2];
            Arrays.fill(any, 100);
            for (int c = (s == null ? 0 : s.charAt(i) - 'a' + 1); c < vowels.length(); ++c) {
                if (vowels.charAt(c) == 'V') {
                    if (any[0] == 100) any[0] = c;
                } else {
                    if (any[1] == 100) any[1] = c;
                }
            }
            if (any[0] == 100) can[0] = false;
            if (any[1] == 100) can[1] = false;
            if (!can[0] && !can[1]) {
                if (s == null) throw new RuntimeException();
                return null;
            }
            if (!can[0]) any[0] = 100;
            if (!can[1]) any[1] = 100;
            int our;
            if (any[0] < any[1]) our = 0;
            else our = 1;
            for (int j = 0; j < 2 * n; ++j) if (edge[i * 2 + our][j]) ++setToTrue[j];
            String child = findSol(setToTrue, null, n, edge, i + 1, vowels);
            for (int j = 0; j < 2 * n; ++j) if (edge[i * 2 + our][j]) --setToTrue[j];
            if (child == null) throw new RuntimeException();
            return (char) ('a' + any[our]) + child;
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