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
            int n = in.nextInt();
            int m = 5;
            int[] numSolvers = new int[m];
            int[] vasyaScore = new int[m];
            int[] petyaScore = new int[m];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    int z = in.nextInt();
                    if (z >= 0) {
                        ++numSolvers[j];
                        if (i == 0) {
                            vasyaScore[j] = 500 - 2 * z;
                        } else if (i == 1) {
                            petyaScore[j] = 500 - 2 * z;
                        }
                    }
                }
            }
            for (long middle = 0; middle <= 100000; ++middle) {
                int sum = 0;
                for (int j = 0; j < m; ++j) {
                    int delta = vasyaScore[j] - petyaScore[j];
                    long p;
                    long q;
                    if (vasyaScore[j] == 0) {
                        p = numSolvers[j];
                        q = n + middle;
                    } else if (vasyaScore[j] > petyaScore[j]) {
                        p = numSolvers[j];
                        q = n + middle;
                    } else {
                        p = numSolvers[j] + middle;
                        q = n + middle;
                    }
                    if (2 * p > q) {
                        sum += delta;
                    } else if (4 * p > q) {
                        sum += 2 * delta;
                    } else if (8 * p > q) {
                        sum += 3 * delta;
                    } else if (16 * p > q) {
                        sum += 4 * delta;
                    } else if (32 * p > q) {
                        sum += 5 * delta;
                    } else {
                        sum += 6 * delta;
                    }
                }
                if (sum > 0) {
                    out.println(middle);
                    return;
                }
            }
            out.println(-1);
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