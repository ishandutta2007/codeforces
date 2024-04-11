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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            TaskF.Item[] items = new TaskF.Item[n];
            for (int i = 0; i < n; ++i) {
                items[i] = new TaskF.Item();
                items[i].val = in.nextLong();
                items[i].mask = in.nextLong();
            }
            Arrays.sort(items, new Comparator<TaskF.Item>() {

                public int compare(TaskF.Item o1, TaskF.Item o2) {
                    return Long.compare(o1.mask, o2.mask);
                }
            });
            long allSum = 0;
            for (TaskF.Item item : items) allSum += item.val;
            if (allSum < 0) {
                for (TaskF.Item item : items) item.val = -item.val;
            }
            long res = 0;
            long rsum = 0;
            int ptr = 0;
            for (int bit = 0; ptr < items.length; ++bit) {
                int nxt = ptr;
                while (nxt < items.length && (items[nxt].mask >>> (bit + 1)) == 0) ++nxt;
                long sum = 0;
                for (int i = ptr; i < nxt; ++i) sum += items[i].val;
                if (sum > 0) {
                    res |= (1L << bit);
                    for (TaskF.Item item : items)
                        if (((item.mask) & (1L << bit)) != 0) {
                            item.val = -item.val;
                        }
                    rsum -= sum;
                } else {
                    rsum += sum;
                }
                ptr = nxt;
            }
            if (rsum >= 0) throw new RuntimeException();
            out.println(res);
        }

        static class Item {
            long val;
            long mask;

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