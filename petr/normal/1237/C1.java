import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
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
        TaskC1 solver = new TaskC1();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC1 {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[][] p = new int[n][4];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < 3; ++j) {
                    p[i][j] = in.nextInt();
                }
                p[i][3] = i + 1;
            }
            Arrays.sort(p, new Comparator<int[]>() {

                public int compare(int[] o1, int[] o2) {
                    for (int i = 0; i < o1.length; ++i) if (o1[i] != o2[i]) return o1[i] - o2[i];
                    return 0;
                }
            });
            boolean[] alive = new boolean[n];
            Arrays.fill(alive, true);
            for (int i = 0; i < n; ++i)
                if (alive[i]) {
                    int j = i + 1;
                    while (!alive[j]) ++j;
                    int diff = 0;
                    while (p[i][diff] == p[j][diff]) ++diff;
                    int k = j;
                    while (k < n && p[k][diff] == p[j][diff]) ++k;
                    int bestScore = Integer.MAX_VALUE;
                    int bt = -1;
                    for (int t = j; t < k; ++t)
                        if (alive[t]) {
                            int score = 0;
                            for (int u = 0; u < 3; ++u) score += Math.abs(p[i][u] - p[t][u]);
                            if (score < bestScore) {
                                bestScore = score;
                                bt = t;
                            }
                        }
                    alive[i] = false;
                    alive[bt] = false;
                    out.println(p[i][3] + " " + p[bt][3]);
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