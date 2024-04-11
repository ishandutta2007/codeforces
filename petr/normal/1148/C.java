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
        private int[] ra;
        private int[] rb;
        private int rcnt;
        private int[] p;
        private int n;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            p = new int[n];
            for (int i = 0; i < n; ++i) {
                p[i] = in.nextInt() - 1;
            }
            ra = new int[5 * n];
            rb = new int[5 * n];
            rcnt = 0;
            for (int i = 0; i < n; ++i)
                while (p[i] != i) {
                    int j = p[i];
                    swap(i, j);
                }
            for (int i = 0; i < n; ++i) if (p[i] != i) throw new RuntimeException();
            out.println(rcnt);
            for (int i = 0; i < rcnt; ++i) {
                out.println((ra[i] + 1) + " " + (rb[i] + 1));
            }
        }

        private void swap(int i, int j) {
            if (2 * Math.abs(i - j) >= n) {
                ra[rcnt] = i;
                rb[rcnt] = j;
                int t = p[i];
                p[i] = p[j];
                p[j] = t;
                ++rcnt;
            } else if (2 * Math.abs(i) >= n && 2 * Math.abs(j) >= n) {
                swap(i, 0);
                swap(j, 0);
                swap(i, 0);
            } else if (2 * Math.abs(n - 1 - i) >= n && 2 * Math.abs(n - 1 - j) >= n) {
                swap(i, n - 1);
                swap(j, n - 1);
                swap(i, n - 1);
            } else {
                if (i > j) {
                    swap(j, i);
                } else {
                    swap(i, n - 1);
                    swap(0, n - 1);
                    swap(0, j);
                    swap(0, n - 1);
                    swap(i, n - 1);
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