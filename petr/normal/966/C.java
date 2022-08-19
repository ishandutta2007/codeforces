import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
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
            TaskC.Item[] items = new TaskC.Item[n];
            for (int i = 0; i < n; ++i) {
                items[i] = new TaskC.Item();
                items[i].b = in.nextLong();
            }
            Arrays.sort(items, new Comparator<TaskC.Item>() {

                public int compare(TaskC.Item o1, TaskC.Item o2) {
                    return Long.compare(o1.b, o2.b);
                }
            });
            int ptr = n;
            TaskC.Item first = null;
            for (int bit = 60; bit >= 0; --bit) {
                int upto = ptr;
                long what = 1L << bit;
                while (ptr > 0 && items[ptr - 1].b >= what) --ptr;
                if (upto == ptr) continue;
                items[ptr].next = first;
                first = items[ptr];
                int at = ptr + 1;
                for (TaskC.Item now = first.next; now != null && at < upto; now = now.next)
                    if ((now.b & what) != 0) {
                        items[at].next = now.next;
                        now.next = items[at];
                        now = items[at];
                        ++at;
                    }
                if (at < upto) {
                    out.println("No");
                    return;
                }
            }
            out.println("Yes");
            while (first != null) {
                out.print(first.b + " ");
                first = first.next;
            }
            out.println();
        }

        static class Item {
            long b;
            TaskC.Item next;

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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}