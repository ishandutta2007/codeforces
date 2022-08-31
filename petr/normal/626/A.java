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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[][] cnt = new int[n + 1][];
            String s = in.next();
            cnt[0] = new int[4];
            for (int i = 0; i < n; ++i) {
                cnt[i + 1] = cnt[i].clone();
                ++cnt[i + 1]["UDRL".indexOf(s.charAt(i))];
            }
            int res = 0;
            for (int a = 0; a < n; ++a) {
                for (int b = a + 1; b <= n; ++b) {
                    if (cnt[b][0] - cnt[a][0] == cnt[b][1] - cnt[a][1]
                            && cnt[b][2] - cnt[a][2] == cnt[b][3] - cnt[a][3]) {
                        ++res;
                    }
                }
            }
            out.println(res);
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