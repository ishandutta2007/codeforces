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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int p2 = 0;
            while ((1 << p2) - 1 <= n) ++p2;
            --p2;
            boolean[] parity = new boolean[(1 << p2) - 1];
            fillParity(parity, 0, parity.length - 1, false);
            int must = (1 << p2) - 1;
            for (int i = 0; i + 1 < parity.length; ++i) {
                if (parity[i] == parity[i + 1])
                    ++must;
            }
            if (n == must || n == must + 1) {
                out.println(1);
            } else {
                out.println(0);
            }
        }

        private void fillParity(boolean[] parity, int left, int right, boolean val) {
            int mid = (left + right) / 2;
            parity[mid] = val;
            if (left < right) {
                fillParity(parity, left, mid - 1, !val);
                fillParity(parity, mid + 1, right, val);
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