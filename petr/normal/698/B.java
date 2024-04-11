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
            int[] cycles = new int[n];
            int cyclePtr = 0;
            int identity = -1;
            int[] a = new int[n];
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt() - 1;
                if (a[i] == i) identity = i;
            }
            int[] mark = new int[n];
            int gen = 0;
            for (int i = 0; i < n; ++i)
                if (mark[i] == 0) {
                    ++gen;
                    int j = i;
                    while (mark[j] == 0) {
                        mark[j] = gen;
                        j = a[j];
                    }
                    if (mark[j] == gen) {
                        cycles[cyclePtr++] = j;
                    }
                }
            cycles = Arrays.copyOf(cycles, cyclePtr);
            int res = cyclePtr - 1;
            if (identity < 0) {
                ++res;
                a[cycles[0]] = cycles[0];
                identity = cycles[0];
            }
            for (int x : cycles) {
                if (x != identity) {
                    a[x] = identity;
                }
            }
            out.println(res);
            for (int i = 0; i < n; ++i) {
                if (i > 0) out.print(" ");
                out.print(a[i] + 1);
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