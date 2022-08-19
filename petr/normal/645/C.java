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
            int n = in.nextInt();
            int k = in.nextInt();
            String s = in.next();
            int avail = 0;
            for (int i = 0; i < s.length(); ++i) if (s.charAt(i) == '0') ++avail;
            int[] free = new int[avail];
            avail = 0;
            for (int i = 0; i < s.length(); ++i) if (s.charAt(i) == '0') free[avail++] = i;
            int mid = 0;
            int res = Integer.MAX_VALUE;
            for (int left = 0; left + k + 1 <= avail; ++left) {
                while (free[mid + 1] - free[left] <= free[left + k] - free[mid + 1]) ++mid;
                res = Math.min(res, Math.max(free[mid] - free[left], free[left + k] - free[mid]));
                res = Math.min(res, Math.max(free[mid + 1] - free[left], free[left + k] - free[mid + 1]));
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