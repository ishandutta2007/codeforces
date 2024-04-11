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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();
            int[] x = new int[k];
            for (int i = 0; i < x.length; ++i) {
                x[i] = in.nextInt() - 1;
            }
            int[] first = new int[n];
            int[] last = new int[n];
            Arrays.fill(first, -1);
            Arrays.fill(last, -1);
            for (int i = 0; i < x.length; ++i) {
                if (first[x[i]] < 0) first[x[i]] = i;
                last[x[i]] = i;
            }
            int res = 0;
            for (int i = 0; i < n; ++i) {
                if (first[i] < 0) ++res;
                if (i + 1 < n && (first[i] < 0 || first[i + 1] < 0 || last[i] < first[i + 1])) ++res;
                if (i + 1 < n && (first[i] < 0 || first[i + 1] < 0 || last[i + 1] < first[i])) ++res;
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