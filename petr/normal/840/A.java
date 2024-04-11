import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.util.Comparator;
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
        TaskA.Number[] read(int n, InputReader in) {
            TaskA.Number[] res = new TaskA.Number[n];
            for (int i = 0; i < n; ++i) {
                res[i] = new TaskA.Number(in.nextInt(), i);
            }
            return res;
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            TaskA.Number[] a = read(n, in);
            TaskA.Number[] b = read(n, in);
            Arrays.sort(b, new Comparator<TaskA.Number>() {

                public int compare(TaskA.Number o1, TaskA.Number o2) {
                    return o1.value - o2.value;
                }
            });
            Arrays.sort(a, new Comparator<TaskA.Number>() {

                public int compare(TaskA.Number o1, TaskA.Number o2) {
                    return o2.value - o1.value;
                }
            });
            int[] res = new int[n];
            for (int i = 0; i < n; ++i) {
                res[b[i].index] = a[i].value;
            }
            for (int x : res) out.print(x + " ");
            out.println();
        }

        static class Number {
            int value;
            int index;

            public Number(int value, int index) {
                this.value = value;
                this.index = index;
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