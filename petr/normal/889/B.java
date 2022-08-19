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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        static final int UNKNOWN = (int) 1e9;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            String[] a = new String[n];
            for (int i = 0; i < n; ++i) {
                a[i] = in.next();
            }
            int[][] delta = new int[26][26];
            boolean[] seen = new boolean[26];
            for (int[] x : delta) Arrays.fill(x, UNKNOWN);
            for (int i = 0; i < 26; ++i) delta[i][i] = 0;
            for (String x : a) {
                int first = x.charAt(0) - 'a';
                seen[first] = true;
                for (int i = 1; i < x.length(); ++i) {
                    int second = x.charAt(i) - 'a';
                    seen[second] = true;
                    int got = i;
                    if (delta[first][second] == UNKNOWN) {
                        delta[first][second] = got;
                        delta[second][first] = -got;
                    } else {
                        if (delta[first][second] != got) {
                            out.println("NO");
                            return;
                        }
                    }
                }
            }
            for (int iter = 0; iter < 2; ++iter) {
                for (int k = 0; k < 26; ++k) {
                    for (int i = 0; i < 26; ++i) {
                        for (int j = 0; j < 26; ++j)
                            if (delta[i][k] != UNKNOWN && delta[k][j] != UNKNOWN) {
                                int got = delta[i][k] + delta[k][j];
                                if (delta[i][j] == UNKNOWN) {
                                    delta[i][j] = got;
                                    delta[j][i] = -got;
                                } else {
                                    if (delta[i][j] != got) {
                                        out.println("NO");
                                        return;
                                    }
                                }
                            }
                    }
                }
            }
            for (int i = 0; i < 26; ++i) {
                for (int j = i + 1; j < 26; ++j) {
                    if (delta[i][j] == 0) {
                        out.println("NO");
                        return;
                    }
                }
            }
            char[] res = new char[26];
            int resLen = 0;
            for (int i = 0; i < 26; ++i)
                if (seen[i]) {
                    boolean first = true;
                    for (int j = 0; j < 26; ++j) if (delta[i][j] < 0) first = false;
                    if (first) {
                        int newLen = resLen;
                        for (int j = 0; j < 26; ++j)
                            if (delta[i][j] != UNKNOWN) {
                                res[resLen + delta[i][j]] = (char) ('a' + j);
                                newLen = Math.max(newLen, resLen + delta[i][j] + 1);
                            }
                        resLen = newLen;
                    }
                }
            out.println(new String(Arrays.copyOf(res, resLen)));
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