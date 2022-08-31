import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Map;
import java.util.HashMap;
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
            int m = in.nextInt();
            Map<String, Integer> got = new HashMap<>();
            for (int i = 0; i < n; ++i) {
                String s = in.next();
                Integer old = got.get(s);
                if (old == null) old = 0;
                got.put(s, old | 1);
            }
            for (int i = 0; i < m; ++i) {
                String s = in.next();
                Integer old = got.get(s);
                if (old == null) old = 0;
                got.put(s, old | 2);
            }
            int[] cnt = new int[4];
            for (int x : got.values()) ++cnt[x];
            cnt[3] %= 2;
            if (cnt[3] == 0) {
                if (cnt[1] <= cnt[2]) {
                    out.println("NO");
                } else {
                    out.println("YES");
                }
            } else {
                if (cnt[2] <= cnt[1]) {
                    out.println("YES");
                } else {
                    out.println("NO");
                }
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