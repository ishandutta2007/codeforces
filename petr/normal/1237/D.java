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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = new int[n * 3];
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
                a[i + n] = a[i];
                a[i + 2 * n] = a[i];
            }
            int[] nextBigger = new int[a.length];
            int[] stack = new int[a.length];
            int sp = 0;
            for (int i = a.length - 1; i >= 0; --i) {
                while (sp > 0 && a[stack[sp - 1]] <= a[i]) --sp;
                if (sp == 0) {
                    nextBigger[i] = a.length;
                } else {
                    nextBigger[i] = stack[sp - 1];
                }
                stack[sp++] = i;
            }
            int[] nextSmaller = new int[a.length];
            sp = 0;
            for (int i = a.length - 1; i >= 0; --i) {
                int bound = (a[i] - 1) / 2;
                int left = -1;
                int right = sp;
                while (right - left > 1) {
                    int middle = (left + right) / 2;
                    if (a[stack[middle]] <= bound) {
                        left = middle;
                    } else {
                        right = middle;
                    }
                }
                if (left >= 0) {
                    nextSmaller[i] = stack[left];
                } else {
                    nextSmaller[i] = a.length;
                }
                while (sp > 0 && a[stack[sp - 1]] >= a[i]) --sp;
                stack[sp++] = i;
            }
            int[] res = new int[a.length];
            for (int i = a.length - 1; i >= 0; --i) {
                if (nextSmaller[i] <= nextBigger[i]) {
                    res[i] = nextSmaller[i];
                } else {
                    res[i] = res[nextBigger[i]];
                }
            }
            for (int i = 0; i < n; ++i) {
                if (res[i] == a.length) out.print(-1);
                else out.print(res[i] - i);
                out.print(" ");
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