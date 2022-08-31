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
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] cnt = new int[3];
            String s = in.next();
            for (int i = 0; i < n; ++i)
                ++cnt["BGR".indexOf(s.charAt(i))];
            boolean[] can = new boolean[3];
            int numZero = 0;
            for (int x : cnt) if (x == 0) ++numZero;
            if (numZero == 0) {
                Arrays.fill(can, true);
            } else if (numZero == 2) {
                for (int i = 0; i < 3; ++i) if (cnt[i] > 0) can[i] = true;
            } else {
                int sum = 0;
                for (int x : cnt) sum += x;
                for (int i = 0; i < 3; ++i) {
                    can[i] = cnt[i] != sum - 1;
                }
            }
            for (int i = 0; i < 3; ++i)
                if (can[i]) {
                    out.print("BGR".charAt(i));
                }
            out.println();
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