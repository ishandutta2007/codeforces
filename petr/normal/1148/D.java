import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeSet;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
import java.util.Collections;
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
            TaskD.Item[] items = new TaskD.Item[n];
            for (int i = 0; i < n; ++i) {
                items[i] = new TaskD.Item(i + 1);
                items[i].a = in.nextInt() - 1;
                items[i].b = in.nextInt() - 1;
            }

            List<TaskD.Item> res = new ArrayList<>();

            for (int iter = 0; iter < 2; ++iter) {
                TreeSet<TaskD.Item> byA = new TreeSet<>(new Comparator<TaskD.Item>() {

                    public int compare(TaskD.Item o1, TaskD.Item o2) {
                        return o1.a - o2.a;
                    }
                });
                TreeSet<TaskD.Item> byB = new TreeSet<>(new Comparator<TaskD.Item>() {

                    public int compare(TaskD.Item o1, TaskD.Item o2) {
                        return o1.b - o2.b;
                    }
                });
                for (TaskD.Item item : items) {
                    if (item.a > item.b) {
                        byA.add(item);
                        byB.add(item);
                    }
                }
                List<TaskD.Item> cur = new ArrayList<>();
                while (!byB.isEmpty()) {
                    TaskD.Item next = byB.pollFirst();
                    byA.remove(next);
                    while (!byA.isEmpty()) {
                        TaskD.Item cand = byA.first();
                        if (cand.a < next.b) {
                            byA.remove(cand);
                            byB.remove(cand);
                        } else {
                            break;
                        }
                    }
                    cur.add(next);
                }
                if (cur.size() > res.size()) {
                    res = cur;
                    if (iter == 1) {
                        Collections.reverse(res);
                    }
                }
                for (TaskD.Item item : items) {
                    int t = item.a;
                    item.a = item.b;
                    item.b = t;
                }
            }
            out.println(res.size());
            for (TaskD.Item item : res) out.print(item.index + " ");
            out.println();
        }

        static class Item {
            int index;
            int a;
            int b;

            public Item(int index) {
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